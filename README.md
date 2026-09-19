# Análise Empírica de Algoritmos de Busca

Este repositório contém a implementação e a análise empírica de desempenho de 8 algoritmos de busca em C++, avaliados no cenário de pior caso (busca por elemento inexistente no vetor).

## Estrutura do Repositório

```
├── dados/
│   └── piores_casos.txt       # Medições empíricas em nanossegundos
├── gráficos/
│   ├── comparacao_lineares.png
│   ├── comparacao_logaritmicas.png
│   └── ...                    # Gráficos individuais dos exercícios
├── src/
│   ├── binaria_iterativa.cpp
│   ├── binaria_recursiva.cpp
│   ├── linear_iterativa.cpp
│   ├── linear_recursiva.cpp
│   ├── sequencial_alternativa_iterativa.cpp
│   ├── sequencial_alternativa_recursiva.cpp
│   ├── ternaria_iterativa.cpp
│   ├── ternaria_recursiva.cpp
│   └── Chrono.cpp             # Módulo de suporte para medição de tempo
└── README.md

```

## Algoritmos Avaliados

1. **Busca Linear Iterativa** —  *(avaliada até* $N = 500.000$*)*

2. **Busca Linear Recursiva** —  *(avaliada até* $N = 20.000$*)*

3. **Busca Sequencial Alternativa Iterativa** —  *(avaliada até* $N = 500.000$*)*

4. **Busca Sequencial Alternativa Recursiva** — *(avaliada até* $N = 20.000$*)*

5. **Busca Binária Iterativa** —  *(avaliada até* $N = 500.000$*)*

6. **Busca Binária Recursiva** —  *(avaliada até* $N = 500.000$*)*

7. **Busca Ternária Iterativa** —  *(avaliada até* $N = 500.000$*)*

8. **Busca Ternária Recursiva** —  *(avaliada até* $N = 500.000$*)*

## Instruções de Compilação e Execução

### Requisitos

* Compilador C++ com suporte a C++11 ou superior (`g++`).

### Compilação

A rotina de temporização (`Chrono`) já se encontra integrada em cada arquivo de código-fonte. A compilação deve ser realizada com a flag `-O0`, garantindo que o compilador não elimine laços ou código ocioso e preservando a fidelidade da medição empírica.

A partir da raiz do repositório, execute no terminal:

```
g++ -std=c++11 -O0 src/linear_iterativa.cpp -o busca

```

*(Substitua `src/linear_iterativa.cpp` pelo arquivo do algoritmo que deseja compilar).*

### Execução

Após a compilação, execute o binário gerado:

```
./busca

```

## Notas Metodológicas

* **Limite da Recursão Linear:** Os algoritmos lineares recursivos operam em profundidade de pilha proporcional a $N$. Por essa razão, foram limitados a $N = 20.000$ para prevenir transbordamento de pilha.
