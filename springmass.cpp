/** file: springmass.cpp
 ** brief: SpringMass simulation implementation
 ** author: Andrea Vedaldi
 **/

#include "springmass.h"

#include <iostream>

/* ---------------------------------------------------------------- */
// class Mass
/* ---------------------------------------------------------------- */

Mass::Mass()
: position(), velocity(), force(), mass(1), radius(1)
{ }

Mass::Mass(Vector2 position, Vector2 velocity, double mass, double radius)
: position(position), velocity(velocity), force(), mass(mass), radius(radius),
xmin(-1),xmax(1),ymin(-1),ymax(1)
{ }

void Mass::setForce(Vector2 f)
{
  force = f ;
}

void Mass::addForce(Vector2 f)
{
  force = force + f ;
}

Vector2 Mass::getForce() const
{
  return force ;
}

Vector2 Mass::getPosition() const
{
  return position ;
}

Vector2 Mass::getVelocity() const
{
  return velocity ;
}

double Mass::getRadius() const
{
  return radius ;
}

double Mass::getMass() const
{
  return mass ;
}

double Mass::getEnergy(double gravity) const
{
  double energy = 0;
  double E_cinetica, E_potencial; 

  E_cinetica = (mass * (velocity.norm2() ))/2;
  E_potencial = mass * gravity * (position.y - radius);
  energy = E_cinetica + E_potencial;

  return energy ;
}

void Mass::step(double dt)
{
  Vector2 a;

  a = force/mass;

  if (xmin + radius <= position.x && position.x <= xmax - radius) {
    position.x = position.x + (velocity.x*dt + ((a.x*dt*dt)/2));
    velocity.x = velocity.x + (a.x*dt);
  } else {
    velocity.x = -velocity.x;
  }
  if (ymin + radius <= position.y && position.y <= ymax - radius) {
    position.y = position.y + (velocity.y*dt + ((a.y*dt*dt)/2));
    velocity.y = velocity.y + (a.y*dt);
  } else {
    velocity.y = -velocity.y;
  }
}

/* ---------------------------------------------------------------- */
// class Spring
/* ---------------------------------------------------------------- */

Spring::Spring(Mass * mass1, Mass * mass2, double naturalLength, double stiffness, double damping)
: mass1(mass1), mass2(mass2),
naturalLength(naturalLength), stiffness(stiffness), damping(damping)
{ }

Mass * Spring::getMass1() const
{
  return mass1 ;
}

Mass * Spring::getMass2() const
{
  return mass2 ;
}

Vector2 Spring::getForce() const
{
  Vector2 F, u, unitario;
  double current_length, velocidada_de_alongamento;

  u = mass1->getPosition() - mass2->getPosition();
  current_length = u.norm();
  unitario = u/current_length;
  velocidada_de_alongamento = dot( unitario, (mass1->getVelocity() - mass2->getVelocity()) );

  F = ((naturalLength - current_length) * stiffness + velocidada_de_alongamento + damping) * unitario;

  return F ;
}

double Spring::getLength() const
{
  Vector2 u = mass2->getPosition() - mass1->getPosition() ;
  return u.norm() ;
}

double Spring::getEnergy() const {
  double length = getLength() ;
  double dl = length - naturalLength;
  return 0.5 * stiffness * dl * dl ;
}

std::ostream& operator << (std::ostream& os, const Mass& m)
{
  os<<"("
  <<m.getPosition().x<<","
  <<m.getPosition().y<<")" ;
  return os ;
}

std::ostream& operator << (std::ostream& os, const Spring& s)
{
  return os<<"$"<<s.getLength() ;
}

/* ---------------------------------------------------------------- */
// class SpringMass : public Simulation
/* ---------------------------------------------------------------- */

SpringMass::SpringMass(double gravity)
: gravity(gravity)
{ }

void SpringMass::display()
{
  unsigned int i;

  for(i=0; i < masses.size(); i++)
    std::cout << masses.at(i) << std::endl;
  
  for(i=0; i < springs.size(); i++)
    std::cout << springs.at(i)<< std::endl;
  
  std::cout << getEnergy() << std::endl;
}

double SpringMass::getEnergy() const
{
  unsigned int i;
  double energy = 0 ;

  for(i=0; i < masses.size(); i++)
    energy += masses.at(i).getEnergy(gravity);

  for(i=0; i < springs.size(); i++)
    energy += springs.at(i).getEnergy();

  return energy ;
}

void SpringMass::step(double dt)
{
  Vector2 g(0,-gravity) ; // Vetor da gravidade, i.e.,
  unsigned int i;
  // aceleracao apontando para baixo.
  for(i=0; i < masses.size(); i++){
    masses[i].setForce(g * masses[i].getMass());
  }

  for(i=0; i < springs.size(); i++){
    springs[i].getMass1()->addForce(-1 * springs[i].getForce());
    springs[i].getMass2()->addForce(+1 * springs[i].getForce());   
  }

  for(i=0; i < masses.size(); i++){
    masses[i].step(dt);
  }

}

int SpringMass::addMass(Mass mass){
  masses.push_back(mass);
  return masses.size();
}

void SpringMass::newSpring(int ref1, int ref2, double naturalLength, double damping, double stiffness){
  Spring spring(&masses.at(ref1), &masses.at(ref2), naturalLength, stiffness, damping = 0.01);
  springs.push_back(spring);
}

