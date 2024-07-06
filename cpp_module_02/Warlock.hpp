#pragma once // #include guard
#include <string>
#include <iostream>
#include <map>
#include "ATarget.hpp"
#include "ASpell.hpp"
#include "SpellBook.hpp"
class Warlock
{
private:
	SpellBook spellBook;
	std::string name;
	std::string title;
	std::map<std::string, ASpell*>spells;
	Warlock();
	Warlock(Warlock const & obj);
	Warlock & operator=(Warlock const & rhs);

public:
	 const std::string& getName() const;//getter que devuelve una referencia al name
	 const std::string& getTitle() const ;//getter que devuelve una referencia al title
	void setTitle(const std::string& title);
	Warlock(const std::string& name ,const std::string& title);
	void introduce() const;
	~Warlock();
	void learnSpell(ASpell *spell);
	void forgetSpell(const std::string &name);
	void launchSpell(const std::string &name,const ATarget &target);
};


