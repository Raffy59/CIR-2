#include <iostream>

using namespace std;

constexpr int multiplier(int x, int y) {
	return x * y;
}

int main() {
	int a;
	int b;
	cout << "Entrez une valeur:" << endl;
	cin >> a;
	cout << "Entrez une autre valeur:" << endl;
	cin >> b;

	cout << multiplier(a+1, b+1) << endl;

	constexpr int val = multiplier(3, 4);
	cout << "3*4=" << val << "calculé à la compilation" << endl;
	return 0;
}