#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

int LCG(int x)
{
	/*promijeniti vrijednosti parametara a, b i m*/
	int m = 1;
	int a = 0;
	int b = 0;
	return (a * x + b) % m;
}

int main()
{
	static bool first = true;
	vector<int> randNs;
	int next;

	int seed = 55;

	if (first) //generiramo prvi flag
	{
		next = LCG(seed);
		randNs.push_back(next);
		first = false;

		for (int i = 0; i < 5; i++)
		{
			next = LCG(next);
			if (next < 10)
			{
				randNs.push_back(0);
				randNs.push_back(next);
			}
			else
				randNs.push_back(next);
		}

		for (int i : randNs)
			cout << i << ' ';
		cout << "\n";
	}


	for (int j = 0; j < 29; j++)  //generiramo ostalih 29 flagova
	{
		randNs.clear();

		for (int i = 0; i < 6; i++)
		{
			next = LCG(next);
			if (next < 10)
			{
				randNs.push_back(0);
				randNs.push_back(next);
			}
			else
				randNs.push_back(next);
		}

		for (int i : randNs)
			cout << i << ' ';
		cout << "\n";
	}
}

