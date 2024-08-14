/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

//definindo os pinos (botões)
const int BTN_PIN = 15;

//definindo os pinos (leds)
const int LED_PIN = 4;

//definindo bobinas
const int BOBINA_1 = 18;
const int BOBINA_2 = 19;
const int BOBINA_3 = 20;
const int BOBINA_4 = 21;



int main() {
    stdio_init_all();

    //iniciando os pinos (botões)
    gpio_init(BTN_PIN);

    //iniciando os pinos (leds)
    gpio_init(LED_PIN);

    //iniciando os pinos (bobinas)
    gpio_init(BOBINA_1);
    gpio_init(BOBINA_2);
    gpio_init(BOBINA_3);
    gpio_init(BOBINA_4);

    //setando como entrada
    gpio_set_dir(BTN_PIN, GPIO_IN);

    //pull up
    gpio_pull_up(BTN_PIN);

    //setando como saída
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_set_dir(BOBINA_1, GPIO_OUT);
    gpio_set_dir(BOBINA_2, GPIO_OUT);
    gpio_set_dir(BOBINA_3, GPIO_OUT);
    gpio_set_dir(BOBINA_4, GPIO_OUT);

    // leds apagados
    gpio_put(LED_PIN, 0);

    //estado dos leds
    bool estado_led = false;

  while (true) {
    if (!estado_led && !gpio_get(BTN_PIN)) {
        for(int i=0; i<2048/4; i++){
            gpio_put(LED_PIN, 1);
            gpio_put(BOBINA_1, 1);
            sleep_ms(10);
            gpio_put(BOBINA_1, 0);
            gpio_put(BOBINA_2, 1);
            sleep_ms(10);
            gpio_put(BOBINA_2, 0);
            gpio_put(BOBINA_3, 1);
            sleep_ms(10);
            gpio_put(BOBINA_3, 0);
            gpio_put(BOBINA_4, 1);
            sleep_ms(10);
            gpio_put(BOBINA_4, 0);
        }
        estado_led = true;
    }
    else if(estado_led && !gpio_get(BTN_PIN)){
      gpio_put(LED_PIN, 0);
      sleep_ms(250);
      estado_led = false;
    }
  }
}
