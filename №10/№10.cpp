#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void sort(int* a, int n)
{
	int i = 0, j = n - 1, mid = a[n / 2];
	do
	{
		while (a[i] < mid) {
			i++;
		}
		while (a[j] > mid) {
			j--;
		}
		if (i <= j)
		{
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0) {
		sort(a, j + 1);
	}
	if (i < n) {
		sort(&a[i], n - i);
	}
}

int main()
{
	FILE* in = fopen("input.bin", "rb"), * out = fopen("output.bin", "wb");
	int num, a, i = 0, j;
	int* arr = new int[1000000];
	while (!feof(in))
	{
		fread(&num, sizeof(int), 1, in);
		if (feof(in))
			break;
		arr[i] = num;
		i++;
	}
	fclose(in);
	a = arr[0];
	for (j = 1; j < a + 1; j++)
		arr[j - 1] = arr[j];
	sort(arr, a);
	for (i = 0; i < a; i++)
	{
		fwrite(&arr[i], sizeof(int), 1, out);
	}
	fclose(out);
}