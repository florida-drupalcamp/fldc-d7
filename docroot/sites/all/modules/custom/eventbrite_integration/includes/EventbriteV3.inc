<?php

define('EVENTBRITE_V3_BASE_URL', 'https://www.eventbriteapi.com/v3/');

class EventbriteV3 extends stdClass {

  protected $api_key;
  protected $user_key;
  protected $oauth_token;

  /**
   * Creates a EventbriteV3.
   */
  public function __construct() {
    $this->api_key = variable_get('eventbrite_app_key', '');
    $this->user_key = variable_get('eventbrite_user_key', '');
    $this->oauth_token = variable_get('eventbrite_oauth_token');
  }

  /**
   * @param array $endpoint
   *   An array of path components.
   *
   * @param string $method
   *   The HTTP method to use.
   *
   * @param array $data
   *   An array of data to send, for example, with a POST request.
   *
   * @return stdClass
   *   Object containing requested information, or an object containing
   *   information about any errors that may have occurred.
   */
  protected function call_api(array $endpoint, $method = 'GET', $data = array()) {
    $endpoint = implode('/', $endpoint);
    $options = array(
      'method' => $method,
      'headers' => array(
        'Authorization' => 'Bearer ' . $this->oauth_token,
      ),
      'data' => implode('&', $data),
    );
    $result = drupal_http_request('https://www.eventbriteapi.com/v3/' . $endpoint, $options);
    return json_decode($result->data);
  }

  /**
   * Gets the list of custom questions for an event.
   *
   * @param int $id
   *   The Eventbrite event's ID.
   *
   * @return stdClass
   *   Object containing information about the custom questions.
   */
  public function get_event_questions($id) {
    $endpoint = array(
      'events',
      $id,
      'questions',
    );
    return $this->call_api($endpoint);
  }

  /**
   * Gets the list of attendees for an event.
   *
   * @param int $id
   *   The Eventbrite event's ID.
   *
   * @return stdClass
   *   Object containing information about the attendees.
   */
  public function get_event_attendees($id) {
    $endpoint = array(
      'events',
      $id,
      'attendees',
    );
    return $this->call_api($endpoint);
  }

}
