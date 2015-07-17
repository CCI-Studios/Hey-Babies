<?php
/**
 * @file
 * hey_babies.features.inc
 */

/**
 * Implements hook_commerce_product_default_types().
 */
function hey_babies_commerce_product_default_types() {
  $items = array(
    'product' => array(
      'type' => 'product',
      'name' => 'Product',
      'description' => 'A basic product type.',
      'help' => '',
      'revision' => 1,
    ),
  );
  return $items;
}

/**
 * Implements hook_commerce_tax_default_rates().
 */
function hey_babies_commerce_tax_default_rates() {
  $items = array(
    'on_hst' => array(
      'name' => 'on_hst',
      'display_title' => 'HST',
      'description' => '',
      'rate' => 0.13,
      'type' => 'sales_tax',
      'rules_component' => 'commerce_tax_rate_on_hst',
      'default_rules_component' => 1,
      'price_component' => 'tax|on_hst',
      'calculation_callback' => 'commerce_tax_rate_calculate',
      'module' => 'commerce_tax_ui',
      'title' => 'ON HST',
      'admin_list' => TRUE,
    ),
  );
  return $items;
}

/**
 * Implements hook_commerce_tax_default_types().
 */
function hey_babies_commerce_tax_default_types() {
  $items = array(
    'sales_tax' => array(
      'name' => 'sales_tax',
      'display_title' => 'Sales tax',
      'description' => 'A basic type for taxes that do not display inclusive with product prices.',
      'display_inclusive' => 0,
      'round_mode' => 0,
      'rule' => 'commerce_tax_type_sales_tax',
      'module' => 'commerce_tax_ui',
      'title' => 'Sales tax',
      'admin_list' => TRUE,
    ),
    'vat' => array(
      'name' => 'vat',
      'display_title' => 'VAT',
      'description' => 'A basic type for taxes that display inclusive with product prices.',
      'display_inclusive' => 1,
      'round_mode' => 1,
      'rule' => 'commerce_tax_type_vat',
      'module' => 'commerce_tax_ui',
      'title' => 'VAT',
      'admin_list' => TRUE,
    ),
  );
  return $items;
}

/**
 * Implements hook_views_api().
 */
function hey_babies_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function hey_babies_image_default_styles() {
  $styles = array();

  // Exported image style: product_thumb.
  $styles['product_thumb'] = array(
    'label' => 'Product thumb',
    'effects' => array(
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 200,
          'height' => 200,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function hey_babies_node_info() {
  $items = array(
    'front_feature' => array(
      'name' => t('Front Feature'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'front_header' => array(
      'name' => t('Front Header'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'product' => array(
      'name' => t('Product'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'webform' => array(
      'name' => t('Webform'),
      'base' => 'node_content',
      'description' => t('Create a new form or questionnaire accessible to users. Submission results and statistics are recorded and accessible to privileged users.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
