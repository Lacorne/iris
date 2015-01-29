<?php
/**
 * @file
 * Contains Links display on header site
 */
?>
<div class="wrapper-header-links">
  <ul>
    <li class="link-normal"><?php print l('onera.fr', 'http://www.onera.fr'); ?></li>
    <li class="link-normal gonera"><?php print l('<span>Google</span> Onera', 'http://googlemini.onera', array('attributes'=> array('target'=>'_blank'), 'html'=>TRUE)); ?></li>
  </ul>
</div>
