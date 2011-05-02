<?php
/**
 * @file
 * twitter_tweet.strongarm.inc
 */

/**
 * Implementation of hook_strongarm().
 */
function twitter_tweet_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_tweet';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_tweet'] = $strongarm;

  return $export;
}
