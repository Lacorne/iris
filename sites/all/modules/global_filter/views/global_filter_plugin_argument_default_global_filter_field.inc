<?php
/**
 * @file
 * Contains the Global Filter default argument plugin (field).
 */

/**
 * Default argument plugin to extract the global filter value set for this
 * contextual filter.
 *
 * If the argument is a date or date range, it must be in this format:
 * YYYY-MM-DD--YYYY-MM-DD  Note the double hyphen.
 *
 * If the Contextual Range Filter modules is enabled, ranges may also be used
 * for numbers (integers, floats), lists, taxonomy terms, node and user ids...
 */
class global_filter_plugin_argument_default_global_filter_field extends views_plugin_argument_default {

  function get_argument() {
    $field_name = $views_field_name = $this->argument->field;
    // Where $views_field_name refers to a field it equals one of:
    // '<field_name>_value', '<field_name>_tid' or '<field_name>_fid'

    $exception_value = $this->argument->options['exception']['value']; // e.g. 'all'

    if (!($filter_key = global_filter_key_by_name($views_field_name))) {
      // Not found as a node property, maybe it's a field.
      if (empty($this->argument->definition['field_name'])) {
        return $exception_value;
      }
      $field_name = $this->argument->definition['field_name'];
      $filter_key = global_filter_key_by_name($field_name);
    }

    if ($filter_key) {
      $arg = global_filter_get_session_value($field_name);
      if (isset($arg) && $arg != '') {
        if (is_array($arg)) {
          // Removing empty entries may not be right when filter is numeric, i.e
          // a single digit 0 will be removed. However 00 will be interpreted
          // correctly as zero.
          $arg = array_filter($arg /* callback */);
          // For Hierarchical select: always use deepest term. For other fields
          // it doesn't matter
          $arg = array_reverse($arg);
          if (empty($arg)) {
            return $exception_value;
          }
        }
        if (is_string($arg)) {
          if ($field = field_info_field($field_name)) {
            // Handle taxonomy terms and list fields that were configured to
            // render as text fields. Convert the entered value back to a tid or
            // list key. Accept a string of values separated by plus signs.
            $args = explode('+', $arg);
            if ($field['type'] == 'taxonomy_term_reference') {
              $arg = array();
              $vocabulary = $field['settings']['allowed_values'][0]['vocabulary'];
              foreach ($args as $value) {
                $arg[] = global_filter_get_tid($value, $vocabulary);
              }
            }
            elseif (strpos($field['type'], 'list_') === 0) {
              $arg = array();
              foreach ($args as $value) {
                $arg[] = global_filter_get_field_value_key($field, $value);
              }
            }
          }
        }
      }
      else {
        $arg = $exception_value;
      }
      // If the argument is multi-valued (combo-box, checkboxes or text field
      // with '+') string the values together separated by plus-signs.
      // Note this requires the user to tick "Allow multiple values" after
      // expanding the "More" fieldset on the Contextual Filter configuration
      // panel. Otherwise only the first of the values will be used.
      // Note:
      // Be careful with spaces: have seen "very cheap" interpreted as "cheap"
      return is_array($arg) ? implode('+', $arg) : $arg;
    }

    // No filter key, field or node property not found.
    $view_name = empty($this->view->human_name) ? $this->view->name : $this->view->human_name;
    drupal_set_message(t('The view %view specifies a global filter field, %name, as its default contextual filter. However there is no associated <strong>Global Filter block</strong> for %name. Please configure a global filter <a href="admin/structure/block">here</a> or remove this contextual filter from the view.', array(
      '%view' => $view_name, '%name' => $views_field_name)), 'warning', FALSE);
    return $exception_value;
  }

}
