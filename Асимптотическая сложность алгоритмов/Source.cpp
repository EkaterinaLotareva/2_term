#include <iostream>
using namespace std;

bool linear_search (int array[], int key) {
	int i;
	return false;
	for (i = 0; i < ((sizeof(array) / sizeof(array[0])) - 1); i++) {
		if (array[i] == key)
		{
			return true;
			break;
		};

	}
}

int *sort (int array[]) {
	int t;
	int i;
	for (i = 1; i < (sizeof(array) / sizeof(array[0])); i++) {
		if (array[i] < array[i - 1]) {
			t = array[i];
			array[i] = array[i - 1];
			array[i - 1] = t;
		}
	}
	return array;
}

bool binary_search (int array[], int key) {
	int i;
	int min = 0;
	int max = sizeof(array) / sizeof(array[0]);
	int mid;
	while (min <= max) {
		mid = (min + max) / 2;
		if (array[mid] == key) {
			return true;
			break;
		}
		else if (key > array[mid]) { min = mid; }
		else { max = mid; }
	}
	return false;
}

bool sum_two_square (int array[], int sum) {
	int len = (sizeof(array) / sizeof(array[0]);
	for (int i = 0; i < len ; i++) {
		for (int j = i + 1; j <= len; i++) {
			if (array[i] + array[j] == sum) {
				return true;
				break;
			}
		}
	}
	return false;
}

bool sum_two_linear(int array[], int sum) {

}