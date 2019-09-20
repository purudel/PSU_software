/*
  * CS - to digital pin 10  (SS pin)
  * SDI - to digital pin 11 (MOSI pin)
  * CLK - to digital pin 13 (SCK pin)
*/
// include the SPI library:
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
static const unsigned char PROGMEM logo_bmp0[] =
{B00000000,B00000000,B00000000,B00000000,B00000000
,B00000000,B00001110,B00000000,B00000000,B00000000
,B00000000,B00111111,B10000000,B00000000,B00000000
,B00000000,B01111111,B11100000,B00000000,B00000000
,B00000000,B11111111,B11100000,B00000011,B11111000
,B00000000,B10000111,B11110011,B11111111,B11100000
,B00000000,B00000011,B11111111,B11111111,B11000000
,B00000000,B00000011,B11111111,B11110000,B00000000
,B00000000,B00000011,B11111111,B11110000,B00000000
,B00000000,B00000011,B11111111,B11110000,B00000000
,B00000000,B00001111,B11111111,B11100000,B00000000
,B00000000,B00011111,B11111000,B11100000,B00000000
,B00000000,B00010000,B10000000,B11100000,B00000000
,B00000000,B00010001,B10000001,B10000000,B00000000
,B00000000,B00010001,B00000011,B00000000,B00000000
,B00000000,B00011000,B01110010,B00000000,B00000000
,B00000000,B00001000,B00000100,B00000000,B00000000
,B00000000,B00000000,B00001000,B00000000,B00000000
  };
static const unsigned char PROGMEM logo_bmp1[] =
{B00000000,B00000000,B00000000,B00000000,B00000000
,B00000000,B00011110,B00000000,B00000000,B00000000
,B00000000,B00111111,B10000000,B00000000,B00000000
,B00000000,B01111111,B11000000,B00000000,B00000000
,B00000000,B11111111,B11100000,B00000001,B11000000
,B00000000,B10000111,B11111111,B11111111,B11111000
,B00000000,B00000111,B11111111,B11111111,B11100000
,B00000000,B00000011,B11111111,B11110000,B00000000
,B00000000,B00000111,B11111111,B11110000,B00000000
,B00000000,B00000011,B11111111,B11110000,B00000000
,B00000000,B00011111,B11111111,B11100000,B00000000
,B00000000,B00100111,B10000001,B11100000,B00000000
,B00000000,B00100110,B00000000,B11100000,B00000000
,B00000000,B00100100,B00000001,B11100000,B00000000
,B00000000,B00100010,B00000110,B00100000,B00000000
,B00000000,B00000001,B10001000,B00100000,B00000000
,B00000000,B00000000,B00001000,B01000000,B00000000
,B00000000,B00000000,B00000000,B01000000,B00000000
};
static const unsigned char PROGMEM logo_bmp2[] =
{B00000000,B00001000,B00000000,B00000000,B00000000
,B00000000,B00111110,B00000000,B00000000,B00000000
,B00000000,B01111111,B10000000,B00000000,B00000000
,B00000000,B11111111,B11000000,B00000000,B00000000
,B00000001,B11111111,B11100000,B00000000,B00000000
,B00000000,B00000111,B11111111,B11111111,B11111000
,B00000000,B00000011,B11111111,B11110111,B11110000
,B00000000,B00000111,B11111111,B11110000,B00000000
,B00000000,B00000111,B11111111,B11110000,B00000000
,B00000000,B00000111,B11111111,B11110000,B00000000
,B00000000,B00111111,B11111111,B11110000,B00000000
,B00000000,B00111100,B00000001,B11111000,B00000000
,B00000000,B01000000,B00000001,B10011100,B00000000
,B00000000,B10001000,B00000001,B00000100,B00000000
,B00000000,B10001000,B00000001,B00000100,B00000000
,B00000000,B00000100,B00000010,B00000100,B00000000
,B00000000,B00000000,B00000100,B00000100,B00000000
,B00000000,B00000000,B00001100,B00000100,B00000000

  };
  static const unsigned char PROGMEM logo_bmp3[] =
{B00000000,B00010000,B00000000,B00000000,B00000000
,B00000000,B00111100,B00000000,B00000000,B00000000
,B00000000,B01111111,B00000000,B00000000,B00000000
,B00000000,B11111111,B11000000,B00000000,B00000000
,B00000011,B11111111,B11100000,B00000000,B00000000
,B00000011,B00001111,B11111111,B11111111,B11111000
,B00000000,B00000111,B11111111,B11111111,B11110000
,B00000000,B00000111,B11111111,B11110001,B11000000
,B00000000,B00000111,B11111111,B11110000,B00000000
,B00000000,B00000111,B11111111,B11110000,B00000000
,B00000000,B00011111,B11111101,B11111000,B00000000
,B00000000,B00111100,B00000001,B11111100,B00000000
,B00000000,B00110000,B00000000,B11000110,B00000000
,B00000000,B00100000,B00000000,B01000010,B00000000
,B00000000,B01100000,B00000000,B01000001,B00000000
,B00000000,B11100000,B00000000,B01000001,B00000000
,B00000011,B00000000,B00000000,B10000000,B10000000
,B00000000,B00000000,B00000000,B10000000,B10000000

  };
  static const unsigned char PROGMEM logo_bmp4[] =
{B00000000,B00000000,B00000000,B00000000,B00000000
,B00000000,B00100000,B00000000,B00000000,B00000000
,B00000000,B11111110,B00000000,B00000000,B00000000
,B00000001,B11111111,B10000000,B00000000,B00000000
,B00000011,B11111111,B11000000,B00000000,B00000000
,B00000111,B00011111,B11111111,B11100110,B00000000
,B00000000,B00001111,B11111111,B11111111,B11011000
,B00000000,B00000111,B11111111,B11110011,B11110000
,B00000000,B00000111,B11111111,B11111000,B00000000
,B00000000,B00000111,B11111111,B11111000,B00000000
,B00000000,B00001111,B11111100,B11111100,B00000000
,B00000000,B00111110,B00000000,B01111111,B00000000
,B00000000,B01001100,B00000000,B00110001,B10000000
,B00000000,B00001000,B00000000,B00011000,B10000000
,B00000000,B10010000,B00000000,B00001000,B01000000
,B00000000,B10010000,B00000000,B00001000,B00010000
,B00000000,B00100000,B00000000,B00001100,B00000000
,B00000000,B01100000,B00000000,B00000000,B00000000

  };
  static const unsigned char PROGMEM logo_bmp5[] =
{B00000000,B00000000,B00000000,B00000000,B00000000
,B00000000,B00000000,B00000000,B00000000,B00000000
,B00000000,B11111100,B00000000,B00000000,B00000000
,B00000001,B11111111,B10000000,B00000000,B00000000
,B00000011,B11111111,B10000000,B00000000,B00000000
,B00000111,B10111111,B11111111,B11101111,B00000000
,B00000000,B00001111,B11111111,B11111111,B11100000
,B00000000,B00001111,B11111111,B11110011,B11100000
,B00000000,B00001111,B11111111,B11111000,B00000000
,B00000000,B00001111,B11111111,B11111100,B00000000
,B00000000,B00001111,B11111111,B11111111,B00000000
,B00000000,B00011111,B00000000,B00111001,B10000000
,B00000000,B00110010,B00000000,B00001100,B11000000
,B00000000,B01100010,B00000000,B00000000,B01100000
,B00000000,B01000010,B00000000,B00000010,B00010000
,B00000000,B10000010,B00000000,B00000010,B00000000
,B00000011,B00000000,B00000000,B00000010,B00000000
,B00000000,B00000000,B00000000,B00000001,B00000000

  };
  static const unsigned char PROGMEM logo_bmp6[] =
{B00000000,B00000000,B00000000,B00000000,B00000000
,B00000000,B00000000,B00000000,B00000000,B00000000
,B00000000,B11110000,B00000000,B00000000,B00000000
,B00000011,B11111110,B00000000,B00000000,B00000000
,B00000111,B11111111,B10000001,B00000100,B00000000
,B00001111,B11111111,B11111111,B11111111,B10000000
,B00000000,B00011111,B11111111,B11100111,B11110000
,B00000000,B00001111,B11111111,B11110000,B10000000
,B00000000,B00001111,B11111111,B11110000,B00000000
,B00000000,B00001111,B11111111,B11111110,B00000000
,B00000000,B00001111,B11111000,B01111110,B00000000
,B00000000,B00001101,B10000000,B00011111,B00000000
,B00000000,B00001001,B10000000,B00000011,B00000000
,B00000000,B00010000,B10000000,B00000001,B10000000
,B00000000,B00010000,B10000000,B00000001,B00000000
,B00000000,B00100000,B10000000,B00000000,B10000000
,B00000000,B01000000,B01000000,B00000000,B10000000
,B00000000,B11000000,B01000000,B00000000,B00000000
  };
  static const unsigned char PROGMEM logo_bmp7[] =
{B00000000,B00000000,B00000000,B00000000,B00000000
,B00000000,B00000000,B00000000,B00000000,B00000000
,B00000011,B11111000,B00000000,B00000000,B00000000
,B00000111,B11111100,B00000000,B00000000,B00000000
,B00001111,B11111111,B00000111,B10111111,B00000000
,B00011100,B01111111,B11111111,B11011111,B11000000
,B00000000,B00111111,B11111111,B11000011,B11110000
,B00000000,B00011111,B11111111,B11100000,B00000000
,B00000000,B00001111,B11111111,B11111000,B00000000
,B00000000,B00001111,B11111111,B11111100,B00000000
,B00000000,B00001111,B11110000,B01111100,B00000000
,B00000000,B00001111,B11000000,B00000110,B00000000
,B00000000,B00001100,B11000000,B00000010,B00000000
,B00000000,B00001100,B01100000,B00000011,B00000000
,B00000000,B00001000,B00100000,B00000010,B10000000
,B00000000,B00001000,B00010000,B00000000,B00000000
,B00000000,B00001000,B00010000,B00000000,B00000000
,B00000000,B00001000,B00001100,B00000000,B00000000

  };
  static const unsigned char PROGMEM logo_bmp8[] =
{B00000000,B00000000,B00000000,B00000000,B00000000
,B00000000,B11000000,B00000000,B00000000,B00000000
,B00000011,B11110000,B00000000,B00000000,B00000000
,B00000111,B11111100,B00000000,B00111100,B00000000
,B00011111,B11111111,B00001111,B11111111,B10000000
,B00011000,B01111111,B11111111,B11001111,B11100000
,B00000000,B00111111,B11111111,B11000000,B00000000
,B00000000,B00011111,B11111111,B11000000,B00000000
,B00000000,B00011111,B11111111,B11110000,B00000000
,B00000000,B00011111,B11111101,B11111000,B00000000
,B00000000,B00001111,B11110000,B00101000,B00000000
,B00000000,B00000111,B10000000,B00011000,B00000000
,B00000000,B00000111,B10000000,B00000100,B00000000
,B00000000,B00000010,B10000000,B00010110,B00000000
,B00000000,B00000010,B01000000,B00000010,B00000000
,B00000000,B00000010,B00011000,B00000000,B00000000
,B00000000,B00000001,B00000000,B00000000,B00000000
,B00000000,B00000001,B00000000,B00000000,B00000000
  };
  static const unsigned char PROGMEM logo_bmp9[] =
{B00000000,B00000000,B00000000,B00000000,B0000000
,B00000000,B11110000,B00000000,B00000000,B00000000
,B00000001,B11111000,B00000000,B00000000,B00000000
,B00000111,B11111100,B00000001,B00111111,B00000000
,B00001111,B11111111,B00000111,B11111111,B11100000
,B00000000,B00111111,B11111111,B11100011,B11000000
,B00000000,B00011111,B11111111,B11100000,B00000000
,B00000000,B00011111,B11111111,B11000000,B00000000
,B00000000,B00001111,B11111111,B11100000,B00000000
,B00000000,B00001111,B11111101,B11111000,B00000000
,B00000000,B00001111,B11110000,B01100000,B00000000
,B00000000,B00000111,B11000000,B01000000,B00000000
,B00000000,B00000001,B10000000,B01001000,B00000000
,B00000000,B00000001,B11000000,B01001000,B00000000
,B00000000,B00000001,B11000000,B01001000,B00000000
,B00000000,B00000000,B00111000,B00000000,B00000000
,B00000000,B00000000,B00010000,B00000000,B00000000
,B00000000,B00000000,B00010000,B00000000,B00000000

  };
  static const unsigned char PROGMEM logo_bmp10[] =
{B00000000,B00000000,B00000000,B00000000,B00000000
,B00000001,B11110000,B00000000,B00000000,B00000000
,B00000011,B11111000,B00000000,B00000000,B00000000
,B00000111,B11111100,B00000000,B00111110,B00000000
,B00001110,B11111110,B00001111,B11111111,B11000000
,B00000000,B00111111,B11111111,B11001011,B10100000
,B00000000,B00111111,B11111111,B11000000,B00000000
,B00000000,B00011111,B11111111,B11000000,B00000000
,B00000000,B00011111,B11111111,B10000000,B00000000
,B00000000,B00011111,B11111111,B11100000,B00000000
,B00000000,B00001111,B11100001,B11100000,B00000000
,B00000000,B00001111,B10000001,B01000000,B00000000
,B00000000,B00001111,B00000001,B01000000,B00000000
,B00000000,B00001001,B00000010,B01000000,B00000000
,B00000000,B00001101,B00000100,B01000000,B00000000
,B00000000,B00000011,B10000100,B01000000,B00000000
,B00000000,B00000000,B00110000,B00000000,B00000000
,B00000000,B00000000,B00010000,B00000000,B00000000
  };

  static const unsigned char PROGMEM logo_bmp11[] =
{B00000000,B00000000,B00000000,B00000000,B00000000
,B00000001,B11100000,B00000000,B00000000,B00000000
,B00000011,B11111000,B00000000,B00000000,B00000000
,B00000111,B11111000,B00000000,B00000000,B00000000
,B00001111,B11111110,B00001111,B01111111,B11000000
,B00001000,B01111111,B11111111,B10111110,B00000000
,B00000000,B00111111,B11111111,B10000000,B00000000
,B00000000,B00111111,B11111111,B10000000,B00000000
,B00000000,B00111111,B11111111,B00000000,B00000000
,B00000000,B00011111,B11111111,B00000000,B00000000
,B00000000,B00011111,B11100111,B10000000,B00000000
,B00000000,B01111111,B10000110,B10000000,B00000000
,B00000000,B01000110,B00001101,B00000000,B00000000
,B00000000,B01000110,B00010010,B00000000,B00000000
,B00000000,B00100110,B00100100,B00000000,B00000000
,B00000000,B00110001,B01100100,B00000000,B00000000
,B00000000,B00010000,B00000000,B00000000,B00000000
,B00000000,B00000000,B00000000,B00000000,B00000000
  };
// set pin 10 as the slave select 1,and 9 as SS2 for the DAC :
const int slaveSelectPin1 = 10;
const int slaveSelectPin2 = 9;
#define citire_curent A6
#define citire_tensiune A7

//4 bit DAC configuration bit3=write to DAC /bit2=* /bit1= !GA(2*Vout) /bit0= !shutdown device(1-active/0-shdn)
unsigned int dacdataH = 0;
unsigned int dacdataL = 0;
unsigned int valglob1 =0;
const byte dacH=00000001,dacL=00000000;

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define d 0
#define rampaVreg   1

#define LOGO_HEIGHT   18
#define LOGO_WIDTH    40


//static const unsigned char PROGMEM logo_bmp0[],logo_bmp1[],logo_bmp2[],logo_bmp3[],logo_bmp4[],
//logo_bmp5[],logo_bmp6[],logo_bmp7[],logo_bmp8[],logo_bmp9[],logo_bmp10[],logo_bmp11[];
float voltage =0,current=0,power=0;


void setup() {

  // put your setup code here, to run once:
 Serial.begin(9600);
 Serial.println("start:");
 
 // set the slaveSelectPin as an output:
  pinMode(slaveSelectPin1, OUTPUT);
  pinMode(slaveSelectPin2, OUTPUT);
  // initialize SPI:
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));   
    for(;;); // Don't proceed, loop forever
  }else Serial.println(F("Display conected with success"));
  display.display();
  delay(100);
  display.clearDisplay();
  DAC_control(0,0);
 // convertodac(28.24);
  testdrawbitmap(3);
  testdrawchar();
voltage_start(50);
/*
 delay(2000);
 DAC_control(7.5,7.5);
 delay(2000);
 DAC_control(15,15);
 delay(2000);
 DAC_control(22.5,22.5);
 delay(2000);
 DAC_control(30,30);
 delay(2000);
 DAC_control(15,15);
 delay(2000);
 */
}

void loop() {
  // put your main code here, to run repeatedly:

delay(100);
citire_analog();
afisare();
/*
display.clearDisplay();
frame();
display.display();
delay(500);
display.invertDisplay(1);
delay(500);
display.invertDisplay(0);
menu1("menu1","submenu12" );
menu2("Volt:","Curr:","Pow :");
valori_menu2(28.1274,2.34165,60.119);
*/
/*
afisare();
  for(int j=0;j<16;j++)
  for(int i=0;i<256;i++)
  {
  DAC2write(j,i);
  DAC1write(j,i);
  //delay(5);
  }
*/
}

void testdrawchar(void) {
  display.clearDisplay();
  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(WHITE,BLACK); // Draw white text
  display.setCursor(0, 0);     // Start at top-left corner
  display.cp437(true);         // Use full 256 char 'Code Page 437' font

  // Not all the characters will fit on the display. This is normal.
  // Library will draw what it can and the rest will be clipped.
  for(int16_t i=0; i<256; i++) {
    if(i==85||i==169)
   { display.clearDisplay();
    display.setCursor(0, 0);  
   }
    
    if(i == '\n') display.write(' ');
    else          display.write(i);   
   
    display.display();
  }
  delay(100);
}

void testdrawbitmap(uint8_t i) {
 
 for(i;i>0;i--){
  display.clearDisplay();
  display.drawBitmap(
    (display.width()  - LOGO_WIDTH ) / 2,
    (display.height() - LOGO_HEIGHT) / 2,
  logo_bmp0, LOGO_WIDTH, LOGO_HEIGHT, 1);
  display.display();
  delay(d);
  display.clearDisplay();
  display.drawBitmap(
    (display.width()  - LOGO_WIDTH ) / 2,
    (display.height() - LOGO_HEIGHT) / 2,
    logo_bmp1, LOGO_WIDTH, LOGO_HEIGHT, 1);
  display.display();
  delay(d); 
  display.clearDisplay();
  display.drawBitmap(
    (display.width()  - LOGO_WIDTH ) / 2,
    (display.height() - LOGO_HEIGHT) / 2,
    logo_bmp2, LOGO_WIDTH, LOGO_HEIGHT, 1);
  display.display();
  delay(d);
  display.clearDisplay();
  display.drawBitmap(
    (display.width()  - LOGO_WIDTH ) / 2,
    (display.height() - LOGO_HEIGHT) / 2,
    logo_bmp3, LOGO_WIDTH, LOGO_HEIGHT, 1);
  display.display();
  delay(d);
  display.clearDisplay();
  display.drawBitmap(
    (display.width()  - LOGO_WIDTH ) / 2,
    (display.height() - LOGO_HEIGHT) / 2,
    logo_bmp4, LOGO_WIDTH, LOGO_HEIGHT, 1);
  display.display();
  delay(d);  
  display.clearDisplay();
  display.drawBitmap(
    (display.width()  - LOGO_WIDTH ) / 2,
    (display.height() - LOGO_HEIGHT) / 2,
    logo_bmp5, LOGO_WIDTH, LOGO_HEIGHT, 1);
  display.display();
  delay(d);
  display.clearDisplay();
  display.drawBitmap(
    (display.width()  - LOGO_WIDTH ) / 2,
    (display.height() - LOGO_HEIGHT) / 2,
    logo_bmp6, LOGO_WIDTH, LOGO_HEIGHT, 1);
  display.display();
  delay(d);
  display.clearDisplay();
  display.drawBitmap(
    (display.width()  - LOGO_WIDTH ) / 2,
    (display.height() - LOGO_HEIGHT) / 2,
    logo_bmp7, LOGO_WIDTH, LOGO_HEIGHT, 1);
  display.display();
  delay(d);
  display.clearDisplay();
  display.drawBitmap(
    (display.width()  - LOGO_WIDTH ) / 2,
    (display.height() - LOGO_HEIGHT) / 2,
    logo_bmp8, LOGO_WIDTH, LOGO_HEIGHT, 1);
  display.display();
  delay(d);
  display.clearDisplay();
  display.drawBitmap(
    (display.width()  - LOGO_WIDTH ) / 2,
    (display.height() - LOGO_HEIGHT) / 2,
    logo_bmp9, LOGO_WIDTH, LOGO_HEIGHT, 1);
  display.display();
  delay(d);
  display.clearDisplay();
  display.drawBitmap(
    (display.width()  - LOGO_WIDTH ) / 2,
    (display.height() - LOGO_HEIGHT) / 2,
    logo_bmp10, LOGO_WIDTH, LOGO_HEIGHT, 1);
  display.display();
  delay(d);
  display.clearDisplay(); 
  display.drawBitmap(
    (display.width()  - LOGO_WIDTH ) / 2,
    (display.height() - LOGO_HEIGHT) / 2,
    logo_bmp11, LOGO_WIDTH, LOGO_HEIGHT, 1);
  display.display();
  delay(d);
 }
  
}

void frame(void)
{
  display.drawRect(0,0,128,32,WHITE);
  display.drawLine(59,11,128, 11,WHITE);
  display.drawLine(59,21,128, 21,WHITE);
  display.drawLine(59,0,59, 32,WHITE);
  
}

void text(String text,int xcursor,int ycursor,int size,bool show)
{
  
  display.setTextSize(size);
  display.setTextColor(WHITE);
  display.setCursor(xcursor, ycursor);
  display.println(text);
  if(show)
    display.display();
  delay(10);
 }
void text2(byte simbol,int xcursor,int ycursor,int size,bool show)
{
  
  display.setTextSize(size);
  display.setTextColor(WHITE);
  display.setCursor(xcursor, ycursor);
  display.write(simbol);
  if(show)
    display.display();
  delay(10);
 }
void text3(double text,int xcursor,int ycursor,int size,bool show)
{
  
  display.setTextSize(size);
  display.setTextColor(WHITE);
  display.setCursor(xcursor, ycursor);
  display.println(text);
  if(show)
   display.display();
  delay(10);
 }
void menu1 (String meniu11,String submeniu12)
{
  text(meniu11,1,0,2,0);
  text2(31,3,17,1,0);
  text(submeniu12,3,23,1,0);
}
void menu2 (String meniu21,String meniu22,String meniu23)
{
  text(meniu21,61,2,1,0);
  text(meniu22,61,13,1,0);
  text(meniu23,61,23,1,0);
}
void valori_menu2(float val21,float val22,float val23)
{
  //float nearest = roundf(val21 * 10) / 10;
  text3(val21,89,2,1,0);
  text3(val22,89,13,1,0);
  text3(val23,89,23,1,0);
  text("V",121,2,1,0);
  text("A",121,13,1,0);
  text("W",121,23,1,0);
  
  //text2(234,121,23,1);//omega simbol
  
}

void afisare(void)
{
  display.clearDisplay();
  frame();
  menu1("menu1","submenu12" );
  menu2("Volt:","Curr:","Pow :");
  valori_menu2(map_(voltage,1023,30),map_(current,1023,5),power);
  display.display();
}

void DAC1write(int addH, int addL) {
  int dach =dacH,dacl=dacL;
  dach <<= 4;
  dach = dach+addH;
  dacl=addL;
  Serial.print("dach1=");
  Serial.print(dach,BIN);
  Serial.print("dacl1=");
  Serial.println(dacl,BIN);
  // take the SS pin low to select the chip:
  digitalWrite(slaveSelectPin1, LOW);
  delay(10);
  //  send in the address and value via SPI:
  SPI.transfer(dach);
  SPI.transfer(dacl);
  delay(10);
  // take the SS pin high to de-select the chip:
  digitalWrite(slaveSelectPin1, HIGH);
  }

void DAC2write(int addH, int addL) {
  int dach =dacH,dacl=dacL;
  dach <<= 4;
  dach = dach+addH;
  dacl=addL;
  Serial.print("dach2=");
  Serial.print(dach,BIN);
  Serial.print("dacl2=");
  Serial.println(dacl,BIN);
  // take the SS pin low to select the chip:
  digitalWrite(slaveSelectPin2, LOW);
  delay(10);
  //  send in the address and value via SPI:
  SPI.transfer(dach);
  SPI.transfer(dacl);
  delay(10);
  // take the SS pin high to de-select the chip:
  digitalWrite(slaveSelectPin2, HIGH);
  }

float transfdac(float valin,float valout)
{
  valout=map(valin,0,4095,0,30); 
  return valout ;
}

// convert a binary string to a decimal number, returns decimal value
int bin2dec(char *bin)   
{
  int  b, k, m, n;
  int  len, sum = 0;
  len = strlen(bin) - 1;
  for(k = 0; k <= len; k++) 
  {
    n = (bin[k] - '0'); // char to numeric value
    if ((n > 1) || (n < 0)) 
    {
      puts("\n\n ERROR! BINARY has only 1 and 0!\n");
      return (0);
    }
    for(b = 1, m = len; m > k; m--) 
    {
      // 1 2 4 8 16 32 64 ... place-values, reversed here
      b *= 2;
    }
    // sum it up
    sum = sum + n * b;
    //printf("%d*%d + ",n,b);  // uncomment to show the way this works
  }
  return(sum);
}

int convertodac(float valin)
{
  unsigned int val=0;
  static unsigned char valout[12];
  val = map_(valin,30,4004);
    Serial.print("valstart=");
    Serial.print(val,BIN);
    Serial.print("/");
    Serial.println(val,DEC);
    //Serial.print(" valout=");
  for(int i=0;i<12;i++)
  {
    valout[i]=(val>>i)&1;
  }
Serial.print(" valout= ");
for(int i=0;i<12;i++)
  {  
    Serial.print(valout[11-i],BIN);
  }
  Serial.println();
  int sablonh=0,sablonl=0;
for(int index=3;index>=0;index--)
{
  sablonh=( sablonh << 1 ) +valout[8+index];
}
for(int index=7;index>=0;index--)
{
  sablonl=(sablonl<<1)+valout[index];
}
dacdataH=sablonh;
dacdataL=sablonl;
Serial.print("dacdataH+dacdataL = ");
Serial.print(dacdataH);
Serial.print(" ");
Serial.println(dacdataL);
valglob1=val;
return valglob1;
}

// converts character array 
// to string and returns it 
String convertToString(char* a) 
{ int a_size = sizeof(a) / sizeof(char);
    int i; 
    String s = ""; 
    for (i = 0; i < a_size; i++) { 
        s = s + a[i];
    } 
    return s; 
} 

void DAC_control(float valdac1,float valdac2)
{ 
  convertodac(valdac1); 
  DAC1write(dacdataH,dacdataL); 
  convertodac(valdac2); 
  DAC2write(dacdataH,dacdataL);
  Serial.println();
  voltage=valdac1;
  current=valdac2;
}

float map_(float valin,float valinmax,float valoutmax)
{
  return valin * valoutmax / valinmax;
}

void citire_analog()
{
  current = analogRead(citire_curent);
  Serial.print("current = ");
  Serial.print(map_(current,1023,5));
  voltage = analogRead(citire_tensiune);
  Serial.print("   voltage = ");
  Serial.println(map_(voltage,1023,5));
}

void voltage_start(char incr)
{
  for(unsigned int index=0;index <4095;index+=incr)
  {
  convertodac(map_(index,4095,30)); 
  DAC1write(dacdataH,dacdataL); 
  //Serial.println();
  voltage=index;
  delay(rampaVreg);
  }
  
  delay(1000);
  for( int index2=4095;index2 >=0;index2-=incr)
  {
  convertodac(map_(index2,4095,30)); 
  DAC1write(dacdataH,dacdataL); 
  voltage=index2;
  delay(rampaVreg);
  }
  
  
  delay(100);
  
}
