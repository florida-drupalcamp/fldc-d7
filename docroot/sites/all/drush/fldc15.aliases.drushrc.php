<?php

// Vagrant
$aliases['vagrant'] = array(
  'uri' => 'fldc15.dev',
  'root' => '/home/vagrant/docroot',
  'remote-host' => 'fldc15.dev',
  'remote-user' => 'vagrant',
);

if (!isset($drush_major_version)) {
  $drush_version_components = explode('.', DRUSH_VERSION);
  $drush_major_version = $drush_version_components[0];
}
// Site fldrupalcamp, environment dev
$aliases['dev'] = array(
  'root' => '/var/www/html/fldrupalcamp.dev/docroot',
  'ac-site' => 'fldrupalcamp',
  'ac-env' => 'dev',
  'ac-realm' => 'prod',
  'uri' => 'fldrupalcampdev.prod.acquia-sites.com',
  'remote-host' => 'staging-11353.prod.hosting.acquia.com',
  'remote-user' => 'fldrupalcamp.dev',
  'path-aliases' => array(
    '%drush-script' => 'drush' . $drush_major_version,
  )
);
$aliases['dev.livedev'] = array(
  'parent' => '@fldrupalcamp.dev',
  'root' => '/mnt/gfs/fldrupalcamp.dev/livedev/docroot',
);
// Site fldrupalcamp, environment stage
$aliases['stage'] = array(
  'root' => '/var/www/html/fldrupalcamp.test/docroot',
  'ac-site' => 'fldrupalcamp',
  'ac-env' => 'test',
  'ac-realm' => 'prod',
  'uri' => 'fldrupalcampstg.prod.acquia-sites.com',
  'remote-host' => 'staging-5197.prod.hosting.acquia.com',
  'remote-user' => 'fldrupalcamp.test',
  'path-aliases' => array(
    '%drush-script' => 'drush' . $drush_major_version,
  )
);
$aliases['stage.livedev'] = array(
  'parent' => '@fldrupalcamp.test',
  'root' => '/mnt/gfs/fldrupalcamp.test/livedev/docroot',
);
// Site fldrupalcamp, environment prod
$aliases['prod'] = array(
  'root' => '/var/www/html/fldrupalcamp.prod/docroot',
  'ac-site' => 'fldrupalcamp',
  'ac-env' => 'prod',
  'ac-realm' => 'prod',
  'uri' => 'fldrupalcamp.prod.acquia-sites.com',
  'remote-host' => 'ded-5779.prod.hosting.acquia.com',
  'remote-user' => 'fldrupalcamp.prod',
  'path-aliases' => array(
    '%drush-script' => 'drush' . $drush_major_version,
  )
);
$aliases['prod.livedev'] = array(
  'parent' => '@fldrupalcamp.prod',
  'root' => '/mnt/gfs/fldrupalcamp.prod/livedev/docroot',
);
