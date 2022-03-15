#pragma once
#include<iostream>
#include<SDL.h>

namespace myspace {
	class Screen
	{

	private:
		SDL_Window *m_window;
		SDL_Renderer *m_renderer;
		SDL_Texture *m_texture;
		Uint32 *m_buffer;
		Uint32 *m_buffer2;

	public:
		const static int SCREEN_WIDTH = 800;
		const static int SCREEN_HEIGHT = 600;

	public:
		Screen();
		~Screen();

		bool init();
		void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
		void screenUpdate();
		bool processEvents();
		void close();
		void clear();
		void boxBlur();
	};

}