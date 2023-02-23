#include <chrono>
#include <iostream>

void func() {
	std :: cout << " Hello world";
}

int main() {
	auto begin = std :: chrono :: steady_clock :: now();
	for(unsigned cnt = 1000; cnt != 0; --cnt)
		func();
	auto end = std :: chrono :: steady_clock :: now();
	auto time_span =
		std :: chrono :: duration_cast<std :: chrono :: milliseconds >(end - begin);
		std :: cout << "\n\n";
	std::cout << time_span.count() << std::endl;
	return 0;

}
