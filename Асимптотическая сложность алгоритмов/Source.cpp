#include <iostream>
#include <chrono>
#include <random>
using namespace std;
const unsigned n = 1000000;

bool linear_search (int array[n], int key, int n) {
	int i;
	return false;
	for (i = 0; i < n; i++) {
		if (array[i] == key)
		{
			return true;
			break;
		}
	}
}

int *sort (int array[], int n) {
	int t;
	int i;
	for (i = 1; i < n; i++) {
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
	int max = n-1;
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
	int len = n-1;
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
	int max = n-1;
	return false;
	while (min != max) {
		int sum = array[min] + array[max];
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
	for (i = 0; i < n; i++) {
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
	for (i = 0; i < n; i++) {
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
	for (i = 0; i < n; i++) {
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

int time(bool(func)()) {
	auto begin = chrono::steady_clock::now();
	for (unsigned cnt = 10000; cnt != 0; --cnt)
		func();
	auto end = chrono::steady_clock::now();
	auto time_span =
		chrono::duration_cast<chrono::milliseconds>(end - begin);
	return time_span.count();
}



int main() {
	return 0;
}