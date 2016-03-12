#include <iostream>
#include <string>
using namespace std;
template <typename T>
struct dinamic
{
	T *name;
	unsigned int n;
	unsigned int N;
	dinamic(){ name=NULL; n=0; N=0;}
	~dinamic(){ delete[] name; }
	
void add(T c)
{

		if (N > n)
		{
			name[n] = c;
			n++;
		}
		else
		{
			unsigned int i;
			char *buff;
			N+=11;
			buff = new T[N];
			for (i = 0; i < N; i++)
			{
				buff[i] = name[i];
			}
			delete[] name;
			name=buff;
			name[n] = c;
			n++;
		}
}
};

int main()
{
	dinamic<char> mass; 
	char c=0;
	unsigned int i;
	cout << "---------------------------------" << endl;
	cout << "Tape | to stop adding." << endl;
	cout << "Tape > to show massive." << endl;
	while (true)
	{
		if (c != '|')
		{
			cout << "Tape symbol:";
			cin >> c;
			cout << "---------------------------------" << endl;
			if (c != '|')
			{
				if (c != '>') mass.add(c);
			}
			else break;

			if (c == '>')
			{
				for (i = 0; i < mass.n; i++)
					cout << mass.name[i] << " ";

				cout << endl;
				cout << "---------------------------------" << endl;
			}

		}
		else 
		{ 
			cout << "---------------------------------" << endl;  
			break; 
		}
	}

	cout << endl;
	if (mass.n > 0)
	{

		for (i = 0; i < mass.n; i++)
			cout << mass.name[i] << " ";

		cout << endl;
		cout << "---------------------------------";
	}
return 0;
}
