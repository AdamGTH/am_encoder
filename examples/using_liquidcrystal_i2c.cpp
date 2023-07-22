#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <am_encoder.h>

#define ENC_PIN_A 10          // OUTPUT ENCODER A
#define ENC_PIN_B 11          // OUTPUT ENCODER B
#define NUMBER_OF_STEPS 225   // OPTIONAL HOW MANY STEPS HAS ENCODER
#define VALUE_MM_PER_CIRCLE 6 // OPTIONAL VALUE IN milimeters THAT NEED TO MEASURE OF ROAD

LiquidCrystal_I2C lcd(0x27, 20, 4);
AM_ENCODER enc;
long pos, pos_old;
String dir = "";

void print_lcd(int value, String dir);

void setup()
{
    enc.begin(ENC_PIN_A, ENC_PIN_B, NUMBER_OF_STEPS, VALUE_MM_PER_CIRCLE);
    lcd.init(); // LUB lcd.begin()
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("WAITING...");
    delay(1000);
}

void loop()
{
    pos = read_step();

    if (poz != poz_old)
    {
        poz > poz_old ? dir = "CW" : dir = "CCW";
        print_lcd(enc.convert_to_mm(poz), dir)
            poz_old = poz;
    }
}

void print_lcd(int value, String dir)
{

    lcd.setCursor(0, 0);
    lcd.print("mm: ");
    lcd.print(String(value));
    lcd.setCursor(0, 1);
    lcd.print("dir: ");
    lcd.print(dir);
}
