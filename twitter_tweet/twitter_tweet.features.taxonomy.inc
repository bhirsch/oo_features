<?php
/**
 * @file
 * twitter_tweet.features.taxonomy.inc
 */

/**
 * Implementation of hook_taxonomy_default_vocabularies().
 */
function twitter_tweet_taxonomy_default_vocabularies() {
  return array(
    'twitter_author' => array(
      'name' => 'Twitter Author',
      'machine_name' => 'twitter_author',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'twitter_hashtags' => array(
      'name' => 'Twitter Hashtags',
      'machine_name' => 'twitter_hashtags',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'twitter_users' => array(
      'name' => 'Referenced Twitter Users',
      'machine_name' => 'twitter_users',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
