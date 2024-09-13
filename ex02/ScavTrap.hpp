#pragma once
#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap {
public:
	// Constructor
	explicit ScavTrap(std::string name);

	// Destructor
	~ScavTrap() override;

	// Copy constructor
	ScavTrap(const ScavTrap &other);

	// Copy assignment operator
	ScavTrap& operator=(const ScavTrap &other);

	// Move constructor
	ScavTrap(ScavTrap &&other) noexcept;

	// Move assignment operator
	ScavTrap& operator=(ScavTrap &&other) noexcept;

	// Member functions
	void attack(const std::string &target) override;
	void guardGate();
private:
	ScavTrap();
};
