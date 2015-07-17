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
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_age']['id'] = 'field_age';
  $handler->display->display_options['fields']['field_age']['table'] = 'field_data_field_age';
  $handler->display->display_options['fields']['field_age']['field'] = 'field_age';
  $handler->display->display_options['fields']['field_age']['relationship'] = 'field_product_product_id';
  $handler->display->display_options['fields']['field_age']['label'] = '';
  $handler->display->display_options['fields']['field_age']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['footer']['area_text_custom']['content'] = '<a class="girls shop" href="/">shop girls</a>';

  /* Display: Block (boys) */
  $handler = $view->new_display('block', 'Block (boys)', 'block_boys');
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Unfiltered text */
  $handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['label'] = 'shop boys';
  $handler->display->display_options['footer']['area_text_custom']['content'] = '<a class="boys shop" href="/">shop boys</a>';
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
  $handler->display->display_options['footer']['area_text_custom']['content'] = '<a class="moms shop" href="/">shop moms</a>';
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
