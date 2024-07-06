#include "ATarget.hpp"

ATarget::ATarget(const std::string &type) : type(type){};
ATarget::~ATarget(){};
const std::string& ATarget::getType() const
{
	return this->type;
}
ATarget::ATarget(ATarget const &other)
{	
	*this = other;
}
ATarget &ATarget::operator=(const ATarget &other)
{
	 if (this != &other) {
        type = other.type;
    }
    return *this;
}

void ATarget::getHitBySpell(const ASpell &spell) const{
std::cout << type << "has been " << spell.getEffects() << std::endl;
}