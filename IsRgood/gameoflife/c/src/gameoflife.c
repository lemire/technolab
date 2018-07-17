#include "pnghelper.h"
#include "basicautomata.h"



int main(int argc, char **argv) {
  if(argc<2) {
    printf("pass a width parameter\n");
    return EXIT_FAILURE;
  }

  size_t N = atoi(argv[1]);
  bool *states = (bool *)malloc(N * N * sizeof(bool));
  uint32_t *counts = (uint32_t *)malloc(N * N * sizeof(uint32_t));


  randomize(states, N, N);


  bitmap_t image;

  /* Create an image. */

  image.width = N;
  image.height = N;
  image.pixels = calloc(image.width * image.height, sizeof(pixel_t));

char cated_string[255];

    for (size_t t = 0; t < 10; t++) {
      gameoflife(counts,  states, N, N);
      mapdatatoimage(&image, states);
      sprintf(cated_string, "result%zu.png",t);
      printf("saving to %s\n", cated_string);
      save_png_to_file(&image, cated_string);
    }


  free(image.pixels);
  free(states);
  free(counts);
  return 0;
}
