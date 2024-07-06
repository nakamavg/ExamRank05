#include "ASpell.hpp"

ASpell::ASpell(const std::string &name, const std::string &effects) :
 name (name), effects(effects)
{}
const std::string ASpell::getName(){
	return this->name;
}
const std::string ASpell::getEffects()const{
	return this->effects;
}
ASpell::ASpell(const ASpell &other)
{
	*this = other;
}
ASpell &ASpell::operator=(const ASpell &other)
{
	name = other.name;
	effects = other.effects;
	return *this;
}

void ASpell::launch(const ATarget &target) const
{
	target.getHitBySpell(*this);
}
ASpell::~ASpell(){}