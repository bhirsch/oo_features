<?php
/**
 * @file video_nominee.theme.inc 
 */

/**
 * Implements hook_theme().
 */
function video_nominee_theme($existing, $type, $theme, $path) {
  return array(
    'node__video_nominee' => array(
      'render element' => 'elements',
      'path' => drupal_get_path('module', 'video_nominee') ."/theme",
      'template' => 'node--video-nominee',
    ),
  );
}


/**
 * Implements hook_preprocess_node().
 */
function video_nominee_preprocess_node(&$vars) {
  if (!empty($vars['nid']) && $vars['type'] == 'video_nominee') {
    $nid = $vars['nid'];
    // Find the Twitter Tag that is the video nominee's name.
    // Load Twitter Tags. 
    // Note: These are automatically loaded if links are 
    // included in display mode. But if they are turned off, they disappear.
    // Better to query this here to allow the flexibility.
    $results = db_query("SELECT field_twitter_tags_tid as tid "
                      . "FROM {field_data_field_twitter_tags} "
                      . "WHERE entity_id = :nid ", array(':nid' => $nid));
    $results = $results->fetchAllAssoc('tid');
    $tag_types = array();

// SECOND MONGODB VIDEO IS RE-SAVING TITLE AS 'HASHTAG' BECAUSE IT'S AN INVALID VIDEO NAME. HANDLE THAT.
// THIS SHOULD PROBABLY JUST LOOK FOR TERMS WITH SAME NAME AS TITLE. LESS FRAGILE THAT WAY.

    foreach ($results as $row) {
      $tag = taxonomy_term_load($row->tid);
      $tag_types = twitter_tweet_get_tag_types($tag);
      if (in_array('video name', $tag_types)) {
        $path = "taxonomy/term/$tag->tid";
        $vars['video_name_url'] = drupal_get_path_alias($path);
      }
    }
    
    // Replace the node title with a link to the taxonomy term page.
  }
/*
  // Only display Twitter Tags for video categories this 
  // video has been nominated for. Filter out any other Twitter tags.
  $vars['content']['field_twitter_tags']['#title'] = t('Nominated for categories: ');
  $twitter_tags = $vars['content']['field_twitter_tags'];
  foreach ($twitter_tags as $delta => $tag) {
    // Skip the render array elements. We only want the arrays of taxonomy terms.
    if (is_numeric($delta)) {

      // Categories are Twitter hashtags. Filter out anything that doesn't 
      // begin with # (e.g. mentions, which begin with @).
      if (substr($tag['#title'], 0, 1) != '#') {
        unset($vars['content']['field_twitter_tags'][$delta]);
      } 

      // Not all hashtags are categories. For example, video name tags are 
      // hashtags. Check tag types and unset anything that's not a 
      // 'video category'.
      else {
        $tids = array();
        // Assume each Twitter Tag is not a video category until we prove otherwise.
        $is_category = FALSE; 
        // Twitter Tag Types are taxonomy terms too. 
        $types = $vars['field_twitter_tags'][$delta]['taxonomy_term']->field_twitter_tag_types['und'];
        foreach ($types as $type) {
          $tids[] = $type['tid'];
        }
        $terms = taxonomy_term_load_multiple($tids);
        foreach ($terms as $term) {
          if ($term->name == 'video category') {
            $is_category == TRUE;  
          }
        }
        if (!$is_category) {
          unset($vars['content']['field_twitter_tags'][$delta]);
        }
      }

    }
  }
//*/
}
