/**
 * N-Body Simulation: Part B
 * 
 * Date: 02/22/2022
 * 
 * Created by: Porchhay Be
 */

#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <memory>
#include "CelestialBody.h"

//Header file
class Universe: public sf::Drawable
{
	private:
		std::vector<std::unique_ptr<CelestialBody>> planet;
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const; //inherit function from sf::Drawable
		int Bodies, vh, vw; // viewportHeight // viewportWidth
		double universeRadius;
		double deltaX, deltaY, Fx, Fy, r, F, Xaccel, Yaccel;
		double gravity = 6.67 * 1e-11;
	public:
		Universe(int width, int height, int bodies);
		void update();
		void setup();
		void printOut();
		void step(double);
		double calForce(double,double,double);
		double calDist(double, double);
		double calR(double, double);
		double netForce(double, double, double);
		friend std::istream& operator>> (std::istream& in, Universe& Universer);
		friend std::ostream& operator<< (std::ostream& out, Universe& Universer);


};