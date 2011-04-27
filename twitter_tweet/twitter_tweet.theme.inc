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

// @todo replace this with a propper field formatter.
function theme_field__field_tweet_original($elements) {
  if ($node = $elements['element']['#object']) {
    if ($node->type == 'tweet') {
      // Get original tweet, to be themed.
      foreach($node->field_tweet_original as $original_tweet) {
        $tweet = $original_tweet[0]['safe_value']; 
      }
      // Replace Twitter mentions and hashtags with hyperlinks.
      if ($twitter_terms = twitter_tweet_get_terms($node->field_twitter_tags)) {
        $items = _twitter_tweet_prepare_replace($twitter_terms);
        $tweet = str_replace($items['find'], $items['replace'], $tweet);
      } 

      return $tweet;
    }
  } 
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
    // @todo Figure out why mentions don't have $uri->tid.
    if (!property_exists($term, 'uri')) {
      $term->uri['path'] = "taxonomy/term/$term->tid";  
    }
    $items['find'][] = $term->name;
    $items['replace'][] = l($term->name, $term->uri['path']);
  }

  return $items; 
}
