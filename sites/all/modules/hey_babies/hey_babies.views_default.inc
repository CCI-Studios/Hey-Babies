<?php
/**
 * @file
 * hey_babies.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function hey_babies_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'front_features';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Front Features';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'front_features' => 'front_features',
  );
  /* Field: Content: Image background */
  $handler->display->display_options['fields']['field_image_background']['id'] = 'field_image_background';
  $handler->display->display_options['fields']['field_image_background']['table'] = 'field_data_field_image_background';
  $handler->display->display_options['fields']['field_image_background']['field'] = 'field_image_background';
  $handler->display->display_options['fields']['field_image_background']['label'] = '';
  $handler->display->display_options['fields']['field_image_background']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_background']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_background']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Link (girl) */
  $handler->display->display_options['fields']['field_link_girl']['id'] = 'field_link_girl';
  $handler->display->display_options['fields']['field_link_girl']['table'] = 'field_data_field_link_girl';
  $handler->display->display_options['fields']['field_link_girl']['field'] = 'field_link_girl';
  $handler->display->display_options['fields']['field_link_girl']['label'] = '';
  $handler->display->display_options['fields']['field_link_girl']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_link_girl']['element_label_colon'] = FALSE;
  /* Field: Content: Link (boy) */
  $handler->display->display_options['fields']['field_link_boy']['id'] = 'field_link_boy';
  $handler->display->display_options['fields']['field_link_boy']['table'] = 'field_data_field_link_boy';
  $handler->display->display_options['fields']['field_link_boy']['field'] = 'field_link_boy';
  $handler->display->display_options['fields']['field_link_boy']['label'] = '';
  $handler->display->display_options['fields']['field_link_boy']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_link_boy']['element_label_colon'] = FALSE;
  /* Field: Content: Link (mom) */
  $handler->display->display_options['fields']['field_link_mom']['id'] = 'field_link_mom';
  $handler->display->display_options['fields']['field_link_mom']['table'] = 'field_data_field_link_mom';
  $handler->display->display_options['fields']['field_link_mom']['field'] = 'field_link_mom';
  $handler->display->display_options['fields']['field_link_mom']['label'] = '';
  $handler->display->display_options['fields']['field_link_mom']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_link_mom']['element_label_colon'] = FALSE;
  /* Field: Content: Text position */
  $handler->display->display_options['fields']['field_text_position']['id'] = 'field_text_position';
  $handler->display->display_options['fields']['field_text_position']['table'] = 'field_data_field_text_position';
  $handler->display->display_options['fields']['field_text_position']['field'] = 'field_text_position';
  $handler->display->display_options['fields']['field_text_position']['label'] = '';
  $handler->display->display_options['fields']['field_text_position']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_text_position']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_text_position']['type'] = 'list_key';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<div class="feature-text [field_text_position]">
<h2>[title]</h2>
<div class="links">
<a href="[field_link_girl]">girls</a>|<a href="[field_link_boy]">boys</a>|<a href="[field_link_mom]">moms</a>
</div>
</div>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'front_feature' => 'front_feature',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_caching'] = '8';
  $export['front_features'] = $view;

  $view = new view();
  $view->name = 'front_headers';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Front Headers';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'slick';
  $handler->display->display_options['style_options']['asnavfor_auto'] = 0;
  $handler->display->display_options['style_options']['preserve_keys'] = 0;
  $handler->display->display_options['style_options']['slide_field_wrapper'] = 0;
  $handler->display->display_options['style_options']['slide_caption'] = array(
    'field_image_background' => 0,
    'body' => 0,
    'field_button_link' => 0,
    'field_button_text' => 0,
  );
  $handler->display->display_options['style_options']['override'] = 0;
  $handler->display->display_options['style_options']['overridables'] = array(
    'arrows' => 0,
    'autoplay' => 0,
    'dots' => 0,
    'draggable' => 0,
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = TRUE;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'front_headers' => 'front_headers',
    'front_features' => 0,
  );
  /* Field: Content: Image background */
  $handler->display->display_options['fields']['field_image_background']['id'] = 'field_image_background';
  $handler->display->display_options['fields']['field_image_background']['table'] = 'field_data_field_image_background';
  $handler->display->display_options['fields']['field_image_background']['field'] = 'field_image_background';
  $handler->display->display_options['fields']['field_image_background']['label'] = '';
  $handler->display->display_options['fields']['field_image_background']['element_type'] = '0';
  $handler->display->display_options['fields']['field_image_background']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_background']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_background']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_image_background']['settings'] = array(
    'url_type' => '1',
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Button link */
  $handler->display->display_options['fields']['field_button_link']['id'] = 'field_button_link';
  $handler->display->display_options['fields']['field_button_link']['table'] = 'field_data_field_button_link';
  $handler->display->display_options['fields']['field_button_link']['field'] = 'field_button_link';
  $handler->display->display_options['fields']['field_button_link']['label'] = '';
  $handler->display->display_options['fields']['field_button_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_button_link']['element_label_colon'] = FALSE;
  /* Field: Content: Button text */
  $handler->display->display_options['fields']['field_button_text']['id'] = 'field_button_text';
  $handler->display->display_options['fields']['field_button_text']['table'] = 'field_data_field_button_text';
  $handler->display->display_options['fields']['field_button_text']['field'] = 'field_button_text';
  $handler->display->display_options['fields']['field_button_text']['label'] = '';
  $handler->display->display_options['fields']['field_button_text']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_button_text']['alter']['text'] = '<a href="[field_button_link]" class="button">[field_button_text]</a>';
  $handler->display->display_options['fields']['field_button_text']['element_label_colon'] = FALSE;
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'front_header' => 'front_header',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['front_headers'] = $view;

  $view = new view();
  $view->name = 'product_node';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Product Node';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Referenced products */
  $handler->display->display_options['relationships']['field_product_product_id']['id'] = 'field_product_product_id';
  $handler->display->display_options['relationships']['field_product_product_id']['table'] = 'field_data_field_product';
  $handler->display->display_options['relationships']['field_product_product_id']['field'] = 'field_product_product_id';
  $handler->display->display_options['relationships']['field_product_product_id']['label'] = 'Product';
  $handler->display->display_options['relationships']['field_product_product_id']['required'] = TRUE;
  /* Field: Commerce Product: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'product_detail_thumb',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_image']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_image']['multi_type'] = 'ul';
  /* Field: Commerce Product: Image */
  $handler->display->display_options['fields']['field_image_1']['id'] = 'field_image_1';
  $handler->display->display_options['fields']['field_image_1']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image_1']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image_1']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['fields']['field_image_1']['label'] = '';
  $handler->display->display_options['fields']['field_image_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_1']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_image_1']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_image_1']['multi_type'] = 'ul';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Commerce Product: Price */
  $handler->display->display_options['fields']['commerce_price']['id'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['table'] = 'field_data_commerce_price';
  $handler->display->display_options['fields']['commerce_price']['field'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['fields']['commerce_price']['label'] = '';
  $handler->display->display_options['fields']['commerce_price']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_price']['settings'] = array(
    'calculation' => '0',
  );
  /* Field: Commerce Product: Retail Price */
  $handler->display->display_options['fields']['field_retail_price']['id'] = 'field_retail_price';
  $handler->display->display_options['fields']['field_retail_price']['table'] = 'field_data_field_retail_price';
  $handler->display->display_options['fields']['field_retail_price']['field'] = 'field_retail_price';
  $handler->display->display_options['fields']['field_retail_price']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['fields']['field_retail_price']['label'] = 'retail';
  $handler->display->display_options['fields']['field_retail_price']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_retail_price']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_retail_price']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_retail_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['field_retail_price']['type'] = 'commerce_price_no_decimals';
  $handler->display->display_options['fields']['field_retail_price']['settings'] = array(
    'calculation' => TRUE,
  );
  /* Field: Commerce Product: Size */
  $handler->display->display_options['fields']['field_size']['id'] = 'field_size';
  $handler->display->display_options['fields']['field_size']['table'] = 'field_data_field_size';
  $handler->display->display_options['fields']['field_size']['field'] = 'field_size';
  $handler->display->display_options['fields']['field_size']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['fields']['field_size']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_size']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Commerce Product: Description */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  /* Field: Commerce Product: Add to Cart form */
  $handler->display->display_options['fields']['add_to_cart_form']['id'] = 'add_to_cart_form';
  $handler->display->display_options['fields']['add_to_cart_form']['table'] = 'views_entity_commerce_product';
  $handler->display->display_options['fields']['add_to_cart_form']['field'] = 'add_to_cart_form';
  $handler->display->display_options['fields']['add_to_cart_form']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['fields']['add_to_cart_form']['label'] = '';
  $handler->display->display_options['fields']['add_to_cart_form']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['add_to_cart_form']['show_quantity'] = 0;
  $handler->display->display_options['fields']['add_to_cart_form']['default_quantity'] = '1';
  $handler->display->display_options['fields']['add_to_cart_form']['combine'] = 1;
  $handler->display->display_options['fields']['add_to_cart_form']['display_path'] = 1;
  $handler->display->display_options['fields']['add_to_cart_form']['line_item_type'] = 'product';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'product' => 'product',
  );
  $handler->display->display_options['arguments']['nid']['validate_options']['access'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'product' => 'product',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['product_node'] = $view;

  $view = new view();
  $view->name = 'products';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Products';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Girls';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'sort by';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'sort' => array(
      'bef_format' => 'bef_links',
      'advanced' => array(
        'collapsible' => 0,
        'collapsible_label' => 'Sort options',
        'combine' => 1,
        'combine_param' => 'sort_bef_combine',
        'combine_rewrite' => 'date added Asc|oldest
date added Desc|newest
price Asc|lowest price
price Desc|highest price',
        'reset' => 0,
        'reset_label' => '',
        'is_secondary' => 0,
        'secondary_label' => NULL,
        'bef_filter_description' => NULL,
        'any_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'pager' => array(
      'bef_format' => 'default',
      'is_secondary' => 0,
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'field_size_tid' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'secondary_label' => NULL,
    'collapsible_label' => NULL,
    'combine_rewrite' => NULL,
    'reset_label' => NULL,
    'bef_filter_description' => NULL,
    'any_label' => NULL,
    'filter_rewrite_values' => NULL,
  );
  $handler->display->display_options['exposed_form']['options']['input_required'] = 0;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'full_html';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '24';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '7';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '24';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = 'view all';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '<div class="view-summary">
<div class="link-new"><a href="">new</a></div>
<div class="summary">showing items @start - @end of @total</div>
<div class="link-all"><a href="?items_per_page=All">view all</a></div>
</div>';
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom_2']['id'] = 'area_text_custom_2';
  $handler->display->display_options['header']['area_text_custom_2']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom_2']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom_2']['label'] = 'show filters';
  $handler->display->display_options['header']['area_text_custom_2']['content'] = '<a href="#" class="show-filters">shop by</a>';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'There are no products here.';
  /* Relationship: Content: Referenced products */
  $handler->display->display_options['relationships']['field_product_product_id']['id'] = 'field_product_product_id';
  $handler->display->display_options['relationships']['field_product_product_id']['table'] = 'field_data_field_product';
  $handler->display->display_options['relationships']['field_product_product_id']['field'] = 'field_product_product_id';
  $handler->display->display_options['relationships']['field_product_product_id']['required'] = TRUE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Commerce Product: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_image']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'product_thumb',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_image']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_image']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Commerce Product: Price */
  $handler->display->display_options['fields']['commerce_price']['id'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['table'] = 'field_data_commerce_price';
  $handler->display->display_options['fields']['commerce_price']['field'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['fields']['commerce_price']['label'] = '';
  $handler->display->display_options['fields']['commerce_price']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_price']['settings'] = array(
    'calculation' => '0',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'date added';
  /* Sort criterion: price */
  $handler->display->display_options['sorts']['commerce_price_amount']['id'] = 'commerce_price_amount';
  $handler->display->display_options['sorts']['commerce_price_amount']['table'] = 'field_data_commerce_price';
  $handler->display->display_options['sorts']['commerce_price_amount']['field'] = 'commerce_price_amount';
  $handler->display->display_options['sorts']['commerce_price_amount']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['sorts']['commerce_price_amount']['ui_name'] = 'price';
  $handler->display->display_options['sorts']['commerce_price_amount']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['commerce_price_amount']['expose']['label'] = 'price';
  /* Contextual filter: Taxonomy Entity Index: Has taxonomy term ID on Commerce Product (with depth and indexed in taxonomy_entity_index) */
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth']['id'] = 'taxonomy_entity_index_tid_depth';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth']['table'] = 'commerce_product';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth']['field'] = 'taxonomy_entity_index_tid_depth';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth']['title'] = '%1';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth']['validate_options']['vocabularies'] = array(
    'clothing_type' => 'clothing_type',
  );
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth']['validate_options']['transform'] = TRUE;
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth']['depth'] = '1';
  /* Contextual filter: Taxonomy Entity Index: Has taxonomy term ID on Commerce Product (with depth and indexed in taxonomy_entity_index) */
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth_1']['id'] = 'taxonomy_entity_index_tid_depth_1';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth_1']['table'] = 'commerce_product';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth_1']['field'] = 'taxonomy_entity_index_tid_depth';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth_1']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth_1']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth_1']['title'] = '%2';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth_1']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth_1']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth_1']['validate_options']['vocabularies'] = array(
    'clothing_type' => 'clothing_type',
  );
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth_1']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth_1']['validate_options']['transform'] = TRUE;
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth_1']['depth'] = '0';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'product' => 'product',
  );
  /* Filter criterion: Commerce Product: Sex (field_sex) */
  $handler->display->display_options['filters']['field_sex_tid']['id'] = 'field_sex_tid';
  $handler->display->display_options['filters']['field_sex_tid']['table'] = 'field_data_field_sex';
  $handler->display->display_options['filters']['field_sex_tid']['field'] = 'field_sex_tid';
  $handler->display->display_options['filters']['field_sex_tid']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['filters']['field_sex_tid']['value'] = array(
    2 => '2',
  );
  $handler->display->display_options['filters']['field_sex_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_sex_tid']['vocabulary'] = 'sex';
  /* Filter criterion: Commerce Product: Size (field_size) */
  $handler->display->display_options['filters']['field_size_tid']['id'] = 'field_size_tid';
  $handler->display->display_options['filters']['field_size_tid']['table'] = 'field_data_field_size';
  $handler->display->display_options['filters']['field_size_tid']['field'] = 'field_size_tid';
  $handler->display->display_options['filters']['field_size_tid']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['filters']['field_size_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_size_tid']['expose']['operator_id'] = 'field_size_tid_op';
  $handler->display->display_options['filters']['field_size_tid']['expose']['label'] = 'size';
  $handler->display->display_options['filters']['field_size_tid']['expose']['operator'] = 'field_size_tid_op';
  $handler->display->display_options['filters']['field_size_tid']['expose']['identifier'] = 'size';
  $handler->display->display_options['filters']['field_size_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_size_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_size_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_size_tid']['vocabulary'] = 'size';
  $handler->display->display_options['filters']['field_size_tid']['error_message'] = FALSE;

  /* Display: Page (girls) */
  $handler = $view->new_display('page', 'Page (girls)', 'page_girls');
  $handler->display->display_options['path'] = 'girls';

  /* Display: Page (boys) */
  $handler = $view->new_display('page', 'Page (boys)', 'page_boys');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Boys';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'product' => 'product',
  );
  /* Filter criterion: Commerce Product: Sex (field_sex) */
  $handler->display->display_options['filters']['field_sex_tid']['id'] = 'field_sex_tid';
  $handler->display->display_options['filters']['field_sex_tid']['table'] = 'field_data_field_sex';
  $handler->display->display_options['filters']['field_sex_tid']['field'] = 'field_sex_tid';
  $handler->display->display_options['filters']['field_sex_tid']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['filters']['field_sex_tid']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_sex_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_sex_tid']['vocabulary'] = 'sex';
  /* Filter criterion: Commerce Product: Size (field_size) */
  $handler->display->display_options['filters']['field_size_tid']['id'] = 'field_size_tid';
  $handler->display->display_options['filters']['field_size_tid']['table'] = 'field_data_field_size';
  $handler->display->display_options['filters']['field_size_tid']['field'] = 'field_size_tid';
  $handler->display->display_options['filters']['field_size_tid']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['filters']['field_size_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_size_tid']['expose']['operator_id'] = 'field_size_tid_op';
  $handler->display->display_options['filters']['field_size_tid']['expose']['label'] = 'size';
  $handler->display->display_options['filters']['field_size_tid']['expose']['operator'] = 'field_size_tid_op';
  $handler->display->display_options['filters']['field_size_tid']['expose']['identifier'] = 'size';
  $handler->display->display_options['filters']['field_size_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_size_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_size_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_size_tid']['vocabulary'] = 'size';
  $handler->display->display_options['filters']['field_size_tid']['error_message'] = FALSE;
  $handler->display->display_options['path'] = 'boys';

  /* Display: Page (moms) */
  $handler = $view->new_display('page', 'Page (moms)', 'page_moms');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Moms';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'product' => 'product',
  );
  /* Filter criterion: Commerce Product: Sex (field_sex) */
  $handler->display->display_options['filters']['field_sex_tid']['id'] = 'field_sex_tid';
  $handler->display->display_options['filters']['field_sex_tid']['table'] = 'field_data_field_sex';
  $handler->display->display_options['filters']['field_sex_tid']['field'] = 'field_sex_tid';
  $handler->display->display_options['filters']['field_sex_tid']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['filters']['field_sex_tid']['value'] = array(
    34 => '34',
  );
  $handler->display->display_options['filters']['field_sex_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_sex_tid']['vocabulary'] = 'sex';
  /* Filter criterion: Commerce Product: Size (field_size) */
  $handler->display->display_options['filters']['field_size_tid']['id'] = 'field_size_tid';
  $handler->display->display_options['filters']['field_size_tid']['table'] = 'field_data_field_size';
  $handler->display->display_options['filters']['field_size_tid']['field'] = 'field_size_tid';
  $handler->display->display_options['filters']['field_size_tid']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['filters']['field_size_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_size_tid']['expose']['operator_id'] = 'field_size_tid_op';
  $handler->display->display_options['filters']['field_size_tid']['expose']['label'] = 'size';
  $handler->display->display_options['filters']['field_size_tid']['expose']['operator'] = 'field_size_tid_op';
  $handler->display->display_options['filters']['field_size_tid']['expose']['identifier'] = 'size';
  $handler->display->display_options['filters']['field_size_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_size_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_size_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_size_tid']['vocabulary'] = 'size';
  $handler->display->display_options['filters']['field_size_tid']['error_message'] = FALSE;
  $handler->display->display_options['path'] = 'moms';

  /* Display: Page (new) */
  $handler = $view->new_display('page', 'Page (new)', 'page_new');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'new arrivals';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'product' => 'product',
  );
  /* Filter criterion: Commerce Product: Size (field_size) */
  $handler->display->display_options['filters']['field_size_tid']['id'] = 'field_size_tid';
  $handler->display->display_options['filters']['field_size_tid']['table'] = 'field_data_field_size';
  $handler->display->display_options['filters']['field_size_tid']['field'] = 'field_size_tid';
  $handler->display->display_options['filters']['field_size_tid']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['filters']['field_size_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_size_tid']['expose']['operator_id'] = 'field_size_tid_op';
  $handler->display->display_options['filters']['field_size_tid']['expose']['label'] = 'size';
  $handler->display->display_options['filters']['field_size_tid']['expose']['operator'] = 'field_size_tid_op';
  $handler->display->display_options['filters']['field_size_tid']['expose']['identifier'] = 'size';
  $handler->display->display_options['filters']['field_size_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_size_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_size_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_size_tid']['vocabulary'] = 'size';
  $handler->display->display_options['filters']['field_size_tid']['error_message'] = FALSE;
  $handler->display->display_options['path'] = 'new';
  $export['products'] = $view;

  $view = new view();
  $view->name = 'recent';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Recent';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Recent';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'slick';
  $handler->display->display_options['style_options']['asnavfor_auto'] = 0;
  $handler->display->display_options['style_options']['preserve_keys'] = 0;
  $handler->display->display_options['style_options']['slide_field_wrapper'] = 0;
  $handler->display->display_options['style_options']['slide_caption'] = array(
    'field_image' => 0,
    'title' => 0,
    'field_age' => 0,
    'commerce_price' => 0,
  );
  $handler->display->display_options['style_options']['override'] = 0;
  $handler->display->display_options['style_options']['overridables'] = array(
    'arrows' => 0,
    'autoplay' => 0,
    'dots' => 0,
    'draggable' => 0,
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Referenced products */
  $handler->display->display_options['relationships']['field_product_product_id']['id'] = 'field_product_product_id';
  $handler->display->display_options['relationships']['field_product_product_id']['table'] = 'field_data_field_product';
  $handler->display->display_options['relationships']['field_product_product_id']['field'] = 'field_product_product_id';
  $handler->display->display_options['relationships']['field_product_product_id']['required'] = TRUE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Commerce Product: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_image']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'product_thumb',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_image']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_image']['delta_offset'] = '0';
  /* Field: Commerce Product: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['title']['element_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_product'] = 0;
  /* Field: Commerce Product: Price */
  $handler->display->display_options['fields']['commerce_price']['id'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['table'] = 'field_data_commerce_price';
  $handler->display->display_options['fields']['commerce_price']['field'] = 'commerce_price';
  $handler->display->display_options['fields']['commerce_price']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['fields']['commerce_price']['label'] = '';
  $handler->display->display_options['fields']['commerce_price']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_price']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_price']['settings'] = array(
    'calculation' => 'calculated_sell_price',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'product' => 'product',
  );
  /* Filter criterion: Commerce Product: Sex (field_sex) */
  $handler->display->display_options['filters']['field_sex_tid']['id'] = 'field_sex_tid';
  $handler->display->display_options['filters']['field_sex_tid']['table'] = 'field_data_field_sex';
  $handler->display->display_options['filters']['field_sex_tid']['field'] = 'field_sex_tid';
  $handler->display->display_options['filters']['field_sex_tid']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['filters']['field_sex_tid']['value'] = array(
    2 => '2',
  );
  $handler->display->display_options['filters']['field_sex_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_sex_tid']['vocabulary'] = 'sex';

  /* Display: Block (girls) */
  $handler = $view->new_display('block', 'Block (girls)', 'block_girls');
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Unfiltered text */
  $handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['label'] = 'shop girls';
  $handler->display->display_options['footer']['area_text_custom']['content'] = '<a class="girls shop" href="/girls">shop girls</a>';

  /* Display: Block (boys) */
  $handler = $view->new_display('block', 'Block (boys)', 'block_boys');
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Unfiltered text */
  $handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['label'] = 'shop boys';
  $handler->display->display_options['footer']['area_text_custom']['content'] = '<a class="boys shop" href="/boys">shop boys</a>';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'product' => 'product',
  );
  /* Filter criterion: Commerce Product: Sex (field_sex) */
  $handler->display->display_options['filters']['field_sex_tid']['id'] = 'field_sex_tid';
  $handler->display->display_options['filters']['field_sex_tid']['table'] = 'field_data_field_sex';
  $handler->display->display_options['filters']['field_sex_tid']['field'] = 'field_sex_tid';
  $handler->display->display_options['filters']['field_sex_tid']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['filters']['field_sex_tid']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_sex_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_sex_tid']['vocabulary'] = 'sex';

  /* Display: Block (mom) */
  $handler = $view->new_display('block', 'Block (mom)', 'block_mom');
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Unfiltered text */
  $handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['label'] = 'shop moms';
  $handler->display->display_options['footer']['area_text_custom']['content'] = '<a class="moms shop" href="/moms">shop moms</a>';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'product' => 'product',
  );
  /* Filter criterion: Commerce Product: Sex (field_sex) */
  $handler->display->display_options['filters']['field_sex_tid']['id'] = 'field_sex_tid';
  $handler->display->display_options['filters']['field_sex_tid']['table'] = 'field_data_field_sex';
  $handler->display->display_options['filters']['field_sex_tid']['field'] = 'field_sex_tid';
  $handler->display->display_options['filters']['field_sex_tid']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['filters']['field_sex_tid']['value'] = array(
    34 => '34',
  );
  $handler->display->display_options['filters']['field_sex_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_sex_tid']['vocabulary'] = 'sex';
  $export['recent'] = $view;

  return $export;
}
