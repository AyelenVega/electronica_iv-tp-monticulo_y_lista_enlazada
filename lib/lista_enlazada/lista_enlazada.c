#include "lista_enlazada.h"
#include <stddef.h>
#include <stdbool.h>


void NodoListaEnlazada_inicializa(NodoListaEnlazada *nodo, int valor) {
    nodo->valor = valor;
    nodo->puntero_siguiente = NULL;
}

void ListaEnlazada_inicializa(ListaEnlazada *lista) {
    *lista = NULL;
}

void ListaEnlazada_inserta(ListaEnlazada *lista, NodoListaEnlazada *nodo) {
    nodo->puntero_siguiente = *lista;
    *lista = nodo;
}

NodoListaEnlazada *ListaEnlazada_obtNodoCabeza(ListaEnlazada *lista) {
    return *lista;
}

bool ListaEnlazada_esVacia(ListaEnlazada *lista) {
    return *lista == NULL;
}

int ListaEnlazada_obtCabeza(ListaEnlazada *lista, int *valor) {
    if (ListaEnlazada_esVacia(lista)) {
        return -1; // Devuelve -1 si la lista esta vacia
    }
    *valor = (*lista)->valor;
    return 0; 
}

ListaEnlazada *ListaEnlazada_obtCola(ListaEnlazada *lista) {
    if (ListaEnlazada_esVacia(lista)) {
        return lista;
    }
    return &((*lista)->puntero_siguiente);
}

NodoListaEnlazada *ListaEnlazada_remueveCabeza(ListaEnlazada *lista) {
    if (ListaEnlazada_esVacia(lista)) {
        return NULL; 
    }
    NodoListaEnlazada *nodoARemover = *lista;
    *lista = (*lista)->puntero_siguiente;
    nodoARemover->puntero_siguiente = NULL;
    return nodoARemover;
}

