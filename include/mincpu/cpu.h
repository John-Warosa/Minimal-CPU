#ifndef MINCPU
#define MINCPU

#include <stdbool.h>
#include <stdint.h>

#define HIGH true
#define LOW false
#define RESET_VECTOR 0xff

typedef bool pin;
typedef uint8_t pin8;

typedef struct {
  uint8_t opcode;
  uint8_t PC;

  struct {
    pin8 data;
    pin8 addr;
    pin RW;
    pin RES;
  };
} MinCPU;

static inline MinCPU MinCPU_init(void) {
  return (MinCPU){
      .RES = LOW,
  };
}

void MinCPU_step(MinCPU *cpu);

#endif // MINCPU
