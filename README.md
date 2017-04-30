# b16-lab

O projeto visa reforçar aspectos da programação estruturada e orientada a objetos. Os exemplos usados nesse projeto são de simulações de experimentos físicos da mecânica clássica.

Para compilar e rodar o aplicativo corretamente se faz necessária a instalação das bibliotecas "lglut" e "lGL".

**Versão do C++**
g++ (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609
Copyright (C) 2015 Free Software Foundation, Inc.

**Compilação:**
1. g++ -Wall -std=c++11 -c ball.cpp
2. g++ -Wall -std=c++11 -o test-ball test-ball.cpp ball.o

**Arquivos**

1. test-ball.cpp
    * Contém função main().
2. simulation.h
    * Declaração da classe virtual herdadas pela classe ball.
3. ball.h
    * Declaração de métodos e atributos de uma instância da classe ball.
4. ball.cpp
    * Implementação de métodos declarados em ball.h.


**Saída do programa**

0.51 0.491222

0.52 0.471556

0.53 0.441

0.54 0.399556

0.55 0.347222

0.56 0.284

0.57 0.209889

0.58 0.124889

0.59 0.029

0.6 -0.0777778

0.61 -0.195444

0.62 -0.324

0.63 -0.463444

0.64 -0.613778

0.65 -0.775

0.66 -0.775

0.67 -0.613778

0.68 -0.463444

0.69 -0.324

0.7 -0.195444

0.71 -0.0777778

0.72 0.029

0.73 0.124889

0.74 0.209889

0.75 0.284

0.76 0.347222

0.77 0.399556

0.78 0.441

0.79 0.471556

0.8 0.491222

0.81 0.5

0.82 0.497889

0.83 0.484889

0.84 0.461

0.85 0.426222

0.86 0.380556

0.87 0.324

0.88 0.256556

0.89 0.178222

0.89 0.089

0.88 -0.0111111

0.87 -0.122111

0.86 -0.244

0.85 -0.376778

0.84 -0.520444

0.83 -0.675

0.82 -0.840444

0.81 -0.840444

0.8 -0.675

0.79 -0.520444

0.78 -0.376778

0.77 -0.244

0.76 -0.122111

0.75 -0.0111111

0.74 0.089

0.73 0.178222

0.72 0.256556

0.71 0.324

0.7 0.380556

0.69 0.426222

0.68 0.461

0.67 0.484889

0.66 0.497889

0.65 0.5

0.64 0.491222

0.63 0.471556

0.62 0.441

0.61 0.399556

0.6 0.347222

0.59 0.284

0.58 0.209889

0.57 0.124889

0.56 0.029

0.55 -0.0777778

0.54 -0.195444

0.53 -0.324

0.52 -0.463444

0.51 -0.613778

0.5 -0.775

0.49 -0.775

0.48 -0.613778

0.47 -0.463444

0.46 -0.324

0.45 -0.195444

0.44 -0.0777778

0.43 0.029

0.42 0.124889

0.41 0.209889

0.4 0.284

0.39 0.347222

0.38 0.399556

0.37 0.441

0.36 0.471556

0.35 0.491222

0.34 0.5

0.33 0.497889

0.32 0.484889

0.31 0.461

0.3 0.426222

0.29 0.380556

![graph](https://github.com/danilodelyima/b16-lab/blob/master/graphic.png "Ball Graphic")
