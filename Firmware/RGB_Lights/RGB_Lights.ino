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
 *    6 LEDs, indexed in this order:
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
 #define PURPLE_LED   0b00000001
 #define BLUE_LED     0b00000010
 #define RED_LED      0b00000100
 #define ORANGE_LED   0b00001000
 #define GREEN_LED    0b00010000
 #define YELLOW_LED   0b00100000

 void set_leds(unsigned int led_configuration);

CRGB leds[NUM_LEDS];

const unsigned int red[6] = {PURPLE_R,BLUE_R,RED_R,ORANGE_R,GREEN_R,YELLOW_R};
const unsigned int green[6] = {PURPLE_G,BLUE_G,RED_G,ORANGE_G,GREEN_G,YELLOW_G};
const unsigned int blue[6] = {PURPLE_B,BLUE_B,RED_B,ORANGE_B,GREEN_B,YELLOW_B};

void setup() {

  Serial.begin(9600);
  
  // put your setup code here, to run once:
  FastLED.addLeds<WS2812, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);

  set_leds(PURPLE_LED | BLUE_LED | RED_LED | ORANGE_LED | GREEN_LED | YELLOW_LED);

  FastLED.show();
}

void loop() {
  // put your main code here, to run repeatedly:

  // TODO: MK II... read analog inputs and use set_leds() function to set outputs accordingly.
}

void set_leds(unsigned int led_configuration)
{
  /* loop through bitmask to check if each LED should be on.
   * if it should be on, set the appropriate RGB values. 
   * if it shouldnt be on, set the RGB values to 0.
   * 
   * bitmask order follows that of the LED RGB const arrays.
   */

  unsigned int i;
  unsigned int temp_mask;

  temp_mask = PURPLE_LED;
  for (i = 0; i<=5; i++)
  {
    if (led_configuration & temp_mask)
    {
      leds[i] = CRGB(red[i], green[i], blue[i]);
    }
    else
    {
      leds[i] = CRGB(0,0,0);
    }
    temp_mask = temp_mask << 1;   //next bitmask.
  }
}

//end of file.
