#include <stdio.h>   // Para operações de entrada/saída
#include <stdlib.h>  // Para alocação de memória dinâmica e funções auxiliares
#include <string.h>  // Para manipulação de strings
int main() {

    FILE* arquivo;
    if (fopen_s(&arquivo, "C:/Users/User/Downloads/backpack/backpack.obj", "rb") != 0) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    /*
    * Usamos a função fseek() para posicionar o ponteiro de leitura no final do arquivo usando SEEK_END. Em seguida, utilizamos a função ftell() para obter a posição atual do ponteiro, que corresponde ao tamanho total do arquivo em bytes. Armazenamos esse valor em tamanhoArquivo.
      Movemos o ponteiro de leitura novamente para o início do arquivo usando fseek() e SEEK_SET.
    */
    fseek(arquivo, 0, SEEK_END);
    long tamanhoArquivo = ftell(arquivo);
    fseek(arquivo, 0, SEEK_SET);

    // Aloca memória para armazenar o conteúdo do arquivo
    char* conteudo = (char*)malloc(tamanhoArquivo + 1);
    if (conteudo == NULL) {
        printf("Erro ao alocar memória.\n");
        fclose(arquivo);
        return 1;
    }

    // Lê o conteúdo do arquivo em blocos
    size_t bytesLidos = fread(conteudo, 1, tamanhoArquivo, arquivo);
    if (bytesLidos != tamanhoArquivo) {
        printf("Erro ao ler o arquivo.\n");
        free(conteudo);
        fclose(arquivo);
        return 1;
    }

    // Adiciona o terminador de string
    conteudo[tamanhoArquivo] = '\0';

    // Processa o conteúdo do arquivo
    printf("%s", conteudo);

    free(conteudo);
    fclose(arquivo);

    return 0;

}