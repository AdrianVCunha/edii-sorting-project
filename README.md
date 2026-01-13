## Descrição do Projeto

Este repositório contém a implementação de diversos **algoritmos de ordenação** em C, com foco em análise de desempenho, como parte da disciplina **Estruturas de Dados II (COM10078)** da **UFES**.

### Algoritmos implementados
    *Bubble sort

### Métricas de Desempenho ###

Para possibilitar a comparação entre os algoritmos, foi definida a estrutura Metrics, responsável por armazenar as métricas coletadas durante a execução de cada algoritmo:

Número de comparações realizadas entre elementos;

Número de trocas efetuadas;

Tempo de execução, em segundos.

A inicialização, reinicialização e impressão das métricas são realizadas por meio de um módulo específico (metrics), garantindo padronização e evitando duplicação de código. A contagem de comparações e trocas é feita diretamente dentro de cada algoritmo de ordenação, enquanto a medição do tempo de execução é realizada externamente, no programa principal.

### Tempo de execução ###

O tempo de execução dos algoritmos é medido no programa principal, de forma externa às implementações dos algoritmos, garantindo que todos sejam avaliados sob as mesmas condições.

A medição é realizada utilizando a função clock(), da biblioteca padrão <time.h>, que contabiliza o tempo de CPU consumido durante a execução do algoritmo. O tempo é obtido pela diferença entre duas chamadas à função clock(), realizadas imediatamente antes e após a execução do algoritmo.

O valor obtido, expresso em ticks de CPU, é convertido para segundos por meio da divisão pela constante CLOCKS_PER_SEC, sendo armazenado na estrutura Metrics associada a cada execução.

Essa abordagem permite uma comparação justa e padronizada do desempenho temporal entre os diferentes algoritmos implementado

### Organização do Projeto ###

O projeto foi estruturado de forma modular, separando claramente interface e implementação, bem como os diferentes domínios do sistema:

include/

     algorithms/   # Cabeçalhos dos algoritmos de ordenação
     metrics/      # Estrutura e funções relacionadas às métricas

src/

    algorithms/   # Implementações dos algoritmos de ordenação
    utils/        # Implementações das funções utilitárias
    metrics/      # Implementação do módulo de métricas
    main.c        # Programa principal (execução e coleta de dados)