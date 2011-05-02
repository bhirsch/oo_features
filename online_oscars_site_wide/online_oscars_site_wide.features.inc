<?php
/**
 * @file
 * online_oscars_site_wide.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function online_oscars_site_wide_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
}
