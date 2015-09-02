<?php
function heybabies_menu_link(array $variables)
{
    $element = $variables['element'];
    $sub_menu = '';
    if ($element['#below'])
    {
        $sub_menu = drupal_render($element['#below']);
    }
    
    $link = l($element['#title'], $element['#href'], $element['#localized_options']);
    if ($element['#original_link']['menu_name'] == 'menu-footer-menu')
    {
        if ($element['#original_link']['link_path'] == '<nolink>')
        {
            $link = '';
            
        }
    }
    $output = '<li' . drupal_attributes($element['#attributes']) . '>' . $link . $sub_menu . "</li>\n";
    return $output;
}

function heybabies_commerce_cart_empty_block()
{
    return '<div class="cart-empty-block"><a href="/cart">my bag <span class="num">0</span></a></div>';
}

function heybabies_form_alter(&$form, &$form_state, $form_id)
{
    if ($form_id == 'user_login')
    {
        $form['name']['#title'] = 'email';
        $form['name']['#attributes']['placeholder'] = 'email';
        $form['pass']['#attributes']['placeholder'] = 'password';
        $form['forgot_pass'] = array(
            '#markup' => '<div class="form-item forgot-pass"><a href="/user/password">forgot password?</a></div>',
            '#weight' => 12,
        );
        unset($form['lost_password']);
        
        $form['actions']['#weight'] = 10;
        $form['remember_me']['#weight'] = 11;
    }
    else if ($form_id == 'user_register_form')
    {    
        unset($form['account']['mail']['#description']);
        $form['account']['mail']['#attributes']['placeholder'] = 'email';
        $form['account']['mail']['#title'] = 'email';
        $form['account']['pass']['#attributes']['placeholder'] = 'password';
        $form['account']['pass']['#process'] = array('form_process_password_confirm', 'heybabies_alter_password_confirm');
        
        $form['actions']['submit']['#value'] = t('signup');
    }
    else if ($form_id == 'user_profile_form')
    {
        drupal_set_title(t('my profile'));
        
        $form['account']['#attributes']['class'][] = 'edit-account';
        unset($form['account']['name']['#description']);
        unset($form['account']['pass']['#description']);
        unset($form['account']['mail']['#description']);
        $form['account']['mail']['#title'] = 'email';
        unset($form['account']['current_pass']['#description']);
        unset($form['mimemail']);
        unset($form['timezone']);
        $form['actions']['#weight'] = 10;
        $form['actions']['submit']['#value'] = t('save');
        
        $uid = $form['#user']->uid;
        $form['addressbook'] = array(
            '#markup' => views_embed_view('commerce_addressbook', 'default', $uid, 'shipping'),
            '#weight' => 11,
        );
    }
    else if ($form_id == 'user_pass')
    {
        drupal_set_title(t('Reset password'));
        
        $form['name']['#attributes']['placeholder'] = 'username or email';
        $form['name']['#title'] = 'username or email';
        $form['description'] = array(
            '#markup' => t('Submit your username or email address to receive a link to reset your password.'),
            '#weight' => 0,
        );
        $form['actions']['submit']['#value'] = 'reset password';
    }
    else if ($form_id == 'search_block_form')
    {
        unset($form['form_build_id']);
        unset($form['form_id']);
        $form['#action'] = '/search';
        $form['#method'] = 'GET';
        $form['search_block_form']['#attributes']['placeholder'] = 'Search';
        if (isset($_GET['keys']))
        {
            $form['search_block_form']['#default_value'] = check_plain($_GET['keys']);
        }
        $form['keys'] = $form['search_block_form'];
        unset($form['search_block_form']);
    }
    else if (substr($form_id, 0, 30) == 'commerce_cart_add_to_cart_form')
    {
        if ($form['#attributes']['class']['stock'] != 'out-of-stock')
        {
            $form['submit']['#value'] = 'add to bag';
        }
        else
        {
            $form['submit']['#value'] = 'item sold';
        }
    }
    else if ($form_id == 'views_form_commerce_cart_form_default')
    {
        $form['actions']['submit']['#value'] = t('Update quantity');
        if (strpos($form['output']['#markup'], '<!--form-item-edit_quantity') === FALSE)
        {
            unset($form['actions']['submit']);
        }
        
        global $user;
        if ($user->uid == 0)
        {
            $form['actions']['checkout']['#value'] = t('guest checkout');
            $form['actions']['login'] = array(
                '#type' => 'markup',
                '#markup' => l(t('login & checkout'), 'user/login', array(
                    'query' => array('destination' => '/checkout'),
                    'attributes' => array('class' => array('login-checkout')),
                )),
            );
        }
    }
    else if ($form_id == 'commerce_checkout_form_checkout')
    {
        $form['#attached']['js'][] = drupal_get_path('theme', 'heybabies') . '/js/checkout.js';
        
        unset($form['commerce_coupon']['coupon_code']['#description']);
        $form['commerce_coupon']['coupon_code']['#title'] = 'discount code';
        
        unset($form['buttons']['cancel']);
        unset($form['buttons']['#type']);
        $form['buttons']['continue']['#value'] = 'continue';
        
        $form['customer_profile_shipping']['addressbook']['#title'] = 'saved addresses';
        unset($form['customer_profile_shipping']['addressbook']['#description']);
        $form['customer_profile_shipping']['heading'] = array('#markup'=>'<h2>shipping</h2>', '#weight'=>-100);
        $form['customer_profile_billing']['heading'] = array('#markup'=>'<h2>billing</h2>', '#weight'=>-100);
        
        if (isset($form['account']))
        {
            $form['account']['login']['mail']['#type'] = 'emailfield';
            $form['account']['login']['mail']['#title'] = 'email';
            $form['account']['login']['mail']['#attributes']['placeholder'] = 'email';
            $form['account']['login']['#prefix'] = '<div class="account-login-container"><h2>contact</h2>';
        }
        foreach (array('customer_profile_shipping', 'customer_profile_billing') as $profile)
        {
            $form[$profile]['commerce_customer_address']['und'][0]['name_block']['name_line']['#title'] = 'your name';
            $form[$profile]['commerce_customer_address']['und'][0]['name_block']['name_line']['#attributes']['placeholder'] = 'your name';
            $form[$profile]['commerce_customer_address']['und'][0]['street_block']['thoroughfare']['#title'] = 'address';
            $form[$profile]['commerce_customer_address']['und'][0]['street_block']['thoroughfare']['#attributes']['placeholder'] = 'address';
            $form[$profile]['commerce_customer_address']['und'][0]['street_block']['premise']['#title'] = 'address 2';
            $form[$profile]['commerce_customer_address']['und'][0]['street_block']['premise']['#attributes']['placeholder'] = 'address 2';
            $form[$profile]['commerce_customer_address']['und'][0]['locality_block']['locality']['#title'] = 'city';
            $form[$profile]['commerce_customer_address']['und'][0]['locality_block']['locality']['#attributes']['placeholder'] = 'city';
            $form[$profile]['commerce_customer_address']['und'][0]['locality_block']['administrative_area']['#title'] = 'province';
            $form[$profile]['commerce_customer_address']['und'][0]['locality_block']['postal_code']['#title'] = 'postal code';
            $form[$profile]['commerce_customer_address']['und'][0]['locality_block']['postal_code']['#attributes']['placeholder'] = 'postal code';
            if (empty($form[$profile]['commerce_customer_address']['und'][0]['locality_block']['administrative_area']['#value']))
            {
                $form[$profile]['commerce_customer_address']['und'][0]['locality_block']['administrative_area']['#value'] = 'ON';
            }
            $form[$profile]['field_phone_number']['und'][0]['value']['#attributes']['placeholder'] = 'phone number';
        }
    }
    else if ($form_id == 'commerce_checkout_form_shipping')
    {
        if (isset($form['commerce_shipping']) && isset($form['commerce_shipping']['shipping_service']))
        {
            foreach($form['commerce_shipping']['shipping_service'] as $key=>$value)
            {
                if (is_array($form['commerce_shipping']['shipping_service'][$key]) && isset($form['commerce_shipping']['shipping_service'][$key]['#description']))
                {
                    unset($form['commerce_shipping']['shipping_service'][$key]['#description']);
                }
            }
            foreach($form['commerce_shipping']['shipping_service']['#options'] as $key=>$value)
            {
                if (substr($value, 0, 10) == 'Shipping: ')
                {
                    $form['commerce_shipping']['shipping_service']['#options'][$key] = substr($value, 10);
                }
            }
        }
        
        unset($form['buttons']['#type']);
        $form['buttons']['continue']['#value'] = 'continue';
        $form['buttons']['back']['#value'] = 'back';
        unset($form['buttons']['back']['#prefix']);
    }
    else if ($form_id == 'commerce_checkout_form_review')
    {
        unset($form['help']);
        unset($form['checkout_review']['review']['#data']['cart_contents']['title']);
        $form['commerce_payment']['heading'] = array('#markup'=>'<h2>payment</h2>', '#weight'=>-100);
        
        unset($form['buttons']['#type']);
        $form['buttons']['continue']['#value'] = 'place order';
        $form['buttons']['back']['#value'] = 'back';
        unset($form['buttons']['back']['#prefix']);
        
        $form['commerce_payment']['payment_details']['credit_card']['owner']['#title'] = 'cardholder name';
        $form['commerce_payment']['payment_details']['credit_card']['owner']['#attributes']['placeholder'] = 'cardholder name';
        $form['commerce_payment']['payment_details']['credit_card']['number']['#title'] = 'card number';
        $form['commerce_payment']['payment_details']['credit_card']['number']['#attributes']['placeholder'] = 'card number';
        $form['commerce_payment']['payment_details']['#prefix'] = '<div class="payment-details-form">';
        $form['commerce_payment']['payment_details']['credit_card']['exp_month']['#title'] = 'expiry';
        $form['commerce_payment']['payment_details']['credit_card']['code']['#title'] = 'security code';
        $form['commerce_payment']['payment_details']['credit_card']['code']['#attributes']['placeholder'] = 'security code';
        
        if (count($form['commerce_payment']['payment_method']['#options'] == 1))
        {
            $form['commerce_payment']['payment_method']['#attributes']['class'][] = 'hidden';
        }
        
        $form['checkout_review']['review']['#data']['account']['title'] = 'contact';
        $form['checkout_review']['review']['#data']['customer_profile_shipping']['title'] = 'shipping';
        $form['checkout_review']['review']['#data']['customer_profile_billing']['title'] = 'billing';
    }
}

function heybabies_alter_password_confirm($element)
{
    $element['pass1']['#attributes']['placeholder'] = t('password');
    $element['pass2']['#attributes']['placeholder'] = t('confirm password');
    return $element;
}

function heybabies_preprocess_html(&$vars)
{
    $path = drupal_get_path_alias($_GET['q']);
    $aliases = explode('/', $path);

    foreach($aliases as $alias)
    {
        $vars['classes_array'][] = 'path-' . drupal_clean_css_identifier($alias);
    }
    $menu_item = menu_get_item();
    if ($menu_item['page_callback'] == 'views_page' && !empty($menu_item['page_arguments']) && $menu_item['page_arguments'][0] == 'products')
    {
        $vars['classes_array'][] = 'product-listing';
    }
    else
    {
        $vars['classes_array'][] = 'not-product-listing';
    }
}
function heybabies_preprocess_page(&$vars)
{
    if (request_path() == 'contact')
    {
        $googleMapsAPIKey = 'AIzaSyD-iJhmhLIKsXb0cQV9WFfevNjk4zZBsI4';
        drupal_add_js("https://maps.googleapis.com/maps/api/js?key=$googleMapsAPIKey", 'external');
    }
}

function heybabies_pager($variables)
{
    $tags = $variables['tags'];
    $element = $variables['element'];
    $parameters = $variables['parameters'];
    $quantity = $variables['quantity'];
    global $pager_page_array, $pager_total;

    // Calculate various markers within this pager piece:
    // Middle is used to "center" pages around the current page.
    $pager_middle = ceil($quantity / 2);
    // current is the page we are currently paged to
    $pager_current = $pager_page_array[$element] + 1;
    // first is the first page listed by this pager piece (re quantity)
    $pager_first = $pager_current - $pager_middle + 1;
    // last is the last page listed by this pager piece (re quantity)
    $pager_last = $pager_current + $quantity - $pager_middle;
    // max is the maximum page number
    $pager_max = $pager_total[$element];
    // End of marker calculations.

    // Prepare for generation loop.
    $i = $pager_first;
    if ($pager_last > $pager_max) {
      // Adjust "center" if at end of query.
      $i = $i + ($pager_max - $pager_last);
      $pager_last = $pager_max;
    }
    if ($i <= 0) {
      // Adjust "center" if at start of query.
      $pager_last = $pager_last + (1 - $i);
      $i = 1;
    }
    // End of generation loop preparation.

    $li_previous = theme('pager_previous', array('text' => (isset($tags[1]) ? $tags[1] : t('‹ previous')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
    $li_next = theme('pager_next', array('text' => (isset($tags[3]) ? $tags[3] : t('next ›')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));

    if ($pager_total[$element] > 1) {
      if ($li_previous) {
        $items[] = array(
          'class' => array('pager-previous'),
          'data' => $li_previous,
        );
      }

      // When there is more than one page, create the pager list.
      if ($i != $pager_max) {
        if ($i > 1) {
          $items[] = array(
            'class' => array('pager-ellipsis'),
            'data' => '…',
          );
        }
        // Now generate the actual pager piece.
        for (; $i <= $pager_last && $i <= $pager_max; $i++) {
          if ($i < $pager_current) {
            $items[] = array(
              'class' => array('pager-item'),
              'data' => theme('pager_previous', array('text' => $i, 'element' => $element, 'interval' => ($pager_current - $i), 'parameters' => $parameters)),
            );
          }
          if ($i == $pager_current) {
            $items[] = array(
              'class' => array('pager-current'),
              'data' => $i,
            );
          }
          if ($i > $pager_current) {
            $items[] = array(
              'class' => array('pager-item'),
              'data' => theme('pager_next', array('text' => $i, 'element' => $element, 'interval' => ($i - $pager_current), 'parameters' => $parameters)),
            );
          }
        }
        if ($i < $pager_max) {
          $items[] = array(
            'class' => array('pager-ellipsis'),
            'data' => '…',
          );
        }
      }
      // End generation.
      if ($li_next) {
        $items[] = array(
          'class' => array('pager-next'),
          'data' => $li_next,
        );
      }
      $items[] = array(
          'class' => array('pager-all'),
          'data' => l(t('view all'), $_GET['q'], array('query' => array('items_per_page' => 'All'))),
        );
      return '<h2 class="element-invisible">' . t('Pages') . '</h2>' . theme('item_list', array(
        'items' => $items,
        'attributes' => array('class' => array('pager')),
      ));
    }
}

function heybabies_menu_local_task($variables)
{
    $link = $variables['element']['#link'];
    $link_text = $link['title'];
    if ($link_text == 'View') return;

    if (!empty($variables['element']['#active'])) {
        // Add text to indicate active tab for non-visual users.
        $active = '<span class="element-invisible">' . t('(active tab)') . '</span>';

        // If the link does not contain HTML already, check_plain() it now.
        // After we set 'html'=TRUE the link will not be sanitized by l().
        if (empty($link['localized_options']['html'])) {
            $link['title'] = check_plain($link['title']);
        }
        $link['localized_options']['html'] = TRUE;
        $link_text = t('!local-task-title!active', array('!local-task-title' => $link['title'], '!active' => $active));
    }

    return '<li' . (!empty($variables['element']['#active']) ? ' class="active"' : '') . '>' . l($link_text, $link['href'], $link['localized_options']) . "</li>\n";
}

function heybabies_commerce_checkout_review($variables)
{
    $form = $variables['form'];
    $rows = '<div class="review-information">';
    foreach ($form['#data'] as $pane_id => $data)
    {
        if ($pane_id == 'account')
        {
            $pane_id = 'checkout_account';
        }
        $rows .= '<div class="'.$pane_id.'">';
        if (isset($data['title']))
        {
            $rows .= '<h2>'.strtolower($data['title']).'</h2>';
        }
        if (is_array($data['data']))
        {
            foreach($data['data'] as $key=>$value)
            {
                $rows .= '<div class="field-content">'.$value.'</div>';
            }
        }
        else
        {
            $rows .= $data['data'];
        }
        $rows .= '</div>';
    }
    $rows .= '</div>';
    return $rows;
}

function heybabies_js_alter(&$js)
{
    unset($js[drupal_get_path('module', 'user').'/user.js']);
    unset($js[drupal_get_path('module', 'logintoboggan').'/logintoboggan.unifiedlogin.js']);
}

function heybabies_lt_unified_login_page($variables)
{
    $login_form = $variables['login_form'];
    $register_form = $variables['register_form'];
    $active_form = $variables['active_form'];
    
    $login_form = '<div class="login-form"><h2>log in</h2>' . $login_form . '</div>';
    $register_form = '<div class="register-form"><h2>signup</h2>' . $register_form . '</div>';
    
    $output = '';
    
    $output .= '<div class="toboggan-unified ' . $active_form . '">';
    if ($active_form == 'login')
    {
        $output .= $login_form . $register_form;
    }
    else
    {
        $output .= $register_form . $login_form;
    }
    $output .= '</div>';

    return $output;
}
?>
