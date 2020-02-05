#include<iostream>
#include<fstream>
#include<cmath>
#include<iostream>
#include<string>
#include<iomanip>

double calculate_mean(double* x, int n)
{
	double sum{ 0 };
	for (int i{ 0 }; i < n; i++) {
		sum = sum + x[i];
	}
	double mean = sum / n;
	return mean;
}

double calculate_standard_deviation(double* x, double mean, int n)
{
	double sum_squared{ 0 };
	for (int i{ 0 }; i < n; i++) {
		sum_squared = sum_squared + pow((x[i] - mean), 2);
	}
	double std_dev_squared = sum_squared / (n-1);
	double std_dev = sqrt(std_dev_squared);
	return std_dev;
}

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
		file.clear();
		file.seekg(0, std::ios::beg); // Send the filestream back to the beginning
		double* data{ new double[n] };
		for (int i{ 0 }; i < n; i++) {
			file >> data[i];
			if (file.fail()) {
				std::cout << "Failure writing at line" << i + 1 << std::endl; //i+1 is more readable than i (line 1 is at i = 0)
				file.clear();
				getline(file, temp); // reads the current line into a string so it can be skipped over
				n--; // Fixes n so that it's adjusted for the number of valid entries
				std::cout << "Number of datapoints has been adjusted to " << n << std::endl;
			}
		}
		double mean = calculate_mean(data, n);
		double std_dev = calculate_standard_deviation(data, mean, n);
		double std_err = std_dev / pow(n, 0.5);
		delete[] data;
		std::cout << "The mean is " << std::setprecision(5) << mean << "x10^-19 C" << std::endl;
		std::cout << "The standard deviation and standard error is " << std::setprecision(3) << std_dev << "x10^-19 and " << std::setprecision(3) << std_err << "x10^-19 respectively" << std::endl;

	}
	else {
		std::cout << "Could not open file" << std::endl;
		return 0;
	}
}
