#include <iostream>
#include<math.h>
#include <SDL.h>
#include"Screen.h"
#include<stdlib.h>
#include<time.h>
#include"Swarm.h"
#include"Particle.h"
using namespace myspace;
using namespace std;

int main(int argc, char * argv[])
{
	srand(time(NULL));
	
		Screen screen;

	if (screen.init() == false) {
		cout << "Error screen initilizatio." << endl;
	}

	bool quit = false;                                         //Used in while loop
	SDL_Event event;                                          //Used in nested while loop

	Swarm swarm;



	// Update Particle 
	// Draw Particle 
	// Check For messages/events

	while (true) {


		int elapsed = SDL_GetTicks();

		
		swarm.update(elapsed);


		unsigned char red = (unsigned char)((1 + sin(elapsed * 0.0001)) * 127);
		unsigned char green = (unsigned char)((1 + cos(elapsed*0.0002)) * 127);
		unsigned char blue = (unsigned char)((1 + cos(elapsed*0.0004)) * 127);


		const Particle *const pParticles = swarm.getParticles();

		for (int i = 0; i < Swarm::NPARTICLES; i++) {

			Particle particle = pParticles[i];


			int x = (particle.m_x + 1)*Screen::SCREEN_WIDTH / 2;
			int y = particle.m_y *Screen::SCREEN_WIDTH / 2+Screen::SCREEN_HEIGHT/2;



			screen.setPixel(x, y, red, green, blue);





		}

		screen.boxBlur();

		screen.screenUpdate();
		if (screen.processEvents() == false) {
			break;
		}
	}

	screen.close();

	return 0;
}