<?php
/**
 * @file
 * video_nominee.features.inc
 */

/**
 * Implementation of hook_node_info().
 */
function video_nominee_node_info() {
  $items = array(
    'video_nominee' => array(
      'name' => t('Video Nominee'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
