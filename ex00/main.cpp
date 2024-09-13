#include <iostream>
// #include <cassert>
#include "ClapTrap.hpp"

void testClapTrap() {
	// Create a ClapTrap instance
	ClapTrap claptrap("TestBot");

	std::cout << std::endl;
	// Test attack with sufficient energy points
	std::cout << "Test: Attack with sufficient energy points" << std::endl;
	claptrap.attack("Target1");
	// assert(claptrap.get_energy_points() == 9); // Assuming attack costs 1 energy point

	std::cout << std::endl;
	// Test attack with attack damage set to 5
	std::cout << "Test: Attack with attack damage set to 5" << std::endl;
	claptrap.set_attack_damage(5);
	claptrap.attack("Target2");
	// assert(claptrap.get_energy_points() == 8); // Assuming attack costs 1 energy point

	std::cout << std::endl;
	// Test attack with zero energy points
	std::cout << "Test: Attack with zero energy points" << std::endl;
	claptrap.set_energy_points(0);
	claptrap.attack("Target2");
	// assert(claptrap.get_energy_points() == 0); // Energy points should remain zero

	std::cout << std::endl;
	// Reset energy points for further tests
	claptrap.set_energy_points(10);

	std::cout << std::endl;
	// Test takeDamage with damage less than hit points
	std::cout << "Test: Take damage less than hit points" << std::endl;
	claptrap.takeDamage(5);
	// assert(claptrap.get_hitpoints() == 5); // Assuming initial hit points were 10

	std::cout << std::endl;
	// Test takeDamage with damage equal to hit points
	std::cout << "Test: Take damage equal to hit points" << std::endl;
	claptrap.takeDamage(5);
	// assert(claptrap.get_hitpoints() == 0); // Hit points should be zero

	std::cout << std::endl;
	// Test takeDamage with damage greater than hit points
	claptrap.set_hitpoints(5);
	std::cout << "Test: Take damage greater than hit points" << std::endl;
	claptrap.takeDamage(10);
	// assert(claptrap.get_hitpoints() == 0); // Hit points should be zero

	std::cout << std::endl;
	// Reset hit points for further tests
	claptrap.set_hitpoints(10);

	std::cout << std::endl;
	// Test beRepaired with normal amount
	std::cout << "Test: Be repaired with normal amount" << std::endl;
	claptrap.beRepaired(5);
	// assert(claptrap.get_hitpoints() == 15); // Assuming initial hit points were 10

	std::cout << std::endl;
	// Test beRepaired with amount causing overflow
	std::cout << "Test: Be repaired with amount causing overflow" << std::endl;
	claptrap.beRepaired(std::numeric_limits<unsigned int>::max());
	// assert(claptrap.get_hitpoints() == std::numeric_limits<unsigned int>::max()); // Hit points should be max

	std::cout << std::endl;
	// Test beRepaired with amount causing overflow
	std::cout << "Test: Be repaired with amount causing overflow" << std::endl;
	claptrap.beRepaired(1);
	// assert(claptrap.get_hitpoints() == std::numeric_limits<unsigned int>::max()); // Hit points should remain max

	std::cout << std::endl;
	// Test beRepaired with zero energy points
	std::cout << "Test: Be repaired with zero energy points" << std::endl;
	claptrap.set_energy_points(0);
	claptrap.beRepaired(5);
	// assert(claptrap.get_hitpoints() == std::numeric_limits<unsigned int>::max()); // Hit points should remain max
}

void testClapTrapConstructors() {
	std::cout << "Test: Default constructor" << std::endl;
	ClapTrap claptrap1("ClapTrap1");
	// assert(claptrap1.get_name() == "ClapTrap1");

	std::cout << std::endl;
	std::cout << "Test: Copy constructor" << std::endl;
	ClapTrap claptrap2(claptrap1);
	// assert(claptrap2.get_name() == "ClapTrap1");

	std::cout << std::endl;
	std::cout << "Test: Copy assignment operator" << std::endl;
	ClapTrap claptrap3("ClapTrap3");
	claptrap3 = claptrap1;
	// assert(claptrap3.get_name() == "ClapTrap1");

	std::cout << std::endl;
	std::cout << "Test: Move constructor" << std::endl;
	ClapTrap claptrap4(std::move(claptrap1));
	// assert(claptrap4.get_name() == "ClapTrap1");

	std::cout << std::endl;
	std::cout << "Test: Move assignment operator" << std::endl;
	ClapTrap claptrap5("ClapTrap5");
	claptrap5 = std::move(claptrap2);
	// assert(claptrap5.get_name() == "ClapTrap1");

	std::cout << std::endl;
	std::cout << "Test: Destructor" << std::endl; {
		ClapTrap claptrap6("ClapTrap6");
		// assert(claptrap6.get_name() == "ClapTrap6");
	} // Destructor will be called here
}

int main() {
	testClapTrapConstructors();
	testClapTrap();
	return 0;
}
