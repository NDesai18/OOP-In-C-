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
  
  
  // Ask user to enter atomic number
  std::cout << "Enter the atomic number, Z, of the atom";
  std:cin >> atomic_number;

  // Ask user to enter initial and final quantum numbers
  std::cout << "Enter the initial quantum number, n_i";
  std::cin >> initial_quantum_number;
  std::cout << "Enter the final quantum number, n_j";
  std::cin >> final_quantum_number;
  
  // Compute photon energy, Delta E = 13.6*(Z^2)*(1/n_j^2-1/n_i^2) eV
  photon_energy = 13.6*pow(atomic_number,2)*(pow(1/final_quantum_number,2)-pow(1/initial_quantum_number,2));
  // Output answer
  std::cout << "The photon energy is " << photon_energy << "eV" << std::end1;

  return 0;
}
