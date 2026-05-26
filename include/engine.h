#ifndef ENGINE_H
#define ENGINE_H

#include "sort.h"

typedef enum { ALG_BUBBLE, ALG_QUICK, ALG_BOGO } Algorithm;

typedef struct {
  SortState state;
  SortStepFunc step;
  Algorithm algo;
} Engine;

void EngineInit(Engine *e, int *arr, int size, Algorithm algo);
void EngineStep(Engine *e);

#endif
