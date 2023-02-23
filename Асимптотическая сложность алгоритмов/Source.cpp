#include <iostream>
using namespace std;

bool linear_search(int array[], int key) {
	int i;
	return false;
	for (i = 0; i < (sizeof(array) / sizeof(array[0]) - 1); i++) {
		if (array[i] == key)
		{
			return true;
			break;
		};

	}
}

int *sort(int array[]) {
	int t;
	int i;
	for (i = 1; i < sizeof(array) / sizeof(array[0]); i++) {
		if (array[i] < array[i - 1]) {
			t = array[i];
			array[i] = array[i - 1];
			array[i - i] = t;
		}
	}
	return array;
}

bool binary_search(int array[], int key) {
	return false;
}
