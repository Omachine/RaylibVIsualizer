#include "../include/engine.h"
#include "../include/render.h"
#include "raylib.h"
#include <stdlib.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 450

typedef enum { STATE_MENU, STATE_INPUT, STATE_SORTING } GameState;

int main() {
  srand(time(NULL));

  InitWindow(WIDTH, HEIGHT, "Sorting Engine");
  SetTargetFPS(60);

  GameState state = STATE_MENU;

  Algorithm algo = ALG_BUBBLE;

  Engine engine;

  int *arr = NULL;
  int size = 0;

  char input[16] = "";
  int len = 0;

  int frame = 0;
  int speed = 5;

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);

    // ---------------- MENU ----------------
    if (state == STATE_MENU) {
      DrawText("Select Algorithm:", 250, 100, 20, WHITE);

      if (IsKeyPressed(KEY_ONE))
        algo = ALG_BUBBLE;
      if (IsKeyPressed(KEY_TWO))
        algo = ALG_QUICK;
      if (IsKeyPressed(KEY_THREE))
        algo = ALG_BOGO;

      DrawText(algo == ALG_BUBBLE ? "> Bubble" : "  Bubble", 250, 160, 20,
               algo == ALG_BUBBLE ? YELLOW : WHITE);

      DrawText(algo == ALG_QUICK ? "> Quick" : "  Quick", 250, 190, 20,
               algo == ALG_QUICK ? YELLOW : WHITE);

      DrawText(algo == ALG_BOGO ? "> Bogo" : "  Bogo", 250, 220, 20,
               algo == ALG_BOGO ? YELLOW : WHITE);

      DrawText("ENTER to continue", 250, 300, 20, GREEN);

      if (IsKeyPressed(KEY_ENTER))
        state = STATE_INPUT;
    }

    // ---------------- INPUT ----------------
    else if (state == STATE_INPUT) {
      int key = GetCharPressed();
      while (key > 0) {
        if (key >= '0' && key <= '9' && len < 15) {
          input[len++] = (char)key;
          input[len] = '\0';
        }
        key = GetCharPressed();
      }

      if (IsKeyPressed(KEY_ENTER)) {
        size = atoi(input);
        if (size < 2)
          size = 2;
        if (size > 800)
          size = 800;

        if (arr)
          free(arr);
        arr = malloc(size * sizeof(int));

        for (int i = 0; i < size; i++)
          arr[i] = GetRandomValue(10, HEIGHT - 20);

        EngineInit(&engine, arr, size, algo);

        state = STATE_SORTING;
      }

      DrawText("Enter size:", 20, 20, 20, WHITE);
      DrawText(input, 20, 60, 30, GREEN);
    }

    // ---------------- SORTING ----------------
    else if (state == STATE_SORTING) {
      frame++;

      if (frame >= speed) {
        frame = 0;
        EngineStep(&engine);
      }

      DrawArray(&engine.state, WIDTH, HEIGHT);

      DrawText("UP/DOWN speed | Q quit", 10, 10, 20, WHITE);

      if (IsKeyPressed(KEY_UP))
        speed--;
      if (IsKeyPressed(KEY_DOWN))
        speed++;
      if (speed < 1)
        speed = 1;

      if (IsKeyPressed(KEY_Q))
        break;

      if (engine.state.sorted)
        DrawText("SORTED", 350, 20, 30, GREEN);
    }

    EndDrawing();
  }

  free(arr);
  CloseWindow();
  return 0;
}
