/**
 * N-Body Simulation: Part B
 * 
 * Date: 02/22/2022
 * 
 * Created by: Porchhay Be
 */

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "./Header/CelestialBody.h"
#include <iostream>
#include <string>
#include "./Header/Universe.h"

int main(int argc, char* argv[]) {
	// framerate
	int framePersec = 60;
	// Window Resolution
	int width = 512;
	int height = 512;
	int bodies;
	//input number from argv
	double T = std::stod(argv[1]);
	double dT = std::stod(argv[2]);
	double t = 0;

	// input number of planets
	std::cin >> bodies;
	// set window render size
	sf::RenderWindow window(sf::VideoMode(width,height), "Universe");
	window.setFramerateLimit(framePersec);
	Universe V(width, height, bodies); //instaniate 
	std:: cin >> V; // write to opject
	V.setup(); // setup Universe


	//Import font
	sf::Font open_san;
	if(!open_san.loadFromFile("./Asset/OpenSans-Regular.ttf"))
	{
		std::cout << "No font file found! - OpenSans-Regular.ttf\n";
	}

	// display text on window
	sf::Text displayCycle;
	displayCycle.setFont(open_san);
	displayCycle.setPosition(10,10);
	displayCycle.setFillColor(sf::Color::White);
	
	// Display time eslapsed
	std::string display;
	sf::Clock clock;


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		// Display Elapsed Time on window
		sf::Time eslape1 = clock.getElapsedTime();  // initialize time elapsed

		if (t < T) // run until tick time (25000) reach time stamp T
		{	
			V.step(dT);
			V.update();
			display = std::to_string(eslape1.asSeconds()); // convert to text
			displayCycle.setString(display); //display time on window
			t += dT;
		}
		else 
		{
			std::cout << "Runtime: " << eslape1.asSeconds() << " seconds " << std::endl;
			// std::cout << V;
			return EXIT_SUCCESS;
		}
		
		window.clear();
		window.draw(displayCycle);
		window.draw(V);
		window.display();
		
	}
	
}