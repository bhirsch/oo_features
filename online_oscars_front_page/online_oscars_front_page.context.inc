<?php
/**
 * @file
 * online_oscars_front_page.context.inc
 */

/**
 * Implementation of hook_context_default_contexts().
 */
function online_oscars_front_page_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'online_oscars_front_page';
  $context->description = '';
  $context->tag = 'Front Page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-recent_tweets-block' => array(
          'module' => 'views',
          'delta' => 'recent_tweets-block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Front Page');
  $export['online_oscars_front_page'] = $context;

  return $export;
}
