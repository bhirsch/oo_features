<?php
/**
 * @file
 * oo_front_page.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
 */
function oo_front_page_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'tweets';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'tweets';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'On Twitter';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Field: Content: Original Tweet */
  $handler->display->display_options['fields']['field_tweet_original']['id'] = 'field_tweet_original';
  $handler->display->display_options['fields']['field_tweet_original']['table'] = 'field_data_field_tweet_original';
  $handler->display->display_options['fields']['field_tweet_original']['field'] = 'field_tweet_original';
  $handler->display->display_options['fields']['field_tweet_original']['label'] = '';
  $handler->display->display_options['fields']['field_tweet_original']['alter']['alter_text'] = 0;
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'tweets';

  /* Display: Block: Recent Tweets */
  $handler = $view->new_display('block', 'Block: Recent Tweets', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $translatables['tweets'] = array(
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
    t('Page'),
    t('Block: Recent Tweets'),
  );
  $export['tweets'] = $view;

  $view = new view;
  $view->name = 'video_nominees';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Video Nominees';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Video Nominees';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Video URL */
  $handler->display->display_options['fields']['field_video_url']['id'] = 'field_video_url';
  $handler->display->display_options['fields']['field_video_url']['table'] = 'field_data_field_video_url';
  $handler->display->display_options['fields']['field_video_url']['field'] = 'field_video_url';
  $handler->display->display_options['fields']['field_video_url']['label'] = '';
  $handler->display->display_options['fields']['field_video_url']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_video_url']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_video_url']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_video_url']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_video_url']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_video_url']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_video_url']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_video_url']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_video_url']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_video_url']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_video_url']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_video_url']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_video_url']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_video_url']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_video_url']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_video_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_video_url']['field_api_classes'] = 0;
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
    'video_nominee' => 'video_nominee',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'video-nominees';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Video Nominees';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $translatables['video_nominees'] = array(
    t('Master'),
    t('Video Nominees'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Page'),
  );
  $export['video_nominees'] = $view;

  return $export;
}
