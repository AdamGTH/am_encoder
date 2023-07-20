#include "am_encoder.h"
// #include <Arduino.h>

void AM_ENCODER::begin(uint8_t pinA, uint8_t pinB, uint16_t resol, uint8_t mm)
{

    nr_pinA = pinA;
    nr_pinB = pinB;
    resolution = resol;
    mm_per_step = (float)((mm * 100.0) / resolution);
    act_step = 0;
    cw = STOP;

    pinMode(nr_pinA, INPUT_PULLUP);
    pinMode(nr_pinB, INPUT_PULLUP);

    pin_enc_A = digitalPinToBitMask(nr_pinA);
    port_enc_A = digitalPinToPort(nr_pinA);
    pin_enc_B = digitalPinToBitMask(nr_pinB);
    port_enc_B = digitalPinToPort(nr_pinB);
}

long AM_ENCODER::read_step(void)
{

    static int dir = 0;

    // QUARTED 0
    if ((*portInputRegister(port_enc_A) & pin_enc_A) && (*portInputRegister(port_enc_B) & pin_enc_B))
    {
        if ((cw == ONE) && (dir == -3))
        {
            //    if(--(*pozycja) == -20) *pozycja = 0;
            --act_step;
        }

        else if ((cw == THR) && (dir == 3))
        {
            //    if(++(*pozycja) == 20) *pozycja=0;
            ++act_step;
        }

        cw = STOP;
        dir = 0;
    }
    // QUARTED 1
    if ((!(*portInputRegister(port_enc_A) & pin_enc_A)) && (*portInputRegister(port_enc_B) & pin_enc_B))
    {
        if ((cw == TWO))
        {
            cw = ONE;
            dir--;
        }

        else if (cw == STOP)
        {
            cw = ONE;
            dir++;
        }
    }
    // QUARTED 2
    if ((!(*portInputRegister(port_enc_A) & pin_enc_A)) && (!(*portInputRegister(port_enc_B) & pin_enc_B)))
    {
        if ((cw == ONE))
        {
            cw = TWO;
            dir++;
        }
        else if ((cw == THR))
        {
            cw = TWO;
            dir--;
        }
    }
    // QUARTED 3
    if ((*portInputRegister(port_enc_A) & pin_enc_A) && (!(*portInputRegister(port_enc_B) & pin_enc_B)))
    {
        if ((cw == TWO))
        {
            cw = THR;
            dir++;
        }
        else if (cw == STOP)
        {
            cw = THR;
            dir--;
        }
    }

    return act_step;
}

String AM_ENCODER::convert_to_mm(long pos)
{

    return String((float)(pos * mm_per_step) / 100);
}