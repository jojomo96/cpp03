
#include "FragTrap.hpp"

// Constructor
FragTrap::FragTrap(std::string name)
	: ClapTrap(name) {
	_hitpoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << name << " created.\n";
}

// Destructor
FragTrap::~FragTrap() {
	std::cout << "FragTrap " << get_name() << " destroyed.\n";
}

// Copy constructor
FragTrap::FragTrap(const FragTrap &other)
	: ClapTrap(other) {
	std::cout << "FragTrap " << other.get_name() << " copied.\n";
}

// Copy assignment operator
FragTrap & FragTrap::operator=(const FragTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		std::cout << "FragTrap " << other.get_name() << " assigned.\n";
	}
	return *this;
}

// Move constructor
FragTrap::FragTrap(FragTrap &&other) noexcept
	: ClapTrap(std::move(other)) {
	std::cout << "FragTrap " << get_name() << " moved.\n";
}

// Move assignment operator
FragTrap & FragTrap::operator=(FragTrap &&other) noexcept {
	if (this != &other) {
		ClapTrap::operator=(std::move(other));
		std::cout << "FragTrap " << get_name() << " move-assigned.\n";
	}
	return *this;
}

// Member functions
void FragTrap::attack(const std::string &target) {
	if (is_dead() || is_out_of_energy()) {
		std::cout << "FragTrap " << get_name() << " cannot attack.\n";
		return;
	}
	std::cout << "FragTrap " << get_name() << " attacks " << target << ", causing " << get_attack_damage() << " points of damage!\n";
	set_energy_points(get_energy_points() - 1);
}

void FragTrap::highFiveGuys() {
	std::cout << "FragTrap " << get_name() << " says: High five, guys!\n";
}
