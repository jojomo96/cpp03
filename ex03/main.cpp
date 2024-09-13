#include <iostream>
#include "DiamondTrap.hpp"

int main() {
	// Create a DiamondTrap object
	DiamondTrap diamond("TestDiamond");

	diamond.printStatus();

	// Test attack method
	diamond.attack("target1");

	// Test takeDamage method
	diamond.takeDamage(30);

	// Test beRepaired method
	diamond.beRepaired(20);

	// Test whoAmI method
	diamond.whoAmI();

	// Print final state
	std::cout << "DiamondTrap " << diamond.get_name() << " has " << diamond.get_hitpoints() << " hit points and " << diamond.get_energy_points() << " energy points." << std::endl;

	return 0;
}
