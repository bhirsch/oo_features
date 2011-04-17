<?php
/**
 * @file
 * twitter_tweet.features.inc
 */

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
