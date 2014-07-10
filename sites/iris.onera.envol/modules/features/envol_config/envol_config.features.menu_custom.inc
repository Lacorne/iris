<?php
/**
 * @file
 * envol_config.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function envol_config_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-menu-haut.
  $menus['menu-menu-haut'] = array(
    'menu_name' => 'menu-menu-haut',
    'title' => 'Menu haut',
    'description' => 'Menu affiché dans le header',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Menu affiché dans le header');
  t('Menu haut');


  return $menus;
}
