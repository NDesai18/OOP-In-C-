//To improve, add a way to sort alphabetically (kill first part of the string (PHYSYYYY and then sort vector)

#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>

int main()
{
	std::vector<std::string> courses;
	const std::string subject_code("PHYS ");
	bool finished_entering = false;
	bool display = false;

	while (!finished_entering) {
		std::string input_string{};
		bool code_valid = 0;
		int course_code;
		std::string course_name;
		std::string course;
		std::cout << "Please enter the course code and name, separated by a space" << std::endl;
		std::cin.clear();
		getline(std::cin, input_string);
		std::istringstream iss(input_string);
		iss >> course_code;
		if (iss.fail()) {
			std::cout << "The course code must be a 5 digit number" << std::endl;
			iss.ignore();
			iss.clear();
			continue;
		}
		else if (course_code > 50000 || course_code < 10000) {
			std::cout << "The course code must begin with 1, 2, 3 or 4 and be a 5 digit number" << std::endl;
			iss.ignore();
			iss.clear();
			continue;
		}
		else {
			code_valid = 1;
		}
		if (code_valid == 1) {
			int length = input_string.length(); //length is the position of the final character of the string 
			course_name = input_string.substr(5, length); //length is used here so the substring is made from the 5th char of input (space) to the final char
			std::ostringstream output_string_stream;
			output_string_stream << subject_code << course_code << course_name;
			courses.push_back(output_string_stream.str());
			std::cout << "If you are finished adding courses and would like to view the entries, press x. Otherwise press any other key to continue adding courses" << std::endl;
			std::cin.clear();
			std::string finish;
			std::cin >> finish;
			if (finish == "x") {
				finished_entering = true;
				display = true;
			}
			else {
				std::cin.clear();
				std::cin.ignore();
				continue;
			}

		}
		while (display) {
			std::vector<std::string>::iterator course_iterator;
			std::vector<std::string>::iterator courses_begin{ courses.begin() };
			std::vector<std::string>::iterator courses_end{ courses.end() };
			std::cout << "Here you can you can view the courses by course code (enter a) or by their year (1, 2, 3 or 4 respectively)" << std::endl;
			std::cin.clear();
			std::string sort_type;
			std::cin >> sort_type;
			if (sort_type == "a") {
				sort(courses_begin, courses_end);
				for (course_iterator = courses_begin; course_iterator < courses_end; course_iterator++) {
					std::cout << *course_iterator << std::endl;
				}
			}
			else if (sort_type == "1") {
				for (course_iterator = courses_begin; course_iterator < courses_end; course_iterator++) {
					std::string test_string;
					test_string = *course_iterator;
					if (test_string.at(5) == '1') {
						std::cout << test_string << std::endl;
					}
					else {
						continue;
					}
				}
			}
			else if (sort_type == "2") {
				for (course_iterator = courses_begin; course_iterator < courses_end; course_iterator++) {
					std::string test_string;
					test_string = *course_iterator;
					if (test_string.at(5) == '2') {
						std::cout << test_string << std::endl;
					}
					else {
						continue;
					}
				}
			}
			else if (sort_type == "3") {
				for (course_iterator = courses_begin; course_iterator < courses_end; course_iterator++) {
					std::string test_string;
					test_string = *course_iterator;
					if (test_string.at(5) == '3') {
						std::cout << test_string << std::endl;
					}
					else {
						continue;
					}
				}
			}
			else if (sort_type == "4") {
				for (course_iterator = courses_begin; course_iterator < courses_end; course_iterator++) {
					std::string test_string;
					test_string = *course_iterator;
					if (test_string.at(5) == '4') {
						std::cout << test_string << std::endl;
					}
					else {
						continue;
					}
				}
			}
			else {
				std::cout << "Please enter a, 1, 2, 3 or 4" << std::endl;
				std::cin.clear();
				std::cin.ignore();
				continue;
			}
			std::string exit;
			std::cout << "Press x if you would like to display the courses again or n if you would like to add more entries, otherwise press any other key to exit the program" << std::endl;
			std::cin.clear();
			std::cin >> exit;
			if (exit == "x") {
				continue;
			}
			else if (exit == "n") {
				std::cin.clear();
				std::cin.ignore();
				finished_entering = false;
				display = false;
				continue;
			}
			else {
				display = false;
			}
		}
	}
	std::cout << "The program will now shut down" << std::endl;
	return 0;
}
