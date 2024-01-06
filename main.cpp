/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

DigitalOut led(PC_0);

void a() {
    InterruptIn key(PA_1);

    key.mode(PullDown);
    key.fall([]() {
        led = !led;
    });
    key.enable_irq();
}

void b() {
    InterruptIn key(PA_1);

    key.mode(PullDown);
    key.rise([]() {
        led = 1;
    });
    key.fall([]() {
        led = 0;
    });
    key.enable_irq();
}

void c() {
    InterruptIn key(PA_1);
    InterruptIn key2(PA_1);

    key.mode(PullDown);
    key2.mode(PullDown);
    key.fall([]() {
        led = 1;
    });
    key2.fall([]() {
        led = 0;
    });
    key.enable_irq();
    key2.enable_irq();
}

void d() {

}

int main()
{
    PortOut leds(PortC, 0xFF);
    leds = 0;

    InterruptIn up(PA_1);
    InterruptIn down(PA_6);

    up.mode(PullDown);
    down.mode(PullDown);

    up.fall();

    up.enable_irq();
    down.enable_irq();

    while(true) {

    }
}
