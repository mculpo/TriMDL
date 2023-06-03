#include <stdio.h>   // Para opera��es de entrada/sa�da
#include <stdlib.h>  // Para aloca��o de mem�ria din�mica e fun��es auxiliares
#include <string.h>  // Para manipula��o de strings
int main() {

    FILE* arquivo;
    if (fopen_s(&arquivo, "C:/Users/User/Downloads/backpack/backpack.obj", "rb") != 0) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    /*
    * Usamos a fun��o fseek() para posicionar o ponteiro de leitura no final do arquivo usando SEEK_END. Em seguida, utilizamos a fun��o ftell() para obter a posi��o atual do ponteiro, que corresponde ao tamanho total do arquivo em bytes. Armazenamos esse valor em tamanhoArquivo.
      Movemos o ponteiro de leitura novamente para o in�cio do arquivo usando fseek() e SEEK_SET.
    */
    fseek(arquivo, 0, SEEK_END);
    long tamanhoArquivo = ftell(arquivo);
    fseek(arquivo, 0, SEEK_SET);

    // Aloca mem�ria para armazenar o conte�do do arquivo
    char* conteudo = (char*)malloc(tamanhoArquivo + 1);
    if (conteudo == NULL) {
        printf("Erro ao alocar mem�ria.\n");
        fclose(arquivo);
        return 1;
    }

    // L� o conte�do do arquivo em blocos
    size_t bytesLidos = fread(conteudo, 1, tamanhoArquivo, arquivo);
    if (bytesLidos != tamanhoArquivo) {
        printf("Erro ao ler o arquivo.\n");
        free(conteudo);
        fclose(arquivo);
        return 1;
    }

    // Adiciona o terminador de string
    conteudo[tamanhoArquivo] = '\0';

    // Processa o conte�do do arquivo
    printf("%s", conteudo);

    free(conteudo);
    fclose(arquivo);

    return 0;

}