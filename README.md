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

## Análise Descritiva: Linha de Base Histórica (1997 vs 2023)

Comparação dos extremos do período geracional analisado (1997–2023) para as principais variáveis estruturais demográficas.

| Indicador | Região | 1997 | 2023 | Variação Absoluta | Variação Relativa (%) |
| :--- | :--- | :---: | :---: | :---: | :---: |
| **População Total** *(TPopulation1July)* | América Central | 131,4 mi | 182,1 mi | +50,7 milhões | +38,6% |
| | América do Sul | 332,6 mi | 432,6 mi | +100,0 milhões | +30,1% |
| **Taxa de Crescimento** *(PopGrowthRate)* | América Central | 1,76% a.a. | 1,00% a.a. | -0,77 p.p. | -43,6% |
| | América do Sul | 1,56% a.a. | 0,60% a.a. | -0,95 p.p. | -61,2% |
| **Idade Mediana** *(MedianAgePop)* | América Central | 20,1 anos | 27,8 anos | +7,7 anos | +38,3% |
| | América do Sul | 23,0 anos | 32,3 anos | +9,3 anos | +40,4% |

