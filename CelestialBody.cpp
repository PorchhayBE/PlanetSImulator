/**
 * N-Body Simulation: Part B
 * 
 * Date: 02/22/2022
 * 
 * Created by: Porchhay Be
 */

#include <string>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <cmath>
#include "./Header/CelestialBody.h"

CelestialBody::CelestialBody() //Default constructor
{
	Xpos = 0;
	Ypos = 0;
	Xvel = 0;
	Yvel = 0;
	Mass = 0;
	universeRadius = 0;
	XwindowDimension = 0;
	YwindowDimension = 0;
	Xcoord = 0;
	Ycoord = 0;
}

CelestialBody::CelestialBody(double x, double y, double Xvelo, double Yvelo, double mass, std::string File) // Constructor
{
	Xpos = x;
	Ypos = y;
	Xvel = Xvelo;
	Yvel = Yvelo;
	Mass = mass;
}

void CelestialBody::loadImage() //load image to sprite
{
	sf::Image image;
	if (!image.loadFromFile(fileName))
	{
		return;
	}

	imageSize = image.getSize();

	texture.loadFromImage(image);
	sprite.setTexture(texture);

	spriteSize = image.getSize();
}

void CelestialBody::setDimension( double radius, double Xwindow, double Ywindow) //Set window dimension
{
	universeRadius = radius;
	XwindowDimension = Xwindow;
	YwindowDimension = Ywindow;
}

void CelestialBody::coordCalculator () // calculate coordinate for the Pos of bodies
{	
	Xcoord = Xpos/(2*universeRadius/XwindowDimension) + XwindowDimension/2 - spriteSize.x/2;
	Ycoord = -Ypos/(2*universeRadius/YwindowDimension) + YwindowDimension/2 - spriteSize.y/2;

	sprite.setPosition(Xcoord, Ycoord);
}

void CelestialBody::calPos(double dT)
{
	Xpos += (Xvel * dT);
	Ypos += (Yvel * dT);
}

void CelestialBody::calVel(double Xaccel, double Yaccel, double dt)
{
	Xvel += (Xaccel * dt);
	Yvel += (Yaccel * dt);
}

double CelestialBody::getXpos()
{
	return Xpos;
}

double CelestialBody::getYpos()
{
	return Ypos;
}

double CelestialBody::getMass()
{
	return Mass;
}

void CelestialBody::draw(sf::RenderTarget& target, sf::RenderStates states)const // draw //inherit from library
{
	target.draw(sprite,states);
}
// sstream
std::istream& operator >> (std::istream& in, CelestialBody& Celestial)
{
	in >> Celestial.Xpos >> Celestial.Ypos >> Celestial.Xvel >> Celestial.Yvel >> Celestial.Mass >> Celestial.fileName;
	return in;
}

std::ostream& operator<< (std::ostream& out, CelestialBody& Celestial)
{
	out << Celestial.Xpos << " " << Celestial.Ypos << " " << Celestial.Xvel << " " << Celestial.Yvel << " "<< Celestial.Mass << " "<< Celestial.fileName << std::endl;
	return out;
}
