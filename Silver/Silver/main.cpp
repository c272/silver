//Importing all Silver engine headers.
#include "silver_inc.h"
#include "silver_core.h"

int main(int argc, char* argv[]) {  
	slvr::Window win("Window Title", 800, 600, false);
	
	bool quit = false;
	while (!quit) {
		//Check for quit.
		SLVR_KEY keypress = win.poll();
		if (keypress==QUIT) {
			quit = true;
		}
		else {
			//Rendering blue screen.
			glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			SDL_GL_SwapWindow(win.getWindow());
		}
	}
	
	return 0;
}
