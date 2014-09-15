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
  
  <header>
    <div class="wrapper-thematique">
      <?php print render($content['field_thematique']); ?>
    </div>
    <?php print render($title_prefix); ?>
      <h1<?php print $title_attributes; ?>><?php print $title; ?></h1>
    <?php print render($title_suffix); ?>

    <?php if ($unpublished): ?>
      <mark class="unpublished"><?php print t('Unpublished'); ?></mark>
    <?php endif; ?>
  </header>

  <div class="wrapper-chroniques">
    <div class="wrapper-image">
      <?php print render($content['field_visuel']);?>
      <?php print render($content['field_chapo']);?>
    </div>

    <div class="wrapper-info">
      <div class="wrapper-print">
        <?php print render($content['print_links']);?>
      </div>
      <?php print render($content['field_date']);?>
      <div class="wrapper-left-padding">
        <?php print render($content['body']);?>
        <?php print render($content['field_auteur']);?>
        <div class="wrapper-collaborateurs clear">
          <p class="first">Cet article a été réalisé en collaboration avec</p>
          <?php print render($content['field_collaborateurs']);?>
        </div>
      </div>
    </div>
  </div>

  <?php print render($content['links']); ?>

  <?php print render($content['comments']); ?>

</article>
