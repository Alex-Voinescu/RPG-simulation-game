#pragma once
#pragma once
#include <iostream>
class Character
{
public:
	static const int baseAttackDamage;
	static const int baseDefence;
	static const int baseHealthPoints;
	static const int maxAttackDamage;
	static const int maxDefence;
	static const int maxHealthPoints;
	static const int startLvl;
	static const int startHealthPotionsCount;
	static const int healPotionRestorationEffect;

	Character();
	Character(char* name, double attackDamage, double healthPoints, double defence);

	char* getName();
	int getLvl();
	double getAttackDamage();
	double getDefence();
	double getHealthPoints();
	double getRemainingHealthPoints();
	double getHealthPotionsCount();


	void setName(char*& name);
	void setLvl(int lvl);
	void setattackDamage(double attackDamage);
	void setDefence(double defence);
	void setHealthPotints(double healthPoints);
	void setRemainingHealthPoints(double remainingHealthPoints);
	void setHealthPotionsCount(double healthPotionsCount);


	void heal();
	void attack(Character& enemy);
	void lvlUp();
	bool isDead();
	void outputInGame();


	friend std::istream& operator>>(std::istream& in, Character& character);
	friend std::ostream& operator<<(std::ostream& out, Character& character);

	bool operator<(const Character& other) const;
	bool operator>(const Character& other) const;
	bool operator==(const Character& other) const;
	bool operator!=(const Character& other) const;
	Character& operator++();
	Character& operator++(int);
private:
	char* name = nullptr;
	int lvl;
	double attackDamage;
	double defence;
	double healthPoints;
	double remainingHealthPoints;
	double healthPotionsCount;

};

