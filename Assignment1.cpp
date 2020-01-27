// Program to calculate transition energy using simple Bohr formula

#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main()
{
	// Declare variables here
	int initial_quantum_number{};
	int final_quantum_number{};
	int atomic_number{};
	double photon_energy{};
	double input_initial_quantum_number{};
	double input_final_quantum_number{};
	double input_atomic_number{};


	// Ask user to enter atomic number
	std::cout << "Enter the atomic number, Z, of the atom" << endl;
	std::cin >> input_atomic_number;
//   while (input_atomic_number - floor(input_atomic_number) != 0 || std::cin.fail());
// 	{
// 	std::cout << "Something went wrong, make sure Z is an integer \n Enter the atomic number, Z, of the atom" << endl;
// 	std::cin.clear();
// 	std::cin.ignore();
// 	std::cin >> input_atomic_number;
// 	}
	atomic_number = input_atomic_number;
	std::cout << "Atomic number = " << atomic_number << endl;






  // Ask user to enter initial and final quantum numbers
  std::cout << "Enter the initial quantum number, n_i" << endl;
  std::cin >> initial_quantum_number;
  std::cout << "Enter the final quantum number, n_j" << endl;
  std::cin >> final_quantum_number;
  
  // Compute photon energy, Delta E = 13.6*(Z^2)*(1/n_j^2-1/n_i^2) eV
  photon_energy = 13.6*pow(atomic_number,2)*(pow(1/final_quantum_number,2)-pow(1/initial_quantum_number,2));

  // Output answer
  std::cout << "The photon energy is " << photon_energy << "eV" << std::endl;

  return 0;
}
