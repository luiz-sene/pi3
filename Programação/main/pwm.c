#include <stdio.h>
#include "driver/ledc.h"
#include "esp_err.h"
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "pwm.h"

/*Conforme a documentação disponibilizado do carrinho, ele utiliza duas pontes H, uma para cada lado, portanto
aqui utilizamos os pinos 19 e 18 para o lado direito, um para andar pra frente e outro para tras, respectivamente
e os pinos 26 e 25 para o lado esquerdo*/

/*define os pinos do pwm para andar para frente*/
#define LEDC_TIMER                  LEDC_TIMER_0            // seleciona o timer 0, possui 3 timers
#define LEDC_MODE                   LEDC_LOW_SPEED_MODE     // modo em low speed
#define LEDC_OUTPUT_IO_DF           (19)                    // pino 19 de saida; PWM1 
#define LEDC_CHANNEL_DF             LEDC_CHANNEL_0          // seleciona o canal 0, possui 16
#define LEDC_OUTPUT_IO_EF           (26)                    // PWM2
#define LEDC_CHANNEL_EF             LEDC_CHANNEL_1          // seleciona o canal 1

/*define os pinos do pwm para andar para tras*/
#define LEDC_OUTPUT_IO_DF_r           (18)                    // PWM1N
#define LEDC_CHANNEL_DF_r             LEDC_CHANNEL_4          // seleciona o canal 0, possui 16
#define LEDC_OUTPUT_IO_EF_r           (25)                    // PWM2N
#define LEDC_CHANNEL_EF_r             LEDC_CHANNEL_5          // 

#define LEDC_DUTY_RES               LEDC_TIMER_13_BIT       // resolução de 13 bits, maximo 15
#define LEDC_DUTY                   (0)                  // 13bits = 8000+, 4095 = 50% da resolução
#define LEDC_FREQUENCY              (1000)                  // frequencia de 5k

static uint32_t sentido=1;

 /*inicia a função ledc para pwm para frente*/
void ledc_init_DF(void)
{

    /*configura as definições do LEDC PWM timer*/
    ledc_timer_config_t ledc_timer = {
        .speed_mode = LEDC_MODE,
        .timer_num = LEDC_TIMER,
        .duty_resolution = LEDC_DUTY_RES,
        .freq_hz = LEDC_FREQUENCY,
        .clk_cfg = LEDC_AUTO_CLK

    };
    /*verifica erro e aplica as configurações do ledc_timer*/
    ESP_ERROR_CHECK(ledc_timer_config(&ledc_timer));
    ;

    /*configura as definições do canal do LEDC PWM */
    ledc_channel_config_t ledc_channel = {
        .speed_mode = LEDC_MODE,
        .channel = LEDC_CHANNEL_DF,
        .timer_sel = LEDC_TIMER,
        .intr_type = LEDC_INTR_DISABLE,
        .gpio_num = LEDC_OUTPUT_IO_DF,
        .duty = 0, //  inicia o duty cycle como 0
        .hpoint = 0};
    /*verifica erro e aplica as configurações do ledc_timer*/
    ESP_ERROR_CHECK(ledc_channel_config(&ledc_channel));
    ;
};

void ledc_init_EF(void)
{

    /*configura as definições do LEDC PWM timer*/
    ledc_timer_config_t ledc_timer = {
        .speed_mode = LEDC_MODE,
        .timer_num = LEDC_TIMER,
        .duty_resolution = LEDC_DUTY_RES,
        .freq_hz = LEDC_FREQUENCY,
        .clk_cfg = LEDC_AUTO_CLK

    };
    /*verifica erro e aplica as configurações do ledc_timer*/
    ESP_ERROR_CHECK(ledc_timer_config(&ledc_timer));
    ;

    /*configura as definições do canal do LEDC PWM */
    ledc_channel_config_t ledc_channel = {
        .speed_mode = LEDC_MODE,
        .channel = LEDC_CHANNEL_EF,
        .timer_sel = LEDC_TIMER,
        .intr_type = LEDC_INTR_DISABLE,
        .gpio_num = LEDC_OUTPUT_IO_EF,
        .duty = 0, //  inicia o duty cycle como 0
        .hpoint = 0};
    /*verifica erro e aplica as configurações do ledc_timer*/
    ESP_ERROR_CHECK(ledc_channel_config(&ledc_channel));
    ;
};


/*inicia as funções ledc para pwm para tras*/
void ledc_init_DF_r(void)
{

    /*configura as definições do LEDC PWM timer*/
    ledc_timer_config_t ledc_timer = {
        .speed_mode = LEDC_MODE,
        .timer_num = LEDC_TIMER,
        .duty_resolution = LEDC_DUTY_RES,
        .freq_hz = LEDC_FREQUENCY,
        .clk_cfg = LEDC_AUTO_CLK

    };
    /*verifica erro e aplica as configurações do ledc_timer*/
    ESP_ERROR_CHECK(ledc_timer_config(&ledc_timer));
    ;

    /*configura as definições do canal do LEDC PWM */
    ledc_channel_config_t ledc_channel = {
        .speed_mode = LEDC_MODE,
        .channel = LEDC_CHANNEL_DF_r,
        .timer_sel = LEDC_TIMER,
        .intr_type = LEDC_INTR_DISABLE,
        .gpio_num = LEDC_OUTPUT_IO_DF_r,
        .duty = 0, //  inicia o duty cycle como 0
        .hpoint = 0};
    /*verifica erro e aplica as configurações do ledc_timer*/
    ESP_ERROR_CHECK(ledc_channel_config(&ledc_channel));
    ;
};

void ledc_init_EF_r(void)
{

    /*configura as definições do LEDC PWM timer*/
    ledc_timer_config_t ledc_timer = {
        .speed_mode = LEDC_MODE,
        .timer_num = LEDC_TIMER,
        .duty_resolution = LEDC_DUTY_RES,
        .freq_hz = LEDC_FREQUENCY,
        .clk_cfg = LEDC_AUTO_CLK

    };
    /*verifica erro e aplica as configurações do ledc_timer*/
    ESP_ERROR_CHECK(ledc_timer_config(&ledc_timer));
    ;

    /*configura as definições do canal do LEDC PWM */
    ledc_channel_config_t ledc_channel = {
        .speed_mode = LEDC_MODE,
        .channel = LEDC_CHANNEL_EF_r,
        .timer_sel = LEDC_TIMER,
        .intr_type = LEDC_INTR_DISABLE,
        .gpio_num = LEDC_OUTPUT_IO_EF_r,
        .duty = 0, //  inicia o duty cycle como 0
        .hpoint = 0};
    /*verifica erro e aplica as configurações do ledc_timer*/
    ESP_ERROR_CHECK(ledc_channel_config(&ledc_channel));
    ;
};

    
/*Função que define o sentido de movimentação do motor. 
Se sentido igual a 1 carro se movimenta pra frente e zera o duty cicle que movimenta a roda para tras
caso contrario o duty cycle relacionado ao pwm para andar pra frente e zerado e pwm que movimenta para
tras e acionado*/

void movimenta_DF(int32_t duty, int32_t sentido){

    
    if(sentido == 1){
         /*define o duty cycle com o valor duty%*/
        ledc_set_duty(LEDC_MODE, LEDC_CHANNEL_DF, duty);
        /*atualiza e aplica os novos valores*/
        ledc_update_duty(LEDC_MODE, LEDC_CHANNEL_DF);

        /*define o duty cycle com o valor duty%*/
        ledc_set_duty(LEDC_MODE, LEDC_CHANNEL_DF_r, 0);
        /*atualiza e aplica os novos valores*/
        ledc_update_duty(LEDC_MODE, LEDC_CHANNEL_DF_r);
    }
    else{
        /*define o duty cycle com o valor duty%*/
        ledc_set_duty(LEDC_MODE, LEDC_CHANNEL_DF, 0);
        /*atualiza e aplica os novos valores*/
        ledc_update_duty(LEDC_MODE, LEDC_CHANNEL_DF);

        /*define o duty cycle com o valor duty%*/
        ledc_set_duty(LEDC_MODE, LEDC_CHANNEL_DF_r, duty);
        /*atualiza e aplica os novos valores*/
        ledc_update_duty(LEDC_MODE, LEDC_CHANNEL_DF_r);
    }
}

void movimenta_EF(int32_t duty, int32_t sentido){

    if(sentido == 1){
         /*define o duty cycle com o valor duty%*/
        ledc_set_duty(LEDC_MODE, LEDC_CHANNEL_EF, duty);
        /*atualiza e aplica os novos valores*/
        ledc_update_duty(LEDC_MODE, LEDC_CHANNEL_EF);

        /*define o duty cycle com o valor duty%*/
        ledc_set_duty(LEDC_MODE, LEDC_CHANNEL_EF_r, 0);
        /*atualiza e aplica os novos valores*/
        ledc_update_duty(LEDC_MODE, LEDC_CHANNEL_EF_r);
    }
    else{
        /*define o duty cycle com o valor duty%*/
        ledc_set_duty(LEDC_MODE, LEDC_CHANNEL_EF, 0);
        /*atualiza e aplica os novos valores*/
        ledc_update_duty(LEDC_MODE, LEDC_CHANNEL_EF);

        /*define o duty cycle com o valor duty%*/
        ledc_set_duty(LEDC_MODE, LEDC_CHANNEL_EF_r, duty);
        /*atualiza e aplica os novos valores*/
        ledc_update_duty(LEDC_MODE, LEDC_CHANNEL_EF_r);
    }
}

/*Função para controlar a direção do carrinho.
para que uma curva seja feita o pwm da direção oposta a desejada e diminuido
tambem e definido o sentido da movimentação, se direção for igual a 4 o sentido passado para função
que movimenta o carrinho se torna difrente de 1, dessa forma o carrinho estara dando re, ate que seja enviado
o comando para que ele ande para frente, alterando o valor do sentiro para 1 novamente*/

void direcao(int32_t dir,int32_t duty){
    
    if(dir == 1){
        sentido = 1;
    }
    else if(dir == 4){
        sentido = 2;
    }
    switch(dir){

        case 1: /*movimento para frente*/
        movimenta_DF(duty,sentido);
        movimenta_EF(duty,sentido);
          break;

        case 2: /*movimento para a direita*/
        movimenta_DF(duty,sentido);
        movimenta_EF(duty/3,sentido);

        break;

        case 3: /*movimento para a para esquerda*/
        movimenta_DF(duty/3,sentido);
        movimenta_EF(duty,sentido);

        break;

        case 4: /*movimento de re*/
        movimenta_DF(duty,sentido);
        movimenta_EF(duty,sentido);

        break;

        default:
            break;

    }
}

















