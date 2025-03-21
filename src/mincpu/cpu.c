#include "mincpu/cpu.h"

static void MinCPU_reset(MinCPU *cpu);

void MinCPU_step(MinCPU *cpu) {
  if (cpu->RES == LOW) {
    MinCPU_reset(cpu);
    return;
  }
}

static void MinCPU_reset(MinCPU *cpu) {
  cpu->RW = HIGH;
  cpu->RES = HIGH;
  cpu->addr = 0x0;
}
