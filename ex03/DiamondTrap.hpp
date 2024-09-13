#pragma once
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
public:
	// Constructor
	explicit DiamondTrap(const std::string &name);

	// Destructor
	~DiamondTrap() override;

	// Copy constructor
	DiamondTrap(const DiamondTrap &other);

	// Copy assignment operator
	DiamondTrap& operator=(const DiamondTrap &other);

	// Move constructor
	DiamondTrap(DiamondTrap &&other) noexcept;

	// Move assignment operator
	DiamondTrap& operator=(DiamondTrap &&other) noexcept;

	// Member functions
	void attack(const std::string &target) override;
	void whoAmI();

private:
	std::string _name;
	DiamondTrap();
};
