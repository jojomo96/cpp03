#include <iostream>
#include "ScavTrap.hpp"

int main() {
	// Create a ScavTrap object
	ScavTrap scav("TestScav");

	// Test attack method
	scav.attack("target1");

	// Test takeDamage method
	scav.takeDamage(20);

	// Test beRepaired method
	scav.beRepaired(10);

	// Test guardGate method
	scav.guardGate();

	// Print final state
	std::cout << "ScavTrap " << scav.get_name() << " has " << scav.get_hitpoints() << " hit points and " << scav.get_energy_points() << " energy points." << std::endl;

	return 0;
}
