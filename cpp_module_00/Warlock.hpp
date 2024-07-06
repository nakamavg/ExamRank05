#pragma once // #include guard
#include <string>
#include <iostream>

class Warlock
{
private:
	std::string name;
	std::string title;
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
};


