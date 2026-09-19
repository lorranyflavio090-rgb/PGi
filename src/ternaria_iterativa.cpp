#include <iostream>
#include <vector>
#include <numeric>
#include <chrono>

using namespace std;

int buscaTernariaIterativa(const vector<int>& arr, int esq, int dir, int x) {
    // Executa enquanto houver elementos a serem verificados no intervalo [esq, dir)
    while (esq < dir) {
        // Calcula o tamanho de um terço do intervalo corrente
        int terco = (dir - esq) / 3;

        // Define os dois pontos pivô que particionam o vetor em três partes
        int meio1 = esq + terco;           // Primeiro pivô (fim do primeiro terço)
        int meio2 = dir - 1 - terco;       // Segundo pivô (início do terceiro terço)

        // Caso base 1: elemento encontrado no primeiro ponto pivô
        if (arr[meio1] == x) {
            return meio1;
        }

        // Caso base 2: elemento encontrado no segundo ponto pivô
        if (arr[meio2] == x) {
            return meio2;
        }

        // Se o valor for menor que o pivô 1, descarta os dois terços superiores
        if (x < arr[meio1]) {
            dir = meio1; // Busca no primeiro terço: [esq, meio1)
        } 
        // Se o valor for maior que o pivô 2, descarta os dois terços inferiores
        else if (x > arr[meio2]) {
            esq = meio2 + 1; // Busca no terceiro terço: [meio2 + 1, dir)
        } 
        // Se estiver entre os pivôs 1 e 2, descarta as extremidades
        else {
            esq = meio1 + 1; // Ajusta limite inferior para após meio1
            dir = meio2;     // Ajusta limite superior até meio2 (exclusivo)
        }
    }

    // Retorna -1 se o intervalo se esgotar sem encontrar o elemento
    return -1;
}

int main() {
    const int START_SIZE = 0;
    const int END_SIZE   = 500000;
    const int STEP       = 10000;
    const int TRIALS     = 10;

    // ==========================================
    // 1. MEDICAO DE PIOR CASO (Elemento nao existe)
    // ==========================================
    cout << "=== PIOR CASO (Elemento nao existe) ===\n";
    cout << "Tamanho,Tempo_ns\n";

    for (int size = START_SIZE; size <= END_SIZE; size += STEP) {
        vector<int> arr(size);
        iota(arr.begin(), arr.end(), 1); // Preenche: 1, 2, 3, ..., size

        int alvo_pior = -1; // Valor inexistente
        long long tempo_total = 0;

        for (int t = 0; t < TRIALS; t++) {
            auto inicio = chrono::high_resolution_clock::now();
            
            volatile int res = buscaTernariaIterativa(arr, 0, size, alvo_pior);
            
            auto fim = chrono::high_resolution_clock::now();
            tempo_total += chrono::duration_cast<chrono::nanoseconds>(fim - inicio).count();
        }

        cout << size << "," << (tempo_total / TRIALS) << "\n";
    }

    // ==========================================
    // 2. MEDICAO DE MELHOR CASO (Elemento no primeiro divisor meio1)
    // ==========================================
    cout << "\n=== MELHOR CASO (Elemento no primeiro divisor meio1) ===\n";
    cout << "Tamanho,Tempo_ns\n";

    for (int size = START_SIZE; size <= END_SIZE; size += STEP) {
        vector<int> arr(size);
        iota(arr.begin(), arr.end(), 1);

        // O melhor caso ocorre logo em meio1 = 0 + (size / 3)
        int alvo_melhor = (size > 0) ? arr[size / 3] : -1;
        long long tempo_total = 0;

        for (int t = 0; t < TRIALS; t++) {
            auto inicio = chrono::high_resolution_clock::now();
            
            volatile int res = buscaTernariaIterativa(arr, 0, size, alvo_melhor);
            
            auto fim = chrono::high_resolution_clock::now();
            tempo_total += chrono::duration_cast<chrono::nanoseconds>(fim - inicio).count();
        }

        cout << size << "," << (tempo_total / TRIALS) << "\n";
    }

    return 0;
}
