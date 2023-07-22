#include <iostream>
#include <fstream>
#include <stdio.h>



using namespace std;

int split(int* a, int count, int aa)
{
	int* temp = new int[count];
	int start = 0, end = count - 1, f = 0, left{}, right{};
	for (int i = 0; i < count; i++)
	{
		if (a[i] < aa)
		{
			f++;
			temp[start++] = a[i];
		}
		else if (a[i] > aa)
			temp[end--] = a[i];
		else
		{
			if (left < right)
			{
				left++;
				f++;
				temp[start++] = a[i];
			}
			else
			{
				right++;
				temp[end--] = a[i];
			}
		}
	}
	for (int i = 0; i < count; i++)
		a[i] = temp[i];
	return f;
}

int main()
{
	int count = 0, aa = 0;
	ifstream in("input.bin", ios::binary);

	in.read((char*)&count, sizeof(int));
	in.read((char*)&aa, sizeof(int));
	int* inm = new int[count];
	for (int i = 0; i < count; i++)
		in.read((char*)&inm[i], sizeof(int));
	const int result = split(inm, count, aa);
	in.close();
	ofstream out("output.bin", ios::binary);

	out.write((const char*)&result, sizeof(int));
	for (int i = 0; i < count; i++)
		out.write((const char*)&inm[i], sizeof(int));

	out.close();
}