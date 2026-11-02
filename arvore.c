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
  /*
  printf("dado: %d\n", arvre->dado);
  printf("dado esq: %d\n", arvre->esq->dado);
  printf("dado esq esq: %d\n", arvre->esq->esq->dado);
  printf("NULL: %p\n", &arvre->esq->esq->esq->dado);
  printf("ponteiro esq: %p\n", arvre->esq);
  printf("ponteiro dir: %p\n", arvre->dir);
*/
}
