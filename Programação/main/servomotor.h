#ifndef SERVOMOTOR_H_INCLUDED
#define SERVOMOTOR_H_INCLUDED

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/mcpwm.h"

//inline uint32_t example_convert_servo_angle_to_duty_us(int angle);
void init_servomotor(void);
void tremelica(void);

#endif