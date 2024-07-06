#include "Warlock.hpp"

Warlock::Warlock(const std::string& name ,const std::string& title)
: name (name), title(title)
{
	std::cout << name << ": This looks like another boring day."<<std::endl;

}

void Warlock::introduce() const 
{
	    std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}
Warlock::~Warlock()
{
	std::cout << this->name << ": My job here is done!" << std::endl;
	for(
	std::map<std::string , ASpell*>::iterator it=spells.begin();
	it != spells.end(); it++)
	{	
		std::cout << "hola" << std::endl;
		delete it->second;		
	}
	spells.clear();
}

void Warlock::setTitle(const std::string& title) 
{
	this->title = title;
}

const std::string& Warlock::getName() const {
    return this->name;
}
const std::string& Warlock::getTitle() const
{
	return this->title;
}

void Warlock::learnSpell(ASpell *spell)
{
	spellBook.learnSpell(spell);
	
}
void Warlock::forgetSpell(const std::string &name)
{
	spellBook.forgetSpell(name);
}
void Warlock::launchSpell(const std::string &name,const ATarget &target) 
{
	ASpell *tmp;
	tmp = spellBook.createSpell(name);
	if(tmp != NULL)
	{
		tmp->launch(target);
	}

}
