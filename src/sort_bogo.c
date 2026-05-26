#include "../include/sort_bogo.h"
#include <stdlib.h>

StepResult BogoStep(SortState *s) {
  for (int i = 0; i < s->size - 1; i++)
    if (s->arr[i] > s->arr[i + 1])
      goto shuffle;

  return STEP_DONE;

shuffle:

  int a = rand() % s->size;
  int b = rand() % s->size;

  s->a = a;
  s->b = b;

  int t = s->arr[a];
  s->arr[a] = s->arr[b];
  s->arr[b] = t;

  return STEP_CONTINUE;
}
