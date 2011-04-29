<?php
/**
 * @file
 * ttt.features.taxonomy.inc
 */

/**
 * Implementation of hook_taxonomy_default_vocabularies().
 */
function ttt_taxonomy_default_vocabularies() {
  return array(
    'twitter_tag_types' => array(
      'name' => 'Twitter Tag Types',
      'machine_name' => 'twitter_tag_types',
      'description' => 'hashtag, mention, and other user-defined types of tags',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '-6',
    ),
  );
}
