#include <iostream>
#include <fstream>
#include <math.h>
#include <string>

using namespace std;

int main(int argv, char* argc[])
{
ifstream inf;
ofstream ouf;
ouf.open("newdata.txt");
ouf << "x\tx^2\tsum" << endl << "-\t---\t---" << endl;
inf.open(argc[1]);
int x, square, sum;
while (inf >> x)
{
	square = pow(x, 2);
	sum += x;
	ouf << x << "\t" << square << "\t" << sum << endl;
}
inf.close();
return 0;
}