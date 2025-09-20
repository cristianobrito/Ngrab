// glyph.h
#ifndef GLYPH_H_INCLUDED
#define GLYPH_H_INCLUDED

typedef struct {
    float x, y;
} Point;

typedef struct {
    Point p1, p2, p3;
} Curve;

typedef struct {
    Curve curves[10];
    int curve_count;
} Glyph;

extern Glyph A;
extern Glyph B;
extern Glyph Y;
extern Glyph V;
extern Glyph Heart;

void render_glyph_svg(Glyph g, const char *filename);

#endif // GLYPH_H_INCLUDED
