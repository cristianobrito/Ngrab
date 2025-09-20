#include "glyph.h"
/*
Glyph Y = {
    .curves = {
        {{2,20},{5,10},{8,20}},   // parte superior esquerda
        {{8,20},{5,10},{5,0}}     // haste vertical
    },
    .curve_count = 2
};
*/
// Glifo da letra Y
Glyph Y = {
    .curves = {
                {{2,0},{5,20},{8,0}},   // parte superior
                {{5,10},{5,15},{5,20}}, // haste direita
                {{5,20},{6,25},{7,20}}  // cauda
    },
    .curve_count = 3
};
