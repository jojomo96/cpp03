#include <iostream>
#include "FragTrap.hpp"

int main() {
	// Create a FragTrap object
	FragTrap frag("TestFrag");

	// Test attack method
	frag.attack("target1");

	// Test takeDamage method
	frag.takeDamage(30);

	// Test beRepaired method
	frag.beRepaired(20);

	// Test highFiveGuys method
	frag.highFiveGuys();

	// Print final state
	std::cout << "FragTrap " << frag.get_name() << " has " << frag.get_hitpoints() << " hit points and " << frag.get_energy_points() << " energy points." << std::endl;

	return 0;
}
