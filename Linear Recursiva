#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

// Busca Linear Recursiva no intervalo semiaberto [esq, dir)
int buscaLinearRecursiva(int arr[], int esq, int dir, int x) {
    if (esq >= dir) {
        return -1;
    }
    if (arr[esq] == x) {
        return esq;
    }
    return buscaLinearRecursiva(arr, esq + 1, dir, x);
}

int main() {
    // Para evitar Stack Overflow na recursão linear simples, testamos até 20.000
    const int START_SIZE = 0;
    const int END_SIZE   = 20000;
    const int STEP       = 1000;
    const int TRIALS     = 10;

    cout << "=== PIOR CASO (Elemento nao existe) ===\n";
    cout << "Tamanho,Tempo_ns\n";

    for (int size = START_SIZE; size <= END_SIZE; size += STEP) {
        vector<int> arr(size, 1);
        int alvo_pior = 0;
        long long tempo_total = 0;

        for (int t = 0; t < TRIALS; t++) {
            auto inicio = chrono::high_resolution_clock::now();
            volatile int res = buscaLinearRecursiva(arr.data(), 0, size, alvo_pior);
            auto fim = chrono::high_resolution_clock::now();
            tempo_total += chrono::duration_cast<chrono::nanoseconds>(fim - inicio).count();
        }
        cout << size << "," << (tempo_total / TRIALS) << "\n";
    }

    cout << "\n=== MELHOR CASO (Elemento no primeiro indice) ===\n";
    cout << "Tamanho,Tempo_ns\n";

    for (int size = START_SIZE; size <= END_SIZE; size += STEP) {
        vector<int> arr(size, 1);
        int alvo_melhor = 1;
        long long tempo_total = 0;

        for (int t = 0; t < TRIALS; t++) {
            auto inicio = chrono::high_resolution_clock::now();
            volatile int res = buscaLinearRecursiva(arr.data(), 0, size, alvo_melhor);
            auto fim = chrono::high_resolution_clock::now();
            tempo_total += chrono::duration_cast<chrono::nanoseconds>(fim - inicio).count();
        }
        cout << size << "," << (tempo_total / TRIALS) << "\n";
    }

    return 0;
}
