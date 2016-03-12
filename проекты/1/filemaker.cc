#include <string>
#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;
string genname(string fname, int x, int y)
{
	char c1, c2, G;
	int a, test1 = 0, i, test2 = 0, b = 0;
	string part1, part2, part3, number;
	a = fname.length();
	c1 = x + '0';
	c2 = y + '0';
	part2 += '.';
	part2 += c1;
	part2 += c2;
	for (i = 0; i<a; i++)
		if (fname[i] == '.')test1 = 1;
	if (test1 == 1)
	{
		while (b != a){G = fname[b];  if (G == '.')test2 = 1; if (test2 == 0)part1 += G; else if (test2 == 1)part3 += G; b++;}
		fname = part1 + part2 + part3;
	}
	else
		fname = fname + part2;
	return(fname);
}
void file_part(string fname)
{
	ifstream f;
	ofstream g;
	char \*mass, *buffer;
	string gname;
	int fat, i, x = 0, y = 0, test, z,str,ASS=0;
	cout << "enter number" << endl;
	cin >> fat;
	cout << "enter massive's fat" << endl;
	cin >> z;
	mass = new char[z];
	buffer = new char[fat-z];
	f.open(fname.c_str(), ios_base::binary);
	while (f.read(mass, x))
	{
		gname = genname(fname, x, y);
		g.open(gname.c_str(), ios_base::binary);
		test = fat;
		while (test > 0)
		{
			if (ASS != 0)
			{
				for (i = 0; i < ASS; i++)
				{
					g.put(buffer[i]);
					test--;
				}
				if (test >= f.gcount())
				{
					str = f.gcount(); g.write(mass, str);
				}
				else
				{
					str = test; g.write(mass, str);
				}
				test = test - str;
				for (i = str; i < f.gcount(); i++)
				{
					buffer[i - str] = mass[i]; ASS = 0; ASS++;
				}
				f.read(mass, z);
			}
			else
			{
				if (test >= f.gcount())
				{
					str = f.gcount(); 
					g.write(mass, str);
				}
				else
				{
					str = test; g.write(mass, str);
				}
				test = test - str;

				for (i = str; i < f.gcount(); i++)
				{
					buffer[i - str] = mass[i]; ASS = 0; ASS++;
				}
				f.read(mass, z);
			}
		}
		if (y<9) y++; else { y = 0; if (x<9) x++; else { break; cout << "error 322" << endl; } }
		g.close();
	}
}
void file_gen(string fname)
{
	ifstream g;
	ofstream f;
	char c;
	string gname;
	int x = 0, y = 0;
	f.open(fname.c_str(), ios_base::binary);
	while (true)
	{
		gname = genname(fname, x, y);
		g.open(gname.c_str(), ios_base::binary);
		if (g.is_open())
		{
			while (g.get(c))
			{
				f.put(c);
			}
			g.close();
			if (y<9) y++; else { y = 0; if (x<9) x++; else { cout << "error 322" << endl; break; } }
		}
		else { break; }
	}
	f.close();
}
int main()
{
	int abs;
	string fname;
	cout << "Need file name!" << endl;
	cin >> fname;
	cout << "0 for segmentation" << endl;
	cout << "1 to pull together" << endl;
	cin >> abs;
	if (abs == 0)
		file_part(fname);
	if (abs == 1)
		file_gen(fname);
		return 0;
}
