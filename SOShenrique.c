#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define BUTTON_GPIO 4
#define BUZZER      GPIO_NUM_23
#define LED         5

#define ponto 200      
#define linha 900      

#define DEBOUNCE_TIME_MS 50
#define HOLD_TIME_MS     6000  // 6 segundos

int ativado = 0;

// Pisca o LED em Morse-Pedro e henrique
void morse(int tempo, int vezes, int entrada) {
    gpio_set_direction(entrada, GPIO_MODE_OUTPUT);
    for(int i = 0; i < vezes; i++) {
        gpio_set_level(entrada, 1);
        vTaskDelay(tempo / portTICK_PERIOD_MS);
        gpio_set_level(entrada, 0);
        vTaskDelay(250 / portTICK_PERIOD_MS);
    }
}

// Letras do SOS
void s() {
    printf("S\n");
    morse(ponto, 3, LED);
    vTaskDelay(250 / portTICK_PERIOD_MS);
}

void o() {
    printf("O\n");
    morse(linha, 3, LED);
    vTaskDelay(250 / portTICK_PERIOD_MS);
}
void app_main(void) {

    printf("Sistema iniciado\n");


    // Configura LED-henrique e buzzer-fernando
    gpio_set_direction(LED, GPIO_MODE_OUTPUT);
    gpio_set_direction(BUZZER, GPIO_MODE_OUTPUT);

    while (1) {
        
