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

  <?php print render($content['field_thematique']); ?>
  <?php if (isset($content['set_title']) && $content['set_title']): ?>
    <div class="node-type-title">
      <?php print $content['title_type']; ?>
    </div>
  <?php endif; ?>
  <?php if ($title_prefix || $title_suffix || !$page && $title): ?>
    <?php print render($title_prefix); ?>
    <?php if (!$page && $title): ?>
      <h2<?php print $title_attributes; ?>><a href="<?php print $base_url . $node_url; ?>"><?php print $title; ?></a></h2>
    <?php endif; ?>
    <?php print render($title_suffix); ?>
  <?php endif; ?>

</article>