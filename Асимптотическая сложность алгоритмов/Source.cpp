#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
using namespace std;
int const N = 10000;
int const M = 100;
int const K = 100000;

bool linear_search (int array[], int key, int n) {

	for (int i = 0; i < n; i++) {
		if (array[i] == key)
		{
			return true;
		}
	}
	return false;
}

int *sort(int arr[], int n) {
	bool sorted = false;
	while (!sorted) {
		sorted = true;
		for (int i = 1; i < n; i++) {
			if (arr[i] < arr[i - 1]) {
				auto t = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = t;
				sorted = false;
			}
		}
	}
	return arr;
}

bool binary_search (int array[], int key, int n) {
	int min = 0;
	int max = n;
	int mid;
	while (min <= max) {
		mid = (min + max) / 2;
		if (array[mid] == key){
			return true;
		}
		if (array[mid] > key) {
			max = mid - 1;
		}
		else {
			min = mid + 1;
		}
	}
	return false;
}


bool sum_two_square (int array[], int key, int n) {
	int len = n-1;
	for (int i = 0; i < len ; i++) {
		for (int j = i + 1; j <= len; j++) {
			if (array[i] + array[j] == key) {
				return true;
			}
		}
	}
	return false;
}

bool sum_two_linear(int array[], int key, int n) {
	int min = 0;
	int max = n-1;
	while (min != max) {
		int sum = array[min] + array[max];
		if (sum < key) { min++; }
		else if (sum > key) { max--; }
		else {
			return true;
		}
	}
	return false;
}

bool linear_search_A (int array[], int key, int n) {
	int t;
	for (int i = 0; i < n; i++) {
		if (array[i] == key)
		{
			return true;
			t = array[0];
			array[0] = array[i];
			array[i] = t;
		}
	}
	return false;
}

bool linear_search_B (int array[], int key, int n) {
	int t;
	for (int i = 0; i < n; i++) {
		if (array[i] == key)
		{
			return true;
			if (i != 1) {
				t = array[i - 1];
				array[i - 1] = array[i];
				array[i] = t;
			}
		}
	}
	return false;
}

bool linear_search_C (int array[], int key, int n) {
	int t;
	int* counter = new int[n];
	for (int i = 0; i < n; i++) {
		if (array[i] == key)
		{
			return true;
			counter[i] += 1;
			if ((i != 1) && (counter[i - 1] < counter[i])) {
				t = array[i - 1];
				array[i - 1] = array[i];
				array[i] = t;
			}
		}
	}
	delete[] counter;
	counter = nullptr;
	return false;
	
}



int* random(int n) {
	srand(200);
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		arr[i] = rand();
	};
	auto array = arr;
	delete[] arr;
	arr = nullptr;
	return array;
}

void writing_to_file(string s) {
	std::ofstream ofs;
	ofs.open("C:\\c_projects\\Asymptotic complexity of algorithms\\data.txt", std::ofstream::out | std::ofstream::app);

	ofs << s <<endl;

	ofs.close();
}

void separate_atring() {
	std::ofstream ofs;
	ofs.open("C:\\c_projects\\Asymptotic complexity of algorithms\\data.txt", std::ofstream::out | std::ofstream::app);

	ofs <<endl;

	ofs.close();
}

void time_linear_search() {
	std::ofstream ofs;
	ofs.open("C:\\c_projects\\Asymptotic complexity of algorithms\\data.txt", std::ofstream::out | std::ofstream::app);
	for (int i = M; i <= N; i+=M) {
		auto array = random(i);
		auto begin = chrono::steady_clock::now();
		for (int j = 0; j <= K; j++) {
			linear_search(array, rand(), i);
		}
		auto end = chrono::steady_clock::now();
		auto time_span =
			chrono::duration_cast<chrono::milliseconds>(end - begin);
		
		ofs << time_span.count() << ",";
	}
	ofs.close();
}

void time_binary_search() {
	std::ofstream ofs;
	ofs.open("C:\\c_projects\\Asymptotic complexity of algorithms\\data.txt", std::ofstream::out | std::ofstream::app);
	for (int i = M; i <= N; i+=M) {
		auto array = random(i);
		auto arr = sort(array, i);
		auto begin = chrono::steady_clock::now();
		for (long long j = 0; j <= 10000000; j++) {
			binary_search(arr, rand(), i);
		}
		auto end = chrono::steady_clock::now();
		auto time_span =
			chrono::duration_cast<chrono::milliseconds>(end - begin);
		
		ofs << time_span.count() << ",";
	}
	ofs.close();
}

void time_sum_two_square() {
	std::ofstream ofs;
	ofs.open("C:\\c_projects\\Asymptotic complexity of algorithms\\data.txt", std::ofstream::out | std::ofstream::app);
	for (int i = M; i <= 1000; i+=10) {
		auto array = random(i);
		auto begin = chrono::steady_clock::now();
		for (int j = 0; j <= 1000; j++) {
			sum_two_square(array, rand(), i);
		}
		auto end = chrono::steady_clock::now();
		auto time_span =
			chrono::duration_cast<chrono::milliseconds>(end - begin);
		
		ofs << time_span.count() << ",";
	}
	ofs.close();
}

void time_sum_two_linear() {
	std::ofstream ofs;
	ofs.open("C:\\c_projects\\Asymptotic complexity of algorithms\\data.txt", std::ofstream::out | std::ofstream::app);
	for (int i = M; i <= N; i+=M) {
		auto array = random(i);
		auto arr = sort(array, i);
		auto begin = chrono::steady_clock::now();
		for (int j = 0; j <= K; j++) {
			sum_two_linear(arr, rand(), i);
		}
		auto end = chrono::steady_clock::now();
		auto time_span =
			chrono::duration_cast<chrono::milliseconds>(end - begin);
		
		ofs << time_span.count() << ",";
	}
	ofs.close();
}

void time_linear_search_A_evenly() {
	std::ofstream ofs;
	ofs.open("C:\\c_projects\\Asymptotic complexity of algorithms\\data.txt", std::ofstream::out | std::ofstream::app);
	for (int i = M; i <= N; i += M) {
		auto array = random(i);
		auto begin = chrono::steady_clock::now();
		for (int j = 0; j <= K; j++) {
			linear_search_A(array, rand(), i);
		}
		auto end = chrono::steady_clock::now();
		auto time_span =
			chrono::duration_cast<chrono::milliseconds>(end - begin);

		ofs << time_span.count() << ",";
	}
	ofs.close();
}

void time_linear_search_B_evenly() {
	std::ofstream ofs;
	ofs.open("C:\\c_projects\\Asymptotic complexity of algorithms\\data.txt", std::ofstream::out | std::ofstream::app);
	for (int i = M; i <= N; i += M) {
		auto array = random(i);
		auto begin = chrono::steady_clock::now();
		for (int j = 0; j <= K; j++) {
			linear_search_B(array, rand(), i);
		}
		auto end = chrono::steady_clock::now();
		auto time_span =
			chrono::duration_cast<chrono::milliseconds>(end - begin);

		ofs << time_span.count() << ",";
	}
	ofs.close();
}

void time_linear_search_C_evenly() {
	std::ofstream ofs;
	ofs.open("C:\\c_projects\\Asymptotic complexity of algorithms\\data.txt", std::ofstream::out | std::ofstream::app);
	for (int i = 100; i <= 10000; i += 100) {
		auto array = random(i);
		auto begin = chrono::steady_clock::now();
		for (int j = 0; j <= 10000; j++) {
			linear_search_C(array, rand(), i);
		}
		auto end = chrono::steady_clock::now();
		auto time_span =
			chrono::duration_cast<chrono::milliseconds>(end - begin);

		ofs << time_span.count() << ",";
	}
	ofs.close();
}

void time_linear_search_A_unevenly() {
	std::ofstream ofs;
	ofs.open("C:\\c_projects\\Asymptotic complexity of algorithms\\data.txt", std::ofstream::out | std::ofstream::app);
	for (int i = M; i <= N; i += M) {
		auto R = rand();
		auto array = random(i);

		auto begin = chrono::steady_clock::now();
		for (int j = 0; j <= N; j++) {
			linear_search_A(array, rand(), i);
			linear_search_A(array, R, i);
		}

		auto end = chrono::steady_clock::now();
		auto time_span =
			chrono::duration_cast<chrono::milliseconds>(end - begin);

		ofs << time_span.count() << ",";
	}
	ofs.close();
}

void time_linear_search_B_unevenly() {
	std::ofstream ofs;
	ofs.open("C:\\c_projects\\Asymptotic complexity of algorithms\\data.txt", std::ofstream::out | std::ofstream::app);
	for (int i = M; i <= N; i += M) {
		auto R = rand();
		auto array = random(i);
		auto begin = chrono::steady_clock::now();
		for (int j = 0; j <= N; j++) {
			linear_search_B(array, rand(), i);
			linear_search_A(array, R, i);
		}
		auto end = chrono::steady_clock::now();
		auto time_span =
			chrono::duration_cast<chrono::milliseconds>(end - begin);

		ofs << time_span.count() << ",";
	}
	ofs.close();
}

void time_linear_search_C_unevenly() {
	std::ofstream ofs;
	ofs.open("C:\\c_projects\\Asymptotic complexity of algorithms\\data.txt", std::ofstream::out | std::ofstream::app);
	for (int i = M; i <= N; i += M) {
		auto R = rand();
		auto array = random(i);
		auto begin = chrono::steady_clock::now();
		for (int j = 0; j <= N; j++) {
			linear_search_C(array, rand(), i);
			linear_search_A(array, R, i);
		}
		auto end = chrono::steady_clock::now();
		auto time_span =
			chrono::duration_cast<chrono::milliseconds>(end - begin);

		ofs << time_span.count() << ",";
	}
	ofs.close();
}

int main() {
	time_linear_search();
	separate_atring();
	time_binary_search();
	separate_atring();
	time_sum_two_square();
	separate_atring();
	time_sum_two_linear();
	separate_atring();
	time_linear_search_A_evenly();
	separate_atring();
	time_linear_search_B_evenly();
	separate_atring();
	time_linear_search_C_evenly();
	separate_atring();
	time_linear_search_A_unevenly();
	separate_atring();
	time_linear_search_B_unevenly();
	separate_atring();
	time_linear_search_C_unevenly();
}