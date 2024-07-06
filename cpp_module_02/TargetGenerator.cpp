#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(){}
TargetGenerator::~TargetGenerator(){
	std::map<std::string, ATarget *>::iterator begin = targets.begin();
	std::map<std::string, ATarget *>::iterator end = targets.end();
	while(begin != end)
	{
		delete begin->second;
		begin++;
	}
	targets.clear();
	
}
TargetGenerator::TargetGenerator(const TargetGenerator &other){
	*this = other;
}
TargetGenerator & TargetGenerator::operator=(const TargetGenerator &other){
	if(this != &other)
	{
		targets=other.targets;
	}
	return *this;
}
void TargetGenerator::learnTargetType(ATarget *target)
{
	if(target)
	{
		std::cout <<"tipo de target:"<< target->getType() << std::endl;

		targets[target->getType()] = target->clone();
	}
}
void TargetGenerator::forgetTargetType(std::string  const &name){
	std::map<std::string, ATarget *>::iterator it = targets.find(name);
	if(it != targets.end())
	{
		delete it->second;
	}
}
ATarget *TargetGenerator::createTarget(std::string const &target)
{
	std::map<std::string,ATarget *>::iterator tmp = targets.find(target);
	if(tmp != targets.end())
	{
		std::cout <<"tipo de target:"<< targets[target]->getType() << std::endl;
		return targets[target];
	}
	return NULL;
}

