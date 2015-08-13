<?php

/**
 * @file
 * easypost.admin.inc
 */

/**
 * Admin settings form.
 */
function easypost_admin_settings_form($form, &$form_state) {
  require_once DRUPAL_ROOT . '/includes/locale.inc';

  // Defaults.
  $states = FALSE;
  $country = isset($form_state['values']['easypost_country']) ? $form_state['values']['easypost_country'] : variable_get('easypost_country', '');

  $form['container'] = array(
    '#type' => 'fieldset',
    '#title' => t('Settings'),
  );
  $form['container']['easypost_test_apikey'] = array(
    '#type' => 'textfield',
    '#title' => t('EasyPost Test API Key'),
    '#description' => t('EasyPost test API key.'),
    '#default_value' => variable_get('easypost_test_apikey', ''),
  );
  $form['container']['easypost_live_apikey'] = array(
    '#type' => 'textfield',
    '#title' => t('EasyPost Live API Key'),
    '#description' => t('EasyPost live API key. Please note that API queries using your live key should only be done over SSL.'),
    '#default_value' => variable_get('easypost_live_apikey', ''),
  );
  $form['container']['easypost_apikey'] = array(
    '#type' => 'select',
    '#title' => t('API Mode'),
    '#options' => array(
      'test' => t('Test'),
      'live' => t('Live'),
    ),
    '#description' => t('Set the API mode to test & allow sandbox functionality.'),
    '#default_value' => variable_get('easypost_apikey', 'test'),
  );

  // Still no addressfield patch... Please see https://drupal.org/node/970048.
  $form['address'] = array(
    '#type' => 'fieldset',
    '#title' => t('From Address'),
    '#prefix' => '<div id="testat">',
    '#suffix' => '</div>',
  );
  $form['address']['easypost_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name/organization'),
    '#default_value' => variable_get('easypost_name', ''),
  ); 
  $form['address']['easypost_country'] = array(
    '#type' => 'select',
    '#title' => t('Country'),
    '#options' => _addressfield_country_options_list(),
    '#default_value' => variable_get('easypost_country', ''),
    '#attributes' => array('class' => array('country')),
    '#required' => TRUE,
    '#ajax' => array(
      'callback' => 'easypost_admin_settings_form_callback',
      'wrapper' => 'testat',
      'effect' => 'fade',
    ),
  );
  $form['address']['easypost_address_one'] = array(
    '#type' => 'textfield',
    '#title' => t('Address One'),
    '#default_value' => variable_get('easypost_address_one', ''),
  );  
  $form['address']['easypost_address_two'] = array(
    '#type' => 'textfield',
    '#title' => t('Address Two'),
    '#default_value' => variable_get('easypost_address_two', ''),
  );

  switch ($country) {
    case 'US':
      $states = array(
        '' => t('--'),
        'AL' => t('Alabama'),
        'AK' => t('Alaska'),
        'AZ' => t('Arizona'),
        'AR' => t('Arkansas'),
        'CA' => t('California'),
        'CO' => t('Colorado'),
        'CT' => t('Connecticut'),
        'DE' => t('Delaware'),
        'DC' => t('District Of Columbia'),
        'FL' => t('Florida'),
        'GA' => t('Georgia'),
        'HI' => t('Hawaii'),
        'ID' => t('Idaho'),
        'IL' => t('Illinois'),
        'IN' => t('Indiana'),
        'IA' => t('Iowa'),
        'KS' => t('Kansas'),
        'KY' => t('Kentucky'),
        'LA' => t('Louisiana'),
        'ME' => t('Maine'),
        'MD' => t('Maryland'),
        'MA' => t('Massachusetts'),
        'MI' => t('Michigan'),
        'MN' => t('Minnesota'),
        'MS' => t('Mississippi'),
        'MO' => t('Missouri'),
        'MT' => t('Montana'),
        'NE' => t('Nebraska'),
        'NV' => t('Nevada'),
        'NH' => t('New Hampshire'),
        'NJ' => t('New Jersey'),
        'NM' => t('New Mexico'),
        'NY' => t('New York'),
        'NC' => t('North Carolina'),
        'ND' => t('North Dakota'),
        'OH' => t('Ohio'),
        'OK' => t('Oklahoma'),
        'OR' => t('Oregon'),
        'PA' => t('Pennsylvania'),
        'RI' => t('Rhode Island'),
        'SC' => t('South Carolina'),
        'SD' => t('South Dakota'),
        'TN' => t('Tennessee'),
        'TX' => t('Texas'),
        'UT' => t('Utah'),
        'VT' => t('Vermont'),
        'VA' => t('Virginia'),
        'WA' => t('Washington'),
        'WV' => t('West Virginia'),
        'WI' => t('Wisconsin'),
        'WY' => t('Wyoming'),
        ' ' => t('--'),
        'AS' => t('American Samoa'),
        'FM' => t('Federated States of Micronesia'),
        'GU' => t('Guam'),
        'MH' => t('Marshall Islands'),
        'MP' => t('Northern Mariana Islands'),
        'PW' => t('Palau'),
        'PR' => t('Puerto Rico'),
        'VI' => t('Virgin Islands'),
      );
    break;
    case 'IT':
      $states = array(
        ''   => t('--'),
        'AG' => 'Agrigento',
        'AL' => 'Alessandria',
        'AN' => 'Ancona',
        'AO' => 'Valle d\'Aosta/Vallée d\'Aoste',
        'AP' => 'Ascoli Piceno',
        'AQ' => 'L\'Aquila',
        'AR' => 'Arezzo',
        'AT' => 'Asti',
        'AV' => 'Avellino',
        'BA' => 'Bari',
        'BG' => 'Bergamo',
        'BI' => 'Biella',
        'BL' => 'Belluno',
        'BN' => 'Benevento',
        'BO' => 'Bologna',
        'BR' => 'Brindisi',
        'BS' => 'Brescia',
        'BT' => 'Barletta-Andria-Trani',
        'BZ' => 'Bolzano/Bozen',
        'CA' => 'Cagliari',
        'CB' => 'Campobasso',
        'CE' => 'Caserta',
        'CH' => 'Chieti',
        'CI' => 'Carbonia-Iglesias',
        'CL' => 'Caltanissetta',
        'CN' => 'Cuneo',
        'CO' => 'Como',
        'CR' => 'Cremona',
        'CS' => 'Cosenza',
        'CT' => 'Catania',
        'CZ' => 'Catanzaro',
        'EN' => 'Enna',
        'FC' => 'Forlì-Cesena',
        'FE' => 'Ferrara',
        'FG' => 'Foggia',
        'FI' => 'Firenze',
        'FM' => 'Fermo',
        'FR' => 'Frosinone',
        'GE' => 'Genova',
        'GO' => 'Gorizia',
        'GR' => 'Grosseto',
        'IM' => 'Imperia',
        'IS' => 'Isernia',
        'KR' => 'Crotone',
        'LC' => 'Lecco',
        'LE' => 'Lecce',
        'LI' => 'Livorno',
        'LO' => 'Lodi',
        'LT' => 'Latina',
        'LU' => 'Lucca',
        'MB' => 'Monza e Brianza',
        'MC' => 'Macerata',
        'ME' => 'Messina',
        'MI' => 'Milano',
        'MN' => 'Mantova',
        'MO' => 'Modena',
        'MS' => 'Massa-Carrara',
        'MT' => 'Matera',
        'NA' => 'Napoli',
        'NO' => 'Novara',
        'NU' => 'Nuoro',
        'OG' => 'Ogliastra',
        'OR' => 'Oristano',
        'OT' => 'Olbia-Tempio',
        'PA' => 'Palermo',
        'PC' => 'Piacenza',
        'PD' => 'Padova',
        'PE' => 'Pescara',
        'PG' => 'Perugia',
        'PI' => 'Pisa',
        'PN' => 'Pordenone',
        'PO' => 'Prato',
        'PR' => 'Parma',
        'PT' => 'Pistoia',
        'PU' => 'Pesaro e Urbino',
        'PV' => 'Pavia',
        'PZ' => 'Potenza',
        'RA' => 'Ravenna',
        'RC' => 'Reggio di Calabria',
        'RE' => 'Reggio nell\'Emilia',
        'RG' => 'Ragusa',
        'RI' => 'Rieti',
        'RM' => 'Roma',
        'RN' => 'Rimini',
        'RO' => 'Rovigo',
        'SA' => 'Salerno',
        'SI' => 'Siena',
        'SO' => 'Sondrio',
        'SP' => 'La Spezia',
        'SR' => 'Siracusa',
        'SS' => 'Sassari',
        'SV' => 'Savona',
        'TA' => 'Taranto',
        'TE' => 'Teramo',
        'TN' => 'Trento',
        'TO' => 'Torino',
        'TP' => 'Trapani',
        'TR' => 'Terni',
        'TS' => 'Trieste',
        'TV' => 'Treviso',
        'UD' => 'Udine',
        'VA' => 'Varese',
        'VB' => 'Verbano-Cusio-Ossola',
        'VC' => 'Vercelli',
        'VE' => 'Venezia',
        'VI' => 'Vicenza',
        'VR' => 'Verona',
        'VS' => 'Medio Campidano',
        'VT' => 'Viterbo',
        'VV' => 'Vibo Valentia',
      );
    break;
    case 'BR':
      $states = array(
         ''   => t('--'),
        'AC' => t('Acre'),
        'AL' => t('Alagoas'),
        'AM' => t('Amazonas'),
        'AP' => t('Amapa'),
        'BA' => t('Bahia'),
        'CE' => t('Ceara'),
        'DF' => t('Distrito Federal'),
        'ES' => t('Espirito Santo'),
        'GO' => t('Goias'),
        'MA' => t('Maranhao'),
        'MG' => t('Minas Gerais'),
        'MS' => t('Mato Grosso do Sul'),
        'MT' => t('Mato Grosso'),
        'PA' => t('Para'),
        'PB' => t('Paraiba'),
        'PE' => t('Pernambuco'),
        'PI' => t('Piaui'),
        'PR' => t('Parana'),
        'RJ' => t('Rio de Janeiro'),
        'RN' => t('Rio Grande do Norte'),
        'RO' => t('Rondonia'),
        'RR' => t('Roraima'),
        'RS' => t('Rio Grande do Sul'),
        'SC' => t('Santa Catarina'),
        'SE' => t('Sergipe'),
        'SP' => t('Sao Paulo'),
        'TO' => t('Tocantins'),
      );
    break;
    case 'CA':
      $states = array(
        ''   => t('--'),
        'AB' => t('Alberta'),
        'BC' => t('British Columbia'),
        'MB' => t('Manitoba'),
        'NB' => t('New Brunswick'),
        'NL' => t('Newfoundland'),
        'NT' => t('Northwest Territories'),
        'NS' => t('Nova Scotia'),
        'NU' => t('Nunavut'),
        'ON' => t('Ontario'),
        'PE' => t('Prince Edward Island'),
        'QC' => t('Quebec'),
        'SK' => t('Saskatchewan'),
        'YT' => t('Yukon Territory'),
      );
    break;
    case 'AU':
      $states = array(
         ''   => t('--'),
        'ACT' => t('Australian Capital Territory'),
        'NSW' => t('New South Wales'),
        'NT' => t('Northern Territory'),
        'QLD' => t('Queensland'),
        'SA' => t('South Australia'),
        'TAS' => t('Tasmania'),
        'VIC' => t('Victoria'),
        'WA' => t('Western Australia'),
      );
    break;
  }

  if (isset($country) && in_array($country, array('AR', 'AU', 'BR', 'BS', 'BY', 'BZ', 'CA', 'CN', 'DO', 'EG', 'ES', 'FJ', 'FM', 'GB', 'HN', 'ID', 'IE', 'IN', 'IT', 'JO', 'JP', 'KI', 'KN', 'KR', 'KW', 'KY', 'KZ', 'MX', 'MY', 'MZ', 'NG', 'NI', 'NR', 'NZ', 'OM', 'PA', 'PF', 'PG', 'PH', 'PR', 'PW', 'RU', 'SM', 'SO', 'SR', 'SV', 'TH', 'TW', 'UA', 'US', 'UY', 'VE', 'VI', 'VN', 'YU', 'ZA'))) {
   $form['address']['easypost_state'] = array(
      '#type' => $states ? 'select' : 'textfield',
      '#title' => t('State'),
      '#default_value' => variable_get('easypost_state', ''),
      '#attributes' => array('class' => array('state')),
      '#required' => TRUE,
    );

    if ($states) {
      $form['address']['easypost_state']['#options'] = $states;
    }
  }

  $form['address']['easypost_postalcode'] = array(
    '#type' => 'textfield',
    '#title' => t('Postal Code'),
    '#default_value' => variable_get('easypost_postalcode', ''),
    '#attributes' => array('class' => array('postal-code')),
    '#required' => TRUE,
  );

  if (isset($country) && in_array($country, array('AF', 'AG', 'AL', 'AO', 'BB', 'BI', 'BJ', 'BO', 'BS', 'BW', 'BZ', 'CF', 'CG', 'CM', 'CO', 'DJ', 'DM', 'EG', 'ER', 'FJ', 'GD', 'GH', 'GM', 'GQ', 'GY', 'IE', 'KI', 'KM', 'KP', 'KY', 'LC', 'LY', 'ML', 'MR', 'NA', 'NR', 'RW', 'SB', 'SC', 'SL', 'SR', 'ST', 'TD', 'TG', 'TL', 'TO', 'TT', 'TV', 'TZ', 'UG', 'VC', 'VU', 'WS', 'ZW'))) {
    unset($form['address']['easypost_postalcode']);
  }

  $form['address']['easypost_locality'] = array(
    '#type' => 'textfield',
    '#title' => t('Locality'),
    '#default_value' => variable_get('easypost_locality', ''),
    '#attributes' => array('class' => array('locality')),
    '#required' => TRUE,
  );
  
  $form['address']['easypost_phone'] = array(
    '#type' => 'textfield',
    '#title' => t('Phone number'),
    '#default_value' => variable_get('easypost_phone', ''),
  );

  return system_settings_form($form);
}

/**
 * Form callback
 */
function easypost_admin_settings_form_callback($form, $form_state) {  
  return $form['address'];
}
