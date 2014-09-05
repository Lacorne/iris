<?php
/**
 * @file
 * Contains Links display on header site
 */
?>
<div class="wrapper-header-links">
  <ul>
    <li class="link-normal"><?php print l('onera.fr', 'http://www.onera.fr'); ?></li>
    <li class="link-normal gonera"><?php print l('<span>Google</span> Onera', '<front>', array('attributes'=> array('target'=>'_blank'), 'html'=>TRUE)); ?></li>
    <li class="icone facebook"><?php print l('<span>Facebook</span>', 'http://www.facebook.fr/thefrenchaerospacelab', array('attributes'=> array('target'=>'_blank'), 'html'=>TRUE)); ?></li>
    <li class="icone twitter"><?php print l('<span>Twitter</span>', 'http://www.twitter.com/@onera_fr', array('attributes'=> array('target'=>'_blank'), 'html'=>TRUE)); ?></li>
    <li class="icone linkedin"><?php print l('<span>linkedIn</span>', 'http://www.linkedin.com/company/onera', array('attributes'=> array('target'=>'_blank'), 'html'=>TRUE)); ?></li>
  </ul>
</div>