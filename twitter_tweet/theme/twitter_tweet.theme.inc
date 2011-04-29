<?php
/**
 * @file twitter_tweet.theme.inc
 *  Theme Twitter tweets.
 */

/**
 * Implements hook_field_formatter_info().
 */
function twitter_tweet_field_formatter_info() { 
  return array(
    'twitter_tweet' => array(
      'label' => t('Tweet'),
      'field types' => array('text'),
    ),
  );
} 

/**
 * Implements hook_field_formatter_view().
 */
function twitter_tweet_field_formatter_view($obj_type, $object, $field, 
                                           $instance, $langcode, $items, 
                                           $display) { 
  $node = $object; 
//dsm($node);

  $elements = array();
  foreach ($items as $delta => $item) {
    $tweet = $item['safe_value'];

    // Replace Twitter mentions and hashtags with hyperlinks.
    if ($twitter_terms = twitter_tweet_get_terms($node->field_twitter_tags)) {
      $terms = _twitter_tweet_prepare_replace($twitter_terms);
    } 

    $find = (isset($terms['find'])) ? $terms['find'] : array();
    $replace = (isset($terms['replace'])) ? $terms['replace'] : array();

    $elements[$delta] = array(
      '#theme' => 'twitter_tweet_formatter',
      '#tweet' => $tweet,
      '#find' => $find,
      '#replace' => $replace,
    );
  }

  return $elements;
}

/**
 * Implements hook_theme().
 */
function twitter_tweet_theme($existing, $type, $theme, $path) {
  return array(
    'twitter_tweet_formatter' => array(
      'variables' => array('tweet' => NULL, 'find' => array(), 'replace' => array()),
    ),
    /*
    // @todo Figure out why this isn't working.
    'taxonomy_term__twitter_tags' => array(
      'render element' => 'elements',
      'template' => 'taxonomy-term--twitter-tags.tpl.php',
      //'override preprocess functions' => TRUE,
      //'preprocess functions' => 'twitter_tweet_test',
    ),
    // */
  );
}
/*
// @todo Figure out why none of these functions are being called.
function template_preprocess_taxonomy_term__twitter_tags($elements) {
  dsm($elements, 'elements');  
}
function video_nominee_preprocess_taxonomy_term__twitter_tags($elements) {
  dsm($elements, 'elements');  
}
function twitter_tweet_test($elements) {
 dsm('test preprocess works');  
}
function twitter_tweet_theme_registry_alter(&$theme_registry) {
  dsm($theme_registry, 'theme_registry');  
}
// */

/**
 * Returns HTML for tweet.
 */
function theme_twitter_tweet_formatter($vars) {
  $tweet = $vars['tweet'];
  $find = $vars['find']; 
  $replace = $vars['replace']; 

  // Convert hyperlinks to links.
  $tweet = check_markup($tweet);
  // Now replace hashtags and mentions with links to taxonomy terms.
  $output = str_replace($find, $replace, $tweet);

  return $output;
}

/**
 * Input a taxonomy field and return an array of taxonomy terms keyed by term name.
 * 
 * @params $terms_field
 *  array, $node->taxonomy_terms_field_name
 * 
 * @return $taxonomy_terms
 *  array('term name' => $term_object);
 */
function twitter_tweet_get_terms($terms_field) {
  $taxonomy_terms = array();

  foreach ($terms_field as $terms) {
   foreach ($terms as $term) {
     if (isset($term['taxonomy_term'])) {
       $taxonomy_term = $term['taxonomy_term'];
     } 
     else {
       $taxonomy_term = taxonomy_term_load($term['tid']);
     }
     if (!empty($taxonomy_term)) {
       $taxonomy_terms[$taxonomy_term->name] = $taxonomy_term;  
     }
   }
  }
  if (empty($taxonomy_terms)) {
    $taxonomy_terms = FALSE; 
  }

  return $taxonomy_terms;
}

/**
 * @param $terms
 *  Array of taxonomy term objects keyed by term name.
 * 
 * @return $items
 *  array, $items['find'] = array('find this', 'then this', 'next this');
 *  array, $items['replace'] = array('replace with this', 'then this', 'next this');
 *
 * @todo Give end users an admin setting to determine the replace path. Use it here.
 *  fall back on $term->uri['path'] as a default, if nothing else is provided.
 * @todo Call a hook here to let modules modify the replace path.
 */
function _twitter_tweet_prepare_replace($terms) {
  $items = array();
  foreach ($terms as $term) {
    // @todo Figure out why sometimes term objects don't have $term->uri.
    if (!property_exists($term, 'uri')) {
      $term->uri['path'] = "taxonomy/term/$term->tid";  
    }
    $items['find'][] = $term->name;
    $items['replace'][] = l($term->name, $term->uri['path']);
  }

  return $items; 
}
