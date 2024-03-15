#include <stdio.h>

int main() {
    int *pti;
    int i = 10;
    pti = &i;
    
    printf("Valor de pti %p\n" ,pti);
    printf("Valor de pti %d\n" ,*pti);
    *pti = 25;
    
    printf("Valor de pti %d\n" ,i);
    printf("Valor endereco de memoria %p\n",pti);
    return 0;
}