#ifndef PWM_H_INCLUDED
#define PWM_H_INCLUDED

#include <stdio.h>
#include "driver/ledc.h"
#include "esp_err.h"
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>



/*funcoes*/
void ledc_init_DF(void);
void ledc_init_EF(void);

void ledc_init_DF_r(void);
void ledc_init_EF_r(void);


/*funcoes define sentido do movimento*/
void movimenta_DF(int32_t duty, int32_t sentido);
void movimenta_EF(int32_t duty, int32_t sentido);

/*define o movimento*/
void direcao(int32_t dir,int32_t duty);

#endif