#include <iostream>
#include <fstream>

using namespace std;


int main()
{
    unsigned Fsim[256] = { 0 };
    string c;
    ifstream in("input.txt", ios::in);

    while (in.peek() != EOF)
    {
        Fsim[in.get()]++;
    }

    in.close();

    ofstream out("output.txt");
    for (int i = 13; i < 256; i++)
    {

        if (Fsim[i])
        {
            out << char(i) << " ";
            for (int j = 0; j < Fsim[i]; j++)
                out << "#";
            out << endl;
            //cout << int(i) << " : " << i << " - " << Fsim[i] << endl;
        }
    }
    out.close();
}