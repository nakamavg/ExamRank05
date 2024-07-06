#include "SpellBook.hpp"

SpellBook::SpellBook(){}
SpellBook::SpellBook(const SpellBook &other){
	*this=other;
}
SpellBook &SpellBook::operator=(const SpellBook &other)
{
	if(this != &other)
	{
		spells=other.spells;
	}
	return *this;
}
SpellBook::~SpellBook(){
	std::map<std::string, ASpell *>::iterator it_begin = spells.begin();
	std::map<std::string, ASpell *>::iterator it_end = spells.end();
	while(it_begin != it_end)
	{
		delete it_begin->second;
		it_begin++;
	}
	spells.clear();

}

void SpellBook::learnSpell(ASpell *spell){
	if(spell)
	{
		spells[spell->getName()] = spell->clone();
	}
}

void SpellBook::forgetSpell(std::string const &name)
{
	std::map<std::string , ASpell*>::iterator it_begin = spells.find(name);
	if(it_begin != spells.end())
	{
		delete it_begin->second;
	}
}
ASpell *SpellBook::createSpell(std::string const &spell)
{
	ASpell *tmp = NULL;
	if(spells.find(spell) != spells.end())
		tmp = spells[spell]->clone();
	return tmp;
}


