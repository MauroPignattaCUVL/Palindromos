#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "includes/palindromo.h"

#define LONG_TEXT 256

int main(int argc, char** argv) {

    //crea archivo donde guardar los palindromos
    FILE *ptrFile = NULL;
    ptrFile = fopen("palindromos.txt","w+");
    
    char *texto = calloc(LONG_TEXT + 1,1);
    //Comprueba que se haya asignado la memoria
    if (texto == NULL)
    {
        printf("No se pudo asignar memoria");
        exit(EXIT_FAILURE);
    }
    //pide el texto donde buscar los palindromos
    printf("Ingrese texto: ");
    gets(texto);
    
    //cuenta cant de palindromos y los guarda en el archivo
    int cantPalindromos = buscarPalindromos(texto, ptrFile);
    
    //situa el cursor al principio del archivo
    rewind(ptrFile);
    
    //imprime los palindromos en caso de haberlos
    if (cantPalindromos>0){
        printf("\nHay %d palindromo/s.\n\n", cantPalindromos);
        imprimirPalindromos(ptrFile);
    }
    else
    {
        puts("\nNo hay palindromos");
    }
    
    //cierra archivo
    fclose(ptrFile);
    return (EXIT_SUCCESS);
}

