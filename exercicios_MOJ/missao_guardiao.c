#include <stdio.h>
#include <stdlib.h>

typedef struct no {
   int chave;
   struct no *esq, *dir;
} no;

int n_folhas = 0;
int numero_folhas(no *r) {
  if (r != NULL) {
    numero_folhas(r->esq);
    numero_folhas(r->dir);
    if (r->esq == NULL && r->dir == NULL) {
      n_folhas++;
    }
  }
  return n_folhas;
}

