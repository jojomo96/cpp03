#pragma once
#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap {
public:
	// Constructor
	explicit FragTrap(std::string name);

	// Destructor
	~FragTrap() override;

	// Copy constructor
	FragTrap(const FragTrap &other);

	// Copy assignment operator
	FragTrap& operator=(const FragTrap &other);

	// Move constructor
	FragTrap(FragTrap &&other) noexcept;

	// Move assignment operator
	FragTrap& operator=(FragTrap &&other) noexcept;

	// Member functions
	void attack(const std::string &target) override;
	void highFiveGuys();
};
