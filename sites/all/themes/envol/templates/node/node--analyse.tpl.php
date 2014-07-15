<?php
/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */
?>
<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  
  <?php if ($title_prefix || $title_suffix || $display_submitted || $unpublished || !$page && $title): ?>
    <header>
      <div class="wrapper-thematique">
        <?php print $content['field_thematique'][0]['#title']; ?>
      </div>
      <?php print render($title_prefix); ?>
        <h1<?php print $title_attributes; ?>><?php print $title; ?></h1>
      <?php print render($title_suffix); ?>

      <?php if ($unpublished): ?>
        <mark class="unpublished"><?php print t('Unpublished'); ?></mark>
      <?php endif; ?>
    </header>
  <?php endif; ?>

  <?php
    if (isset($content['experts'])) {
      $exp_elm = '';
      foreach ($content['experts'] as $key => $value) {
        $name_exp = $content['experts'][$key]['name'];
        $function_epx = $content['experts'][$key]['function'];
        $localisation_epx = $content['experts'][$key]['localisation'];
        $visuel_epx = file_create_url($content['experts'][$key]['visuel']);
        $exp_elm .= '<li>
                    <span class="visuel-exp"><img src="' . $visuel_epx . '" class="visuel-exp-thumbnail" /></span>
                    <div class="wrapper-info">
                      <span class="name-exp">' . $name_exp . '</span>
                      <span class="function-exp">' . $function_epx . '</span>
                      <span class="localisation-exp">' . $localisation_epx . '</span>
                    </div>
                   </li>';
      }
      $wrapper_expert = '<div class="wrapper-experts"><h2 class="title-encart">Paroles d\'experts</h2><ul>' . $exp_elm . '</ul></div>';

      $save_body = $content['body'][0]['#markup'];
      $new_body = explode('</p>', $save_body);
      $new_body['1'] = $wrapper_expert . $new_body['1'];
      $new_body = implode('</p>', $new_body);
      $content['body'][0]['#markup'] = $new_body;
    }

  ?>
  <?php //print render($content); ?>
  <div class="wrapper-image">
    <?php print render($content['field_visuel']);?>
    <?php print render($content['field_chapo']);?>
  </div>

  <div class="wrapper-info">
    <?php print render($content['field_date']);?>
    <?php print render($content['body']);?>
    <?php print render($content['field_auteur']);?>
  </div>

  <div class="wrapper-collaborateurs clear">
    <p class="first">Cet article a été réalisé en collaboration avec</p>
    <?php print render($content['field_collaborateurs']);?>
  </di>

  <?php print render($content['links']); ?>

  <?php print render($content['comments']); ?>

</article>
