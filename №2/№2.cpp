#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("input.txt", ios::in);
	string str;
	int buffer[50] = { 0 };
	while ((fin >> str))
	{
		buffer[(str.length())]++;
	}
	fin.close();
	ofstream out("output.txt");
	for (int i = 1; i < 50 - 1; i++)
	{
		if (buffer[i] > 0)
			out << i << " - " << buffer[i] << endl;
	}
	out.close();