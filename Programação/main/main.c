/*
   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

/****************************************************************************
*
* This demo showcases creating a GATT database using a predefined attribute table.
* It acts as a GATT server and can send adv data, be connected by client.
* Run the gatt_client demo, the client demo will automatically connect to the gatt_server_service_table demo.
* Client demo will enable GATT server's notify after connection. The two devices will then exchange
* data.
*
****************************************************************************/
#include "pwm.h"
#include "sensor.h"
#include "servomotor.h"
#include "bt.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#define GATTS_TABLE_TAG "GATTS_TABLE_DEMO"

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

   
   rotina_bt();
   while(1){
      verifica_sensor();
      vTaskDelay(pdMS_TO_TICKS(1000));
   }

}
