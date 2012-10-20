#include "indice.h"
#include <stdio.h>
#include <stdlib.h>
#include "Log.h"

#define TAM_INICIAL 5
#define TAM_A_AMPLIAR 50

void primero(t_indice *ind)
{
    if(ind->cantReg == 0)
    {
        ind->fin = 1;
        return ;
    }
    ind->actual = 0;
    ind->fin = 0;
}

int finIndice(const t_indice *ind)
{
    return ind->fin;
}

void siguiente(t_indice *ind)
{
    if(ind->actual == ind->cantReg-1)
    {
        ind->fin = 1;
        return;
    }
    ind->actual++;
}

const t_reg_ind * actual(t_indice *ind)
{
    return &ind->vInd[ind->actual];
}

int crearIndice(t_indice * ind) {
    ind->vInd = (t_reg_ind*)malloc(TAM_INICIAL*sizeof(t_reg_ind));
    if (!ind -> vInd)
        return SIN_MEM;
    ind->capacidad = TAM_INICIAL;
    ind->cantReg = 0;
    ind->vInd[0].dni = 999999999;

    return TODO_BIEN;
}

int buscarEnIndice(const t_indice * ind,t_reg_ind * reg) {

    int med,
        fin=ind->cantReg,
        ini=0;

    do
    {
        med = (ini + fin)/2;
        if(reg->dni == ind->vInd[med].dni)
        {
            reg->nroReg = ind->vInd[med].nroReg;
            return med;
        }else{
            if(reg->dni < ind->vInd[med].dni)
              fin = med - 1;
            else
              ini = med + 1;
        }
    }while(ini <= fin);

    return NO_ENCONTRADO;
}

int indiceLleno (const t_indice * ind)
{
    return ind->cantReg == ind->capacidad-1;
}

int ampliarIndice (t_indice * ind)
{
    ind -> vInd = (t_reg_ind*)realloc(ind->vInd,(ind->capacidad + TAM_A_AMPLIAR)*sizeof(t_reg_ind));
    if (!ind -> vInd)
        return SIN_MEM;
    ind -> capacidad += TAM_A_AMPLIAR;
    return TODO_BIEN;
}
 //llamar a la fc buscar para ver q no existe previamente.
 //Esta fc hace una insercion en orden. El vector tiene que estar siempre ordenado.
 //Primero validar si hay espacio en el vector, sino realloc.
 //Recorro el vector de atras para adelante y pregunto si el dni a instertar es menos al q voy viendo.
 //Hay que verificar que el subindice no sea menor a cero, sino me meto en memoria que no corresponde.

int insertarEnIndice(t_indice * ind, t_reg_ind * reg) {

    int ini = 0,
      med,
      fin = ind->cantReg,
      i;

    if(buscarEnIndice(ind,reg) == NO_ENCONTRADO)
    {
        if(indiceLleno(ind) && !ampliarIndice(ind))
            return SIN_MEM;

        do
        {
            med = (ini + fin)/2;
            if(reg->dni < ind->vInd[med].dni)
              fin = med - 1;
            else
              ini = med + 1;
        }while(ini <= fin);

        for(i=ind->cantReg;i>=ini;i--)
             ind->vInd[i+1]= ind->vInd[i];

        ind->vInd[ini].dni = reg->dni;
        ind->vInd[ini].nroReg = reg->nroReg;
        ind ->cantReg++;

        return TODO_BIEN;
    }

    return CLA_DUP;
}

int eliminarDeIndice(t_indice * ind, t_reg_ind * reg) {
    int pos, i;
    if((pos = buscarEnIndice(ind,reg))>=0)
    {
        for(i=pos;i<ind ->cantReg;i++)
             ind->vInd[i]= ind->vInd[i+1];

        ind ->cantReg--;

        return TODO_BIEN;
    }

    return NO_ENCONTRADO;
}

void vaciarIndice(t_indice * ind)
{
    ind->cantReg=0;
    ind->actual =0;
    ind->fin =0;
}
