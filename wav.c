#include "wav.h"

#include <stdio.h>
#include <stdlib.h>

struct gall_wav * gall_load_wav_file(char *filename) {
  FILE *f = fopen(filename, "rb");
  fseek(f, 0, SEEK_END);
  long fsize = ftell(f);
  fseek(f, 0, SEEK_SET);

  uint8_t *contents = malloc(fsize + 1);
  fread(contents, fsize, 1, f);
  fclose(f);
  contents[fsize]=0;

  struct gall_wav *result = malloc(sizeof(struct gall_wav));

  /* Load riff descriptor */
  memcpy(result->riff_descriptor->chunk_id[0], contents[0], 4 * sizeof(uint8_t));
  result->riff_descriptor->chunk_size = (uint32_t) contents[4] + (((uint32_t) contents[5]) << 8) + (((uint32_t) contents[6]) << 16) + (((uint32_t) contents[7]) << 24);
  
  

  /* Load fmt chunk */


  /* Load data chunk */
  

}

void gall_wav_info(struct gall_wav) {
  
}

