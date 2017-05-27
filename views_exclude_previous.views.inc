<?php

/**
 * @file
 * Views functions for views exclude previous.
 */

/**
 * Implements hook_views_data_alter().
 */
function views_exclude_previous_views_data_alter(&$data) {
  $data['node']['views_exclude_previous'] = [
    'group' => t('Content'),
    'title' => t('Views Exclude Previous'),
    'help' => t('Excludes nodes that have already been loaded/viewed in the current page.'),
    'filter' => ['id' => 'views_exclude_previous'],
  ];
}

/**
 * Implements hook_views_post_execute().
 */
function views_exclude_previous_views_post_execute($view) {
  if ($view->base_table === 'node') {
    foreach ($view->result as $result) {
      if (!empty($result->nid)) {
        _views_exclude_previous('views', $result->nid);
      }
    }
  }
}
