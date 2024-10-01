#include <stdio.h>

void exibe(int a);


int main(){
    int a = 10; // Variavel Local
    exibe(a);
    return (0);
}

void exibe(int a){
    printf("A: %d\n", a);
}