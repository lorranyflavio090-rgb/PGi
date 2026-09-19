#include <iostream>
#include <vector>
#include <numeric>
#include <chrono>

using namespace std;

int buscaTernariaRecursiva(const vector<int>& arr, int esq, int dir, int x) {
    // Caso base 1: Se o intervalo for vazio ou invalido (esq >= dir), elemento nao existe
    if (esq >= dir) {
        return -1;
    }

    // Divide o intervalo atual em tres partes
    int terco = (dir - esq) / 3;

    // Calcula os dois indices divisores
    int meio1 = esq + terco;
    int meio2 = dir - 1 - terco;

    // Caso base 2: Elemento encontrado no primeiro divisor
    if (arr[meio1] == x) {
        return meio1;
    }

    // Caso base 3: Elemento encontrado no segundo divisor
    if (arr[meio2] == x) {
        return meio2;
    }

    // Caso recursivo 1: O alvo e menor que arr[meio1] -> busca em [esq, meio1)
    if (x < arr[meio1]) {
        return buscaTernariaRecursiva(arr, esq, meio1, x);
    }

    // Caso recursivo 2: O alvo e maior que arr[meio2] -> busca em [meio2 + 1, dir)
    if (x > arr[meio2]) {
        return buscaTernariaRecursiva(arr, meio2 + 1, dir, x);
    }

    // Caso recursivo 3: O alvo esta entre arr[meio1] e arr[meio2] -> busca em [meio1 + 1, meio2)
    return buscaTernariaRecursiva(arr, meio1 + 1, meio2, x);
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
        iota(arr.begin(), arr.end(), 1); // Preenche de 1 ate size

        int alvo_pior = -1; // Inexistente
        long long tempo_total = 0;

        for (int t = 0; t < TRIALS; t++) {
            auto inicio = chrono::high_resolution_clock::now();
            
            volatile int res = buscaTernariaRecursiva(arr, 0, size, alvo_pior);
            
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
            
            volatile int res = buscaTernariaRecursiva(arr, 0, size, alvo_melhor);
            
            auto fim = chrono::high_resolution_clock::now();
            tempo_total += chrono::duration_cast<chrono::nanoseconds>(fim - inicio).count();
        }

        cout << size << "," << (tempo_total / TRIALS) << "\n";
    }

    return 0;
}
