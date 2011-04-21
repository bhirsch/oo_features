<?php
/**
 * @file twitter_tweet.theme.inc
 *  Theme Twitter tweets.
 */
/**
 * Implements hook_theme().
 */
function twitter_tweet_theme($existing, $type, $theme, $path) {
  return array(
    'field__field_tweet_original' => array(
      'render element' => 'elements',
    ),
  );
}
// */

/**
 * Implements hook_preprocess_field().
 */
/*
function twitter_tweet_preprocess_field(&$variables) {
  if ($variables['element']['#field_name'] == 'field_tweet_original') {
  //  dsm($variables, 'twitter_tweet_preprocess_field');
  }
}
// */

function theme_field__field_tweet_original($elements) {
  $node = $elements['element']['#object'];

  // Get original tweet, to be themed.
  foreach($node->field_tweet_original as $original_tweet) {
    $tweet = $original_tweet[0]['safe_value']; 
  }

  // Replace user names with hyperlinks.
  $twitter_user_terms = twitter_tweet_get_terms($node->field_twitter_users);
  $items = _twitter_tweet_prepare_replace($twitter_user_terms);
  $tweet = str_replace($items['find'], $items['replace'], $tweet);

  // Replace hashtags with hyperlinks.
  $twitter_hashtag_terms = twitter_tweet_get_terms($node->field_twitter_hashtags);
  $items = _twitter_tweet_prepare_replace($twitter_hashtag_terms);
  $tweet = str_replace($items['find'], $items['replace'], $tweet);
  
  return $tweet;
}

/**
 * Input a taxonomy field and return an array of taxonomy terms keyed by term name.
 * 
 * @params $term_groups
 *  array, $node->taxonomy_field_name
 * 
 * @return $taxonomy_terms
 *  array('term name' => $term_object);
 */
function twitter_tweet_get_terms($term_groups) {
  foreach ($term_groups as $terms) {
   foreach ($terms as $term) {
     $taxonomy_term = $term['taxonomy_term'];
     $taxonomy_terms[$taxonomy_term->name] = $taxonomy_term;  
   }
  }
  return $taxonomy_terms;
}

/**
 * @param $terms
 *  array of taxonomy term objects keyed by term name
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
    $items['find'][] = $term->name;
    $items['replace'][] = l($term->name, $term->uri['path']);
  }

  return $items; 
}
