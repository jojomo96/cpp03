#include "ClapTrap.hpp"

#include <iostream>

// Constructor
ClapTrap::ClapTrap(std::string name) : _name(std::move(name)) {
	std::cout << "ClapTrap " << _name << " created." << std::endl;
}

// Destructor
ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " destroyed." << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &other)
	: _name(other._name), _hitpoints(other._hitpoints), _energyPoints(other._energyPoints),
	  _attackDamage(other._attackDamage) {
	std::cout << "ClapTrap " << _name << " copied." << std::endl;
}

// Copy assignment operator
ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other) {
		_name = other._name;
		_hitpoints = other._hitpoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "ClapTrap " << _name << " assigned." << std::endl;
	return *this;
}

// Move constructor
ClapTrap::ClapTrap(ClapTrap &&other) noexcept
	: _name(std::move(other._name)), _hitpoints(other._hitpoints), _energyPoints(other._energyPoints),
	  _attackDamage(other._attackDamage) {
	other._hitpoints = 0;
	other._energyPoints = 0;
	other._attackDamage = 0;
	std::cout << "ClapTrap " << _name << " moved." << std::endl;
}

// Move assignment operator
ClapTrap &ClapTrap::operator=(ClapTrap &&other) noexcept {
	if (this != &other) {
		_name = std::move(other._name);
		_hitpoints = other._hitpoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;

		other._hitpoints = 0;
		other._energyPoints = 0;
		other._attackDamage = 0;
	}
	std::cout << "ClapTrap " << _name << " move-assigned." << std::endl;
	return *this;
}

bool ClapTrap::check_hitpoints() const {
	if (_hitpoints == 0) {
		std::cout << "ClapTrap " << _name << " is dead and cannot attack." << std::endl;
		return true;
	}
	return false;
}

bool ClapTrap::check_energy_points() const {
	if (_energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " is out of energy and cannot attack." << std::endl;
		return true;
	}
	return false;
}

void ClapTrap::attack(std::string const &target) {
	if (check_hitpoints()) return;

	if (check_energy_points()) return;

	this->_energyPoints -= 1;

	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!"
			<< std::endl;
}

void ClapTrap::takeDamage(const unsigned int amount) {
	if (amount >= _hitpoints) {
		_hitpoints = 0;
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage and is now destroyed." <<
				std::endl;
	} else {
		_hitpoints -= amount;
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage, remaining hit points: " <<
				_hitpoints << "." << std::endl;
	}
}

void ClapTrap::beRepaired(const unsigned int amount) {
	if (check_energy_points()) return;

	if (_hitpoints + amount < _hitpoints) {
		// Check for overflow
		_hitpoints = std::numeric_limits<unsigned int>::max();
		std::cout << "ClapTrap " << _name << " is repaired by " << amount << " points, new hit points: " << _hitpoints
				<< " (max)." << std::endl;
	} else {
		_hitpoints += amount;
		std::cout << "ClapTrap " << _name << " is repaired by " << amount << " points, new hit points: " << _hitpoints
				<< "." << std::endl;
	}
}

std::string ClapTrap::get_name() const {
	return _name;
}

void ClapTrap::set_name(const std::string &name) {
	_name = name;
}

unsigned int ClapTrap::get_hitpoints() const {
	return _hitpoints;
}

void ClapTrap::set_hitpoints(const unsigned int hitpoints) {
	_hitpoints = hitpoints;
}

unsigned int ClapTrap::get_energy_points() const {
	return _energyPoints;
}

void ClapTrap::set_energy_points(const unsigned int energy_points) {
	_energyPoints = energy_points;
}

unsigned int ClapTrap::get_attack_damage() const {
	return _attackDamage;
}

void ClapTrap::set_attack_damage(const unsigned int attack_damage) {
	_attackDamage = attack_damage;
}
