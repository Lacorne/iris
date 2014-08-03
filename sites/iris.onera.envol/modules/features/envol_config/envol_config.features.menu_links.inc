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

  // Exported menu link: menu-menu-haut_agenda:agenda
  $menu_links['menu-menu-haut_agenda:agenda'] = array(
    'menu_name' => 'menu-menu-haut',
    'link_path' => 'agenda',
    'router_path' => 'agenda',
    'link_title' => 'Agenda',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-menu-haut_agenda:agenda',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
  );
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
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-menu-haut_chroniques:chroniques
  $menu_links['menu-menu-haut_chroniques:chroniques'] = array(
    'menu_name' => 'menu-menu-haut',
    'link_path' => 'chroniques',
    'router_path' => 'chroniques',
    'link_title' => 'Chroniques',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-menu-haut_chroniques:chroniques',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
  );
  // Exported menu link: menu-menu-haut_ensemble:ensemble
  $menu_links['menu-menu-haut_ensemble:ensemble'] = array(
    'menu_name' => 'menu-menu-haut',
    'link_path' => 'ensemble',
    'router_path' => 'ensemble',
    'link_title' => 'Ensemble',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-menu-haut_ensemble:ensemble',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: menu-menu-haut_focus:focus
  $menu_links['menu-menu-haut_focus:focus'] = array(
    'menu_name' => 'menu-menu-haut',
    'link_path' => 'focus',
    'router_path' => 'focus',
    'link_title' => 'Focus',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-menu-haut_focus:focus',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
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
  // Exported menu link: menu-menu-haut_linvit:invite
  $menu_links['menu-menu-haut_linvit:invite'] = array(
    'menu_name' => 'menu-menu-haut',
    'link_path' => 'invite',
    'router_path' => 'invite',
    'link_title' => 'L\'invité',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-menu-haut_linvit:invite',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-menu-haut_une-journe-avec:une-journee-avec
  $menu_links['menu-menu-haut_une-journe-avec:une-journee-avec'] = array(
    'menu_name' => 'menu-menu-haut',
    'link_path' => 'une-journee-avec',
    'router_path' => 'une-journee-avec',
    'link_title' => 'Une journée avec',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-menu-haut_une-journe-avec:une-journee-avec',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Agenda');
  t('Analyse');
  t('Chroniques');
  t('Ensemble');
  t('Focus');
  t('L\'invité');
  t('Le fil');
  t('Une journée avec');


  return $menu_links;
}
