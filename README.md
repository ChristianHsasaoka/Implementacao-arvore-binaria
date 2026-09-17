# 🌳 Árvore Binária de Busca

Implementação de uma **Árvore Binária de Busca (ABB)** em linguagem C, desenvolvida como atividade acadêmica.

## 📌 Sobre o projeto

O programa implementa uma árvore binária de busca seguindo a seguinte regra:

* Valores **menores** que o nó atual são inseridos à **esquerda**.
* Valores **maiores ou iguais** ao nó atual são inseridos à **direita**.

O programa possui as operações de:

* Inserção de elementos;
* Busca de elementos por valor;
* Remoção de elementos por valor;
* Localização do menor elemento da subárvore direita;
* Impressão da árvore em ordem;
* Tratamento de elementos que não são encontrados.

## ⚙️ Estrutura do nó

Cada nó da árvore possui:

```c
typedef struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
} No;
```

Cada nó armazena um valor inteiro e dois ponteiros: um para o filho esquerdo e outro para o filho direito.

## ➕ Inserção

Na inserção, o valor é comparado com o valor do nó atual:

```text
valor menor → esquerda
valor maior ou igual → direita
```

A função utiliza recursão para encontrar a posição correta do novo elemento.

## 🔎 Busca

A busca também utiliza a propriedade da árvore para encontrar o elemento.

Se o valor procurado for menor que o nó atual, a busca continua pela esquerda. Se for maior, continua pela direita.

Caso a busca chegue a `NULL`, significa que o elemento não está presente na árvore.

## 🗑️ Remoção

A remoção considera três situações:

1. **Nó sem filhos:** o nó é removido.
2. **Nó com um filho:** o filho ocupa o lugar do nó removido.
3. **Nó com dois filhos:** é utilizado o **menor elemento da subárvore direita** para substituir o nó removido.

### Exemplo

Antes da remoção:

```text
        50
       /  \
     30    70
    / \    / \
   20 40  60 80
```

Ao remover o `50`, o menor elemento da subárvore direita é o `60`.

Depois:

```text
        60
       /  \
     30    70
    / \     \
   20 40     80
```

## 🖥️ Exemplo de execução

O programa insere os seguintes valores:

```text
50 30 70 20 40 60 80
```

A impressão em ordem resulta em:

```text
20 30 40 50 60 70 80
```

Depois é realizada uma busca pelo valor `40` e uma remoção do valor `50`.

## 🛠️ Como executar

É necessário ter um compilador C, como o **GCC**.

### Compilar

```bash
gcc main.c -o arvore
```

### Executar

No Linux/macOS:

```bash
./arvore
```

No Windows:

```bash
arvore.exe
```

## 📁 Arquivos

```text
📦 arvore-binaria
 └── main.c
```

## 🎓 Atividade acadêmica

**Tema:** Árvore Binária de Busca
**Linguagem:** C
**Operações:** Inserção, busca e remoção

Desenvolvido para fins acadêmicos.
