#include "render/render.h"
#include "raylib.h"
#include <stdio.h>

static struct {
  // rendering constants
  size_t scrWidth;
  size_t scrHeight;
  size_t fps;

  // Texture for rendering VRAM
  Image img;
  Texture2D tex;
} RC;

void render_init(size_t width, size_t height, size_t fps) {
  InitWindow(width, height, "Minimal cycle-accurate CPU");

  RC.scrWidth = width;
  RC.scrHeight = height;
  RC.fps = fps;
  RC.img = GenImageColor(16, 16, WHITE);
  RC.tex = LoadTextureFromImage(RC.img);
}

void render_screen(uint8_t vram[]) {
  UpdateTexture(RC.tex, RC.img.data);

  BeginDrawing();

  DrawTextureEx(RC.tex, (Vector2){0, 0}, 0, 10, WHITE);

  EndDrawing();
}
