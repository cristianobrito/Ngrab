// glyph_render.c
#include "glyph.h"
#include <stdio.h>

void render_glyph_svg(Glyph g, const char *filename) {
    FILE *f = fopen(filename, "w");
    if(!f) return;

    fprintf(f, "<svg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 20 20'>\n");
    for(int i=0; i<g.curve_count; i++) {
        Curve c = g.curves[i];
        fprintf(f, "<path d='M %f %f Q %f %f %f %f' stroke='black' fill='none'/>\n",
                c.p1.x, c.p1.y, c.p2.x, c.p2.y, c.p3.x, c.p3.y);
    }
    fprintf(f, "</svg>\n");
    fclose(f);
}
