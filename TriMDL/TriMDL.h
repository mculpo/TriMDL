#include <stdio.h>   // Para operações de entrada/saída
#include <stdlib.h>  // Para alocação de memória dinâmica e funções auxiliares
#include <string.h>  // Para manipulação de strings
int main() {
    FILE* arquivo = fopen("C:/Users/User/Downloads/backpack/backpack.obj", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Lê o conteúdo do arquivo linha por linha
    char linha[256];
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }

    fclose(arquivo);

    return 0;
}