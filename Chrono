int main() {
    // Parametros conforme o slide do professor
    const int START_SIZE = 0;       // Inicio em 0 elementos
    const int END_SIZE   = 500000;  // Limite em 500.000
    const int STEP       = 10000;   // Incremento de 10.000 em 10.000
    const int TRIALS     = 10;      // 10 repeticoes para calcular a media

    // ==========================================
    // 1. MEDICAO DE PIOR CASO
    // ==========================================
    cout << "=== PIOR CASO (Elemento nao existe) ===\n";
    cout << "Tamanho,Tempo_ns\n";

    for (int size = START_SIZE; size <= END_SIZE; size += STEP) {
        vector<int> arr(size, 1);
        int alvo_pior = 0; // Nao existe no vetor (todos sao 1)
        long long tempo_total = 0;

        for (int t = 0; t < TRIALS; t++) {
            auto inicio = chrono::high_resolution_clock::now();
            
            // Chama a sua funcao de busca no intervalo [0, size)
            volatile int res = buscaLinearIterativa(arr, 0, size, alvo_pior);
            
            auto fim = chrono::high_resolution_clock::now();
            tempo_total += chrono::duration_cast<chrono::nanoseconds>(fim - inicio).count();
        }

        cout << size << "," << (tempo_total / TRIALS) << "\n";
    }

    // ==========================================
    // 2. MEDICAO DE MELHOR CASO
    // ==========================================
    cout << "\n=== MELHOR CASO (Elemento no primeiro indice) ===\n";
    cout << "Tamanho,Tempo_ns\n";

    for (int size = START_SIZE; size <= END_SIZE; size += STEP) {
        vector<int> arr(size, 1);
        int alvo_melhor = 1; // Encontrado imediatamente no indice 0
        long long tempo_total = 0;

        for (int t = 0; t < TRIALS; t++) {
            auto inicio = chrono::high_resolution_clock::now();
            
            volatile int res = buscaLinearIterativa(arr, 0, size, alvo_melhor);
            
            auto fim = chrono::high_resolution_clock::now();
            tempo_total += chrono::duration_cast<chrono::nanoseconds>(fim - inicio).count();
        }

        cout << size << "," << (tempo_total / TRIALS) << "\n";
    }

    return 0;
}
