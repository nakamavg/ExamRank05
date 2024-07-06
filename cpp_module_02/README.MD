# Apuntes
## Modulo 2 examen
### clase spellbook

```cpp
#pragma once
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <map>
#include <string>

class spellBook{

	private:
		spellBook(spellBook const  &other);
		spellBook & operator=(spellBook  const &other);
		std::map<std::string, ASpell*>spells;
	public:
		spellBook();
		~spellBook();
		void learnSpell(ASpell *spell);
		void forgetSpell(std::string  const &name);
		ASpell *createSpell(std::string const &spell);
};
```
- Toca paasar todas las funciones relativas a los hechizos de la clase 
Warlock a la nueva clase SpellBook

#### metodo `ASpell *createSpell(std::string const &spell);`

```cpp
ASpell *spellBook::createSpell(std::string const &spell)
{
	ASpell *tmp = NULL;
	if(spells.find(spell) != spells.end())
		tmp = spells[spell]->clone();
	return tmp;
}
```
- Devuelve un un puntero paa que la clase Warlock en su metodo launchspell pueda lanzar el hechizo

```cpp
void Warlock::launchSpell(const std::string &name,const ATarget &target) 
{
	ASpell *tmp;
	tmp = spellBook.createSpell(name);
	if(tmp != NULL)
	{
		tmp->launch(target);
	}

}
```
- los demas metodos de warlock tambien cambian  y ahora llaman a los metodos de spellBook;

- Para eso dentro de los atributos de la clase Warlock en private
vamos a crear un objeto de tipo SpellBook

```cpp
void Warlock::learnSpell(ASpell *spell)
{
	spellBook.learnSpell(spell);
	
}
void Warlock::forgetSpell(const std::string &name)
{
	spellBook.forgetSpell(name);
}
``````