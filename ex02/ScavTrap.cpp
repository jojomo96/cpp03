#include "ScavTrap.hpp"

// Constructor
ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name) {
	_hitpoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << name << " created.\n";
}

// Destructor
ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << get_name() << " destroyed.\n";
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap &other)
	: ClapTrap(other) {
	std::cout << "ScavTrap " << other.get_name() << " copied.\n";
}

// Copy assignment operator
ScavTrap & ScavTrap::operator=(const ScavTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		std::cout << "ScavTrap " << other.get_name() << " assigned.\n";
	}
	return *this;
}

// Move constructor
ScavTrap::ScavTrap(ScavTrap &&other) noexcept
	: ClapTrap(std::move(other)) {
	std::cout << "ScavTrap " << get_name() << " moved.\n";
}

// Move assignment operator
ScavTrap & ScavTrap::operator=(ScavTrap &&other) noexcept {
	if (this != &other) {
		ClapTrap::operator=(std::move(other));
		std::cout << "ScavTrap " << get_name() << " move-assigned.\n";
	}
	return *this;
}

// Member functions
void ScavTrap::attack(const std::string &target) {
	if (is_dead() || is_out_of_energy()) {
		std::cout << "ScavTrap " << get_name() << " cannot attack.\n";
		return;
	}
	std::cout << "ScavTrap " << get_name() << " attacks " << target << ", causing " << get_attack_damage() << " points of damage!\n";
	set_energy_points(get_energy_points() - 1);
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << get_name() << " is now in Gate keeper mode.\n";
}
