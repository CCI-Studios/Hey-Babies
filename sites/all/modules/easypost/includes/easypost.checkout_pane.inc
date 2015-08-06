<?php

/**
 * @file
 * easypost.checkout_pane.inc
 *
 * @todo, Implement a pane settings form & replace
 * the easypost.admin.inc logic.
 */

/**
 * Prepare rates.
 *
 * @todo, Implement proper caching & call this logic earlier.
 */
function easypost_query_rates($profile_id, $order) {
  // Return shipping address.
  $addresses = _easypost_return_addresses($profile_id);

  // Return parcel objects.
  $parcels = _easypost_parcel_params($order);
  foreach ($parcels as $parcel) {
    $shipment_params = array(
      'from_address' => $addresses['from_address'],
      'to_address' => $addresses['to_address'],
      'parcel' => $parcel,
    );

    $shipment = \EasyPost\Shipment::create($shipment_params);
    $rates = $shipment->get_rates();

    foreach ($rates->rates as $rate) {
      $services[$rate['service']] = array(
        'carrier' => $rate['carrier'],
        'service' => $rate['service'],
        'rate' => $rate['rate'],
        'est_delivery_days' => $rate['est_delivery_days'],
      );
    }
  }

  return $services;
}

/**
 * Implements base_checkout_form()
 */
function easypost_pane_checkout_form($form, &$form_state, $checkout_pane, $order) {
  // API key status.
  $status = _easypost_return_status();

  if ($status) {
    $amount = 0;

    // Default message.
    $details = t('No shipping service has been selected.');
    
    if (empty($order->commerce_customer_shipping))
    {
        return;
    }
    
    $services = easypost_query_rates($order->commerce_customer_shipping['und'][0]['profile_id'], $order);
    if (isset($form_state['values']['checkout_easypost']) && isset($form_state['values']['checkout_easypost']['rates']['shipment'])) {
      $select = $form_state['values']['checkout_easypost']['rates']['shipment'];

      // Shipping rate.
      $amount = $services[$select]['rate'];
      $form_state['values']['commerce_shipping']['shipping_rates']['easypost_shipping_service']->commerce_unit_price['und'][0]['amount'] = $services[$select]['rate'];

      // @todo, Implement own theme function for cleaner display.
      $item_list_vars = array(
        'type' => 'ul',
        'items' => array(
          'carrier' => array(
            'data' => '<span class="label">Carrier: </span>' . $services[$select]['carrier'],
          ),
          'service' => array(
            'data' => '<span class="label">Service: </span>' . $services[$select]['service'],
          ),
          'rate' => array(
            'data' => '<span class="label">Rate: </span>' . commerce_currency_format($amount, 'USD', NULL, FALSE),
          ),
          'est_delivery_days' => array(
            'data' => '<span class="label">Estimated Delivery: </span>' . $services[$select]['service']['est_delivery_days'],
          ),
        ),
        'title' => theme('image', array(
          'path' => url('sites/all/modules/easypost/images/' . $services[$select]['carrier'] . '.png'),
        )),
        'attributes' => array(
          'class' => array('shipping-info'),
        ),
      );

      $details = theme('item_list', $item_list_vars);
    }

    $pane_form['rates'] = array(
      '#type' => 'fieldset',
      '#title' => t('Shipping rates'),
    );
    
    // Option list.
    foreach ($services as $key => $service) {
      $rate_options[$key] = $service['carrier'] . ' ' . $key;
    }

    $pane_form['rates']['shipment'] = array(
      '#type' => 'radios',
      '#title' => t('Shipping Options'),
      '#options' => $rate_options,
      '#executes_submit_callback' => FALSE,
      '#ajax' => array(
        'callback' => 'easypost_pane_checkout_form_callback',
        'wrapper' => 'shipment-details-ajax-wrapper',
      ),
    );
    $pane_form['rates']['amount'] = array(
      '#type' => 'hidden',
      '#value' => $amount,
    );

    $pane_form['rates_info'] = array(
      '#type' => 'fieldset',
      '#title' => t('Shipping information'),
    );
    $pane_form['rates_info']['details'] = array(
      '#type' => 'markup',
      '#markup' => $details,
      '#prefix' => '<div id="shipment-details-ajax-wrapper">',
      '#suffix' => '</div>',
    );
  }

  return $pane_form;
}

/**
 * Shipping option form callback.
 */
function easypost_pane_checkout_form_callback($form, $form_state) {
  $rate = $form_state['values']['commerce_shipping']['shipping_rates']['easypost_shipping_service']->commerce_unit_price['und'][0]['amount'];

  // Update price display.
  $form['commerce_shipping']['shipping_service']['easypost_shipping_service']['#title'] = 'Shipping: ' . commerce_currency_format($rate, 'USD', NULL, FALSE);

  return array(
    '#type' => 'ajax',
    '#commands' => array(
      ajax_command_replace('#shipment-details-ajax-wrapper', render($form['checkout_easypost']['rates_info']['details'])),
      ajax_command_replace('#commerce-shipping-ajax-wrapper', render($form['commerce_shipping']['shipping_service']))
    )
  );
}

/**
 * Implements base_checkout_form_submit()
 */
function easypost_pane_checkout_form_submit($form, &$form_state, $checkout_pane, $order) {
  // Sync shipping amount...
  // @todo, complete me.
  $amount = $form_state['values']['checkout_easypost']['rates']['amount'];
}
