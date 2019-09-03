#include "../includes/palindromo.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define LONG_TEXT 256

int contarChar (char const *palabra)
{
    int cont=0;
    while (*palabra++)
    {
        cont++; 
    }
    return cont;
}
void strrev(char * destino, char const *origen)
{
    int i = 0;
    int cantCaracteres = contarChar(origen);
    while (i < cantCaracteres)
    {
        * (destino + i) = * (origen + n - 1 - i);
        i++;
    }
    * (destino + i) = '\0';
}

bool compararCadena(char const * primerCadena,char const * segundaCadena)
{
    bool compare = true;
    while (*x && compare)
    {
        compare = *primerCadena ++ == * segundaCadena ++ ? true : false;
    }
    return compare;
}

bool esPalindromo(char const * palabra, FILE * ptrFile)
{
    char *aux = calloc(LONG_TEXT + 1,1);
    //Comprueba que se haya asignado la memoria
    if (aux == NULL)
    {
        printf("No se pudo asignar memoria");
        exit(EXIT_FAILURE);
    }
    //invierte cadena
    strrev(aux, palabra);
    //compara las cadena
    bool palindromo = compararCadena(aux, palabra);
    //guarda palindromo en archivo
    if (palindromo)
    {
        fprintf( ptrFile,"%s\n",palabra);
    }
    return palindromo;
}

int buscarPalindromos(char const * texto, FILE * ptrFile)
{
    int cont = 0;
    char *aux = calloc(LONG_TEXT + 1 + 1,1);
    //Comprueba que se haya asignado la memoria
    if (aux == NULL)
    {
        printf("No se pudo asignar memoria");
        exit(EXIT_FAILURE);
    }
    char *ptrAux = aux;
    while (*texto)
    {
        aux = ptrAux;
        while(*texto && *texto != ' ')
        {
            *aux++ = *texto++ ;
        }
        *aux = '\0';
        cont += esPalindromo(ptrAux, ptrFile)? 1 : 0;
        texto++;
    }
    return cont;
}

void imprimirPalindromos(FILE * ptrFile)
{
    char *aux = calloc(LONG_TEXT + 1, 1);
    if (aux == NULL)
    {
        printf("No se pudo asignar memoria");
        exit(EXIT_FAILURE);
    }
    printf("Los palindromos son:\n");
    while(!feof(ptrFile))
    {
        aux = memset((char*) aux,'\0', sizeof(aux));
        fgets(aux,LONG_TEXT + 1,ptrFile);
        printf("%s",aux);
    }
}
