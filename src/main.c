#include "mincpu/cpu.h"
#include "render/render.h"

#define WIDTH 320
#define HEIGHT 320
#define FPS 60

int main(int argc, char **argv) {
  uint8_t vram[256] = {0};

  render_init(WIDTH, HEIGHT, FPS);
  render_screen(vram);
}
