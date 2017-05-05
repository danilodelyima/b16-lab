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

  E_cinetica = (mass * (velocity * velocity))/2;
  E_potencial = mass * gravity * (position.y - radius);
  energy = E_cinetica + E_potencial;

  return energy ;
}

void Mass::step(double dt)
{
  /* INCOMPLETE: TYPE YOUR CODE HERE 
     Este eh o metodo mais complexo, ele atualiza 
     - a posicao e 
     - a velocidade desta massa 
     usando a 
     - forca que eh aplicada `a massa (armazenada em
       atributo protegido) e 
     - a fracao de tempo (dt).
     Isso eh feito atravez da aplicacao de equacoes 
     basicas de mecanica. 
     1. Calcule a aceleracao:
        F = m*a  ->  a = m/F
     2. Atualize a posicao:
        S = S0 + V*dt + (a*dt^2)/2 
     3. Atualize a velocidade:
        V = V0 + a*dt
     Note que nos passos 2 e 3, eh necessario tratar
     de colisoes com as paredes da caixa. Para isso,
     eh melhor separar os calculos de componentes
     x e y da velocidade e da posicao.
   */
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

  u = mass1->getPosition() - mass2.getPosition();
  current_length = u.norm();
  unitario = u/current_length;
  velocidada_de_alongamento = dot( unitario, (mass1->getVelocity() - mass2->getVelocity()) );

  F = (naturalLength - current_length) * stiffness + velocidada_de_alongamento + damping;

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

  /* INCOMPLETE: TYPE YOUR CODE HERE 
     Implemente usando dois loops:
     1. imprima todas as massas
     2. imprima todas as molas
     Note que voce pode ousar o operador << diretamente
     para massas e molas, pois eles foram definidos acima.
     Posteriormente, imprima a energia total do sistema.     
   */
}

double SpringMass::getEnergy() const
{
  double energy = 0 ;

  /* INCOMPLETE: TYPE YOUR CODE HERE 
     A energia total do sistema eh
     a soma das energias de todas as massas 
     + a soma das energias de todas as molas.
   */

  return energy ;
}

void SpringMass::step(double dt)
{
  Vector2 g(0,-gravity) ; // Vetor da gravidade, i.e.,
  // aceleracao apontando para baixo.
  
  /* INCOMPLETE: TYPE YOUR CODE HERE 
     1. para cada massa,
        atualize sua forca usando m*g, i.e.
  masses[i].setForce(g * masses[i].getMass()) 
     2. para cada mola, obtenha a forca da mola e 
        adicione-a a cada massa ligada a esta mola, i.e.,
  springs[i].getMass1()->addForce(-1 * force) ;
  springs[i].getMass2()->addForce(+1 * force) ;     
     3. Atualize a posicao e velocidade de todas as massas,
        i.e., execute o metodo step() delas.
   */
}


/* INCOMPLETE: TYPE YOUR CODE HERE 

   Neste ponto, insira os metodos que estao faltando:
   um para adicionar uma massa e outro para adicionar uma mola
   no sistema.
   Para adicionar elementos numa estrutura do tipo vector,
   use o metodo push_back().
   O metodo de adicionar massa pode retornar o numero total
   de massas, i.e., return (int)masses.size() -1;
   O metodo de adicionar mola deve usar referencias 
   `a massa de cada extremidade e o construtor de mola.
 */


