# Apuntes
## Modulo 0 examen
### clase Warlock

```cpp
#pragma once 
#include <string>
#include <iostream>
class Warlock
{
	private:
	std::string name;
	std::string title;
	public:
	const std::string& getName() const;
	const std::string& getTitle() const;
	void setTitle(const std::string& title);

}
```

- una clase se declara usando class NombreDeLaCLASE
- En este ejercicio noes estan pidiendo dos metodos getter y un setter;
	* getName, returns a reference to constant string
	* getTitle, returns a reference to constant string
	* setTitle, returns void and takes a reference to constant string
- Explicando las palabras clave aqui :
	- # Referencia: 
		1. Eficiencia:
			- Evitamos la copia 
			- Menos operaciones
	- # const
		1.	Protección contra modificaciones:
			-	Inmutabilidad: se garantiza que la función no puede modificar el objeto original.
		2.	Convención y legibilidad:
		3.	Convención de C++: En C++, es una práctica común pasar objetos grandes (como std::string, std::vector, etc.) por referencia constante para mejorar el rendimiento y la seguridad.
		4.	Claridad del código: comunica claramente al lector del código que la función no modificará los argumentos.

```cpp
#pragma once 
#include <string>
#include <iostream>
class Warlock
{
	private:
		std::string name;
		std::string title;
		Warlock();
		Warlock(Warlock const & obj);
		Warlock & operator=(Warloc const & rhs);
	public:
		const std::string& getName() const;
		const std::string& getTitle() const;
		void setTitle(const std::string& title);
		Warlock(const std::string& name, const std::string& name);
		~Warlock();
		void introduce() const :

}
```
- Tambien nos piden que sea en Coplien form que el constructor reciba el nombre y el titulo , y que no se permita ser copiado instanciado en copia o instanciado sin argumentos , es decir estos metodos tienen que ser privados;

- El constructor de copia es:
```cpp
Warlock(Warlock const & obj);	
```
### cpp Warlock

 #### Metodo constructor
```cpp
#include <string>
#include <iostream>
Warlock::Warlock(const std::string& name, const std::string title) : name(name),title(title)
{
	std::cout << name << ": This looks like another boring day."<<std::endl;
}
```
- Esta forma es la mejor forma de inicializar los datos ya que si lo hacemos de otra manera primero se construirian name  y title como elementos vacios y luego hariamos la asignacion de esta forma inicializamos directamente la case con los valores que queramos.

Usar const std::string& en la firma del constructor es importante para:

	•	Optimizar el rendimiento al evitar copias innecesarias.
	•	Garantizar la inmutabilidad de los argumentos dentro del constructor.
	•	Mantener la simplicidad y claridad del código.

Por lo tanto, la elección de const std::string& es tanto una cuestión de eficiencia como de buenas prácticas de programación en C++.

- Luego simplemente hay que hacer
```cpp
std::cout << name << ": This looks like another boring day."<<std::endl
```
`std::cout y std::endl`
son parte de `<iostream>`
y sirven para mostrar por consola y meter un salto de linea;
### Metodo destructor
```cpp
#include <string>
#include <iostream>
Warlock::~Warloc(){
	std::cout << this->name << ": My job here is done!" << std::endl;
}
```
- El destructor se llama automáticamente cuando el objeto sale de su ámbito(scope) o se libera explícitamente usando delete.
- Que es que se salga de su scope 

```cpp
#include <iostream>

class MiClase {
public:
    MiClase() {
        std::cout << "Constructor de MiClase" << std::endl;
    }

    ~MiClase() {
        std::cout << "Destructor de MiClase" << std::endl;
    }
};

int main() {
    {
        MiClase objeto; // Se crea un objeto MiClase dentro de este bloque
    } // Al llegar aquí, el objeto MiClase sale de su ámbito y se destruye automáticamente

    return 0;
} // Fin del ámbito de main, todos los objetos locales se destruyen automáticamente
```
- Si la clase se genera con un new entonces tenemos que llamar a delete para que pase por destructor

#### Metodos getters y setter
```cpp
		const std::string& getName() const {
			return this->Name
		}
		const std::string& getTitle() const {
			return this->Title
		}
		void setTitle(const std::string& title){
			this->Title = title;
		}

```

- Al usar this estamos haciendo referencia al objeto instanciado y obteniendo los valores que necesitamos.

#### metodo introduce
```cpp
void Warlock::introduce() const 
{
	    std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}
```