<?php
/**
 * @file
 * online_oscars_front_page.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
 */
function online_oscars_front_page_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'recent_tweets';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Recent Tweets';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'On Twitter';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Twitter Author */
  $handler->display->display_options['fields']['field_twitter_author']['id'] = 'field_twitter_author';
  $handler->display->display_options['fields']['field_twitter_author']['table'] = 'field_data_field_twitter_author';
  $handler->display->display_options['fields']['field_twitter_author']['field'] = 'field_twitter_author';
  $handler->display->display_options['fields']['field_twitter_author']['label'] = '';
  $handler->display->display_options['fields']['field_twitter_author']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_twitter_author']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_twitter_author']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_twitter_author']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_twitter_author']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_twitter_author']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_twitter_author']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_twitter_author']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_twitter_author']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_twitter_author']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_twitter_author']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_twitter_author']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_twitter_author']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_twitter_author']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_twitter_author']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_twitter_author']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_twitter_author']['click_sort_column'] = 'tid';
  $handler->display->display_options['fields']['field_twitter_author']['field_api_classes'] = 0;
  /* Field: Content: Original Tweet */
  $handler->display->display_options['fields']['field_tweet_original']['id'] = 'field_tweet_original';
  $handler->display->display_options['fields']['field_tweet_original']['table'] = 'field_data_field_tweet_original';
  $handler->display->display_options['fields']['field_tweet_original']['field'] = 'field_tweet_original';
  $handler->display->display_options['fields']['field_tweet_original']['label'] = '';
  $handler->display->display_options['fields']['field_tweet_original']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_tweet_original']['alter']['text'] = '[field_twitter_author]: [field_tweet_original]';
  $handler->display->display_options['fields']['field_tweet_original']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_tweet_original']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_tweet_original']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_tweet_original']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_tweet_original']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_tweet_original']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_tweet_original']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_tweet_original']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_tweet_original']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_tweet_original']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_tweet_original']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_tweet_original']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_tweet_original']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_tweet_original']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_tweet_original']['type'] = 'twitter_tweet';
  $handler->display->display_options['fields']['field_tweet_original']['field_api_classes'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'tweet' => 'tweet',
  );

  /* Display: Page: Recent Tweets w Media */
  $handler = $view->new_display('page', 'Page: Recent Tweets w Media', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Recent Video Nominees';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Media URL */
  $handler->display->display_options['fields']['field_media_url']['id'] = 'field_media_url';
  $handler->display->display_options['fields']['field_media_url']['table'] = 'field_data_field_media_url';
  $handler->display->display_options['fields']['field_media_url']['field'] = 'field_media_url';
  $handler->display->display_options['fields']['field_media_url']['label'] = '';
  $handler->display->display_options['fields']['field_media_url']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_media_url']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_media_url']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_media_url']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_media_url']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_media_url']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_media_url']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_media_url']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_media_url']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_media_url']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_media_url']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_media_url']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_media_url']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_media_url']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_media_url']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_media_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_media_url']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_media_url']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_media_url']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_media_url']['field_api_classes'] = 0;
  /* Field: Content: Twitter Author */
  $handler->display->display_options['fields']['field_twitter_author']['id'] = 'field_twitter_author';
  $handler->display->display_options['fields']['field_twitter_author']['table'] = 'field_data_field_twitter_author';
  $handler->display->display_options['fields']['field_twitter_author']['field'] = 'field_twitter_author';
  $handler->display->display_options['fields']['field_twitter_author']['label'] = '';
  $handler->display->display_options['fields']['field_twitter_author']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_twitter_author']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_twitter_author']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_twitter_author']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_twitter_author']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_twitter_author']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_twitter_author']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_twitter_author']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_twitter_author']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_twitter_author']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_twitter_author']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_twitter_author']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_twitter_author']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_twitter_author']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_twitter_author']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_twitter_author']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_twitter_author']['click_sort_column'] = 'tid';
  $handler->display->display_options['fields']['field_twitter_author']['field_api_classes'] = 0;
  /* Field: Content: Original Tweet */
  $handler->display->display_options['fields']['field_tweet_original']['id'] = 'field_tweet_original';
  $handler->display->display_options['fields']['field_tweet_original']['table'] = 'field_data_field_tweet_original';
  $handler->display->display_options['fields']['field_tweet_original']['field'] = 'field_tweet_original';
  $handler->display->display_options['fields']['field_tweet_original']['label'] = '';
  $handler->display->display_options['fields']['field_tweet_original']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_tweet_original']['alter']['text'] = '[field_twitter_author]: [field_tweet_original]';
  $handler->display->display_options['fields']['field_tweet_original']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_tweet_original']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_tweet_original']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_tweet_original']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_tweet_original']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_tweet_original']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_tweet_original']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_tweet_original']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_tweet_original']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_tweet_original']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_tweet_original']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_tweet_original']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_tweet_original']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_tweet_original']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_tweet_original']['type'] = 'twitter_tweet';
  $handler->display->display_options['fields']['field_tweet_original']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'tweet' => 'tweet',
  );
  /* Filter criterion: Fields: Media URL (field_media_url) - url */
  $handler->display->display_options['filters']['field_media_url_url']['id'] = 'field_media_url_url';
  $handler->display->display_options['filters']['field_media_url_url']['table'] = 'field_data_field_media_url';
  $handler->display->display_options['filters']['field_media_url_url']['field'] = 'field_media_url_url';
  $handler->display->display_options['filters']['field_media_url_url']['operator'] = 'longerthan';
  $handler->display->display_options['filters']['field_media_url_url']['value'] = '10';
  $handler->display->display_options['path'] = 'recent-tweets';

  /* Display: Block: Recent Tweets */
  $handler = $view->new_display('block', 'Block: Recent Tweets', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $translatables['recent_tweets'] = array(
    t('Master'),
    t('On Twitter'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('[field_twitter_author]: [field_tweet_original]'),
    t('Page: Recent Tweets w Media'),
    t('Recent Video Nominees'),
    t('Block: Recent Tweets'),
  );
  $export['recent_tweets'] = $view;

  return $export;
}
