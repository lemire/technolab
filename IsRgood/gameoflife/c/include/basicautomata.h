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
void randomize(bool *states, size_t width, size_t height) {
  for (size_t i = 0; i < height; i++) {
    for (size_t j = 0; j < width; j++) {
      states[i * width + j] = rand() & 1;
    }
  }
}

void computecounts(uint32_t *counts, const bool *states, size_t width,
                   size_t height) {
  clear(counts, width, height);
  for (size_t i = 0; i < height; i++) {
    for (size_t j = 0; j < width; j++) {
      if (states[i * width + j]) {
        if (i < height - 1)
          counts[(i + 1) * width + j]++;
        if (i > 1)
          counts[(i - 1) * width + j]++;
        if (j < width - 1)
          counts[i * width + j + 1]++;
        if (j > 1)
          counts[i * width + j - 1]++;
        if ((i < height - 1) && (j < width - 1))
          counts[(i + 1) * width + (j + 1)]++;
        if ((i > 1) && (j > 1))
          counts[(i - 1) * width + ( j - 1 )]++;
        if ((j < width - 1) && (i > 1))
          counts[(i - 1) * width + j + 1]++;
        if ((j > 1) && (i < height - 1))
          counts[(i + 1) * width + (j - 1)]++;
      }
    }
  }
}

void gameoflife(uint32_t *counts, bool *states, size_t width, size_t height) {
  computecounts(counts, states, width, height);
  for (size_t i = 0; i < height; i++) {
    for (size_t j = 0; j < width; j++) {
      size_t coord = i * width + j;
      bool currentvalue = states[coord];
      uint32_t neighbors = counts[coord];
      if (currentvalue) {
        if (neighbors < 2 || neighbors > 3) {
          states[coord] = false;
        }
      } else {
        if (neighbors == 3) {
          states[coord] = true;
        }
      }
    }
  }
}
#endif
