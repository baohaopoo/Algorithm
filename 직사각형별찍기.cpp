#include <iostream>

using namespace std;

int main(void) {
	int a;
	int b;
	cin >> a >> b;

	for (int i = 0; i < a * b; ++i)
	{
		if (i != 0 && i % a == 0)
			cout << endl;
		cout << "*";
	}
	return 0;
}