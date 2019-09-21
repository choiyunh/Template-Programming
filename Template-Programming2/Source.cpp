#include <iostream>
#include <string>

template<class T_int, class T_float, class T_double>
class Vector2D
{
public:

	T_int x_;
	T_float y_;
	T_double z_;

	Vector2D(const T_int& x_input, const T_float& y_input, const T_double& z_input)
		:x_(x_input), y_(y_input), z_(z_input)
	{}

	void print()
	{
		std::cout << x_ << " " << y_ << " " << z_ << std::endl;
	}
};

int main()
{

	Vector2D<int, float, double> str_int_vector(1, 2.0f, 3.0f);
	str_int_vector.print();

	return 0;
}

