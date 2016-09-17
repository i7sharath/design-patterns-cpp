/*
 * C++ Design Patterns: Bridge
 * Author: Jakub Vojvoda [github.com/JakubVojvoda]
 * 2016
 *
 * Source code is licensed under MIT licence
 * (for more details see LICENCE)
 *
 */

#include <iostream>

/*
 * Implementor
 * defines the interface for implementation classes
 */
class Implementor {
public:
  virtual void action() = 0;
  // ...
};

/*
 * Concrete Implementors
 * implement the Implementor interface and define concrete implementations
 */
class ConcreteImplementorA : public Implementor {
public:
  void action() {
    std::cout << "Concrete Implementor A" << std::endl;
  }
  // ...
};

class ConcreteImplementorB : public Implementor {
public:
  void action() {
    std::cout << "Concrete Implementor B" << std::endl;
  }
  // ...
};

/*
 * Abstraction
 * defines the abstraction's interface
 */
class Abstraction {
public:
  virtual void operation() = 0;
  // ...
};

/*
 * RefinedAbstraction
 * extends the interface defined by Abstraction
 */
class RefinedAbstraction : public Abstraction {
public:
  RefinedAbstraction(Implementor *impl)
    : implementor(impl) {}

  void operation() {
    implementor->action();
  }
  // ...
  
private:
  Implementor *implementor;
};


int main()
{
  Implementor *ia = new ConcreteImplementorA;
  Implementor *ib = new ConcreteImplementorB;

  Abstraction *abstract1 = new RefinedAbstraction(ia);
  abstract1->operation();

  Abstraction *abstract2 = new RefinedAbstraction(ib);
  abstract2->operation();

  return 0;
}
