#include "Platform/Platform.hpp"



int main()
{
	//Assume this runs sommet to do with setting up the platoform
	//util::Platform platform;

	sf::RenderWindow window(sf::VideoMode(1000, 600), "Asteroids");
	window.setVerticalSyncEnabled(true);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			//Allows window to be closed
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//Update all gameobject

		window.clear(sf::Color::Black); // Set the window background color to black

		//Draw all gameobject

		// Add your rendering code here if needed

		window.display();
	}

	return 0;
}
