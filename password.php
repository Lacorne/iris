<?php

define('DRUPAL_ROOT', getcwd());
require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

require_once 'includes/password.inc';
echo user_hash_password('admin');

//Old: $S$DGZXykdxjMhrObX2pkt9Yi.2HOcTRrRRdi2fFO0VTMNi/fAAdnA5
//Mine: $S$DBqRO997UmGx2LHV/pu.kr7RBqKdSI/ayQ1ZNCVW5b9HWOl0SBTz

die();