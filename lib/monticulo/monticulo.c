#include "monticulo.h"
#include <stddef.h>
#include <stdbool.h>
#include <assert.h>

void Monticulo_inicializa(Monticulo *m, int *celdas, int numCeldas, TipoMonticulo tipo) {
    m->celdas = celdas;
    m->capacidad = numCeldas;
    m->tamano = 0;
    m->tipo = tipo;
}

static void intercambiar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

static void subir(Monticulo *m, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        bool debeIntercambiar = (m->tipo == Monticulo_MINIMO) ? (m->celdas[index] < m->celdas[parent]) : (m->celdas[index] > m->celdas[parent]);
        if (debeIntercambiar) {
            intercambiar(&m->celdas[index], &m->celdas[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

int Monticulo_introduce(Monticulo *m, int valor) {
    if (m->tamano >= m->capacidad) {
        return -1; // Montículo lleno
    }
    m->celdas[m->tamano] = valor;
    subir(m, m->tamano);
    m->tamano++;
    return 0;
}

int Monticulo_leeTope(const Monticulo *m, int *destino) {
    if (m->tamano == 0) {
        return -1; // Montículo vacío
    }
    *destino = m->celdas[0];
    return 0;
}

static void bajar(Monticulo *m, int index) {
    while (index * 2 + 1 < m->tamano) {
        int hijoIzq = index * 2 + 1;
        int hijoDer = index * 2 + 2;
        int hijoIntercambio = hijoIzq;
        if (hijoDer < m->tamano && ((m->tipo == Monticulo_MINIMO) ? (m->celdas[hijoDer] < m->celdas[hijoIzq]) : (m->celdas[hijoDer] > m->celdas[hijoIzq]))) {
            hijoIntercambio = hijoDer;
        }
        bool debeIntercambiar = (m->tipo == Monticulo_MINIMO) ? (m->celdas[hijoIntercambio] < m->celdas[index]) : (m->celdas[hijoIntercambio] > m->celdas[index]);
        if (debeIntercambiar) {
            intercambiar(&m->celdas[index], &m->celdas[hijoIntercambio]);
            index = hijoIntercambio;
        } else {
            break;
        }
    }
}

int Monticulo_tomaTope(Monticulo *m, int *destino) {
    if (m->tamano == 0) {
        return -1; // Montículo vacío
    }
    *destino = m->celdas[0];
    m->tamano--;
    m->celdas[0] = m->celdas[m->tamano];
    bajar(m, 0);
    return 0;
}
