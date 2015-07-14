<?php
/**
 * @file
 * hey_babies.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function hey_babies_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'commerce_customer_profile-billing-commerce_customer_address'
  $field_instances['commerce_customer_profile-billing-commerce_customer_address'] = array(
    'bundle' => 'billing',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'administrator' => array(
        'label' => 'hidden',
        'module' => 'addressfield',
        'settings' => array(
          'format_handlers' => array(
            0 => 'address',
          ),
          'use_widget_handlers' => 1,
        ),
        'type' => 'addressfield_default',
        'weight' => -10,
      ),
      'customer' => array(
        'label' => 'hidden',
        'module' => 'addressfield',
        'settings' => array(
          'format_handlers' => array(
            0 => 'address',
          ),
          'use_widget_handlers' => 1,
        ),
        'type' => 'addressfield_default',
        'weight' => -10,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'addressfield',
        'settings' => array(
          'format_handlers' => array(
            0 => 'address',
          ),
          'use_widget_handlers' => 1,
        ),
        'type' => 'addressfield_default',
        'weight' => -10,
      ),
    ),
    'entity_type' => 'commerce_customer_profile',
    'field_name' => 'commerce_customer_address',
    'label' => 'Address',
    'required' => TRUE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'addressfield',
      'settings' => array(
        'available_countries' => array(),
        'default_country' => 'site_default',
        'format_handlers' => array(
          0 => 'address',
          1 => 'name-oneline',
        ),
      ),
      'type' => 'addressfield_standard',
      'weight' => -10,
    ),
  );

  // Exported field_instance:
  // 'commerce_customer_profile-shipping-commerce_customer_address'
  $field_instances['commerce_customer_profile-shipping-commerce_customer_address'] = array(
    'bundle' => 'shipping',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'administrator' => array(
        'label' => 'hidden',
        'module' => 'addressfield',
        'settings' => array(
          'format_handlers' => array(
            0 => 'address',
          ),
          'use_widget_handlers' => 1,
        ),
        'type' => 'addressfield_default',
        'weight' => -10,
      ),
      'customer' => array(
        'label' => 'hidden',
        'module' => 'addressfield',
        'settings' => array(
          'format_handlers' => array(
            0 => 'address',
          ),
          'use_widget_handlers' => 1,
        ),
        'type' => 'addressfield_default',
        'weight' => -10,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'addressfield',
        'settings' => array(
          'format_handlers' => array(
            0 => 'address',
          ),
          'use_widget_handlers' => 1,
        ),
        'type' => 'addressfield_default',
        'weight' => -10,
      ),
    ),
    'entity_type' => 'commerce_customer_profile',
    'field_name' => 'commerce_customer_address',
    'label' => 'Address',
    'required' => TRUE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'addressfield',
      'settings' => array(
        'available_countries' => array(),
        'default_country' => 'site_default',
        'format_handlers' => array(
          0 => 'address',
          1 => 'name-oneline',
        ),
      ),
      'type' => 'addressfield_standard',
      'weight' => -10,
    ),
  );

  // Exported field_instance: 'commerce_product-product-commerce_price'
  $field_instances['commerce_product-product-commerce_price'] = array(
    'bundle' => 'product',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'commerce_line_item_display' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'commerce_line_item_token' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 1,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'line_item' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 1,
      ),
      'node_teaser' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
      'token' => array(
        'label' => 'hidden',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => 'calculated_sell_price',
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'commerce_product',
    'field_name' => 'commerce_price',
    'label' => 'Price',
    'required' => TRUE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'commerce_price',
      'settings' => array(
        'currency_code' => 'default',
      ),
      'type' => 'commerce_price_full',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'commerce_product-product-field_age'
  $field_instances['commerce_product-product-field_age'] = array(
    'bundle' => 'product',
    'commerce_cart_settings' => array(
      'attribute_field' => 0,
      'attribute_widget' => 'select',
      'attribute_widget_title' => 'Age',
    ),
    'default_value' => array(
      0 => array(
        'tid' => 33,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 3,
      ),
      'line_item' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'node_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'commerce_product',
    'field_name' => 'field_age',
    'label' => 'Age',
    'product_catalog' => 1,
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'commerce_product-product-field_brand'
  $field_instances['commerce_product-product-field_brand'] = array(
    'bundle' => 'product',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
      'line_item' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
      'node_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'commerce_product',
    'field_name' => 'field_brand',
    'label' => 'Brand',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'commerce_product-product-field_clothing_type'
  $field_instances['commerce_product-product-field_clothing_type'] = array(
    'bundle' => 'product',
    'commerce_cart_settings' => array(
      'attribute_field' => 0,
      'attribute_widget' => 'select',
      'attribute_widget_title' => 'Clothing type',
    ),
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 4,
      ),
      'line_item' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
      'node_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'commerce_product',
    'field_name' => 'field_clothing_type',
    'label' => 'Clothing type',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'commerce_product-product-field_color'
  $field_instances['commerce_product-product-field_color'] = array(
    'bundle' => 'product',
    'commerce_cart_settings' => array(
      'attribute_field' => 0,
      'attribute_widget' => 'commerce_fancy_attributes',
      'attribute_widget_title' => 'Color',
    ),
    'default_value' => array(
      0 => array(
        'tid' => 31,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 11,
      ),
      'line_item' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'node_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'commerce_product',
    'field_name' => 'field_color',
    'label' => 'Color',
    'product_catalog' => 1,
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'commerce_product-product-field_description'
  $field_instances['commerce_product-product-field_description'] = array(
    'bundle' => 'product',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
      'line_item' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'node_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'commerce_product',
    'field_name' => 'field_description',
    'label' => 'Description',
    'required' => 0,
    'settings' => array(
      'display_summary' => 1,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'commerce_product-product-field_image'
  $field_instances['commerce_product-product-field_image'] = array(
    'bundle' => 'product',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 10,
      ),
      'line_item' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'node_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'commerce_product',
    'field_name' => 'field_image',
    'label' => 'Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'commerce_product-product-field_inventory_date'
  $field_instances['commerce_product-product-field_inventory_date'] = array(
    'bundle' => 'product',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 13,
      ),
      'line_item' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'node_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'commerce_product',
    'field_name' => 'field_inventory_date',
    'label' => 'Inventory Date',
    'required' => 0,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 1,
        'input_format' => 'Y-m-d H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'text_parts' => array(),
        'year_range' => '2015:+3',
      ),
      'type' => 'date_popup',
      'weight' => 11,
    ),
  );

  // Exported field_instance:
  // 'commerce_product-product-field_physical_dimensions'
  $field_instances['commerce_product-product-field_physical_dimensions'] = array(
    'bundle' => 'product',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'physical',
        'settings' => array(),
        'type' => 'physical_dimensions_formatted',
        'weight' => 15,
      ),
      'line_item' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'node_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'commerce_product',
    'field_name' => 'field_physical_dimensions',
    'label' => 'Physical dimensions',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'physical',
      'settings' => array(
        'default_unit' => 'cm',
        'unit_select_list' => 1,
      ),
      'type' => 'physical_dimensions_textfields',
      'weight' => 16,
    ),
  );

  // Exported field_instance: 'commerce_product-product-field_physical_weight'
  $field_instances['commerce_product-product-field_physical_weight'] = array(
    'bundle' => 'product',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'physical',
        'settings' => array(),
        'type' => 'physical_weight_formatted',
        'weight' => 14,
      ),
      'line_item' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'node_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'commerce_product',
    'field_name' => 'field_physical_weight',
    'label' => 'Physical weight',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'physical',
      'settings' => array(
        'default_unit' => 'g',
        'unit_select_list' => 1,
      ),
      'type' => 'physical_weight_textfield',
      'weight' => 15,
    ),
  );

  // Exported field_instance: 'commerce_product-product-field_retail_price'
  $field_instances['commerce_product-product-field_retail_price'] = array(
    'bundle' => 'product',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => FALSE,
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 8,
      ),
      'line_item' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'node_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'commerce_product',
    'field_name' => 'field_retail_price',
    'label' => 'Retail Price',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'commerce_price',
      'settings' => array(
        'currency_code' => 'default',
      ),
      'type' => 'commerce_price_simple',
      'weight' => 9,
    ),
  );

  // Exported field_instance:
  // 'commerce_product-product-field_retail_source_link'
  $field_instances['commerce_product-product-field_retail_source_link'] = array(
    'bundle' => 'product',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 9,
      ),
      'line_item' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
      'node_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'commerce_product',
    'field_name' => 'field_retail_source_link',
    'label' => 'Retail source link',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'commerce_product-product-field_sex'
  $field_instances['commerce_product-product-field_sex'] = array(
    'bundle' => 'product',
    'commerce_cart_settings' => array(
      'attribute_field' => 0,
      'attribute_widget' => 'select',
      'attribute_widget_title' => 'Sex',
    ),
    'default_value' => array(
      0 => array(
        'tid' => 32,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 2,
      ),
      'line_item' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
      'node_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'commerce_product',
    'field_name' => 'field_sex',
    'label' => 'Sex',
    'product_catalog' => 1,
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'commerce_product-product-field_tags'
  $field_instances['commerce_product-product-field_tags'] = array(
    'bundle' => 'product',
    'commerce_cart_settings' => array(
      'attribute_field' => 0,
      'attribute_widget' => 'select',
      'attribute_widget_title' => 'Tags',
    ),
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 5,
      ),
      'line_item' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 13,
      ),
      'node_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'commerce_product',
    'field_name' => 'field_tags',
    'label' => 'Tags',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'node-page-body'
  $field_instances['node-page-body'] = array(
    'bundle' => 'page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Body',
    'required' => FALSE,
    'settings' => array(
      'display_summary' => TRUE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => -4,
    ),
  );

  // Exported field_instance: 'node-product-field_product'
  $field_instances['node-product-field_product'] = array(
    'bundle' => 'product',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'commerce_cart',
        'settings' => array(
          'combine' => TRUE,
          'default_quantity' => 1,
          'line_item_type' => 'product',
          'show_quantity' => FALSE,
          'show_single_product_attributes' => FALSE,
        ),
        'type' => 'commerce_cart_add_to_cart_form',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_product',
    'label' => 'Product',
    'required' => 0,
    'settings' => array(
      'field_injection' => 1,
      'referenceable_types' => array(
        'product' => 'product',
        'product1' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'inline_entity_form',
      'settings' => array(
        'fields' => array(),
        'type_settings' => array(
          'allow_existing' => 0,
          'autogenerate_title' => 0,
          'delete_references' => 0,
          'label_plural' => 'products',
          'label_singular' => 'product',
          'match_operator' => 'CONTAINS',
          'override_labels' => 0,
        ),
      ),
      'type' => 'inline_entity_form_single',
      'weight' => 32,
    ),
  );

  // Exported field_instance: 'node-webform-body'
  $field_instances['node-webform-body'] = array(
    'bundle' => 'webform',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Body',
    'required' => 0,
    'settings' => array(
      'display_summary' => 0,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 32,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Address');
  t('Age');
  t('Body');
  t('Brand');
  t('Clothing type');
  t('Color');
  t('Description');
  t('Image');
  t('Inventory Date');
  t('Physical dimensions');
  t('Physical weight');
  t('Price');
  t('Product');
  t('Retail Price');
  t('Retail source link');
  t('Sex');
  t('Tags');

  return $field_instances;
}
