#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int buscaSequencialAlternativaRecursiva(const vector<int>& arr, int esq, int dir, int x) {
    // Caso base 1: intervalo vazio ou inválido (busca esgotada sem sucesso)
    if (esq >= dir) {
        return -1;
    }

    // Caso base 2: elemento encontrado no limite inferior atual
    if (arr[esq] == x) {
        return esq;
    }

    int ultimo = dir - 1; // Converte o limite exclusivo para o último índice válido

    // Caso base 3: intervalo possuía apenas um único elemento e ele não era x
    if (esq == ultimo) {
        return -1;
    }

    // Caso base 4: elemento encontrado no limite superior atual
    if (arr[ultimo] == x) {
        return ultimo;
    }

    // Passo recursivo: estreita o intervalo em ambas as extremidades e continua
    return buscaSequencialAlternativaRecursiva(arr, esq + 1, ultimo, x);
}

    return buscaSequencialAlternativaRecursiva(arr, esq + 1, dir - 1, x);
}

int main() {
    // Limite ajustado para evitar Stack Overflow na recursao linear
    const int START_SIZE = 0;
    const int END_SIZE   = 20000;
    const int STEP       = 1000;
    const int TRIALS     = 10;

    // ==========================================
    // 1. MEDICAO DE PIOR CASO (Elemento nao existe)
    // ==========================================
    cout << "=== PIOR CASO (Elemento nao existe) ===\n";
    cout << "Tamanho,Tempo_ns\n";

    for (int size = START_SIZE; size <= END_SIZE; size += STEP) {
        vector<int> arr(size, 1);
        int alvo_pior = 0; // Elemento inexistente no vetor
        long long tempo_total = 0;

        for (int t = 0; t < TRIALS; t++) {
            auto inicio = chrono::high_resolution_clock::now();
            
            volatile int res = buscaSequencialAlternativaRecursiva(arr, 0, size, alvo_pior);
            
            auto fim = chrono::high_resolution_clock::now();
            tempo_total += chrono::duration_cast<chrono::nanoseconds>(fim - inicio).count();
        }

        cout << size << "," << (tempo_total / TRIALS) << "\n";
    }

    // ==========================================
    // 2. MEDICAO DE MELHOR CASO (Elemento no indice 0)
    // ==========================================
    cout << "\n=== MELHOR CASO (Elemento no primeiro indice) ===\n";
    cout << "Tamanho,Tempo_ns\n";

    for (int size = START_SIZE; size <= END_SIZE; size += STEP) {
        vector<int> arr(size, 1);
        int alvo_melhor = 1; // Encontrado imediatamente na primeira verificacao
        long long tempo_total = 0;

        for (int t = 0; t < TRIALS; t++) {
            auto inicio = chrono::high_resolution_clock::now();
            
            volatile int res = buscaSequencialAlternativaRecursiva(arr, 0, size, alvo_melhor);
            
            auto fim = chrono::high_resolution_clock::now();
            tempo_total += chrono::duration_cast<chrono::nanoseconds>(fim - inicio).count();
        }

        cout << size << "," << (tempo_total / TRIALS) << "\n";
    }

    return 0;
}
