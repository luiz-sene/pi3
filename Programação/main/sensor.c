#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "sensor.h"
#include "servomotor.h"

#define SNR 12
#define ON 1
#define OFF 0

static bool last_state_snr = 0; // Armazena o último estado do botão
    
/*incializa o sensor como entrada*/
void init_sensor(void){

    gpio_pad_select_gpio(SNR);
    gpio_set_direction(SNR, GPIO_MODE_INPUT);
}
/*verifica o sinal do sensor*/
void verifica_sensor(void){

    bool state_snr = gpio_get_level(SNR);

    if (!state_snr && !last_state_snr)
    {
        last_state_snr = true;
        tremelica();
    }
    else if(state_snr && last_state_snr)
    {
        last_state_snr = false;
    }
    return;
}