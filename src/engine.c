#include "../include/engine.h"

#include "../include/sort_bogo.h"
#include "../include/sort_bubble.h"
#include "../include/sort_quick.h"

void EngineInit(Engine *e, int *arr, int size, Algorithm algo) {
  e->state.arr = arr;
  e->state.size = size;

  e->state.i = 0;
  e->state.j = 0;

  e->state.sorted = 0;

  e->state.stackTop = -1;

  e->algo = algo;

  if (algo == ALG_QUICK) {
    e->state.stackTop = 0;
    e->state.stackLow[0] = 0;
    e->state.stackHigh[0] = size - 1;
  }

  switch (algo) {
  case ALG_BUBBLE:
    e->step = BubbleStep;
    break;
  case ALG_QUICK:
    e->step = QuickStep;
    break;
  case ALG_BOGO:
    e->step = BogoStep;
    break;
  }
}

void EngineStep(Engine *e) {
  if (!e->state.sorted) {
    StepResult r = e->step(&e->state);
    if (r == STEP_DONE)
      e->state.sorted = 1;
  }
}
