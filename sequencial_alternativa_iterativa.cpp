#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int buscaAlternativaIterativa(int arr[], int esq, int dir, int x) {
    int inicio = esq;
    int fim = dir - 1;

    while (inicio <= fim) {
        if (arr[inicio] == x) return inicio;
        if (arr[fim] == x) return fim;
        inicio++;
        fim--;
    }
    return -1;
}

int main() {
    const int START_SIZE = 0;
    const int END_SIZE   = 500000;
    const int STEP       = 10000;
    const int TRIALS     = 10;

    cout << "=== PIOR CASO (Elemento nao existe) ===\n";
    cout << "Tamanho,Tempo_ns\n";

    for (int size = START_SIZE; size <= END_SIZE; size += STEP) {
        vector<int> arr(size, 1);
        int alvo_pior = 0;
        long long tempo_total = 0;

        for (int t = 0; t < TRIALS; t++) {
            auto inicio = chrono::high_resolution_clock::now();
            volatile int res = buscaAlternativaIterativa(arr.data(), 0, size, alvo_pior);
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
            volatile int res = buscaAlternativaIterativa(arr.data(), 0, size, alvo_melhor);
            auto fim = chrono::high_resolution_clock::now();
            tempo_total += chrono::duration_cast<chrono::nanoseconds>(fim - inicio).count();
        }
        cout << size << "," << (tempo_total / TRIALS) << "\n";
    }

    return 0;
}
