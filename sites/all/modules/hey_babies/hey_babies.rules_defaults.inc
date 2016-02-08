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
  $items['commerce_ss_canceling_an_order_send_an_email_to_the_user'] = entity_import('rules_config', '{ "commerce_ss_canceling_an_order_send_an_email_to_the_user" : {
      "LABEL" : "Canceling an order, send an email to the user",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "mimemail", "entity" ],
      "ON" : { "commerce_order_update" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "commerce-order:status" ], "value" : "canceled" } },
        { "data_is" : {
            "data" : [ "commerce-order-unchanged:status" ],
            "op" : "IN",
            "value" : { "value" : {
                "pending" : "pending",
                "processing" : "processing",
                "completed" : "completed"
              }
            }
          }
        }
      ],
      "DO" : [
        { "mimemail" : {
            "key" : "order-cancelled",
            "to" : [ "commerce-order:mail" ],
            "subject" : "Order Cancelled",
            "body" : "Your order #[commerce-order:order-number] was cancelled. A refund is being processed.",
            "plaintext" : "Your order #[commerce-order:order-number] was cancelled. A refund is being processed.",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['commerce_ssr_stock_validate_checkout_out_of_stock_'] = entity_import('rules_config', '{ "commerce_ssr_stock_validate_checkout_out_of_stock_" : {
      "LABEL" : "Stock: validate checkout (out of stock)",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "-1",
      "OWNER" : "rules",
      "REQUIRES" : [ "commerce_ss", "rules", "commerce_stock" ],
      "ON" : { "commerce_stock_check_product_checkout" : [] },
      "IF" : [
        { "commerce_ss_stock_enabled_on_product" : { "commerce_product" : [ "commerce_product" ] } },
        { "commerce_ss_stock_not_disabled" : { "commerce_product" : [ "commerce_product" ] } },
        { "data_is" : { "data" : [ "commerce-product:commerce-stock" ], "value" : "0" } }
      ],
      "DO" : [
        { "commerce_stock_checkout_state" : {
            "stock_action" : "1",
            "message" : "The item [commerce-product:title] is out of stock.",
            "approved_quantity" : [ "commerce-product:commerce-stock" ]
          }
        }
      ]
    }
  }');
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
  $items['rules_redirect_after_customer_profile_save_delete'] = entity_import('rules_config', '{ "rules_redirect_after_customer_profile_save_delete" : {
      "LABEL" : "Redirect after customer profile save\\/delete",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "entity" ],
      "ON" : { "commerce_customer_profile_delete" : [] },
      "IF" : [
        { "entity_is_of_type" : {
            "entity" : [ "commerce-customer-profile" ],
            "type" : "commerce_customer_profile"
          }
        }
      ],
      "DO" : [ { "redirect" : { "url" : "user\\/me\\/edit" } } ]
    }
  }');
  $items['rules_redirect_to_edit_profile_after_login'] = entity_import('rules_config', '{ "rules_redirect_to_edit_profile_after_login" : {
      "LABEL" : "Redirect to edit profile after login",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_login" : [] },
      "DO" : [ { "redirect" : { "url" : "user\\/me\\/edit", "force" : "0" } } ]
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
