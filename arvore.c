#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  int dado;
  struct celula *esq, *dir;
} celula;

//se quiser passar a raiz direto a funcao fica void
celula *criar_arvore(int n) {
  celula *raiz = malloc(sizeof(celula));
  raiz->dado = n;
  raiz->esq = raiz->dir = NULL;
  return raiz;
};

celula *inserir_folha(celula *raiz, int dado) {
  if (raiz != NULL) {
    if (dado < raiz->dado) 
      raiz->esq = inserir_folha(raiz->esq, dado);
    else if (dado > raiz->dado)
      raiz->dir = inserir_folha(raiz->dir, dado);
    return raiz;
  }
  else {
    return criar_arvore(dado);
  }
}

int altura(celula *raiz) {
  if (raiz == NULL) {
    return -1;
  }

  int he = altura(raiz->esq);
  int hd = altura(raiz->dir);

  if (he > hd) return he+1;
    else return hd+1;
  return -1;
}

celula *remover(celula *raiz, int x) {
  if (raiz == NULL)
    return NULL;                      // x não tá na árvore

  if (x < raiz->dado)
    raiz->esq = remover(raiz->esq, x);
  else if (x > raiz->dado)
    raiz->dir = remover(raiz->dir, x);
  else {                              // achou
    if (raiz->esq == NULL) {          // caso 1 (inclui folha)
      celula *p = raiz->dir;
      free(raiz);
      return p;
    }
    else if (raiz->dir == NULL) {     // caso 2
      celula *p = raiz->esq;
      free(raiz);
      return p;
    }
    else {                            // caso 3: dois filhos
      celula *p = raiz;               // pai do sucessor
      celula *s = raiz->dir;          // sucessor
      while (s->esq != NULL) {
        p = s;
        s = s->esq;
      }
      raiz->dado = s->dado;
      if (s == p->esq)
        p->esq = s->dir;
      else
        p->dir = s->dir;
      free(s);
    }
  }
  return raiz;
}

int n = 0;
int soma_folha(celula *raiz) {
  if (raiz != NULL) {
    soma_folha(raiz->esq);
    soma_folha(raiz->dir);
    if (raiz->esq == NULL && raiz->dir == NULL) {
      n++;
    }
  }
  return n;
}

int soma_folha_recursao(celula *raiz) {
  if (raiz == NULL)
    return 0;
  if (raiz->esq == NULL && raiz->dir == NULL) {
    return 1;
  }
  int esq = soma_folha_recursao(raiz->esq);
  int dir = soma_folha_recursao(raiz->dir);

  return esq + dir;
}

void preordem(celula *raiz) {
  if (raiz != NULL) {
    printf("%d ", raiz->dado);
    preordem(raiz->esq);
    preordem(raiz->dir);
  }
}

void emordem(celula *raiz) {
  if (raiz != NULL) {
    emordem(raiz->esq);
    printf("%d ", raiz->dado);
    emordem(raiz->dir);
  }
}

void posordem(celula *raiz) {
  if (raiz != NULL) {
    posordem(raiz->esq);
    posordem(raiz->dir);
    printf("%d ", raiz->dado);
  }
}
/* depois implementar fila/pilha e fazer iterativamente as funcoes de pos/em/pre ordem q seria mais ou menos assim:
void largura (celula *raiz) {
  fila *f = cria_fila(f);
  enfileira(f, raiz);
  while (!fila_vazia(f)) {
    raiz = desempilha(f);
    printf("%d", raiz -> dado);
    if (raiz ->esq != NULL) enfileira (f, raiz->esq);
    if (raiz ->dir != NULL) enfileira (f, raiz->dir);
  }
  destroi_fila(f);
}
*/

int main(int argc, char *argv[])
{
  celula *arvre = criar_arvore(4);
  arvre = inserir_folha(arvre, 2);
  arvre = inserir_folha(arvre, 1);
  arvre = inserir_folha(arvre, 3);
  arvre = inserir_folha(arvre, 7);
  arvre = inserir_folha(arvre, 6);
  arvre = inserir_folha(arvre, 9);

  printf("preordem: \n");
  preordem(arvre);
  printf("\nem ordem:\n");
  emordem(arvre);
  printf("\nposordem:\n");
  posordem(arvre);
  printf("\n");
  printf("folhas: %d\n", soma_folha(arvre));
  printf("\n");
  printf("folhas recursao: %d\n", soma_folha_recursao(arvre));
  printf("altura : %d\n", altura(arvre));
  /*
  printf("dado: %d\n", arvre->dado);
  printf("dado esq: %d\n", arvre->esq->dado);
  printf("dado esq esq: %d\n", arvre->esq->esq->dado);
  printf("NULL: %p\n", &arvre->esq->esq->esq->dado);
  printf("ponteiro esq: %p\n", arvre->esq);
  printf("ponteiro dir: %p\n", arvre->dir);
*/
}
