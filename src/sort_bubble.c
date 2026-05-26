#include "../include/sort_bubble.h"

StepResult BubbleStep(SortState *s) {
  if (s->i >= s->size - 1)
    return STEP_DONE;

  s->a = s->j;
  s->b = s->j + 1;

  if (s->j < s->size - s->i - 1) {
    if (s->arr[s->j] > s->arr[s->j + 1]) {
      int t = s->arr[s->j];
      s->arr[s->j] = s->arr[s->j + 1];
      s->arr[s->j + 1] = t;
    }

    s->j++;
  } else {
    s->j = 0;
    s->i++;
  }

  return STEP_CONTINUE;
}
