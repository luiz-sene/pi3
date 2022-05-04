# Design
Seguindo as necessidades apresentadas na concepção do projeto, apresentaremos os componentes que serão utilizados neste projeto, bem como analisaremos as escolhas de acordo com as caracteristicas de alguns componentes do mercado

## Componentes

|Quantidade|Componente|
|:-:|:-:|
|1|Microcontrolador|
|1|Módulo Bluetooth|
|1|Sensor de Proximidade|
|1|Servomotor|
|1|Haste Flexivel com bagulhinho na ponta|
|1|Módulo de carrinho Vrum Vrum|

## Bluetooth VS WiFi

|#|  **BLUETOOTH** | **WIFI** |
|-|:-:|:-:|
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
 1. Cortex M0
 2. Cortex M3
 3. Arduino
 4. MSP430
