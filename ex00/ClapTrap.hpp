#pragma once
#include <string>

class ClapTrap {
public:
	// Default constructor
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

	[[nodiscard]] bool check_hitpoints() const;

	[[nodiscard]] bool check_energy_points() const;

	void attack(std::string const &target);

	void takeDamage(unsigned int amount);

	void beRepaired(unsigned int amount);

	[[nodiscard]] std::string get_name() const;

	void set_name(const std::string &name);

	[[nodiscard]] unsigned int get_hitpoints() const;

	void set_hitpoints(unsigned int hitpoints);

	[[nodiscard]] unsigned int get_energy_points() const;

	void set_energy_points(unsigned int energy_points);

	[[nodiscard]] unsigned int get_attack_damage() const;

	void set_attack_damage(unsigned int attack_damage);
private:
	std::string _name;
	unsigned int _hitpoints = 10;
	unsigned int _energyPoints = 10;
	unsigned int _attackDamage = 0;
};
