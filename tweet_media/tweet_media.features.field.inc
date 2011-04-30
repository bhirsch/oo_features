<?php
/**
 * @file
 * tweet_media.features.field.inc
 */

/**
 * Implementation of hook_field_default_fields().
 */
function tweet_media_field_default_fields() {
  $fields = array();

  // Exported field: 'node-tweet-field_media_url'
  $fields['node-tweet-field_media_url'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_media_url',
      'foreign keys' => array(),
      'indexes' => array(
        'height' => array(
          0 => 'height',
        ),
        'width' => array(
          0 => 'width',
        ),
      ),
      'module' => 'video_filter_field',
      'settings' => array(),
      'translatable' => '1',
      'type' => 'video_filter',
    ),
    'field_instance' => array(
      'bundle' => 'tweet',
      'default_value' => array(
        0 => array(
          'autoplay' => 0,
          'height' => '400',
          'url' => '',
          'width' => '400',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'video_filter_field',
          'settings' => array(),
          'type' => 'video_filter_field_default',
          'weight' => '5',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_media_url',
      'label' => 'Media URL',
      'required' => 0,
      'settings' => array(
        'autoplay' => 0,
        'max_height' => 400,
        'max_width' => 400,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'video_filter_field',
        'settings' => array(),
        'type' => 'video_filter',
        'weight' => '4',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Media URL');

  return $fields;
}
