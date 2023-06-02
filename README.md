# TriMDL (Tridimensional Mesh Data Loader)
# TriMDL (Carregador de Dados de Malhas Tridimensionais)

TriMDL é uma biblioteca leve em C projetada para importar e carregar dados de malhas tridimensionais de softwares populares de modelagem 3D, como Blender, Maya e outros. Ela fornece uma forma simples e eficiente de analisar e extrair posições de vértices, coordenadas de textura, normais e índices de faces de arquivos de modelos 3D.

## Recursos

- Suporta formatos de arquivo comuns de modelos 3D, como OBJ.
- Analisa posições de vértices, coordenadas de textura, normais e índices de faces.
- Fornece uma interface amigável para acessar e manipular os dados da malha importada.
- Projetada para ser leve e eficiente, adequada para aplicativos em tempo real.
- Compatibilidade multiplataforma para integração fácil em vários projetos.


## Uso

Inclua o arquivo de cabeçalho da biblioteca TriMDL em seu projeto:

```c
#include "TriMDL.h"
```


Inicialize um objeto TriMDL e carregue o arquivo do modelo 3D:

```c
TriMDL* modelo = TriMDL_Criar();
if (TriMDL_Carregar(modelo, "modelo.obj") != TRI_MDL_SUCESSO) {
    // Tratar erro
}
```

Acesse os dados da malha:

```c
// Obtenha o número de vértices na malha
int numVertices = TriMDL_ObterNumVertices(modelo);

// Acesse vértices individuais
for (int i = 0; i < numVertices; ++i) {
    TriMDL_Vertice vertice = TriMDL_ObterVertice(modelo, i);
    // Processe os dados do vértice (posição, coordenadas de textura, normais, etc.)
}

// Acesse os índices das faces
int numFaces = TriMDL_ObterNumFaces(modelo);
for (int i = 0; i < numFaces; ++i) {
    TriMDL_Face face = TriMDL_ObterFace(modelo, i);
    // Processe os índices das faces
}

// Libere recursos e finalize
TriMDL_Destruir(modelo);
```

Para instruções de uso mais detalhadas e exemplos, consulte a documentação.

## Dependências

TriMDL não possui dependências externas, facilitando sua integração em seus projetos sem se preocupar com dependências adicionais.

## Contribuições

Contribuições para o TriMDL são bem-vindas! Se você encontrar problemas ou tiver sugestões de melhorias, sinta-se à vontade para abrir uma issue ou enviar uma pull request no repositório do projeto no GitHub.

## Licença

TriMDL é lançado sob a Licença Apache-2.0. Você tem permissão para usar, modificar e distribuir a biblioteca tanto para fins comerciais quanto não comerciais.

## Reconhecimentos

TriMDL foi inspirado pela necessidade e estudo de uma biblioteca simples e eficiente para carregar dados de malhas tridimensionais em C.

## Base de Dados para Implementação

https://docs.blender.org/manual/pt/2.79/addons/io_obj.html

