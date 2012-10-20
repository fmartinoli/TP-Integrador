
#include "Menu.h"
#include <stdio.h>
#include <stdlib.h>

char menu (const char mOpc[][100] , const char * titulo)
{
    char opc;
    opc = pedirOpcion(mOpc, titulo, "Ingrese su opcion");

    while(!strchr(mOpc[0],opc))
        opc = pedirOpcion(mOpc, titulo, "Opcion invalida, ingrese nuevamente");

    return opc;
}

char pedirOpcion(const char mOpc[][100], const char * titulo, const char * mensaje)
{
    int cantOpciones, i;
    char opc;

    system("cls");
    puts(titulo);
    puts("");

    cantOpciones = strlen(mOpc[0]);

    for(i=0 ;i< cantOpciones;i++)
        printf("%c - %s\n",mOpc[0][i], mOpc[i+1]);

    puts(mensaje);
    fflush(stdin);
    opc = getchar();

    return opc;
}

void mantenimiento(){
    char mOpc[][100] = {"abcv","Alta", "Baja", "Modificacion", "Volver"};
    char opcion;

    do{
        opcion = menu(mOpc, "Efectuar Mantenimiento");

        switch(opcion){
            case 'a':
                //raiz();
                break;
            case 'b':
                //puts("seno");
                //getch();
                break;
            case 'c':
                //puts("factorial");
                //getch();
                break;
        }
    }while(opcion != 'v');
}
