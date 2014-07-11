<?php
/**
 * @file
 * envol_config.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function envol_config_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-menu-haut_analyse:analyse
  $menu_links['menu-menu-haut_analyse:analyse'] = array(
    'menu_name' => 'menu-menu-haut',
    'link_path' => 'analyse',
    'router_path' => 'analyse',
    'link_title' => 'Analyse',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-menu-haut_analyse:analyse',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-menu-haut_le-fil:lefil
  $menu_links['menu-menu-haut_le-fil:lefil'] = array(
    'menu_name' => 'menu-menu-haut',
    'link_path' => 'lefil',
    'router_path' => 'lefil',
    'link_title' => 'Le fil',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-menu-haut_le-fil:lefil',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Analyse');
  t('Le fil');


  return $menu_links;
}
