#include <iostream>

using namespace std;

int main() {

	while (true) {
		cout << "Array Length" << endl;
		int n;
		cin >> n;

		if (n <= 0)
			break;

		int* array = new int[n];

		cout << "Array elements?" << endl;

		for (int i = 0; i < n; i++) {
			cin >> array[i];
		}

		for (int i = 0; i < n - 1; i++) {

			for (int j =  i + 1; j < n; j++) {
				if (array[i] > array[j]) {
					int p = array[i];
					array[i] = array[j];
					array[j] = p;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			cout << array[i] << ", ";
		}
		cout << endl;
		delete[] array;
	}
	return 0;
}