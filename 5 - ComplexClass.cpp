#include<iostream>
#include<cmath>
#include<string>
#include<sstream>

class complex
{
	friend complex operator+(double x, const complex &c);
	friend complex operator-(double x, const complex &c);
	friend complex operator*(double x, const complex &c);
	friend complex operator/(double x, const complex &c);
	friend std::ostream & operator<<(std::ostream &os, const complex &c);
	friend std::istream & operator>>(std::istream& is, const complex& c);
private:
	char name{ 'z' };
	double real{ 0.0 };
	double imaginary{ 0.0 };

public:
	// Constructors and Destructors
	complex() = default; //default is z = 0 + i0
	complex(char name_in, double real_in, double imaginary_in) : name{ name_in }, real { real_in }, imaginary{ imaginary_in }
	{}
	~complex() {};

	// Member function prototypes
	void set_real(double real_in) { real = real_in; }
	void set_imaginary(double imaginary_in) { imaginary = imaginary_in; }
	double get_real() const { return real; }
	double get_imaginary() const { return imaginary; }
	double get_modulus(const complex &c);
	double get_argument(const complex &c);
	complex get_conjugate(const complex &c) const
	{
		complex conjugate{ 'c', c.real, c.imaginary * -1 };
		return conjugate;
	}

	//Overloard operators
	complex operator+(const complex& c) const
	{
		complex temp{ 's' , real + c.real, imaginary + c.imaginary };
		return temp;
	}

	complex operator-(const complex &c) const
	{
		complex temp{ 'm', real - c.real, imaginary - c.imaginary };
		return temp;
	}

	complex operator*(const complex &c) const
	{
		double new_real = (real * c.real) - (imaginary * c.imaginary);
		double new_imaginary = (real * c.imaginary) + (imaginary * c.real);
		complex temp{ 'p', new_real, new_imaginary };
		return temp;
	}

	complex operator/(const complex &c) const
	{
		complex conjugate = get_conjugate(c);
		complex complex_denominator = c * conjugate;
		double new_real = (real * conjugate.real) - (imaginary * conjugate.imaginary);
		double new_imaginary = (real * conjugate.imaginary) + (imaginary * conjugate.real);
		complex numerator{ 'n', new_real, new_imaginary };
		double denominator = complex_denominator.real;
		complex temp{ 'd', numerator.real / denominator, numerator.imaginary / denominator };
		return temp;
	}
};

// Member functions
double complex::get_argument(const complex &c)
{
	double argument = atan(c.imaginary / c.real);
	return argument;
}

double complex::get_modulus(const complex &c)
{
	double modulus = pow(pow(c.real, 2) + pow(c.imaginary, 2), 0.5);
	return modulus;
}


//Friend functions
//Overloading operators so non-complex doubles can act on complex numbers - not demonstrated in main()
complex operator+(const double x, const complex& c)
{
	complex temp{ 'c', x + c.real, c.imaginary };
	return temp;
}
complex operator-(const double x, const complex& c)
{
	complex temp{ 'c', x - c.real, c.imaginary };
	return temp;
}
complex operator*(const double x, const complex& c)
{
	complex temp{ 'c', x * c.real, x * c.imaginary };
	return temp;
}
complex operator/(const double x, const complex& c)
{
	complex temp{ 'c', c.real / x, c.imaginary / x };
	return temp;
}

std::ostream& operator<<(std::ostream& os, const complex& c)
{
	if (c.imaginary > 0) {
		os << c.name << " = " << c.real << " + " << c.imaginary << "i" << std::endl;
		return os;
	}
	else if (c.imaginary < 0) {
		os << c.name << " = " << c.real << " - " << abs(c.imaginary) << "i" << std::endl;
		return os;
	}
}

std::istream& operator>>(std::istream& is, complex& c)
{
	bool validated = false;
	while (!validated) {
		std::string input_string{};
		double input_real;
		double input_imaginary;
		char sign;
		getline(is, input_string);
		std::istringstream iss(input_string);
		iss >> input_real;
		iss >> sign;
		iss >> input_imaginary;
		if (iss.fail()) {
			iss.clear();
			iss.ignore();
			std::cout << "Please input again" << std::endl;
			continue;
		}
		else {
			c.set_real(input_real);
			if (sign == '-') {
				c.set_imaginary(-1 * input_imaginary);
				validated = true;
			}
			else if (sign == '+') {
				c.set_imaginary(input_imaginary);
				validated = true;
			}
			else {
				iss.clear();
				iss.ignore();
				std::cout << "Please input again" << std::endl;
				continue;
			}
		}
	}
	return is;
}

int main()
{
	//Show functionality of class
	complex a('a', 3, 4);
	complex b('b', 1, -2);
	std::cout << "The complex numbers a and b are given by " << a << " and " << b << std::endl;
	std::cout << "arg(a) = " << a.get_argument(a) << " mod(a) = " << a.get_modulus(a) << " Re(a) = " << a.get_real() << " Im(a) = " << a.get_imaginary() << std::endl;
	std::cout << "arg(b) = " << b.get_argument(b) << " mod(b) = " << b.get_modulus(b) << " Re(b) = " << b.get_real() << " Im(b) = " << b.get_imaginary() << std::endl;
	std::cout << "The complex conjugate of a is " << a.get_conjugate(a) << std::endl;
	std::cout << "The complex conjugate of b is " << b.get_conjugate(b) << std::endl;
	std::cout << "a+b is given by " << a + b << std::endl;
	std::cout << "a-b is given by " << a - b << std::endl;
	std::cout << "a*b is given by " << a * b << std::endl;
	std::cout << "a/b is given by " << a / b << std::endl;
	std::cout << "You can input your own complex number, z, as long as it follows the format x+/-y for x+iy." << std::endl;

	//Using overloaded operators to write to/from class variable
	complex d;
	std::cin >> d; 
	std::cout << d << std::endl;
	return 0;
}
