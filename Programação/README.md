# Repositorio de codigos e configurações

Todos os codigos foram gerados tendo como alvo o microcontrolador ESP32. Os arquivos principais se encontram na pasta Main e estão dividiso da seguinte forma:
Main - arquivo principal.
servomotor.c/.h - inicialição do motor, configuração dos parametros necessários e a função para ele seja ativado.
sensor.c/.h     - inicialição do sensor, configuração dos parametros necessários e uma função para detectar o obstaculo e ativar o motor.
bt.c/.h         - repositorio de codigos relacionados ao bluetooth. E nele tambem onde a informação enviada pelo aplicativo e recebida e então ele chama a função
                  desejada pelo usuario, como se movimentar ou ativar o motor. Na linha 377 do bt.c e possível ver quando o evento de escrita e ativado e como é
                  feita a comparação para que a função correta seja chamada. 
