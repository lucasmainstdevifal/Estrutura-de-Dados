typedef struct ponto Ponto; 

Ponto* criar(int x, int y);

void imprimir(Ponto *p);

void modificarX(Ponto *p, int novox);

void liberar(Ponto *p);