#pragma once
#include "ATarget.hpp"
#include <map>
#include <string>

class TargetGenerator{

	private:
		TargetGenerator(TargetGenerator const  &other);
		TargetGenerator & operator=(TargetGenerator  const &other);
		std::map<std::string, ATarget*>targets;
	public:
		TargetGenerator();
		~TargetGenerator();
		void learnTargetType(ATarget *target);
		void forgetTargetType(std::string  const &name);
		ATarget *createTarget(std::string const &target);
};