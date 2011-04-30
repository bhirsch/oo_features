<?php
/**
 * @file ttt.index.inc
 *  Callbacks for ttt/index/% page.
 */
/**
 * Callback for ttt/index/% title.
 * 
 * @return
 *  Name of taxonomy term in arg(2).
 */
function ttt_index_title($tid) {
  $term = taxonomy_term_load($tid);
  $title = $term->name . ' ' . t('index');
  drupal_set_title($title);
}

/**
 * Callback for access to ttt/index/%.
 */
function ttt_index_page($tid) {
  $tag_type = taxonomy_term_load($tid);

  $results = db_query("SELECT tid, name "
                    . "FROM taxonomy_term_data "
                    . "JOIN field_data_field_twitter_tag_types ON tid = entity_id "
                    . "WHERE field_twitter_tag_types_tid = :tid", 
                    array(':tid' => $tid))
                      ->fetchAllAssoc('name');
  ksort($results);
  /*
  $results = db_select('taxonomy_term_data', 'ttd')
    ->fields('ttd')
    ->join('field_data_field_twitter_tag_types', 'fdfttt', 'ttd.tid = fdfttt.entity_id')
    ->condition('fdfttt.field_twitter_tag_types_tid', $tid)
    ->execute()
    ->fetchAssoc();
    // */

  $link = array();
  $items = array();
  foreach ($results as $row) {
    $tid = $row->tid;
    $name = $row->name;

    $link = array(
      '#theme' => 'link',
      '#text' => $name,
      '#path' => "taxonomy/term/$tid",
      '#options' => array(
        'attributes' => array(
          'class' => array('ttt', "ttt-$tag_type->name"), 
          'id' => "$name", 
          'alt' => "$tag_type->name: $name"
        ),
        'html' => FALSE,
      ),
    );

    $items[] = array(
      '#theme' => 'ttt_index_term',
      '#item' => array($link),
    );
  }
   
  return $items;
}

function theme_ttt_index_term($variables) {
  $output = '';

  // @todo I don't think it's right to call render from a theme function. But 
  //   I can't seem to get it to render the children before here... ?
  $link = render($variables);
  $output = '<div >' . $link . '</div>'; 

  return $output;
}
