/**
 * N-Body Simulation: Part B
 * 
 * Date: 02/22/2022
 * 
 * Created by: Porchhay Be
 */
#pragma once
#include <string>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

// Header file
class CelestialBody: public sf::Drawable {
	public:
		CelestialBody();
		CelestialBody(double x, double y, double Xvelo, double Yvelo, double mass, std::string File);
		double getXpos();
		double getYpos();
		double getMass();
		void coordCalculator();
		void loadImage();
		void setDimension(double radius, double Xwindow, double Ywindow);
		void calPos(double);
		void calVel(double,double,double);
		friend std::ostream& operator<< (std::ostream& out, CelestialBody& CelestialBody);
		friend std::istream& operator>> (std::istream& in, CelestialBody& CelestialBody);
	private:
		double Xpos, Ypos, Xvel, Yvel, Mass, universeRadius, XwindowDimension, YwindowDimension, Xcoord, Ycoord;
		std::string fileName;
		sf::Texture texture;
		sf::Sprite sprite;
		sf::Vector2u spriteSize;
		sf::Vector2u imageSize;
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;
};