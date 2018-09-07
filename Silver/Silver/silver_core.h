#ifndef SILVER_CORE_H
#define SILVER_CORE_H
//Header guarding.

//Including core includes.
#include "silver_inc.h"

//Wrapping all functions in the SLVR namespace.
//All documentation for class functions is contained within CPP files, and not in the header.

// SECTION 0
// Enumerations

enum SLVR_KEY {
	QUIT,
	a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z,
	NOKEY
};


namespace slvr {

	// SECTION I
	// Classes

	//"Window" class, for housing SDL and OGL window data.
	class Window {
	public:
		Window(std::string name, int height, int width, bool centered);
		~Window();
		SDL_Window* getWindow();
		SLVR_KEY poll();
	private:
		SDL_Event quitEvent;
		SDL_Window* winlocation = NULL;
		SDL_GLContext* glContextLocation = NULL;
	};
	
	// SECTION II
	// Globals
	extern SDL_GLContext glGhostContext;
	extern bool isGlInitialized;

	// SECTION III
	// Functions

	//Function that initializes SDL, OpenGL and GLEW.
	void slInitBasic();
	
}

#endif