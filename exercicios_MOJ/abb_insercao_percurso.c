#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int dado;
    struct node *esq, *dir;
} node;

node *criar_abb(int n) {
  node *raiz = malloc(sizeof(node));
  raiz->dado = n;
  raiz->esq = raiz->dir = NULL;
  return raiz;
}

node *inserir_node(node *raiz, int x) {
  if (raiz != NULL) {
  if (x < raiz->dado) 
      raiz->esq = inserir_node(raiz->esq, x);
  else if (x > raiz->dado)
      raiz->dir = inserir_node(raiz->dir, x);
    return raiz;
  }
  else
    return criar_abb(x);
}

void preordem(node *raiz) {
  if (raiz != NULL) {
    printf("%d ", raiz->dado);
    preordem(raiz->esq);
    preordem(raiz->dir);
  }
}
void posordem(node *raiz) {
  if (raiz != NULL) {
    posordem(raiz->esq);
    posordem(raiz->dir);
    printf("%d ", raiz->dado);
  }
}
void emordem(node *raiz) {
  if (raiz != NULL) {
    emordem(raiz->esq);
    printf("%d ", raiz->dado);
    emordem(raiz->dir);
  }
}



int main (void) {
  node *arvore;
  int d;
  scanf("%d", &d);
  arvore = criar_abb(d);
  int n;
  while (scanf("%d", &n) != EOF) {
    arvore = inserir_node(arvore, n);
  }
  preordem(arvore); printf(" .\n");
  emordem(arvore); printf(" .\n");
  posordem(arvore); printf(" .\n");
}
