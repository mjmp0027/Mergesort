#include <stdio.h>
#include <stdlib.h>
#include "ivector.h"

#define umbral 2


void burbuja(int primero, int ultimo, ivector v) {
    int aux;
    int para = 1;
    for (int i = primero; i < ultimo && para; i++) {
        para = 0;
        for (int j = primero; j < ultimo; j++) {
            if (v[j] > v[j + 1]) {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                para = 1;
            }
        }
    }
}

void mostrarVectorOrdenado(ivector v, int tam) {
    for (int i = 0; i < tam; ++i) {
        printf("%d ", v[i]);
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
//    while (x <= centro) {
//        aux[z] = v[x];
//        x++;
//        z++;
//    }
//    while (y <= ultimo) {
//        aux[z] = v[y];
//        y++;
//        z++;
//    }
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
        burbuja(primero, ultimo, v);
    } else {
        centro = (primero + ultimo) / 2;
        mergeSort(v, primero, centro);
        mergeSort(v, centro, ultimo);
        juntar(primero, ultimo, centro, v);
    }
}


int main() {
    printf("Hello, World!\n");
    ivector v = icreavector(11);
    for (int i = 0; i < 11; ++i) {
        v[i] = rand() % 12;
    }
    mergeSort(v, 0, 11);

    mostrarVectorOrdenado(v, 11);
    free(v);

    return 0;
}
