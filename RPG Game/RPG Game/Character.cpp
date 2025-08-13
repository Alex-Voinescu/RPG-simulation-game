#include "Character.h"


const int Character::baseAttackDamage = 2;
const int Character::baseDefence = 40;
const int Character::baseHealthPoints = 35;
const int Character::maxAttackDamage = 44;
const int Character::maxDefence = 450;
const int Character::maxHealthPoints = 300;
const int Character::startLvl = 1;
const int Character::startHealthPotionsCount = 4;
const int Character::healPotionRestorationEffect = 30;

Character::Character()
{
	name = nullptr;
	lvl = startLvl;
	attackDamage = baseAttackDamage;
	defence = baseDefence;
	healthPoints = baseHealthPoints;
	healthPotionsCount = startHealthPotionsCount;
	remainingHealthPoints = baseHealthPoints;
}

Character::Character(char* name, double attackDamage, double healthPoints, double defence)
{
	setName(name);
	setattackDamage(attackDamage);
	setHealthPotints(healthPoints);
	setDefence(defence);
	lvl = startLvl;
	healthPotionsCount = startHealthPotionsCount;
	setRemainingHealthPoints(healthPoints);
}



char* Character::getName()
{
	return name;
}

int Character::getLvl()
{
	return lvl;
}

double Character::getAttackDamage()
{
	return attackDamage;
}

double Character::getDefence()
{
	return defence;
}

double Character::getHealthPoints()
{
	return healthPoints;
}

double Character::getRemainingHealthPoints()
{
	return remainingHealthPoints;
}

double Character::getHealthPotionsCount()
{
	return healthPoints;
}

void Character::setName(char*& name)
{
	this->name = name;
}

void Character::setLvl(int lvl)
{
	this->lvl = lvl;
}

void Character::setattackDamage(double attackDamage)
{
	if (attackDamage < baseAttackDamage)
		this->attackDamage = baseAttackDamage;
	else if (attackDamage > maxAttackDamage)
		this->attackDamage = maxAttackDamage;
	else
		this->attackDamage = attackDamage;
}

void Character::setDefence(double defence)
{
	if (defence < baseDefence)
		this->defence = baseDefence;
	else if (defence > maxDefence)
		this->defence = maxDefence;
	else
		this->defence = defence;
}

void Character::setHealthPotints(double healthPoints)
{
	if (healthPoints < baseHealthPoints)
		this->healthPoints = baseHealthPoints;
	else if (healthPoints > maxHealthPoints)
		this->healthPoints = maxHealthPoints;
	else
		this->healthPoints = healthPoints;
}

void Character::setRemainingHealthPoints(double remainingHealthPoints)
{
	if (remainingHealthPoints > maxHealthPoints)
		this->remainingHealthPoints = maxHealthPoints;
	else
		this->remainingHealthPoints = remainingHealthPoints;
}

void Character::setHealthPotionsCount(double healthPotionsCount)
{
	this->healthPotionsCount = healthPotionsCount;
}

void Character::heal()
{
	if (healthPotionsCount > 0)
	{
		if (remainingHealthPoints + healPotionRestorationEffect > healthPoints)
		{
			remainingHealthPoints = healthPoints;
		}
		else
			remainingHealthPoints += healPotionRestorationEffect;
		healthPotionsCount--;
	}
	else
		std::cout << "No more potions\n";

}

void Character::attack(Character& enemy)
{
	double damageDealt = attackDamage * std::min((double)enemy.healthPoints / enemy.defence, 1.0);
	enemy.setRemainingHealthPoints(enemy.remainingHealthPoints - damageDealt);
}

void Character::lvlUp()
{
	setattackDamage(this->attackDamage + baseAttackDamage);
	setDefence(this->defence + baseDefence);
	setHealthPotints(this->healthPoints + baseHealthPoints);
	lvl++;
	setRemainingHealthPoints(this->remainingHealthPoints + baseHealthPoints);
	setHealthPotionsCount(this->healthPotionsCount + startHealthPotionsCount);

}

bool Character::isDead()
{
	if (this->remainingHealthPoints <= 0)
		return true;
	return false;
}

void Character::outputInGame()
{
	std::cout << this->name << " Level: " << this->lvl << " Attack Damage: " << this->attackDamage << " Defence: " << this->defence << " Remaining health: " << this->remainingHealthPoints << "\n";
}

bool Character::operator<(const Character& other) const
{
	double prodThis = healthPoints * attackDamage * defence;
	double prodOther = other.healthPoints * other.attackDamage * other.defence;
	if (prodThis < prodOther)
		return true;
	return false;
}

bool Character::operator>(const Character& other) const
{
	double prodThis = healthPoints * attackDamage * defence;
	double prodOther = other.healthPoints * other.attackDamage * other.defence;
	if (prodThis > prodOther)
		return true;
	return false;
}

bool Character::operator==(const Character& other) const
{
	double prodThis = healthPoints * attackDamage * defence;
	double prodOther = other.healthPoints * other.attackDamage * other.defence;
	if (prodThis == prodOther)
		return true;
	return false;
}

bool Character::operator!=(const Character& other) const
{
	return !(*this == other);
}

Character& Character::operator++()
{
	this->lvlUp();
	return *this;
}

Character& Character::operator++(int)
{
	Character temp = *this;
	this->lvlUp();
	return temp;
}

std::istream& operator>>(std::istream& in, Character& character)
{
	char* name = new char[256];
	double attackDamage, healthPoints, defence, lvl;
	in >> name >> lvl >> attackDamage >> healthPoints >> defence;
	character.lvl = lvl;
	character.setName(name);
	character.setattackDamage(attackDamage);
	character.setHealthPotints(healthPoints);
	character.setDefence(defence);
	character.setRemainingHealthPoints(healthPoints);
	return in;
}

std::ostream& operator<<(std::ostream& out, Character& character)
{
	out << character.name << " " << character.lvl << " " << character.attackDamage << " " << character.defence << " " << character.healthPoints << " " << character.remainingHealthPoints << "\n";
	return out;
}

