#pragma once
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <map>
#include <string>

class SpellBook{

	private:
		SpellBook(SpellBook const  &other);
		SpellBook & operator=(SpellBook  const &other);
		std::map<std::string, ASpell*>spells;
	public:
		SpellBook();
		~SpellBook();
		void learnSpell(ASpell *spell);
		void forgetSpell(std::string  const &name);
		ASpell *createSpell(std::string const &spell);
};