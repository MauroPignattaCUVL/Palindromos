#ifndef PALINDROMO_H
#define PALINDROMO_H

#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

    int buscarPalindromos(char const * texto, FILE * ptrFile);
    
    void imprimirPalindromos(FILE * ptrFile);



#ifdef __cplusplus
}
#endif

#endif /* PALINDROMO_H */

