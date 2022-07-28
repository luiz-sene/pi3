#ifndef SENSOR_H_INCLUDED
#define SENSOR_H_INCLUDED

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "sensor.h"

void init_sensor(void);
void verifica_sensor(void);

#endif