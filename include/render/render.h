#ifndef RENDER_H
#define RENDER_H

#include <stddef.h>
#include <stdint.h>

void render_init(size_t width, size_t height, size_t fps);

void render_screen(uint8_t vram[]);

#endif // RENDER_H
