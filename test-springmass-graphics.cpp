/** file: test-springmass-graphics.cpp
 ** brief: Tests the spring mass simulation with graphics
 ** author: Andrea Vedaldi
 **/

#include "graphics.h"
#include "springmass.h"

#include <iostream>
#include <sstream>
#include <iomanip>

/* ---------------------------------------------------------------- */
class SpringMassDrawable : public SpringMass, public Drawable
/* ---------------------------------------------------------------- */
{
/* INCOMPLETE: TYPE YOUR CODE HERE */
private:
  Figure figure;

public:
  SpringMassDrawable()
  : figure("Bouncing Balls and Sticks")
  {
    figure.addDrawable(this);
  }

  void draw() {
    unsigned int i;

    for(i = 0; i < masses.size(); i++) {
      figure.drawCircle(masses.at(i).getPosition().x,masses.at(i).getPosition().y,masses.at(i).getRadius());
    }
    for(i = 0; i < springs.size(); i++) {
      figure.drawLine(springs.at(i).getMass1()->getPosition().x, springs.at(i).getMass1()->getPosition().y,
                      springs.at(i).getMass2()->getPosition().x, springs.at(i).getMass2()->getPosition().y, 0.1);
    }
  }

  void display() {
    figure.update();
  }
};

int main(int argc, char** argv)
{
  glutInit(&argc,argv) ;

  SpringMassDrawable springmass ;

  const double mass = 0.05 ;
  const double radius = 0.02 ;
  const double naturalLength = 0.95 ;
  const double stiffness = 0.3;
  const double damping = 0.01;

  Mass m1(Vector2(-0.5,-0.2), Vector2(), mass, radius) ;
  Mass m2(Vector2(+0.5,0), Vector2(), mass, radius) ;

  springmass.addMass(m1);
  springmass.addMass(m2);
  springmass.newSpring(0, 1, naturalLength, damping, stiffness);

  run(&springmass, 1/120.0) ;
}
