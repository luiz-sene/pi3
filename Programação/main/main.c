#include "pwm.h"
#include "sensor.h"
#include "servomotor.h"
#include "bt.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{
   
/*inicia as configurações do ledc*/
   ledc_init_DF();
   ledc_init_EF();


   ledc_init_DF_r();
   ledc_init_EF_r();

   /*inicializa sensor*/
   init_sensor();

   /*inicializa servo motor*/
   init_servomotor();

/*função que chama as diversas funções do bt*/   
   rotina_bt();
   while(1){
      verifica_sensor();
      vTaskDelay(pdMS_TO_TICKS(1000));
   }

}
