#include "../include/sort_quick.h"

StepResult QuickStep(SortState *s) {
  if (s->stackTop < 0) {
    for (int i = 0; i < s->size - 1; i++)
      if (s->arr[i] > s->arr[i + 1])
        return STEP_CONTINUE;

    return STEP_DONE;
  }

  int low = s->stackLow[s->stackTop];
  int high = s->stackHigh[s->stackTop];
  s->stackTop--;

  s->a = low;
  s->b = high;

  int pivot = s->arr[high];
  int p = low;

  for (int k = low; k < high; k++) {
    if (s->arr[k] < pivot) {
      int t = s->arr[k];
      s->arr[k] = s->arr[p];
      s->arr[p] = t;
      p++;
    }
  }

  int t = s->arr[p];
  s->arr[p] = s->arr[high];
  s->arr[high] = t;

  if (p - 1 > low) {
    s->stackTop++;
    s->stackLow[s->stackTop] = low;
    s->stackHigh[s->stackTop] = p - 1;
  }

  if (p + 1 < high) {
    s->stackTop++;
    s->stackLow[s->stackTop] = p + 1;
    s->stackHigh[s->stackTop] = high;
  }

  return STEP_CONTINUE;
}
