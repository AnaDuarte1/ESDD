#include <stdio.h>

int main(){
    int candidatos;
    int aux = 0;

    int c;

    scanf("%d", &c);

    for(int i = 0; i < c; i++){
        scanf("%d", &candidatos);

        if(candidatos == 1){
            aux++;
        }
    }

    printf("%d\n", aux);
}