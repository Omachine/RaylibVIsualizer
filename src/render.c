#include "../include/render.h"
#include "raylib.h"

void DrawArray(SortState *s, int width, int height) {
  int spacing = 1;
  int barWidth = (width / s->size) - spacing;
  if (barWidth < 1)
    barWidth = 1;

  for (int i = 0; i < s->size; i++) {
    int x = i * (barWidth + spacing);

    Color c = WHITE;

    if (s->sorted)
      c = GREEN;
    else if (i == s->a || i == s->b)
      c = RED;

    DrawRectangle(x, height - s->arr[i], barWidth, s->arr[i], c);
  }
}
