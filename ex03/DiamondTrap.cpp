#include "DiamondTrap.hpp"
#include <iostream>

// Constructor
DiamondTrap::DiamondTrap(const std::string &name)
	: ClapTrap(name + "_clap_name"), FragTrap(name),  ScavTrap(name), _name(name) {
	// _hitpoints = FragTrap::_hitpoints;
	// _energyPoints = ScavTrap::_energyPoints;
	// _attackDamage = FragTrap::_attackDamage;
	_hitpoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	std::cout << "DiamondTrap " << this->_name << " created." << std::endl;
}

// Destructor
DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->_name << " destroyed." << std::endl;
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap &other)
	: ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name) {
	std::cout << "DiamondTrap " << this->_name << " copied." << std::endl;
}

// Copy assignment operator
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		FragTrap::operator=(other);
		ScavTrap::operator=(other);
		this->_name = other._name;
	}
	std::cout << "DiamondTrap " << this->_name << " assigned." << std::endl;
	return *this;
}

// Move constructor
DiamondTrap::DiamondTrap(DiamondTrap &&other) noexcept
	: ClapTrap(std::move(other)), FragTrap(std::move(other)), ScavTrap(std::move(other)),
	  _name(std::move(other._name)) {
	std::cout << "DiamondTrap " << this->_name << " moved." << std::endl;
}

// Move assignment operator
DiamondTrap &DiamondTrap::operator=(DiamondTrap &&other) noexcept {
	if (this != &other) {
		ClapTrap::operator=(std::move(other));
		FragTrap::operator=(std::move(other));
		ScavTrap::operator=(std::move(other));
		this->_name = std::move(other._name);
	}
	std::cout << "DiamondTrap " << this->_name << " move-assigned." << std::endl;
	return *this;
}

// Member functions
void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << "I am " << this->_name << " and my ClapTrap name is " << ClapTrap::_name << "." << std::endl;
}

DiamondTrap::DiamondTrap() : ClapTrap("Default"), FragTrap("Default"), ScavTrap("Default") {
	std::cout << "DiamondTrap " << this->_name << " created." << std::endl;
}
