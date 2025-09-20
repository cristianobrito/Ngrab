// glyph_data.c
#include "glyph.h"
/*
Glyph A = {
    .curves = {
                {{2,0},{5,20},{8,0}},   // parte superior
                {{5,10},{5,15},{5,20}}, // haste direita
                {{5,20},{6,25},{7,20}}  // cauda
    },
    .curve_count = 3
};
*/

Glyph A = {
    .curves = {
        {{2,0},{5,20},{8,0}},     // lado esquerdo até topo
        {{10,20},{5,-10},{1,20}},     // lado direito até topo
        {{3,10},{5,10},{8,10}}    // travessão do meio
    },
    .curve_count = 3
};

