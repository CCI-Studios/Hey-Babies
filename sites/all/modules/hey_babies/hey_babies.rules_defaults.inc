<?php
/**
 * @file
 * hey_babies.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function hey_babies_default_rules_configuration() {
  $items = array();
  $items['commerce_tax_rate_on_hst'] = entity_import('rules_config', '{ "commerce_tax_rate_on_hst" : {
      "LABEL" : "Calculate ON HST",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "Commerce Tax", "sales_tax" ],
      "REQUIRES" : [ "commerce_tax" ],
      "USES VARIABLES" : { "commerce_line_item" : { "type" : "commerce_line_item", "label" : "Line item" } },
      "DO" : [
        { "commerce_tax_rate_apply" : {
            "USING" : {
              "commerce_line_item" : [ "commerce-line-item" ],
              "tax_rate_name" : "on_hst"
            },
            "PROVIDE" : { "applied_tax" : { "applied_tax" : "Applied tax" } }
          }
        }
      ]
    }
  }');
  $items['rules_add_to_cart_redirect_to_cart'] = entity_import('rules_config', '{ "rules_add_to_cart_redirect_to_cart" : {
      "LABEL" : "Add to Cart Redirect to Cart",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "commerce" ],
      "REQUIRES" : [ "rules", "commerce_cart" ],
      "ON" : { "commerce_cart_product_add" : [] },
      "DO" : [ { "redirect" : { "url" : "cart" } } ]
    }
  }');
  $items['rules_validate_maximum_1_coupon'] = entity_import('rules_config', '{ "rules_validate_maximum_1_coupon" : {
      "LABEL" : "Validate maximum 1 coupon",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "commerce_coupon" ],
      "ON" : { "commerce_coupon_validate" : [] },
      "DO" : [
        { "commerce_coupon_action_remove_all_coupons_from_order" : { "commerce_order" : [ "commerce_order" ] } }
      ]
    }
  }');
  return $items;
}
