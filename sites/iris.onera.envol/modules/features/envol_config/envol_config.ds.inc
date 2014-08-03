<?php
/**
 * @file
 * envol_config.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function envol_config_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'block_node';
  $ds_view_mode->label = 'Block Node';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['block_node'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'teaser_big_img';
  $ds_view_mode->label = 'teaser big img';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['teaser_big_img'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'teaser_small_img';
  $ds_view_mode->label = 'teaser small img';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['teaser_small_img'] = $ds_view_mode;

  return $export;
}
