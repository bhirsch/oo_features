<?php
/**
 * @file
 * twitter_tweet.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function twitter_tweet_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function twitter_tweet_node_info() {
  $items = array(
    'tweet' => array(
      'name' => t('Tweet'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Tweet'),
      'help' => '',
    ),
  );
  return $items;
}
