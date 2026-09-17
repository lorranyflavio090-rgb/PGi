#include <iostream>

using namespace std;

// Funcao de busca linear no intervalo semiaberto [esq, dir)
int buscaLinearIterativa(int arr[], int esq, int dir, int x) {
    // Percorre do indice esq ate antes de dir
    for (int i = esq; i < dir; i++) {
        // Se encontrar o valor, retorna a posicao imediatamente
        if (arr[i] == x) {
            return i;
        }
    }
    // Retorna -1 caso o elemento nao esteja no intervalo
    return -1;
}

int main() {
    int n, x;
    int arr[7500]; // Vetor estatico suficiente para ate 3000 elementos

    // 1. Le o tamanho N e o elemento procurado X direto do arquivo[cite: 1]
    if (!(cin >> n >> x)) {
        return 0;
    }

    // 2. Preenche o vetor com os N elementos informados[cite: 1]
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 3. Executa a busca linear no intervalo semiaberto [0, n)[cite: 1]
    int resultado = buscaLinearIterativa(arr, 0, n, x);

    // 4. Exibe a saida
    if (resultado != -1) {
        cout << "Elemento encontrado no indice: " << resultado << endl;
    } else {
        cout << "Elemento nao encontrado" << endl;
    }

    return 0;
}
