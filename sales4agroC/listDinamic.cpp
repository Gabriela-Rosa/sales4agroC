#include <stdio.h>
#include <malloc.h>
#define ERRO -1
#define true 1
#define false 0

typedef int bool;

typedef int ANUNCIOID;
typedef int TIPO;
typedef char TITULO[15];
typedef char USUARIO[15];

typedef struct{
ANUNCIOID identificador;
TIPO tipo;
TITULO titulo;
USUARIO usuario;
} ANUNCIO;

typedef struct tempRegistro{
  ANUNCIO anuncio;
  struct tempRegistro *prox;
} REGISTRO;

typedef REGISTRO* PONT;

typedef struct {
  PONT inicio;
} LISTA;


void inicializarLista(LISTA *l){
  l->inicio = NULL;
}

void exibirLista(LISTA *l){
  PONT end = l->inicio;
  printf("Anuncios: \" ");
  while (end != NULL){
    printf("%d ", end->anuncio); 
    end = end->prox;
  }
  printf("\"\n");
}


int tamanho(LISTA *l) {
  PONT end = l->inicio;
  int tam = 0;
  while (end != NULL){
    tam++;
    end = end->prox;
  }
  return tam;
} 

int tamanhoEmBytes(LISTA *l) {
  return(tamanho(l) * sizeof(REGISTRO)) + sizeof(LISTA); 
}

PONT buscaSeq(ANUNCIO an, LISTA *l){
  PONT pos = l->inicio;
  while (pos != NULL){
    if (pos->anuncio == an) {
      return pos;
    }
    pos = pos->prox;
  }
  return NULL;
}


PONT buscaSeqExc(ANUNCIO an, LISTA *l, PONT *ant){
  *ant = NULL;
  PONT pos = l->inicio;
  while ((pos != NULL) && (pos->anuncio<an)){
    *ant = pos;
    pos = pos->prox;
  }
  if ((pos != NULL) && (pos->anuncio == an)) {
           return pos;
  }
  return NULL;
} 

bool excluirElemLista(ANUNCIO an, LISTA *l){
  PONT ant, i;
  i = buscaSeqExc(an, l, &ant);
  if (i == NULL) {
    return false;
  }
  if (ant == NULL) {
    l->inicio = i->prox;
  }
  else { 
    ant->prox = i->prox;
  }
  free(i);
  return true;
} 

void destruirLista(LISTA *l) {
  PONT end = l->inicio;
  while (end != NULL){
    PONT apagar = end;
    end = end->prox;
    free(apagar);
  }
  l->inicio = NULL;
} 








bool inserirElemListaOrd(REGISTRO reg, LISTA *l) {
  ANUNCIO an = reg.chave;
  PONT ant, i;
  i = buscaSeqExc(an, l, &ant);
  if (i != NULL)  {
    return false;
  }
  i = (PONT) malloc(sizeof(REGISTRO));
  *i = reg;
  if (ant == NULL) { 
    i->prox = l->inicio;
    l->inicio = i;
  } else {  
    i->prox = ant->prox;
    ant->prox = i;
  }  
  return true;
} 





PONT retornarPrimeiro(LISTA *l, ANUNCIO *an){
  if (l->inicio != NULL) {
    *ch = l->inicio->anuncio;
  }
  return l->inicio;
}






PONT retornarUltimo(LISTA *l, ANUNCIO *an){
  PONT ultimo = l->inicio;
  if (l->inicio == NULL) {
    return NULL;
  }
  while (ultimo->prox != NULL) {
    ultimo = ultimo->prox;
  }
  *ch = ultimo->anuncio;
  return ultimo;
} 
