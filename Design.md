# Design
Seguindo as necessidades apontadas na concepção do projeto, apresentaremos os componentes que serão utilizados neste projeto, bem como analisaremos as escolhas de acordo com as caracteristicas de alguns componentes do mercado.

## Componentes

|Quantidade|Componente|Custo no Projeto|
|:-:|:-:|:-:|:-:|
|1|Microcontrolador|R$69,90||
|1|Módulo Bluetooth|Integrado ao Microcontrolador||
|1|Sensor de Proximidade|R$5,49||
|1|Servomotor|R$29,90||
|1|Bateria 9V recarregavel|R$19,98||
|1|Haste Flexivel com bagulhinho na ponta|R$-|R$-|
|1|Módulo de carrinho Vrum Vrum|R$-|R$-|

## Bluetooth VS WiFi

|#|  **BLUETOOTH** | **WIFI** |
|:-|:-:|:-:|
|Protocolo de Comunicação|IEEE 802.15.1|802.11|
|Frequencia (Hz)|2,4G|2,4~5G|
|Alcance|Até 100m|Maior que 100m|
|Custo de Mercado*|R$27,90|R$24,90|
|Alimentação|Baixo Consumo|Alto Consumo|
|Vantagem|Baixo Custo|Longo Alcance|
|Desvantagem|Baixo Alcance|Alto consumo energético|

*Pesquisado em 04/05/2022 - FilipeFlop

### Escolha
O módulo de comunicação escolhido foi o bluetooth devido ao baixo consumo energético deste dispositivo; apesar do baixo alcançe, atende a necessidade deste projeto; além disso, já temos familiardade com este dispositivo devido a trabalhos anteriores.

## Microcontrolador

Possibilidades
 1. ESP32
 2. Cortex M3
 3. ATMEGA328

O microcontrolador escolhido foi o ESP32, pois é o que melhor atende as nossas necessidades. Ele já possui módulos de comunicação bluetooth e wifi integrados, possui 4Mb de memória flash, que será utilizada para armazenamento dos dados coletados da aplicação, é um componnente que possui uma boa eficiencia no consumo energético, com diversos modos sleeps. Ele possui uma quantidade de pinos suficiente para este projeto, com 18 canais ADC, 34 portas GPIO, PWM e outras.

Além disso, ele está disponível junto ao professor Charles, que trabalhará com este microcontrolador na disciplina de Microcontroladores 2.

O que precisa que faça, quais me atendem, preços, descartar arduino,

## ServoMotor

Já tivemos experiência com o Servomotor Tower Pro SG90. Este servomotor pode rotacionar em aproximadamente 180º, 90º para cada lado. Possui cerca de 9g e 3 pinos analógicos: VCC, GND e comando. Ele opera em um torque de 8kgfcm, velocidade de 60º/0.1s e tensão de operação de 3V a 7,2V. Por fim, ele é um dos mais baratos do mercado.

## Sensor de proximidade

O sensor de obstáculo é um circuito composto por um emissor e um receptor IR, mais o CI comparador LM393, que facilita sua conexão com Arduino, PIC ou Raspberry Pi, visto que sua tensão é de 3,3-5V.

Seu funcionamento é simples: quando algum obstáculo é colocado em frente ao sensor, o sinal infravermelho é refletido para o receptor. Quando isso acontece, o pino de saída OUT é colocado em nível baixo (0), e o led verde do módulo é aceso, indicando que algum obstáculo foi detectado.

O alcance do sensor é de 2 à 80 cm, que pode ser ajustado por meio do potenciômetro na placa. O sensor de obstáculo é um componente que atende as nossas necessidades.

## Interface para Smartphone

Algumas
