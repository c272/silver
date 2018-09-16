#ifndef SILVER_CORE_H
#define SILVER_CORE_H
//Header guarding.

//Including core includes.
#include "silver_inc.h"

//All functions are wrapped in the SLVR namespace.
//All documentation for class functions is contained within CPP files, and not in the header.

// SECTION 0
// Enumerations

enum SLVR_KEY {
	QUIT,
	a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z,
	A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
	ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, ZERO,
	NOKEY
};


namespace slvr {

	// SECTION I
	// Classes

	//"Window" class, for housing SDL and OGL window data.
	class Window {
	public:
		Window(std::string name, int width, int height, bool centered);
		~Window();
		SDL_Window* getWindow();
		SLVR_KEY poll();
		void renderTest();
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