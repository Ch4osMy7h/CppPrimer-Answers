#include <iostream>

auto Sum = [](int a, int b){
	return a + b;
};

int main() {
	std::cout << Sum(1, 2) << std::endl;
}