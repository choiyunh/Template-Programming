#include <iostream>

// Generic Function
template <class T>
void print(const T& i)
{
	std::cout << i << std::endl;
}

int main()
{
	print(1);
	print(2.345f);
	print("Hello World");

	return 0;
}