#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
	int a, b, half_sum;
	ifstream input("input.bin", ios::binary);
	input.read((char*)(&a), sizeof(a));
	input.read((char*)(&b), sizeof(b));
	input.close();
	half_sum = floor(double(a) / 2 + double(b) / 2);
	ofstream output("output.bin", ios::binary);
	output.write((char*)(&half_sum), sizeof(int));
	output.close();
}