<?php
/**
 * @file
 * envol_config.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function envol_config_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "bean_admin_ui" && $api == "bean") {
    return array("version" => "5");
  }
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function envol_config_image_default_styles() {
  $styles = array();

  // Exported image style: 232.
  $styles['232'] = array(
    'name' => '232',
    'label' => '232',
    'effects' => array(
      1 => array(
        'label' => 'Échelle',
        'help' => 'La mise à l\'échelle maintiendra les proportions originales de l\'image. Si une seule dimension est précisée, l\'autre dimension sera calculée automatiquement.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 232,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 484.
  $styles['484'] = array(
    'name' => '484',
    'label' => '484',
    'effects' => array(
      1 => array(
        'label' => 'Échelle',
        'help' => 'La mise à l\'échelle maintiendra les proportions originales de l\'image. Si une seule dimension est précisée, l\'autre dimension sera calculée automatiquement.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 484,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: 75x95.
  $styles['75x95'] = array(
    'name' => '75x95',
    'label' => '75x95',
    'effects' => array(
      1 => array(
        'label' => 'Mise à l’échelle et recadrage',
        'help' => 'La mise à l\'échelle et le recadrage maintiendront les proportions originales de l\'image puis recadreront la dimension la plus large. C\'est très utile pour créer des vignettes carrées sans étirer les images.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 75,
          'height' => 95,
        ),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: 232x270.
  $styles['232x270'] = array(
    'name' => '232x270',
    'label' => '232x270',
    'effects' => array(
      1 => array(
        'label' => 'Mise à l’échelle et recadrage',
        'help' => 'La mise à l\'échelle et le recadrage maintiendront les proportions originales de l\'image puis recadreront la dimension la plus large. C\'est très utile pour créer des vignettes carrées sans étirer les images.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 232,
          'height' => 270,
        ),
        'weight' => 4,
      ),
    ),
  );

  // Exported image style: 315x210.
  $styles['315x210'] = array(
    'name' => '315x210',
    'label' => '315x210',
    'effects' => array(
      4 => array(
        'label' => 'Mise à l’échelle et recadrage',
        'help' => 'La mise à l\'échelle et le recadrage maintiendront les proportions originales de l\'image puis recadreront la dimension la plus large. C\'est très utile pour créer des vignettes carrées sans étirer les images.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 315,
          'height' => 210,
        ),
        'weight' => 5,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function envol_config_node_info() {
  $items = array(
    'agenda' => array(
      'name' => t('Agenda'),
      'base' => 'node_content',
      'description' => t('Gestion des contenus de type Agenda'),
      'has_title' => '1',
      'title_label' => t('Titre'),
      'help' => '',
    ),
    'analyse' => array(
      'name' => t('Analyse'),
      'base' => 'node_content',
      'description' => t('Gestion des contenus de type Analyse'),
      'has_title' => '1',
      'title_label' => t('Titre'),
      'help' => '',
    ),
    'article' => array(
      'name' => t('Article'),
      'base' => 'node_content',
      'description' => t('Utilisez les <em>articles</em> pour des contenus possédant une temporalité tels que des actualités, des communiqués de presse ou des billets de blog.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'chroniques' => array(
      'name' => t('Chroniques'),
      'base' => 'node_content',
      'description' => t('Gestion des contenus de type Chroniques'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'ensemble' => array(
      'name' => t('Ensemble'),
      'base' => 'node_content',
      'description' => t('Gestion des contenus de type Ensemble'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'focus' => array(
      'name' => t('Focus'),
      'base' => 'node_content',
      'description' => t('Gestion des contenus de type Focus'),
      'has_title' => '1',
      'title_label' => t('Titre'),
      'help' => '',
    ),
    'invite' => array(
      'name' => t('Invité'),
      'base' => 'node_content',
      'description' => t('Gestion des contenus de type Invité'),
      'has_title' => '1',
      'title_label' => t('Titre'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Page de base'),
      'base' => 'node_content',
      'description' => t('Utilisez les <em>pages de base</em> pour votre contenu statique, tel que la page \'Qui sommes-nous\'.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'regards_exterieurs' => array(
      'name' => t('Regards extérieurs'),
      'base' => 'node_content',
      'description' => t('Gestion des contenus de type Regards extérieurs'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'story' => array(
      'name' => t('Actualité'),
      'base' => 'node_content',
      'description' => t('Pour poster de l\'actualité sur la page d\'accueil d\'envol.onera'),
      'has_title' => '1',
      'title_label' => t('Titre'),
      'help' => '',
    ),
    'temoignage' => array(
      'name' => t('Témoignage'),
      'base' => 'node_content',
      'description' => t('Gestion des contenus de type Témoignage'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'une_journee_avec' => array(
      'name' => t('Une journée avec'),
      'base' => 'node_content',
      'description' => t('Gestion des contenus de type Une journée avec'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
