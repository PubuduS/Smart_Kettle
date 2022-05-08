<?php
require __DIR__ . '/vendor/autoload.php';
use Twilio\Rest\Client;
echo "Insiode PHP File";

// Your Account SID and Auth Token from twilio.com/console
$account_sid = 'AC2bea65263ff5d93f8acab46c41114578';
$auth_token = 'a8e2c8f8fd183b5be9824e658fcf808d';
// In production, these should be environment variables. E.g.:
// $auth_token = $_ENV["TWILIO_AUTH_TOKEN"]

// A Twilio number you own with SMS capabilities
$twilio_number = "+14025435588";

$client = new Client($account_sid, $auth_token);
$client->messages->create(
    // Where to send a text message (your cell phone?)
    '+16055926443',
    array(
        'from' => $twilio_number,
        'body' => 'First working test Message! Yay :)'
    )
);
?>
