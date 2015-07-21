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
    if ($form_id == 'search_block_form')
    {
        $form['search_block_form']['#attributes']['placeholder'] = 'Search';
    }
}

function heybabies_preprocess_html(&$vars)
{
    $path = drupal_get_path_alias($_GET['q']);
    $aliases = explode('/', $path);

    foreach($aliases as $alias)
    {
        $vars['classes_array'][] = 'path-' . drupal_clean_css_identifier($alias);
    }
    
    if (in_array($aliases[0], array('new','girls','boys','moms')))
    {
        $vars['classes_array'][] = 'product-listing';
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

    //$li_first = theme('pager_first', array('text' => (isset($tags[0]) ? $tags[0] : t('« first')), 'element' => $element, 'parameters' => $parameters));
    $li_previous = theme('pager_previous', array('text' => (isset($tags[1]) ? $tags[1] : t('‹ previous')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
    $li_next = theme('pager_next', array('text' => (isset($tags[3]) ? $tags[3] : t('next ›')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
    //$li_last = theme('pager_last', array('text' => (isset($tags[4]) ? $tags[4] : t('last »')), 'element' => $element, 'parameters' => $parameters));

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
?>
