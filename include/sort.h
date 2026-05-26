#ifndef SORT_H
#define SORT_H

typedef struct {
  int *arr;
  int size;

  int i, j;

  int stackLow[1024];
  int stackHigh[1024];
  int stackTop;

  int a, b;

  int sorted;
} SortState;

typedef enum { STEP_CONTINUE, STEP_DONE } StepResult;

typedef StepResult (*SortStepFunc)(SortState *s);

#endif
