#include <stdio.h>

extern char mp3_data[];
extern int size;

int main(void)
{
    FILE *file = fopen("output.mp3", "wb");
    
    int results = fwrite(mp3_data, 1, size, file);
    if (results == EOF)
    {
	return -1;
    }

    return 0;
}
