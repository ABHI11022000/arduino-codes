#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "a994fb4184f440489a6d9e7d9762b7e1";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "MAK incotech";
char pass[] = "Password";

#define ledPIN 2          
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Serial.println(h);
  Blynk.virtualWrite(V5, h);
}

void setup()
{
  Serial.begin(9600); // See the connection status in Serial Monitor
  Blynk.begin(auth, ssid, pass);

}

void loop()
{
  Blynk.run(); // Initiates Blynk
}

