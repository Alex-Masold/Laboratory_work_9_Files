#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream in("input.txt", ios::in);

    string c;

    int counter = 0;

    while (!in.eof())
    {
        c = in.get();
        for (int i = 0; i < c.length(); i++)
        {
            if (c[i] == '\n')
            {

                counter++;
            }
        }
    }
    in.close();
    ofstream out("output.txt");
    out << counter;
    /*cout << c;*/
    out.close();
}