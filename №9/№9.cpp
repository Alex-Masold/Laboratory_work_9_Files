#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

using namespace std;
void sort(int* arr, int n);

int main()
{
	FILE* in = fopen("input.bin", "rb"), * out = fopen("output.bin", "wb");;
	int num, n, i = 0;
	int* arr = new int[1000000];
	while (!feof(in))
	{
		fread(&num, sizeof(int), 1, in);
		if (feof(in))
			break;
		arr[i] = num;
		i++;
	}
	n = arr[0];
	for (int ZSS = 1; ZSS < n + 1; ZSS++)
		arr[ZSS - 1] = arr[ZSS];
	sort(arr, n);
	for (int i = 0; i < n; i++)
		fwrite(&arr[i], sizeof(int), 1, out);
	fclose(in);
	fclose(out);
}

void sort(int* arr, int n)
{
	int temp = 1;
	int* arr_temp = (int*)malloc(n * sizeof(int));
	while (temp < n)
	{
		int  i = 0, l = 0, r = l + (temp * 2), m = l + temp;
		do {
			if (m >= n)
				m = n;
			if (r >= n)
				r = n;
			int i1 = l, i2 = m;
			while (i1 < m && i2 < r)
			{
				if (arr[i1] < arr[i2])
					arr_temp[i++] = arr[i1++];
				else
					arr_temp[i++] = arr[i2++];
			}
			while (i1 < m)
				arr_temp[i++] = arr[i1++];
			while (i2 < r)
				arr_temp[i++] = arr[i2++];
			l += temp * 2;
			r += temp * 2;
			m += temp * 2;
		} while (l < n);
		for (int i = 0; i < n; i++)
			arr[i] = arr_temp[i];
		temp *= 2;
	}
}