#include "mincpu/cpu.h"
#include "raylib.h"
#include "render/render.h"
#include <stdio.h>

#define WIDTH 320
#define HEIGHT 320
#define FPS 60

int main(int argc, char **argv) {
  render_init(WIDTH, HEIGHT, FPS);

  uint8_t vram[256];

  for (size_t i = 0; i < 256; ++i) {
    vram[i] = i;
  }

  while (!WindowShouldClose()) {
    render_screen(vram);
  }
}
