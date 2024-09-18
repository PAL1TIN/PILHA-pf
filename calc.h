
struct no {
    float info;
    struct no* prox;
};
typedef struct no No;

typedef struct{
    No* prim;
}Pilha;

typedef struct{
    char f[21];
    Pilha* p;
}Calc;


Calc* cria_calc (char* f);
void operando (Calc* c, float v);
void operador (Calc* c, char op);
void libera_calc (Calc* c);
