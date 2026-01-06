#include <iostream>
#include <iomanip>

using namespace std;

constexpr int multiplier(int x, int y) {
	return x * y;
}

int main() {
	int a;
	cout << "Entrez une valeur:" << endl;
	cin >> a;
	for (int i = 1; i < 10; ++i) {
		cout << setw(2)<<a<< " * " << setw(1)<<i << " = " << setw(2)<<multiplier(a, i) << endl;
	}
}
