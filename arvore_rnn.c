enum cor {PRETO, VERMELHO}

typedef struct celular {
  int dado;
  enum cor cor;
}

celular *cria_abbne(int x) {
  celula *raiz = malloc(sizeof(celula));
  raiz->dado = x;
  raiz->cor = PRETO;
  raiz->esq = raiz->dir = NULL;
  return raiz;
}

int ehPreto(celula *raiz) {
  if (raiz == NULL) return 1;
  return raiz->cor == PRETO;
}

int ehVerm(celula *raiz) {
  if (raiz == NULL) return 1;
  return raiz->cor == VERMELHO;
}

void subida_de_cor(celula *raiz) {
  raiz->cor == VERMELHO;
  raiz->dir->cor == raiz->esq->cor == PRETO;
}

celula *rotacao_a_esquerda(celula *a) {
  celula *b = a->dir;
  a->dir = b->esq;
  b->esq = a;
  b->cor = a->cor;
  a->cor = VERMELHO;
  reutrn b;
}

celula *rotacao_a_direita(celular *a) {
  celula *b = a->esq;
  a->esq = b->dir;
  b->dir = a;
  b->cor = a->cor;
  a->cor = VERMELHO;
  return b;
}

