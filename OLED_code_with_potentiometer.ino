#include <Adafruit_GFX.h>  
#include <Adafruit_SSD1306.h> 
#include <Wire.h>

Adafruit_SSD1306 d(128, 64);  


int potentiometer;
int x;
void setup() {
  delay(100);  

  d.begin(SSD1306_SWITCHCAPVCC, 0x3C);  
 
  d.clearDisplay();  

  d.setTextColor(WHITE);  

  d.setRotation(0);  

  d.setTextWrap(false);  

  d.dim(0);  //Set brightness (0 is maximun and 1 is a little dim)

  

}

void loop() {
  
   potentiometer = analogRead(A0);
   x = map(potentiometer, 0, 1023, 0, 400);
 
  d.clearDisplay();  
  d.setTextSize(2);
  d.setCursor(84, 48);  
  d.println(x);
  d.setCursor(12, 16);  // (x,y)
  d.println("Spool(SPS)");  
  d.setTextSize(2);
  d.setCursor(10, 48);  
  d.println("SPS -");
  d.display();

    }
