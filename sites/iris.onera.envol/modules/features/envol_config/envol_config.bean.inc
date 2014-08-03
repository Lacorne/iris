<?php
/**
 * @file
 * envol_config.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function envol_config_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'fond_blanc';
  $bean_type->label = 'Fond Blanc';
  $bean_type->options = '';
  $bean_type->description = 'Block avec un fond blanc';
  $export['fond_blanc'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'fond_gris';
  $bean_type->label = 'Fond Gris';
  $bean_type->options = '';
  $bean_type->description = 'Block avec un fond gris';
  $export['fond_gris'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'fond_gris_filet';
  $bean_type->label = 'Fond Gris avec filet';
  $bean_type->options = '';
  $bean_type->description = 'Block avec un fond gris et un filet à gauche de la zone de texte';
  $export['fond_gris_filet'] = $bean_type;

  return $export;
}
