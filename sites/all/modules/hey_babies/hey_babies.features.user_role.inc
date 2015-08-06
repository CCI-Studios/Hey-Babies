<?php
/**
 * @file
 * hey_babies.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function hey_babies_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  return $roles;
}
