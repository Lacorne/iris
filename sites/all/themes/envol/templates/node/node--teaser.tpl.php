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

  <a href="<?php print $node_url; ?>" class="left mr20"><?php print render($content['field_image_actu']); ?></a>
  <div class="wrapper-info">
    <?php print render($content['field_date']); ?>
    <?php print render($content['field_thematique']); ?>
    <?php if ($title_prefix || $title_suffix || !$page && $title): ?>
      <?php print render($title_prefix); ?>
      <?php if (!$page && $title): ?>
        <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
    <?php endif; ?>
    <?php print render($content['field_chapo']); ?>
    <a href="<?php print $node_url; ?>" class="readmore">Suite</a>
    <?php
      if(isset($content['links']['node']['#links']['node-readmore'])) {
        unset($content['links']['node']['#links']['node-readmore']);
      }
    ?>
    <?php print render($content['links']); ?>
  </div>

</article>
