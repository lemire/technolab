#ifndef BASICAUTOMATA_H
#define BASICAUTOMATA_H

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

void clear(uint32_t *counts, size_t width, size_t height) {
  for (size_t i = 0; i < height; i++) {
    for (size_t j = 0; j < width; j++) {
      counts[i * width + j] = 0;
    }
  }
}
void randomize(uint8_t *states, size_t width, size_t height) {
  for (size_t i = 0; i < height; i++) {
    for (size_t j = 0; j < width; j++) {
      states[i * width + j] = rand() & 1;
    }
  }
}

void computecounts(uint32_t *counts, const uint8_t *states, size_t width,
                   size_t height) {
  clear(counts, width + 2, height + 2);
  size_t awidth = width + 2;
  for (size_t i = 0; i < height; i++) {
    for (size_t j = 0; j < width; j++) {
      uint32_t val = states[i * width + j];
          counts[(i + 1 + 1) * awidth + j + 1] += val;
          counts[(i - 1 + 1) * awidth + j + 1] += val;
          counts[(i + 1) * awidth + j + 1 + 1] += val;
          counts[(i + 1) * awidth + j - 1 + 1] += val;
          counts[(i + 1 + 1) * awidth + (j + 1) + 1] += val;
          counts[(i - 1 + 1) * awidth + ( j - 1 ) + 1] += val;
          counts[(i - 1 + 1) * awidth + j + 1 + 1] += val;
          counts[(i + 1 + 1) * awidth + (j - 1) + 1] += val;
      }
    }
  
}

void gameoflife(uint32_t *counts, uint8_t *states, size_t width, size_t height) {
  computecounts(counts, states, width, height);
  for (size_t i = 0; i < height; i++) {
    for (size_t j = 0; j < width; j++) {
      size_t coord = i * width + j;
      bool currentvalue = states[coord];
      uint32_t neighbors = counts[(i + 1) * (width + 2) + j + 1];
      if (currentvalue == 1) {
        if (neighbors < 2 || neighbors > 3) {
          states[coord] = 0;
        }
      } else {
        if (neighbors == 3) {
          states[coord] = 1;
        }
      }
    }
  }
}
#endif
