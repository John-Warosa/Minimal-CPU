#include "render/render.h"
#include "raylib.h"

#define RGB_MASK_RED 224
#define RGB_MASK_GREEN 28
#define RGB_MASK_BLUE 3

static struct {
  // rendering constants
  size_t scrWidth;
  size_t scrHeight;
  size_t fps;

  // Texture for rendering VRAM
  Image img;
  Texture2D tex;
} RC;

static void update_pixels(uint8_t vram[]);
static inline uint8_t get_rgb_red(uint8_t num);
static inline uint8_t get_rgb_green(uint8_t num);
static inline uint8_t get_rgb_blue(uint8_t num);

void render_init(size_t width, size_t height, size_t fps) {
  InitWindow(width, height, "Minimal cycle-accurate CPU");

  RC.scrWidth = width;
  RC.scrHeight = height;
  RC.fps = fps;
  RC.img = GenImageColor(16, 16, WHITE);
  RC.tex = LoadTextureFromImage(RC.img);
}

void render_screen(uint8_t vram[]) {
  update_pixels(vram);
  UpdateTexture(RC.tex, RC.img.data);

  BeginDrawing();

  DrawTextureEx(RC.tex, (Vector2){0, 0}, 0, 10, WHITE);

  EndDrawing();
}
#include <stdio.h>
static void update_pixels(uint8_t vram[]) {
  static Color *pixels;
  pixels = (Color *)RC.img.data;

  for (size_t i = 0; i < 256; ++i) {
    uint8_t rgb = vram[i];
    pixels[i] =
        (Color){get_rgb_red(rgb), get_rgb_green(rgb), get_rgb_blue(rgb), 255};
  }
}

static inline uint8_t get_rgb_red(uint8_t num) {
  return ((num & RGB_MASK_RED) >> 5) * 32;
}

static inline uint8_t get_rgb_green(uint8_t num) {
  return ((num & RGB_MASK_GREEN) >> 2) * 32;
}

static inline uint8_t get_rgb_blue(uint8_t num) {
  return (num & RGB_MASK_BLUE) * 64;
}
