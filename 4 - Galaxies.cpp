#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>

class galaxy
{
private:
	std::string hubble_type{ "E0" };
	double redshift{ 0.0 };
	double total_mass{ 0.0 };
	double stellar_mass_fraction{ 0.0 };
	std::vector<galaxy> satellites;
public:
	galaxy() = default; //default galaxy is [E0, 0, 0, 0]
	galaxy(std::string galaxy_type, double galaxy_redshift, double galaxy_mass, double galaxy_stellar_mass_fraction) :
		hubble_type{ galaxy_type }, redshift{ galaxy_redshift }, total_mass{ galaxy_mass }, stellar_mass_fraction{ galaxy_stellar_mass_fraction }
	{}
	~galaxy() {};

	double stellar_mass();
	void set_type(const std::string &type) { hubble_type = type; }
	void print_data();
	void add_satellite(const galaxy &satellite) { satellites.push_back(satellite); }
	void print_satellite_data();
};

double galaxy::stellar_mass()
{
	double stellar_mass = stellar_mass_fraction * total_mass;
	std::cout << "The stellar mass is " << stellar_mass << std::endl;
	return stellar_mass;
}

void galaxy::print_data()
{
	std::cout << "Galaxy: [Type, Redshift, Mass, Stellar Mass Fraction] = [" << hubble_type << ", " << redshift << ", " << total_mass << ", " << stellar_mass_fraction << "]" << std::endl;
	std::cout << "The galaxy has " << satellites.size() << " satellites" << std::endl;
	if (satellites.size() > 0) {
		std::vector<galaxy>::iterator satellite_iterator;
		for (satellite_iterator = satellites.begin(); satellite_iterator < satellites.end(); satellite_iterator++) {
			satellite_iterator->galaxy::print_satellite_data();
		}
	}
}

void galaxy::print_satellite_data()
{
	std::cout << "Satellite galaxy: [Type, Redshift, Mass, Stellar Mass Fraction] = [" << hubble_type << ", " << redshift << ", " << total_mass << ", " << stellar_mass_fraction << "]" << std::endl;
}

std::string validate_type() //Function to receive and validate galaxy types
{
	bool validated = false;
	while (!validated) {
		std::string allowed_types[17] = { "E0", "E1", "E2", "E3", "E4", "E5", "E6", "E7", "S0", "Sa", "Sb", "Sc", "SBa", "SBb", "SBc", "Irr", " "}; 
		std::cin.clear();
		std::string temp;
		std::cin >> temp;
		auto position = find(std::begin(allowed_types), std::end(allowed_types), temp); //The last item in allowed_types[] is left empty so Irr does not return as an invalid entry
		if (position == std::end(allowed_types)) {
			std::cout << "The Hubble Type should be: E0-7, S0, Sa, Sb, Sc, SBa, SBb, SBc, or Irr (case sensitive)" << std::endl;
			continue;
		}
		else {
			std::string galaxy_type;
			galaxy_type = temp;
			validated = true;
			return galaxy_type;
		}
	}
}

double get_input(double a, double b) //Function to get the input of user between two defined limits, a and b
{
	double input;
	bool valid_input = false;
	while (!valid_input) {
		std::cin >> input;
		if (std::cin.fail()) {
			std::cout << "Please enter a number" << std::endl;
			std::cin.clear();
			std::cin.ignore();
			continue;
		}
		else if (input > b || input < a) {
			std::cout << "The number should be between " << a << "and " << b << std::endl;
			std::cin.clear();
			std::cin.ignore();
			continue;
		}
		else {
			std::cin.clear();
			std::cin.ignore();
			return input;
		}
	}
}

int main()
{
	bool view = false;
	bool add_more = true;
	std::vector<galaxy> galaxy_data;
	while (add_more) {
		std::string type;
		std::string temp;
		std::cout << "Enter d to create a default galaxy [E0, 0, 0, 0], x to exit this part of the program or any other key to enter a specific galaxy" << std::endl;
		std::cin.clear();
		std::cin >> temp;
		if (temp == "d") {
			galaxy g0;
			galaxy_data.push_back(g0);
			continue;
		}
		else if (temp == "x") {
			add_more = false;
			view = true;
		}
		else {
			std::cout << "Enter the hubble type of the galaxy" << std::endl;
			type = validate_type();
			std::cout << "Enter the redshift of the galaxy" << std::endl;
			double redshift = get_input(0.0, 10.0);
			std::cout << "Enter the mass of the galaxy" << std::endl;
			double mass = get_input(pow(10, 7), pow(10, 12));
			std::cout << "Enter the stellar mass fraction of the galaxy" << std::endl;
			double mass_fraction = get_input(0.0, 0.05);
			std::cout << "If this galaxy has any satellites, enter the number of satellites else, enter 0" << std::endl;
			std::cin.clear();
			int satellite_number;
			std::cin >> satellite_number;
			galaxy g1(type, redshift, mass, mass_fraction);
			for (int i = 0; i < satellite_number; i++) {
				std::cout << "Enter the hubble type of the satellite galaxy" << std::endl;
				type = validate_type();
				std::cout << "Enter the redshift of the satellite galaxy" << std::endl;
				double redshift = get_input(0.0, 10.0);
				std::cout << "Enter the mass of the satellite galaxy" << std::endl;
				double mass = get_input(pow(10, 7), pow(10, 12));
				std::cout << "Enter the stellar mass fraction of the satellite galaxy" << std::endl;
				double mass_fraction = get_input(0.0, 0.05);
				galaxy sat1(type, redshift, mass, mass_fraction);
				g1.galaxy::add_satellite(sat1);
			}
			galaxy_data.push_back(g1);
			std::cout << "To enter data for a new galaxy, press y. To change the type of this galaxy, press x. Pressing any other key will let you view the galaxies you've added." << std::endl;
			std::cin.clear();
			std::cin >> temp;
			if (temp == "y") {
				continue;
			}
			else if (temp == "x") {
				std::cout << "Enter the new galaxy type for this galaxy" << std::endl;
				type = validate_type();
				g1.set_type(type);
				galaxy_data.pop_back();
				galaxy_data.push_back(g1);
				std::cout << "To enter a new galaxy press y, or any other key to view the galaxies" << std::endl;
				std::cin.clear();
				std::cin >> temp;
				if (temp == "y") {
					continue;
				}
				else {
					add_more = false;
					view = true;
				}
			}
			else {
				add_more = false;
				view = true;
			}
		}
	}

	if (view) {
		std::cout << "The galaxies are" << std::endl;
		for (auto galaxy_iterator = galaxy_data.begin(); galaxy_iterator < galaxy_data.end(); galaxy_iterator++) {
			galaxy_iterator->galaxy::print_data();
			galaxy_iterator->galaxy::stellar_mass();
		}
	}
}
