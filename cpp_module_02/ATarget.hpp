#pragma once
#include <string>
#include "ASpell.hpp"
#include <iostream>

class ASpell;

class ATarget
{
	protected:
		std::string type;
	public:
		ATarget(const std::string &type);
		virtual ATarget *clone() const = 0;
		virtual ~ATarget();
		const std::string &getType() const;
		ATarget( const ATarget  &other);
		ATarget &operator=(const ATarget &other);
		void getHitBySpell(const ASpell &spell) const;
};

