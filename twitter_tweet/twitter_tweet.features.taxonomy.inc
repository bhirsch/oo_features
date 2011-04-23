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
      'weight' => '-9',
    ),
    'twitter_tag_types' => array(
      'name' => 'Twitter Tag Types',
      'machine_name' => 'twitter_tag_types',
      'description' => 'hashtag, mention, and other user-defined types of tags',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '-6',
    ),
    'twitter_tags' => array(
      'name' => 'Twitter Tags',
      'machine_name' => 'twitter_tags',
      'description' => 'Twitter mentions and hashtags',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '-7',
    ),
  );
}
