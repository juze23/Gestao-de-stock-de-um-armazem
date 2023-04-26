#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *fp = NULL;
    char buffer[2048];

    fp = fopen("produtos.dat", "rb");
    if(fp == NULL){

        printf("Erro ao abrir o ficheiro");
        exit(-1);
    }

    while (fread(&buffer, sizeof(buffer), 1, fp)) {
        printf("%s", buffer);
        
    }

    fclose(fp);

    return 0;
}