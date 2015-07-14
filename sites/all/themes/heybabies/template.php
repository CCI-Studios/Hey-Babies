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
?>
