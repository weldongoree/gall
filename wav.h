/***** wav.h *****
 *
 * Internal format for WAV data
 *
 * This file is part of the Gall project
 *
 * (c) 2017 Weldon Goree. See LICENSE for distribution rights
 *
 *****************/

#include <stdint.h> 
#DEFINE GALL_WAV_SAMPLE_TYPE uint16_t
struct gall_riff_descriptor {
  uint8_t[4] chunk_id;
  uint32_t chunk_size;
  uint8_t[4] format;
};

struct gall_fmt_chunk {
  uint8_t[4] subchunk_id;
  uint8_t[4] subchunk_size;
  uint8_t[2] audio_format;
  uint8_t[2] num_channels;
  uint8_t[4] sample_rate;
  uint8_t[4] byte_rate;
  uint8_t[2] block_align;
  uint8_t[2] sample_bits;
};

struct gall_sample {
  GALL_WAV_SAMPLE_TYPE *samples;
  uint16_t channels;
};

struct gall_data_chunk {
  uint8_t[4] subchunk_id;
  uint8_t[4] subchunk_size;
  struct gall_sample *data;
};

struct gall_wav {
  struct gall_riff_descriptor riff_descriptor;
  struct gall_fmg_chunk fmt_chunk;
  struct gall_data_chunk data_chunk;
};

void gall_wav_info(struct gall_wav);

struct gall_wav *gall_load_wav_file(char *filename);

int gall_validate_riff_descriptor(struct gall_wav);
