#include "glyph.h"
/*
Glyph Heart = {
    .curves = {
        {{5,10},{0,15},{5,20}},   // lado esquerdo
        {{5,10},{10,15},{5,20}},  // lado direito
        {{5,20},{5,22},{5,24}}    // ponta inferior
    },
    .curve_count = 3
};
*/

/*
// Glifo do Coração
Glyph Heart = {
    .curves = {
        {{5,10}, {0,25}, {0,0}},     // Lado esquerdo do topo
        {{0,0}, {10,25}, {5,10}},    // Lado direito do topo
        {{0,0}, {5, -10}, {5, -10}}, // Lado esquerdo da ponta
        {{5, -10}, {10,-10}, {5, -10}}  // Lado direito da ponta
    },
    .curve_count = 4
};
*/

Glyph Heart = {
    .curves = {
        {{5,10},{0,15},{5,20}},   // lado esquerdo do topo
        {{5,10},{10,15},{5,20}},  // lado direito do topo
        {{5,20},{5,25},{5,30}}    // ponta inferior
    },
    .curve_count = 3
};
