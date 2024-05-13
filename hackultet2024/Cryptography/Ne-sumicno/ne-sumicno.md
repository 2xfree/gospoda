# Ne-sumicno (100 points)

We get a clue that this is a LCG and we also get the source code but without the correct parameters.

```cpp
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
```

So, we need to find out the values of `a`, `b`, and `m`. We get the first two flags.

```text
CTF2024[213496490010]
CTF2024[125260225401]
```

We also get a hint that `m < 100` because the text says that the LCG generates 6 numbers which are less than 100.

This challenge is pretty trivial and the easiest way to solve it is to brute force the parameters.

```cpp
#include <iostream>
#include <random>
#include <string>
#include <vector>
using namespace std;

int a = 0;
int b = 0;
int m = 1;

int LCG(int x) {
    return (a * x + b) % m;
}

int main() {
    vector<int> lookingFor = {21, 34, 96, 49, 0, 0, 10};

    for (int i = 0; i <= 100; i++) {
        a = i;
        for (int j = 0; j <= 100; j++) {
            b = j;
            for (int k = 1; k <= 100; k++) {
                m = k;
                bool first = true;
                vector<int> randNs;
                int next;

                int seed = 55;

                if (first) 
                {
                    next = LCG(seed);
                    randNs.push_back(next);
                    first = false;

                    for (int i = 0; i < 5; i++) {
                        next = LCG(next);
                        if (next < 10) {
                            randNs.push_back(0);
                            randNs.push_back(next);
                        } else
                            randNs.push_back(next);
                    }

                    bool match = false;
                    if (randNs.size() == lookingFor.size()) {
                        match = true;
                        for (int i = 0; i < randNs.size(); i++) {
                            if (randNs[i] != lookingFor[i]) {
                                match = false;
                            }
                        }
                    }
                    if (match) {
                        for (int i : randNs) {
                            cout << i << ' ';
                        }
                        cout << "\n";

                        cout << "a=" << a << " b=" << b << " m=" << m << endl;
                    }
                } 
            }
        }
    }
}
```

This code spits out `a=20 b=10 m=99`. Putting these as parameters into the original code, we can see the first three number sequences.

```text
21 34 96 49 0 0 10 
12 52 60 22 54 0 1 
30 16 33 76 45 19 
```

If we check the first two, we see that they match with the flags we were given, so the third one would be `CTF2024[301633764519]` and this is the correct answer.
