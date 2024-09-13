#pragma once
#include <string>

class ClapTrap {
public:
	// Constructor
	explicit ClapTrap(std::string name);

	// Destructor
	~ClapTrap();

	// Copy constructor
	ClapTrap(const ClapTrap &other);

	// Copy assignment operator
	ClapTrap& operator=(const ClapTrap &other);

	// Move constructor
	ClapTrap(ClapTrap &&other) noexcept;

	// Move assignment operator
	ClapTrap& operator=(ClapTrap &&other) noexcept;

	// Member functions
	[[nodiscard]] bool is_dead() const;
	[[nodiscard]] bool is_out_of_energy() const;
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void printStatus() const;

	// Getters
	[[nodiscard]] std::string get_name() const;
	[[nodiscard]] unsigned int get_hitpoints() const;
	[[nodiscard]] unsigned int get_energy_points() const;
	[[nodiscard]] unsigned int get_attack_damage() const;

	// Setters
	void set_name(const std::string &name);
	void set_hitpoints(unsigned int hitpoints);
	void set_energy_points(unsigned int energy_points);
	void set_attack_damage(unsigned int attack_damage);

private:
	ClapTrap();
	std::string _name;
	unsigned int _hitpoints = 10;
	unsigned int _energyPoints = 10;
	unsigned int _attackDamage = 0;
};
