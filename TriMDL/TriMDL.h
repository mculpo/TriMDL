#include <stdio.h>   // Para opera��es de entrada/sa�da
#include <stdlib.h>  // Para aloca��o de mem�ria din�mica e fun��es auxiliares
#include <string.h>  // Para manipula��o de strings
int main() {
    FILE* arquivo = fopen("C:/Users/User/Downloads/backpack/backpack.obj", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // L� o conte�do do arquivo linha por linha
    char linha[256];
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }

    fclose(arquivo);

    return 0;
}