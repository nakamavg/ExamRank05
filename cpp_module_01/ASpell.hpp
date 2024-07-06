#pragma once
#include <string>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
	protected:
		std::string name;
		std::string effects;
	public:
		ASpell(const std::string &name, const std::string &effects);
		virtual ASpell *clone() const = 0;
		virtual ~ASpell();
		const std::string getName();
		const std::string getEffects() const;
		ASpell( const ASpell  &other);
		ASpell &operator=(const ASpell &other);
		void launch(const ATarget &target) const;	

};

