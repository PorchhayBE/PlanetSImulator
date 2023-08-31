/**
 * N-Body Simulation: Part B
 * 
 * Date: 02/22/2022
 * 
 * Created by: Porchhay Be
 */
#include "./Header/Universe.h"
#include "./Header/CelestialBody.h"
#include <sstream>
#include <iostream>
#include <memory>
#include <cmath>
#include <vector>
//Constructor
Universe::Universe(int width, int height, int bodies)
{
	vh = height;
	vw = width;
	Bodies = bodies;
	for (int i = 0; i < Bodies; i++) 
	{
		//allocate new memory for Celestial bodies
		planet.push_back(std::make_unique<CelestialBody>()); //push memory to vector point
	}
}

double Universe::calForce(double mass1, double mass2, double r)
{
	return (gravity * mass1 * mass2) / pow(r,2);
}

double Universe::calDist(double pos1, double pos2)
{
	return pos2-pos1;
}

double Universe::calR( double dx, double dy)
{
	return sqrt(pow(dx,2) + pow(dy,2));
}

double Universe::netForce(double delta, double r, double F)
{
	return F * (delta / r);
}


void Universe::setup() // To update the view, and calculate the coord // write to object
{
	for (int i = 0; i < Bodies; i++)
	{
		std:: cin >> *planet[i]; // write to object using stream overloading
		planet[i]->loadImage();
		planet[i]->setDimension(universeRadius, vw, vh);
	}
}

void Universe::update()
{
	for (int i = 0; i < Bodies; i++)
	{
		planet[i]->coordCalculator();
	}
}

void Universe::step(double dt)
{
	// Calculate each component of physic between each two planet
	for (int i = 0; i < Bodies; i++)
	{
		Fx = 0;
		Fy = 0;
		for (int j = 0; j < Bodies; j++)
		{
			if ( i != j)
			{
				deltaX = calDist(planet[i]->getXpos(), planet[j]->getXpos());
				deltaY = calDist(planet[i]->getYpos(), planet[j]->getYpos());
				r = calR(deltaX, deltaY);
				F = calForce(planet[i]->getMass(), planet[j]->getMass(), r);
				Fx += (F * deltaX ) / r;
				Fy += (F * deltaY ) / r;			
			}
		}
		Xaccel = Fx / (planet[i]->getMass());
		Yaccel = Fy / (planet[i]->getMass());

		planet[i]->calVel(Xaccel, Yaccel, dt);
		planet[i]->calPos(dt);
	}
}

void Universe::draw(sf::RenderTarget& target, sf::RenderStates states)const //Inherit Draw func from sf::Drawable
{
	for (int i = 0; i < Bodies; i++)
	{
		target.draw(*planet[i],states); //draw each of instance
	}
}

void Universe::printOut() // print out all of the sstream
{
	for (int i = 0; i < Bodies; i++)
	{
		std::cout << *planet[i];
	}

	std::cout << std::endl << universeRadius;
	
}

// stream overloading input to object
std::istream& operator >> (std::istream& in, Universe& Universal)
{
	in >>Universal.universeRadius;
	return in;
}

std::ostream& operator<< (std::ostream& out, Universe& Universal)
{
	out << Universal.Bodies << std::endl;
	for (int i = 0; i < Universal.Bodies; i++)
	{
		out << *Universal.planet[i];
	}
	return out;
}





