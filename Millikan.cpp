#include<iostream>
#include<fstream>
#include<cmath>
#include<iostream>
#include<string>

//double calculate_mean(double* x, int n)
//{

//}

//double calculate_standard_deviation(double* x, double mean, int n)
//{

//}

int main()
{
	std::string file_name;
	std::cout << "Enter the full name of the file you want to open" << std::endl;
	std::cin >> file_name;
	std::fstream file("P:\\OOP in CPP\\" + file_name);

	// Introduce way to check number of points in data file
	if (file.is_open()) {
		int n{ 0 }; // n = number of data points 
		std::string temp;
		while (getline(file, temp)) { // Everytime the program is able to get a line, it increments n by one - counting the lines of data 
			n++;
		}
		std::cout << "There are " << n << " datapoints" << std::endl;
		double* data{ new double[n] };
		while (!file.eof()) {
			int i = 0;
			double temp;
			file >> temp;
			data[i] = temp;
			i++;
		}
		
		if(file.fail()){}
	}
	else {
		std::cout << "Could not open file" << std::endl;
		return 0;
	}
}
