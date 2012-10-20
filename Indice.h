#ifndef INDICE_H_INCLUDED
#define INDICE_H_INCLUDED

#define SIN_MEM 0
#define TODO_BIEN 1
#define NO_ENCONTRADO -1
#define CLA_DUP 2;

typedef struct{
    long dni;
    int nroReg;
}t_reg_ind;

typedef struct{
    t_reg_ind *vInd;
    int capacidad,
        cantReg,
        actual, // subindice actual de vInd
        fin; // fin del array
}t_indice;

int crearIndice(t_indice * ind);
int buscarEnIndice(const t_indice * ind,t_reg_ind * reg);
int insertarEnIndice(t_indice * ind, t_reg_ind * reg);
int eliminarDeIndice(t_indice * ind, t_reg_ind * reg);
void vaciarIndice(t_indice * ind);

void primero(t_indice *ind);
void siguiente(t_indice *ind);
const t_reg_ind * actual(t_indice *ind);
int finIndice(const t_indice *ind);

#endif // INDICE_H_INCLUDED
