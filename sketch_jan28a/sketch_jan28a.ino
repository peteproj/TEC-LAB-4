#include <DHT.h>
#include <Grove_Temperature_And_Humidity_Sensor.h>
#include <U8x8lib.h>

U8X8_SSD1306_128X64_ALT0_HW_I2C u8x8(/* reset=*/ 
U8X8_PIN_NONE);
DHT dht(3, DHT11); //Humididty sensor pin 3

void setup() {
  // put your setup code here, to run once:
  u8x8.begin();
  u8x8.setFlipMode(1);
  u8x8.clear();
  dht.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  double temp = dht.readTemperature(); //reads temp
  double humidity = dht.readHumidity(); //reads humidity levels
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  u8x8.setCursor(0, 0);
  u8x8.println("Hello World!");
  u8x8.print("temp: ");
  u8x8.print(temp);
  u8x8.println(" F");
  u8x8.print("humidity: ");
  u8x8.print(humidity);
  u8x8.println("%");

}
