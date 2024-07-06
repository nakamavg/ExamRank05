#include "Warlock.hpp"
#include "Fwoosh.hpp"
#include "Dummy.hpp"
#include "BrickWall.hpp"
#include "Polymorph.hpp"
#include "TargetGenerator.hpp"
#include "Fireball.hpp"
#include "ATarget.hpp"
#include "ASpell.hpp"
#include "SpellBook.hpp"

int main()
{
  Warlock richard("Richard", "foo");
  richard.setTitle("Hello, I'm Richard the Warlock!");
  BrickWall model1;
  Dummy model2;

  Polymorph* polymorph = new Polymorph();
  TargetGenerator tarGen;

  tarGen.learnTargetType(&model1);
  tarGen.learnTargetType(&model2);
  richard.learnSpell(polymorph);
  richard.launchSpell("Polymorph", model1);
  

  Fireball* fireball = new Fireball();

  richard.learnSpell(fireball);


  ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall");
  ATarget* wall2 = tarGen.createTarget("Target Practice Dummy");



  richard.introduce();
  std::cout<<"peta"<<std::endl;
  richard.launchSpell("Polymorph", *wall);
  richard.launchSpell("Fireball", *wall);
  richard.launchSpell("Fireball", *wall2);

  
}
