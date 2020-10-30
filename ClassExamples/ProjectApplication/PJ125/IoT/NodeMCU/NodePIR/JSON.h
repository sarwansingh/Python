void jsonPOST(String content) {
  WiFiClient client;

  if (client.connect("192.168.4.30", 80)) {
      Serial.println("Connected to server");
  // Make the HTTP request
      client.println("POST /iot/testjs.php HTTP/1.1");
      client.println("Host: 192.168.4.30");
      client.println("Accept: */*");
      client.println("Content-Length: " + String(content.length()));
      client.println("Content-Type: application/json");
      client.println();
      client.println(content);
 
      Serial.println(content);
  }
  delay(1000);
}
