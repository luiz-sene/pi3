# Design
Seguindo as necessidades apontadas na concepção do projeto, apresentaremos os componentes que serão utilizados neste projeto, bem como analisaremos as escolhas de acordo com as caracteristicas de alguns componentes do mercado.

## Componentes

|Quantidade|Componente|Custo no Mercado|Custo no Projeto|
|:-:|:-:|:-:|:-:|
|1|Microcontrolador|R$69,90|R$-|
|1|Módulo Bluetooth|Integrado ao Microcontrolador|R$-|
|1|Sensor de Obstáculo|R$49,90|R$-|
|1|Servomotor|R$59,90||
|1|Bateria 9V recarregavel|R$19,98|R$-|
|1|Haste Flexivel com bagulhinho na ponta|R$-|R$-|
|1|Módulo de carrinho Vrum Vrum|R$-|R$-|
||Total|R$199,98|R$0,00|

O custo total deste projeto foi zerado pois todos os componentes utilizados estavam disponíveis nos laboratórios do DAELN/IFSC.

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

## Framework

Foi utilizado o framework ESP-IDF, que é o framework oficial da Espressif para o desenvolvimento de aplicações parar toda a família ESP32.

## ServoMotor

Já tivemos experiência com o Servomotor Tower Pro SG90. Este servomotor pode rotacionar em aproximadamente 180º, 90º para cada lado. Possui cerca de 9g e 3 pinos analógicos: VCC, GND e comando. Ele opera em um torque de 8kgfcm, velocidade de 60º/0.1s e tensão de operação de 3V a 7,2V. Por fim, ele é um dos mais baratos do mercado. Infelizmente, este componente é extremamente frágil e não conseguiremos utilizá-lo de forma satisfatória. 

Outro servomotor disponível nos laboratórios foi o MG995. O Servo TowerPro MG995 possui ótima qualidade e alto torque, todas as suas engrenagens são metálicas, possui faixa de rotação de 180 graus, a tensão de operação é de 4,8V a 7,2V (facilmente atingida por meio das baterias do carrinho). Por fim, sua escolha se deu principalmente por sua robustez, que atingia as necessidades do projeto.

## Sensor de proximidade

O sensor de obstáculo é um circuito composto por um emissor e um receptor IR, mais o CI comparador LM393, que facilita sua conexão com Arduino, PIC ou Raspberry Pi, visto que sua tensão é de 3,3-5V.

Seu funcionamento é simples: quando algum obstáculo é colocado em frente ao sensor, o sinal infravermelho é refletido para o receptor. Quando isso acontece, o pino de saída OUT é colocado em nível baixo (0), e o led verde do módulo é aceso, indicando que algum obstáculo foi detectado.

O alcance do sensor é de 3 à 80 cm, que pode ser ajustado por meio do potenciômetro na placa. O sensor de obstáculo é um componente que atende as nossas necessidades.

### Escolha

Sensor de Obstaculo Infravermelho - E18-D80NK

## Bateria

2 Baterias de litio em série que já estão inseridas no prototipo do carrinho disponível do LPAE 3,7V

## Regulador de tensão chaveado

Regulador de Tensão LM2596 Conversor DC-DC Step Down ou similar

## Interface para Usuário

Existem alguns softwares no mercado para implementar uma interface de controle para o usuário. Neste projeto, pensamos em 2 opções: implementar uma interface para o usuário no Qt Creator, orientando toda a programação deste projeto a objetos; ou utilizar o MIT App Inventor para implementar um aplicativo para smartphone.

O Qt Creator é um ambiente de desenvolvimento integrado (IDE) multiplataforma criado para a máxima experiência do desenvolvedor. O Qt Creator é executado nos sistemas operacionais de desktop Windows, Linux e macOS e permite que os desenvolvedores criem software em plataformas desktop, móveis e incorporadas.

O MIT App Inventor é um ambiente de programação visual intuitivo que permite que todos criem aplicativos totalmente funcionais para telefones Android, iPhones e tablets Android/iOS. Essa ferramenta é baseada em blocos, facilitando a criação de aplicativos complexos e de alto impacto em um tempo significativamente menor do que os ambientes de programação tradicionais.

No caso do Qt Creator, pudemos ter o auxilio e orientação do Profº Hugo Marcondes, na disciplina de Programação Orientada a Objetos. No entanto, nesta disciplina utilizamos apenas o framework do Arduino para implementar nossos objetivos. Como este framework era dispensável para a disciplina de Projeto Integrador III, implementamos também uma interface final no MIT App Inventor.

## Placa de Circuito Impresso

Foi implementado também uma placa de circuito impresso para acoplar com facilidade o microcontrolador escolhido com o cabo flet do carrinho. Para isto, foi utilizado o software KiCad, que é um programa computacional de código aberto para projeto eletrônico assistido por computador, com o objetivo de facilitar a concepção de layouts e suas conversões para placas de circuito impresso. Além dele, foi utilizado as instalações do IFSC para a confecção da placa.
