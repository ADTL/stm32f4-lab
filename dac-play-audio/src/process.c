#include <stdio.h>
#include <stdlib.h>

extern char bin_data[];
extern int bin_size;

// WAVE PCM soundfile format (you can find more in https://ccrma.stanford.edu/courses/422/projects/WaveFormat/ )
typedef struct header_file
{
    char chunk_id[4];
    int chunk_size;
    char format[4];
    char subchunk1_id[4];
    int subchunk1_size;
    short int audio_format;
    short int num_channels;
    int sample_rate;// sample_rate denotes the sampling rate.
    int byte_rate;
    short int block_align;
    short int bits_per_sample;
    char subchunk2_id[4];
    int subchunk2_size;// subchunk2_size denotes the number of samples.
} header;

typedef struct header_file* header_p;
int main(void)
{
    header_p meta = (header_p)bin_data;

    int size = sizeof(*meta);

    printf(" Size of Header file is %d bytes\r\n", size);
    printf(" Sampling rate of the input wave file is %u Hz\r\n", meta->sample_rate);
    printf(" Number of samples in wave file are %u samples\r\n" , meta->subchunk2_size);

    short int *p = (short int*)bin_data;

    short int *end = (short int*)(bin_data + bin_size);

    while (p < end)
    {
	short int val = (*p);
	val &= 0x0000ffff;
	printf("address: %x value:%04x  val int:%d\r\n", p, val & 0xffff, val & 0xffff);
	p++;

    }
    return 0;
}
