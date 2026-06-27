#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

HardwareSerial mySerial(PA10, PA9);

void showTextDemo() {
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(10, 0);
    display.println("STM32");
    display.setTextSize(1);
    display.setCursor(0, 24);
    display.println("OLED SSD1306 Demo");
    display.setCursor(0, 40);
    display.println("I2C @ 0x3C");
    display.setCursor(0, 52);
    display.println("Blue Pill - Exp 08");
    display.display();
    delay(3000);
}

void showCounterDemo() {
    for (int i = 0; i <= 10; i++) {
        display.clearDisplay();
        display.setTextSize(1);
        display.setCursor(0, 0);
        display.println("Counter Demo:");
        display.setTextSize(3);
        display.setCursor(40, 24);
        display.println(i);
        display.display();
        delay(500);
    }
}

void showProgressBar() {
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.println("Progress Bar:");
    
    for (int i = 0; i <= 128; i += 4) {
        // clear only the dynamic area
        display.fillRect(0, 20, 128, 44, SSD1306_BLACK);
        
        // progress bar
        display.fillRect(0, 20, i, 16, SSD1306_WHITE);
        
        // percentage in big text below bar
        display.setTextSize(2);
        display.setTextColor(SSD1306_WHITE);
        display.setCursor(40, 42);
        int percent = map(i, 0, 128, 0, 100);
        display.print(percent);
        display.print("%");
        
        display.display();
        delay(50);
    }
    delay(1000);
}
void setup() {
    mySerial.begin(9600);

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        mySerial.println("OLED init failed!");
        while (true);
    }

    mySerial.println("OLED Demo starting!");
}

void loop() {
    showTextDemo();
    showCounterDemo();
    showProgressBar();
}