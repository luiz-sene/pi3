# IMPLEMENTAÇÃO
Nesta etapa do projeto colocaremos em prática o que foi abordado e definido pelas etapas anteriores. De forma a atingir os objetivos estipulados, podemos definir duas diferentes frentes de trabalho. Programação e Montagem do equipamento.

## Programação

O primeiro passo foi realizar testes com os componentes individualmente de forma a verificar e compreender seu funcionamento. Ao longo deste processo pode-se notar que muito do que era feito ali poderia e foi integrado ao código final. Para tal, foi instalado o ESP-IDF, o qual foi utilizado junto ao VS-CODE para implementar todas as funcionalidades desejadas. Este ambiente de desenvolvimento suporta as linguagens C e C++, além de já possuir alguns exemplos que nos guiaram. Apesar destes exemplos, é importante destacar a grande dificuldade de encontrar bibliografia suficiente para o entendimento pleno da utilização deste framework.

Cada componente foi testado separadamente através de rotinas simples, após isso métodos de interação entre eles foram gerados, resultando em um código funcional que atende as exigências do projeto. Inicialmente, optamos por realizar a comunicação via bluetooth, visto que a partir deste ponto poderíamos prosseguir com a implementação de todo o restante das nossas funcionalidades de forma mais fluída. Para os futuros projetos que desejem seguir com esta implementação, é importante mencionar que foi justamente aqui que encontramos a nossa maior dificuldade durante todo o processo: tornar o código exemplo do Bluetooth em modo de economia de energia funcional às nossas necessidades. Após muito estudo, conseguimos manipular os dados enviados ao esp32 de forma que para cada dado recebido uma ação fosse desencadeada, uma mensagem serial de confirmação também é exibida no serial monitor. Embora para este projeto não tenha sido utilizado, o ato do esp32 enviar dados via bluetooth e não apenas receber, também está funcional. Após a comunicação ser implementada conforme desejávamos, iniciamos a criação do Aplicativo para Smartphone, a qual seria a nossa interface de controle do usuário. O objetivo desta interface era escanear a procura do dispositvo bluetooth desejado, esp32, e uma vez conectado que ele pudesse enviar dados de forma que controlasse o movimento do carrinho e o motor da haste. Para que esta comunicação fosse realizada ambos os dispositvos, a interface e o esp32, precisavam ter o mesmo service uuid, um numero de 128 bits utilizado para identificar informações, uma vez que ele não era disponibilizado na documentação do ESP-IDF foi utilizado um aplicativo disponivel na playstore para se conectar com o microcontrolador e uma vez que ele enviava dados era possivel analisar o log gerado por esse aplicativo para identificar esse numero e implementa-lo na interface. Para o caso dos motores do carrinho, foi importante entender a documentação disposta no GitHub do LPAE, encontrada [clicando neste link](https://github.com/xtarke/automated_buggy). Implementamos os 4 PWMs necessários para o correto funcinonamento dos motores de acordo com as nossas necessidades. Ao receber os comandos via comunicação bluetooth, o acionamento ocorria de forma satisfatória. Lembrando que o acionamento do carrinho era desejado APENAS por meio da interface do usuário. Por fim, implementamos o servo motor e o sensor de obstáculo. Para o servo motor, implementamos uma rotação de 90º para ambos os lados, fazendo com que este gire o que chamamos de "tremelique". Neste protótipo, implementamos apenas uma volta de 90º no sentido horário e outro no sentido anti-horário, de forma a ser uma validação de conceito. O sensor de obstáculo foi implementado enviando um sinal ao ESP32, o qual ativa o servo motor sempre que o sensor detecta um obstáculo próximo. Portanto, conforme desejado inicialmente, o acionamento do tremelique ocorre por 2 métodos: Controle do usuário por meio do aplicativo, ou aproximação do felino sendo detectada pelo sensor de obstáculo. Após todos os testes individuais, pudemos realizar o código final com todas as aplicações requeridas por este projeto juntas e funcionais. O código podeser acessado por meio do link abaixo. Reforço que ara este código ser compilado, é necessário o a correta instalação do ESP-IDF, bem como a criação de novo projeto.

![Aplicativo](https://github.com/juliopacheco12/PIN22107/blob/main/Imagens/App%20Miau%20Miau.jpeg)

### Código esp32
[Clique aqui para ver o código deste projeto](https://github.com/juliopacheco12/PIN22107/tree/main/Programação).

### App
[Clique aqui para ver o código do App](https://github.com/juliopacheco12/PIN22107/tree/main/App)

## Montagem
Assim como na parta da programação, inicialmente realizamos todos os testes individuais, de forma a entender o funcionamento dos componentes utilizados. Caso este projeto seja continuado, é de extrema importância o entendimento do funcionamento do carrinho por meio da documentação disponibilizada pelos laboratórios responsáveis por todos os carrinhos disponibilizados pelo IFSC. O teste dos PWMs ocorreram primeiramente com o auxilio de um osciloscópio, onde pudemos verificar o correto funcionamento. Testamos também este acionamento com o auxilio de 4 leds, onde pudemos verificar o correto acionamento de todas as direções desejadas e acionadas pelo controle do usuário.

Antes de conectar todos os componentes ao carrinho, decidimos testar o acionamento do servo motor e do sensor de obstáculo juntamente aos leds na brotoboard, verificando e corrigindo algumas inconsistências do código. Logo após todos os testes, acoplamos todos os componentes ao carrinho. Nesta etapa, realizamos a calibragem dos PWMs, conseguindo acionar corretamente o giro de todas as rodas, de forma a fazê-lo andar em todas as direções conforme desejado e acionado pelo controle do usuário.

Após confirmarmos o funcionamento de todos os componentes integrados, desejamos corrigir um detalhe que poderia nos causar problemas: a utilização de cabos. Para isto, realizamos a confecção de uma placa de circuito impresso, onde pudemos acoplar o ESP32 de forma a realizar todas as conexões com a mínima utilização de cabos jumper necessária. Acoplamos também o conector para o cabo flat do carrinho, o qual se conectá a todas as funcionalidades que o carrinho possui. Infelizmente, passamos por problemas nesta etapa que nos fez abortar a utilização desta PCI na apresentação final do projeto. Os problemas já foram corrigidos no layout da placa projetada, o qual pode ser encontrado [clicando neste link](https://github.com/juliopacheco12/PIN22107/tree/main/PCI), porém não houve tempo hábil para a nova impressão.

Felizmente, apesar de não ter a placa para acoplar os componentes, realizamos a montagem de todos os componentes "a bordo" do carrinho, e o funcionamento de toda a estrutura pode ser confirmado em sala de aula.

![Carrinho](https://github.com/juliopacheco12/PIN22107/blob/main/Imagens/Carrinho%20Vrum%20Vrum.jpeg)

Por fim, devido ao encurtamento do semestre 2022/1, o qual teve menos semanas que um semestre comum no IFSC, visto a necessidade de tornar o calendário acadêmico normal novamente pós pandemia, alguns pontos desejados não puderam ser implementados.
1. Nova placa de circuito impresso;
2. Impressão 3D da haste flexível;
3. Impressão 3D de estrutura de suporte para os componetes para acoplar ao carrinho.

Era de desejo nosso realizar estes três pontos, mas infelizmente não foi possível. Como citado, solucionamos a falta destes pontos da seguinte forma:
1. Estrutura de cabos jumper para conexão entre componentes, validando o caso;
2. Apenas realizando validação do funcionamento servo motor, visto que esta estrutura seria acoplada às hastes giratórias do servo e serviria apenas para "embelezar" o projeto;
3. Acoplar componentes diretamente na estrutura pré existente do carrinho.

## Sugestões para trabalhos futuros
No caso de seguimento deste projeto por algum colega, segue algumas sugestões que podem ser realizadas para aprimorar o projeto:
1. Sanar pontos não implementados citados no tópico anterior;
2. Armazenar dados de utilização;
3. Expor ao usuário dados de utilização do brinquedo;
