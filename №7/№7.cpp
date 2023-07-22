#include <iostream>
#include <math.h>
#include <stdio.h>



using namespace std;

void func_change(const int* a, int zv, const int* b, int ww, int* r)
{
	int j = 0, i = 0, vv = 0, x;
	while ((j < zv) || (i < ww))
	{
		if (j == zv)
			x = b[i++];
		else if (i == ww)
			x = a[j++];
		else if (a[j] < b[i])
			x = a[j++];
		else
			x = b[i++];
		r[vv++] = x;
	}
}

int main()
{
	long signed N = 0, M = 0;
	FILE* in = fopen("input.bin", "rb");
	FILE* out = fopen("output.bin", "wb");
	fread(&N, sizeof(int), 1, in);
	fread(&M, sizeof(int), 1, in);
	int* a = new int[N]();
	int* b = new int[M]();
	int* ab = new int[N + M]();
	for (int i = 0; i < N; i++)
		fread(&a[i], sizeof(int), 1, in);
	for (int i = 0; i < M; i++)
		fread(&b[i], sizeof(int), 1, in);
	func_change(a, N, b, M, ab);
	for (int i = 0; i < N + M; i++)
		fwrite(&ab[i], sizeof(int), 1, out);
	delete[] a, b, ab;
	fclose(in);
	fclose(out);
	return 0;
}