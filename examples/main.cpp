#include <Arduino.h>
#include <am_encoder.h>

#define ENC_PIN_A 10          // OUTPUT ENCODER A
#define ENC_PIN_B 11          // OUTPUT ENCODER B
#define NUMBER_OF_STEPS 225   // OPTIONAL HOW MANY STEPS HAS ENCODER
#define VALUE_MM_PER_CIRCLE 6 // OPTIONAL VALUE IN milimeters THAT NEED TO MEASURE OF ROAD

long poz = 0, poz_old = 0;
AM_ENCODER enc; // VARIABLE TYPE OF AM_ENCODER

void setup()
{
    // LOAD THE VALUE FOR WORK OUR ENCODER, BUT TWO LAST VALUE ARE OPTIONAL
    enc.begin(ENC_PIN_A, ENC_PIN_B, NUMBER_OF_STEPS, VALUE_MM_PER_CIRCLE);
    Serial.begin(9600);
}

void loop()
{

    poz = enc.read_step(); // READ THE ACTUAL STEP

    if (poz != poz_old)
    {
        Serial.print(enc.convert_to_mm(poz)); // using method convert_to_mm() have returned the value in millimeters converted to string
        Serial.println(" mm");
        poz_old = poz;
    }
}