<?php
/**
 * @file
 * twitter_search_feed.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function twitter_search_feed_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function twitter_search_feed_node_info() {
  $items = array(
    'twitter_search_feed' => array(
      'name' => t('Twitter Search Feed'),
      'base' => 'node_content',
      'description' => t('Generate Twitter search feeds here: http://search.twitter.com/.'),
      'has_title' => '1',
      'title_label' => t('Feed Name'),
      'help' => '',
    ),
  );
  return $items;
}
