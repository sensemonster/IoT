#include <Adafruit_SSD1306.h>

#include <DHT.h>
#define DHTPIN D4     // DHT 11 connected to this pin
#define DHTTYPE DHT11   // DHT 11
 
#define OLED_RESET 0  // GPIO0
Adafruit_SSD1306 display(OLED_RESET);

DHT dht11(DHTPIN, DHTTYPE);
 
void setup() 
{
  dht11.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  delay(2000);
}
 
void loop() {
  // Temperature/Humidit reading takes approximately 250 milliseconds
  // Sensor reading latency potentially 2 seconds on DHT 11 type sensors
  float relativeH = dht11.readHumidity();
  relativeH = relativeH + 34;  // Apply my local correction factor for this reading
  delay(2000);
  float temperatureC = dht11.readTemperature(); // Celcius reading as the default

  temperatureC = (temperatureC - 2.5); // Apply my local correction factor for this reading
  
  /* 
   *  A true param returns Fahrenheit
   *  This reading not utilised to ensure conversion using Celcius value obtained from single reading
   */
  // float TemperatureF = dht11.readTemperature(true); 

  float TemperatureF = (temperatureC * 9/5) + 32 ; // My Celcius to Fahrenheit conversion
 
  // Any sensor read errors stop further action
//  if (isnan(relativeH) || isnan(temperatureC) || isnan(TemperatureF)) {
  if (isnan(relativeH) || isnan(temperatureC))  {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(32, 8);
    display.println("DHT error");
    return;
  }
 
  // Heat index readings are unused here
  // float heatIndexF = dht11.computeHeatIndex(TemperatureF, relativeH);
  // a false parameter returs index in Celcius
  // float heatIndexF = dht11.computeHeatIndex(temperatureC, relativeH, false);
 
  display.setCursor(32, 8);
  display.clearDisplay();
  display.print(temperatureC);
  display.println(" C");
  display.setCursor(32, 17);
  display.print(TemperatureF);
  display.println(" F");
  display.setCursor(32, 25);
  display.print(relativeH);
  display.println("% rH");
  display.display();
  delay(6000);
}
