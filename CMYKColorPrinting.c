/*
R = 255 × (100 - C)% × (100 - K)%
G = 255 × (100 - M)% × (100 - K)%
B = 255 × (100 - Y)% × (100 - K)%
*/

#include <stdio.h>
#include <math.h>
#define MAX_SIZE 256

unsigned int W, H;
unsigned int image[MAX_SIZE][MAX_SIZE] = {0};

char layers[4] = {'C', 'M', 'Y', 'K'};

void print_C(unsigned int mask[][MAX_SIZE]);
void print_M(unsigned int mask[][MAX_SIZE]);
void print_Y(unsigned int mask[][MAX_SIZE]);
void print_K(unsigned int mask[][MAX_SIZE]);
void CMYK_to_RGB();

unsigned int ori[4][MAX_SIZE][MAX_SIZE] = {0};
void print_C(unsigned int mask[][MAX_SIZE])
{
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            ori[0][i][j] = mask[i][j];
        }
    }
}

void print_M(unsigned int mask[][MAX_SIZE])
{
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            ori[1][i][j] = mask[i][j];
        }
    }
}

void print_Y(unsigned int mask[][MAX_SIZE])
{
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            ori[2][i][j] = mask[i][j];
        }
    }
}

void print_K(unsigned int mask[][MAX_SIZE])
{
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            ori[3][i][j] = mask[i][j];
        }
    }
}

void CMYK_to_RGB()
{
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            double R = 255 * (100.0 - ori[0][i][j]) * (100.0 - ori[3][i][j]) / 10000;
            double G = 255 * (100.0 - ori[1][i][j]) * (100.0 - ori[3][i][j]) / 10000;
            double B = 255 * (100.0 - ori[2][i][j]) * (100.0 - ori[3][i][j]) / 10000;
            int r = lround(R);
            int g = lround(G);
            int b = lround(B);
            image[i][j] = r * 65536 + g * 256 + b;
        }
    }
}


int main()
{
    // Get the dimension of the image.
    scanf("%u %u", &W, &H);

    // Declare the mask for single ink color.
    unsigned int mask[MAX_SIZE][MAX_SIZE] = {0};

    // For each layer, do the following:
    for (int layer = 0; layer < 4; ++layer)
    {
        // Get color mask.
        for (int i = 0; i < H; ++i)
        {
            for (int j = 0; j < W; ++j)
            {
                scanf("%u", &mask[i][j]);
            }
        }

        // Print a layer of that color to the paper.
        switch (layers[layer])
        {
            case 'C': print_C(mask); break;
            case 'M': print_M(mask); break;
            case 'Y': print_Y(mask); break;
            case 'K': print_K(mask); break;
        }
    }

    // Convert CMYK color to RGB color.
    CMYK_to_RGB();

    // Show the final result.
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            printf("#%06x ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}
