void jsonPOST(String content) {
  WiFiClient client;

  if (client.connect("sarwansingh.com", 80)) {
      Serial.println("Connected to server");
  // Make the HTTP request
      client.println("POST /iot/cht/rec.php HTTP/1.1");
      client.println("Host: arshbir.com");
      client.println("Accept: */*");
      client.println("Content-Length: " + String(content.length()));
      client.println("Content-Type: application/json");
      client.println();
      client.println(content);
 
      Serial.println(content);
  }
  delay(1000);
}
