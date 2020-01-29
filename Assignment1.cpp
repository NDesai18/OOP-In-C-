#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>

double deltaE(int Z, int n_i, int n_f) // returns the photon energy
{
	double delta_e;
	delta_e = 13.6 * pow(Z, 2) * (pow(1 / n_f, 2) - pow(1 / n_i, 2));
	return delta_e;
}

double eVToJoules(double E) //converts energies from eV to Joules
{
	double j;
	j = E / 1.6;
	return j;
}

int main(){
bool run{ true };
std::string temp;
std::string temp1;
std::string temp2;

while (run == true) 
{
	int initial_quantum_number{};
	int final_quantum_number{};
	int atomic_number{};
	double photon_energy{};
	bool quantum_numbers_valid{ false };
	bool units_valid{ false };

	std::cout << "Enter the atomic number, Z, of the atom" << std::endl;
	std::getline(std::cin, temp);
	atomic_number = std::stoi(temp);
	if (atomic_number >= 0) {
		std::cout << "Z =" << atomic_number << std::endl;
	}
	else { 
		continue;  //User cannot continue unless they enter a positive value of Z
	}

	while (quantum_numbers_valid == false) 
	{
		std::cout << "Enter the initial quantum number, n_i" << std::endl;
		std::getline(std::cin, temp1);
		initial_quantum_number = std::stoi(temp1);
		std::cout << "Enter the final quantum number, n_f" << std::endl;
		std::getline(std::cin, temp2);
		final_quantum_number = std::stoi(temp2);

		if (initial_quantum_number <= final_quantum_number) {
			std::cout << initial_quantum_number << ",";
			std::cout << final_quantum_number << std::endl;
			std::cout << "Error, the inital quantum number must be larger than the final quantum number" << std::endl;
			std::cin.clear();
			std::cin.ignore();
			continue; //Again, user cannot continue unless their inputs are Physically allowed
		}
		else {
			std::cout << "The initial quantum number is " << initial_quantum_number << "and the final quantum number is " << final_quantum_number << std::endl;
			quantum_numbers_valid = true;
		}

	photon_energy = deltaE(atomic_number, initial_quantum_number, final_quantum_number);

	while (units_valid == false)
	{
		std::cout << "Would you like the energy in eV (e) or Joules (j)?" << std::endl;
		std::string units;
		std::cin >> units;
		if (units == "e") {
			std::cout << "The photon energy is " << std::setprecision(3) << photon_energy << "eV" << std::endl;
			units_valid = true;
		}
		else if (units == "j") {
			photon_energy = eVToJoules(photon_energy);
			std::cout << "The photon energy is " << std::setprecision(3) << photon_energy << "x10^-16 J" << std::endl;
			units_valid = true;
		}
		else {
			continue;
		}
		std::cout << "Press y to run the program again, or any other key to exit" << std::endl;
		std::string yesno;
		std::cin >> yesno;
		if (yesno == "y") {
			std::cin.clear();
			std::cin.ignore();
			continue;
		}
		else {
			run = false;
		}
	}
}
}
return 0;
}
