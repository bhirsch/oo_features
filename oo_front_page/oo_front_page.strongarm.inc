<?php
/**
 * @file
 * oo_front_page.strongarm.inc
 */

/**
 * Implementation of hook_strongarm().
 */
function oo_front_page_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_frontpage';
  $strongarm->value = 'video-nominees';
  $export['site_frontpage'] = $strongarm;

  return $export;
}
