#include <iostream>
#include <vector>
#include <numeric>
#include <chrono>

using namespace std;

/**
 * Realiza a busca binária de forma iterativa em um vetor previamente ordenado.
 * 
 * @param arr Vetor de inteiros passado por referência constante (sem cópia de dados).
 * @param esq Índice inicial do intervalo de busca (inclusivo).
 * @param dir Índice final do intervalo de busca (exclusivo: tamanho do vetor).
 * @param x   Elemento procurado.
 * @return    O índice do elemento no vetor se encontrado; caso contrário, retorna -1.
 */
int buscaBinariaIterativa(const vector<int>& arr, int esq, int dir, int x) {
    // Executa enquanto houver pelo menos um elemento no intervalo [esq, dir)
    while (esq < dir) {
        // Calcula o índice do meio prevenindo possível overflow aritmético
        int meio = esq + (dir - esq) / 2;

        // Caso base de sucesso: elemento encontrado no ponto central
        if (arr[meio] == x) {
            return meio; // Retorna o índice onde o elemento foi localizado
        }
        
        // Se o valor procurado for menor, ele só pode estar na metade esquerda
        if (x < arr[meio]) {
            dir = meio;     // Ajusta o limite superior para descartar a metade direita
        } 
        // Se o valor procurado for maior, ele só pode estar na metade direita
        else {
            esq = meio + 1; // Ajusta o limite inferior para descartar a metade esquerda
        }
    }

    // Se o laço terminar e os limites se cruzarem, o elemento não está no vetor
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
            
            volatile int res = buscaBinariaIterativa(arr, 0, size, alvo_pior);
            
            auto fim = chrono::high_resolution_clock::now();
            tempo_total += chrono::duration_cast<chrono::nanoseconds>(fim - inicio).count();
        }

        cout << size << "," << (tempo_total / TRIALS) << "\n";
    }

    // ==========================================
    // 2. MEDICAO DE MELHOR CASO (Elemento no meio exato)
    // ==========================================
    cout << "\n=== MELHOR CASO (Elemento no meio exato) ===\n";
    cout << "Tamanho,Tempo_ns\n";

    for (int size = START_SIZE; size <= END_SIZE; size += STEP) {
        vector<int> arr(size);
        iota(arr.begin(), arr.end(), 1);

        // O melhor caso da busca binaria e o elemento central da primeira comparacao
        int alvo_melhor = (size > 0) ? arr[size / 2] : -1;
        long long tempo_total = 0;

        for (int t = 0; t < TRIALS; t++) {
            auto inicio = chrono::high_resolution_clock::now();
            
            volatile int res = buscaBinariaIterativa(arr, 0, size, alvo_melhor);
            
            auto fim = chrono::high_resolution_clock::now();
            tempo_total += chrono::duration_cast<chrono::nanoseconds>(fim - inicio).count();
        }

        cout << size << "," << (tempo_total / TRIALS) << "\n";
    }

    return 0;
}
