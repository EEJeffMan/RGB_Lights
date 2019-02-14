/*
 * Name: RGB_Lights
 * Author: EEJeffMan
 * Date: 2/14/19
 * 
 * Description:
 *    Control 6 RGB LEDs.
 *    
 *    Currently using WS2812 RGB LEDs.
 *    
 *    RGB's use "FastLED" library, credit to tutorial in link below:
 *    https://howtomechatronics.com/tutorials/arduino/how-to-control-ws2812b-individually-addressable-leds-using-arduino/
 *     
 *    6 LEDs:
 *      Purple
 *      Blue
 *      Red
 *      Orange
 *      Green
 *      Yellow
 *    
 *    Yes, this is a pop-culture application, it's for my kids to enjoy :)
 *    
 *    MK I: LEDs illuminated all the time.
 *    
 *    MK II: Incorporate flex sensors to serve as on/off control of the lights.
 */

#include <FastLED.h>

#define NUM_LEDS      6
#define LED_PIN       2
#define COLOR_ORDER   GRB

// color table

/*
 * Values curtesy of https://www.rapidtables.com/web/color/RGB_Color.html
 */

 #define RED_R  255
 #define RED_G  0
 #define RED_B  0

 #define GREEN_R  0
 #define GREEN_G  255
 #define GREEN_B  0

 #define BLUE_R 0
 #define BLUE_G 0 
 #define BLUE_B 255

 #define YELLOW_R 255
 #define YELLOW_G 255
 #define YELLOW_B 0

 #define PURPLE_R  127
 #define PURPLE_G  0
 #define PURPLE_B  255

 #define ORANGE_R  255
 #define ORANGE_G  128
 #define ORANGE_B  0   

 // LED index (aka order of colors)
 #define PURPLE_LED   0
 #define BLUE_LED     1
 #define RED_LED      2
 #define ORANGE_LED   3
 #define GREEN_LED    4
 #define YELLOW_LED   5

CRGB leds[NUM_LEDS];

void setup() {

  Serial.begin(9600);
  
  // put your setup code here, to run once:
  FastLED.addLeds<WS2812, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);

  leds[PRUPLE_LED] = CRGB(PURPLE_R, PURPLE_G, PURPLE_B);
  leds[BLUE_LED] = CRGB(BLUE_R, BLUE_G, BLUE_B);
  leds[RED_LED] = CRGB(RED_R, RED_G, RED_B);
  leds[ORANGE_LED] = CRGB(ORANGE_R, ORANGE_G, ORANGE_B);
  leds[GREEN_LED] = CRGB(GREEN_R, GREEN_G, GREEN_B);
  leds[YELLOW_LED] = CRGB(YELLOW_R, YELLOW_G, YELLOW_B);

  FastLED.show();
}

void loop() {
  // put your main code here, to run repeatedly:
   
}
