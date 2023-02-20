#include <stdio.h>
#include <stdlib.h>
#include "ivector.h"

#define umbral 2
#define TAM 11



void mostrarVectorOrdenado(ivector v, int tam) {
    for (int i = 0; i < tam; ++i) {
        printf("%d ", v[i]);
    }
}

void insercion(ivector v, int tam) {
    int clave, j;
    for (int i = 1; i < tam; ++i) {
        clave = *(v + i);
        j = i - 1;
        while (j >= 0 && *(v + j) > clave) {
            *(v + j + 1) = *(v + j);
            j--;
        }
        *(v + j + 1) = clave;
    }
}

void juntar(int primero, int ultimo, int centro, ivector v) {
    int x = primero, y = centro + 1, z = 0;
    ivector aux = v;
    while ((x <= centro) && (y <= ultimo)) {
        if (v[x] <= v[y]) {
            aux[z] = v[x];
            x++;
        } else {
            aux[z] = v[y];
            y++;
        }
        z++;
    }
    z = 0;
    for (int i = primero; i < ultimo; ++i) {
        v[i] = aux[z];
        z++;
    }

    free(aux);
}


void mergeSort(ivector v, int primero, int ultimo) {
    int centro;
    if (primero - ultimo + 1 <= umbral) {
        insercion(v, TAM);
    } else {
        centro = (primero + ultimo) / 2;
        mergeSort(v, primero, centro);
        mergeSort(v, centro, ultimo);
        juntar(primero, ultimo, centro, v);
    }
}


int main() {
    printf("Hello, World!\n");
    ivector v = icreavector(TAM);
    for (int i = 0; i < TAM; ++i) {
        v[i] = rand() % 12;
    }
    mergeSort(v, 0, TAM);

    mostrarVectorOrdenado(v, TAM);
    free(v);

    return 0;
}
