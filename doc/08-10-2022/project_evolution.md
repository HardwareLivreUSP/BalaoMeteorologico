# Descrição dos avanços do projeto

## Compras feitas de equipamentos
A compra de alguns equipamentos foi feita, por meio do aliexpress, os seguintes itens:
- [1x GPS Tracker Model Sinotrack S901](https://pt.aliexpress.com/item/4000966305141.html?spm=a2g0o.order_list.0.0.7e58caa4f9FLp4&gatewayAdapt=glo2bra) - R$ 100,83

- [4x Baloões de Latex (2x 48' e 2x 96')](https://pt.aliexpress.com/item/1005004295540241.html?spm=a2g0o.order_list.0.0.1853caa4N1xVIJ&gatewayAdapt=glo2bra) - R$96,26 / R$244,04

- [1x Paraquedas para sonda meteorologica](https://pt.aliexpress.com/item/32593461662.html?spm=a2g0o.order_list.0.0.1853caa4N1xVIJ&gatewayAdapt=glo2bra) - R$ 254,62

- [Camera SJCAM SJ4000 air](https://pt.aliexpress.com/item/32951167213.html?spm=a2g0o.order_list.0.0.1853caa4N1xVIJ&gatewayAdapt=glo2bra) - R$275,94


### Decisões Tomadas

- Após examinar algumas técnicas de rastreio de balões meteorológicas utilizadas e comparando os diversos protocolos chegamos a conclusão que o de melhor custo beneficio para a técnica é embarcar um rastreador GSM com GPS, o qual envia um "ping" para a base com a respectiva posição sempre que esta dentro da área de cobertura gsm. O principal problema dessa técnica é caso o balão caia em áreas sem cobertura de redes móveis. Para esses casos usaremos o nosso emissor de telemetria via banda UHF com antena direcional para triangular a posição aproximada do balão e assim então conseguirmos possivelmente encontra-lo. 
Técnicas mais avançadas seriam caras e pesadas demais para embarcarmos em nosso payload.


- Para fazer a telemetria do balão foi tomada a decisão por se usar o protocolo LoRa, que apesar de possuir uma banda estreita para envio de dados, possui baixo consumo de energia e longo alcance, em teoria. Outras tecnologias foram levantadas como opção, ao exemplo de protocolos de comunicação entre controle e drones (ELRS, FRsky, REDPINE), no entanto os custos para essas tecnologias serem embarcadas se tornaram inviáveis para a nosso orçamento.

- Os balões escolhidos foram de 48' e 96' polegadas para finalidade de testes e redundancias. Esses balões são de latex, e classicos por serem usados em Balões meteorologicos amadores e de baixo custo. Existem diversos desafios envolvendo esses balões como a falta de padronização no diametro de estouro, peso por balão e até mesmo a garantia de não haver furos. Teremos de tomar diversas medidads para garantir que esses baloes sejam devidamente inflados e protegidos da luz ultra violeta durante o lançamento. Temos por espectativa de fazermos testes usando baloes de heliousados em festas de aniversario para ensaios de empuxo por quantidade de gás.

- O gás helio é uma das principais preocupações levando em consideração que o orçamento do projeto não nos permite a aquisição de grandes quantidades. Fizemos orçamento com empresas que fornecem esse tipo de gás para festas de aniversario e o valor minimo que encontramos para uma carga de 1m³ foi de R$ 410.

- A nossa payload tem que ser mínima para que a quantidade de gás seja reduzida, nesse aspecto levamos em consideração uso de hardwares mínimos. O sistema de paraquedas é apenas colocado em série entre o balao e a payload, para que ele seja ativado pelo arrasto no momento em que o balão cair.


### Considerações a respeito dos gases

Foi levantada a hipótese de se utilizar 2 tipos de gases diferentes para o lançamento do balão, H e He, dada a inflamabilidade e risco de morte que o H pode prover, tomamos a decisão de usar He, apesar do seu custo mais elevado. (Apesar de todas as reuniões repensarmos sobre isso)

### Sobre o microcontrolador

Em nosso projeto usaremos algum microcoontrolador da familia esp ou da familia ARM. Nossas duas opçoes estão entre os ESP32, microcontrolador barato e amplamente encontrável e as placas Pulga do projeto caninos loucos, desenvolvida no Laboratorio CITI da USP.


### Testes feitos 

- Fizemos testes de alcance usando placas esp32 com lora embarcado, no entanto não obtivemos sucesso em ter um longo alcance. Atingimos um maximo de aproximadamente 50m. E estamos estudando as possíveis causas desse problema. Entre as hipóteses estão o baixo poder de transmissão das placas esp com lora nativo, as antenas ou até mesmo alguma limitação por software que tenha nos passado batido.