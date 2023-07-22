#include<stdio.h>
#include <iostream>
#include <fstream>
using namespace std;
int needRev = 0;

unsigned int reverse(unsigned int s)
{
    unsigned int a[4];
    a[3] = s & 0xFF;
    a[2] = (s >> 8) & 0xFF;
    a[1] = (s >> 16) & 0xFF;
    a[0] = (s >> 24) & 0xFF;
    return a[0] + (a[1] << 8) + (a[2] << 16) + (a[3] << 24);
}

int main()
{
    FILE* in = fopen("input.bin", "rb");

    unsigned int N;

    fread(&N, 4, 1, in);

    if (N > 10000)
    {
        needRev = 1;
        N = reverse(N);
    }

    unsigned int sum = 0;

    for (int i = 0; i < N; ++i)
    {
        unsigned int m;

        fread(&m, 4, 1, in);

        if (needRev)
            m = reverse(m);

        sum += m;
    }
    fclose(in);

    FILE* out = fopen("output.bin", "wb");

    if (needRev)
        sum = reverse(sum);

    fwrite(&sum, 4, 1, out);

    fclose(out);
}