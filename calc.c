#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"


Pilha* cria (){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->prim = NULL;

    return p;
}

No* ins_ini (No* l, float v){
    No* p = (No*) malloc(sizeof(No));
    p->info = v;
    p->prox = l;

 return p;
}


No* ret_ini (No* l){
    No* p = l->prox;
    free(l);

  return p;
}


void push (Pilha* p, float v){
    p->prim = ins_ini(p->prim,v);
}

int vazia (Pilha* p){
  return (p->prim==NULL);
}

float pop (Pilha* p){
    float v;
    if (vazia(p)) {
        printf("Pilha vazia.\n");
        exit(1);
    }
    v = p->prim->info;
    p->prim = ret_ini(p->prim);
    return v;
}

void libera (Pilha* p){
    No* q = p->prim;

    while (q!=NULL) {
        No* t = q->prox;
        free(q);
        q = t;
    }

 free(p);
}

Calc* cria_calc (char* formato){
    Calc* c = (Calc*) malloc(sizeof(Calc));
    strcpy(c->f,formato);
    c->p = cria();
  return c;
}


void operando (Calc* c, float v)
{
    push(c->p,v);
    printf(c->f,v);
}


void operador (Calc* c, char op){
  float v1, v2, v, x;


  if (vazia(c->p)){

    v2 = 0.0;
  }else{

    v2 = pop(c->p);
  }
  if (vazia(c->p)){
    v1 = 0.0;
  }
  else{
    v1 = pop(c->p);




  switch (op) {
    case '+': v = v1+v2;
    break;
    case '-': v = v1-v2;
    break;
    case '*': v = v1*v2;
    break;
    case '/': v = v1/v2;
    break;
    case '^': v = pow(v1, v2);//funcao de math.h para exponenciacao
    break;
    case '&': v = v1 + sqrt(v2);//funcao para raiz
    break;
    }

  push(c->p,v);
  printf(c->f,v);
    }
}

void libera_calc (Calc* c){
    libera(c->p);
    free(c);
}

