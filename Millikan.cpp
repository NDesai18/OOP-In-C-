#include<iostream>
#include<fstream>
#include<cmath>
#include<iostream>
#include<string>

double calculate_mean(double* x, int n)
{
double sum{0};
for(int i{0}; i < n; i++){
	sum = sum + x[i];
	}
double mean = sum / n;
return mean;
}

double calculate_standard_deviation(double* x, double mean, int n)
{
double sum_squared{0};
for(int i{0}; i < n; i++){
	sum_squared = sum_squared + pow(x[i] - mean, 2);
	}
double std_dev_squared = sum_squared / n -1;
double std_dev = sqrt(std_dev_squared);
	
	
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
	double* data{ new double[n] };
	for(int i{0}; i < n; i++) {
		double temp{};
		file >> temp;
		data[i] = temp;
		i++;
		if(file.fail()){
			std::cout << "Failure writing to line" << i + 1 << std::endl; //i+1 is more readable than i (line 1 is at i = 0)
			file.clear()
			n = n-1; // Fixes n so that it's adjusted for the number of valid entries
			i++; // Move on to next line
		}
		 mean = calculate_mean{data, n);
		 std_dev = caclulate_standard_deviation(data, mean, n);
		 std_err = std_dev / pow(std_dev, 0.5);
					     
		std::cout << "The mean is " << std::setprecision(3) << mean << "C" << std::endl;
		std::cout << "The standard deviation and standard error is" << std::setprecision(3) << std_dev << "and" << std_err << "respectively" << std::endl;
	}
	}
else {
	std::cout << "Could not open file" << std::endl;
	return 0;
}
}
