# Apuntes
## Modulo 1 examen
### clases Abstractas

### Aspell

```cpp
class Aspell
{
	protected:
		std::string name;
		std::string effects;
	public:
		Aspell(const std::string &name, const std::string &effects);
		virtual Aspell*clone() const = 0;
		const std::string getName();
		const std::string getEffects();
		Aspell( const Aspell &other);
		Aspell operator=(const Aspell &other);
		virtual ~Aspell();

}
```

#### Atrinbutos protegidos

- protected:
	-  std::string name;
    - std::string effects;

- Estos atributos están protegidos para que las clases derivadas puedan acceder a ellos directamente.
- La diferencia entre private y protected es que estos pueden ser usados dentro de las clases que heredan la clase Aspell;

##### caso incorrecto
```cpp
Aspell a("nombre", "efectos");
std::cout << a.name; // Esto dará un error de compilación
```
##### caso correcto
```cpp
Aspell a("nombre", "efectos");
std::cout << a.getName(); //para eso tenemos los getters;
```

#### clase ATarget

```cpp
#pragma once
#include <string>
#include "ASpell.hpp"
#include <iostream>

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
		void getHitBySpell(const Aspell &spell) const;
};

```
##### Inclusion de Aspell

- La funcion `void getHitBySpell(const Aspell &spell) const;`
- Recibe una constante de la clase Aspell pasada por referencia para evitar 
duplicados.
- el const final es para decir que no va cambiar el estado de Atarget

## Clases concretas que deviran de las Abstractas

- La sitaxis de la herencia en c++ es
```cpp
class DerivedClass : accessSpecifier BaseClass {
    // cuerpo de la clase derivada
};

```
- accessSpecifier puede ser public, protected, o private.
#### Public Inheritance (public)
- Cuando una clase se hereda públicamente de otra:

	- •	Los miembros públicos de la clase base se convierten en miembros públicos de la clase derivada.
	- •	Los miembros protegidos de la clase base se convierten en miembros protegidos de la clase derivada.
	- •	Los miembros privados de la clase base no son accesibles directamente desde la clase derivada, aunque siguen existiendo en ella.
```cpp
#pragma once
#include "Aspell.cpp"

class Fwoosh : public Aspell
{
	public: 
		Fwoosh();
		~Fwoosh();
		virtual Aspell *clone() const;
};

```

- Fwoosh hereda públicamente de ASpell. Esto significa que todos los métodos públicos de ASpell (getName, getEffects, y clone) están disponibles públicamente en Fwoosh.

#### Como implementar el constructor y el metodo clone 

```cpp
Fwoosh::Fwoosh() : Aspell("Fwoosh" , "fwooshed")
{}
```
- La parte Aspell("Fwoosh" , "fwooshed") estamos llamando al constructor
de la clase original 
```cpp
		Aspell(const std::string &name, const std::string &effects);
```
- Es más eficiente inicializar los miembros directamente en la lista de inicialización que asignarles valores dentro del cuerpo del constructor. 
- Esto se debe a que los miembros se inicializan en el orden en que se declaran en la clase base, no en el orden en que aparecen en la lista de inicialización.
- En este caso, name y effects se inicializan directamente con los valores "Fwoosh" y "fwooshed".


## Clase Warlock 

```cpp
#pragma once // #include guard
#include <string>
#include <iostream>
#include <map>
#include "Atarget.hpp"
#include "Aspell.hpp"

class Warlock
{
private:
	std::string name;
	std::string title;
	std::map<std::string, Aspell*>spells;
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
	void learnSpell(Aspell *spell);
	void forgetSpell(const std::string &name);
	void launchSpell(const std::string &name,const ATarget &target);
};

```

- incluimos `<map>`
- Ahora tenemos un mapa privado para crearlo le decimos 
	-std::map
	- `<std::string, Aspell*>`
	- la clave es un string que guarda punteros objetos hechizo

#### Nuevos metodos

```cpp
void Warlock::learnSpell(Aspell *spell)
{
	if (spell)
		spells[spell->getName()] = spell->clone(); 
	
}
```
- 1 Recibimos un puntero al spell
- 2 comprobamos que exista spell
- 3 spells[spell->getName()] = spell->clone();:
	-	spell->getName(): Llama al método getName() del objeto spell, que devuelve el nombre del hechizo.
	-	spell->clone(): Llama al método clone() de ASpell, que se supone que devuelve un puntero a una nueva instancia de ASpell (o de una clase derivada como Fwoosh en el caso anterior).
	-	spells[spell->getName()] = ...;: Utiliza el nombre del hechizo como clave en el mapa spells y asigna al valor el resultado de spell->clone(). Esto significa que el Warlock está aprendiendo o almacenando el hechizo spell en su colección de hechizos (spells).


- Razones para usar clone() en learnSpell()

	•	Al clonar el hechizo utilizando clone(), el Warlock obtiene su propia copia del hechizo.
	•	Esto evita problemas de compartir la misma instancia de hechizo entre múltiples Warlock o entre Warlock y otros objetos.
	•	Permite que cada Warlock tenga control sobre su propia instancia de hechizo y pueda liberarla correctamente cuando sea necesario.

```cpp
void Warlock::forgetSpell(const std::string &name)
{
	if (spell.find(name) != spells.end())
		spells.erase(spells.find(name));
	
}
```

1. Pequeña comprobacion el metodo find del mapa devuelve end si no encuentra el hechizo
2. Si lo encuentra lo borramos como el metodo erase
3. lo que borramos es la entrada del mapa pero no el objeto al que apunta el puntero para esto tenemos que mejorar nuesto destructor

```cpp
Warlock::~Warlock()
{
	std::cout << this->name << ": My job here is done!" << std::endl;
	for(
	std::map<std::string , Aspell*>::iterator it=spells.begin();
	it != spells.end(); it++)
	{
		delete it->second;		
	}
	spells.clear();
}
```
1. Dentro del bucle de borrado , inicializamos un iterador:
	- ```cpp
		std::map<std::string , Aspell *>::iterator it = spells.begin();
	  ```
		-  Inicializamos el iterador con que apunte al inicio de spells con
		spells.begin
	- ```cpp
	  	it != spells.end()
	  ```
	  - estara dentro del bucle mientras it no apunte al final 
	- it++ avanzamos el puntero en cada vuelta
	
	- spells.clear(); limpia el mapa despues de liberar la memoria de cada objeto

```cpp
void Warlock::launchSpell(const std::string &name,const Atarget &target)
{
	if(spells.find(name) != spells.end())
		spells[name]->launch(target);
}
```

- usa metodo launch sobre el target si encuentra el spell dentro del mapa