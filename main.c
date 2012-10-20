#include <stdio.h>
#include <stdlib.h>
#include "Indice.h"
#include "Menu.h"
#include "Utilitarios.h"

#define ARCH_IDX "..\\TP1\\indice.idx"

int main()
{
    char mOpc[][100] = {"abcdes","Efectuar Mantenimiento", "Listar dados de baja", "Listar en orden(sin los dados de baja)", "Actualizacion automatica","Depuracion", "Salir"};
    char opcion;

    FILE * fpIdx;
    t_reg_ind regIndice;
    t_indice indice;

    /* Bloque para cargar el archivo de indice en memoria */
    if(!abrirArchivo(&fpIdx, ARCH_IDX, "rb", CON_MSJ))
        return;

    fread(&regIndice, sizeof(t_reg_ind), 1 , fpIdx);

    crearIndice(&indice);
    while(!feof(fpIdx))
    {
        insertarEnIndice(&indice, &regIndice);
        fread(&regIndice, sizeof(t_reg_ind), 1 , fpIdx);
    }

    fclose(fpIdx);


    do{
        opcion = menu(mOpc, "TP Integrador");

        switch(opcion){
            case 'a':
                mantenimiento();
                break;
            case 'b':
               // listarBajas();
                break;
            case 'c':
                //listarOrden();
                break;
            case 'd':
                //actualizacionAutomatica();
                break;
            case 'e':
                //depuracion();
                break;
            case 's':
                exit(1);
                break;
        }

    }while(opcion != 's');

    return 0;
}


