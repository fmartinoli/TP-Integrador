#include <stdlib.h>
#include <stdio.h>
#include "Utilitarios.h"


int abrirArchivo(FILE **fp,const char * nomArch, const char * modo,int conSin)
{
    *fp = fopen(nomArch,modo);
    if(*fp==NULL)
    {
        if(conSin==CON_MSJ)
            fprintf(stderr,"Error abriendo \"%s\" en modo \"%s\" \n",nomArch,modo);

        return 0;

    }
    return 1;
}
