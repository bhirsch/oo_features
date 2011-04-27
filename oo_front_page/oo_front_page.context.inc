<?php
/**
 * @file
 * oo_front_page.context.inc
 */

/**
 * Implementation of hook_context_default_contexts().
 */
function oo_front_page_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'recent-tweets_front-page';
  $context->description = 'Recent Tweets';
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
        'views-tweets-block' => array(
          'module' => 'views',
          'delta' => 'tweets-block',
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
  t('Recent Tweets');
  $export['recent-tweets_front-page'] = $context;

  return $export;
}
