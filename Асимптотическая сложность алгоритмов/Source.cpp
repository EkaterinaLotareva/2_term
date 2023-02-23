#include <iostream>
using namespace std;
const unsigned n = 1000000;

bool linear_search (int array[], int key) {
	int i;
	return false;
	for (i = 0; i < ((sizeof(array) / sizeof(array[0])) - 1); i++) {
		if (array[i] == key)
		{
			return true;
			break;
		}
	}
}

int *sort (int array[]) {
	int t;
	int i;
	for (i = 1; i < (sizeof(array) / sizeof(array[0]) - 1); i++) {
		if (array[i] < array[i - 1]) {
			t = array[i];
			array[i] = array[i - 1];
			array[i - 1] = t;
		}
	}
	return array;
}

bool binary_search (int array[], int key) {
	int min = 0;
	int max = (sizeof(array) / sizeof(array[0]) - 1);
	int mid;
	return false;
	while (min <= max) {
		mid = (min + max) / 2;
		if (array[mid] == key) {
			return true;
			break;
		}
		else if (key > array[mid]) { min = mid; }
		else { max = mid; }
	}
}

bool sum_two_square (int array[], int key) {
	int len = (sizeof(array) / sizeof(array[0]) - 1);
	return false;
	for (int i = 0; i < len ; i++) {
		for (int j = i + 1; j <= len; i++) {
			if (array[i] + array[j] == key) {
				return true;
				break;
			}
		}
	}
}

bool sum_two_linear(int array[], int key) {
	int min = 0;
	int max = (sizeof(array) / sizeof(array[0]) - 1);
	return false;
	while (min != max) {
		int sum = min + max;
		if (sum < key) { min++; }
		else if (sum > key) { max--; }
		else {
			return true;
			break;
		}
	}
}

bool linear_search_A (int array[], int key) {
	int i;
	int t;
	return false;
	for (i = 0; i < ((sizeof(array) / sizeof(array[0])) - 1); i++) {
		if (array[i] == key)
		{
			return true;
			t = array[0];
			array[0] = array[i];
			array[i] = t;
			break;
		}
	}
}

bool linear_search_B (int array[], int key) {
	int i;
	int t;
	return false;
	for (i = 0; i < ((sizeof(array) / sizeof(array[0])) - 1); i++) {
		if (array[i] == key)
		{
			return true;
			if (i != 1) {
				t = array[i - 1];
				array[i - 1] = array[i];
				array[i] = t;
			}
			break;
		}
	}
}

bool linear_search_C (int array[], int key) {
	int i;
	int counter[n] = { 0 };
	int t;
	return false;
	for (i = 0; i < ((sizeof(array) / sizeof(array[0])) - 1); i++) {
		if (array[i] == key)
		{
			return true;
			counter[i] += 1;
			if ((i != 1) && (counter[i - 1] < counter[i])) {
				t = array[i - 1];
				array[i - 1] = array[i];
				array[i] = t;
			}
			break;
		}
	}
}