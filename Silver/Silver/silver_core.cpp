//Including SILVER_CORE header and includes.
#include "silver_inc.h"
#include "silver_core.h"

//  SECTION 0
//  GLOBAL DECLARATION

SDL_GLContext slvr::glGhostContext = NULL;
bool slvr::isGlInitialized = false;

//  SECTION I
//  FUNCTION DECLARATION

//Starts SDL and GLEW for OpenGL commands. Runs when a window is created.
void slvr::slInitBasic() {
	//Checking if SDL/GLEW is already up and running.
	if (slvr::isGlInitialized == false) {
		//Initializing SDL.
		if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
			std::cout << "FATAL ERROR: SDL could not initialize. Please check dump for errors.\n";
			exit(-1);
		}

		//Starting GLEW.
		glewExperimental = true;
		glewInit();

		//Setting initialized bool to true.
		slvr::isGlInitialized = true;
	}
}

///The main window of Silver, must be started to display things on screen.
///Parameters: (std::string [nameofwindow], int [heightofwindow], int [widthofwindow], OPTIONAL int [iscentered=false])
slvr::Window::Window(std::string name, int width, int height, bool centered = false) {
	//Starting SDL and OpenGL.
	slvr::slInitBasic();

	//Creating window and GLContext.
	//Checking whether to create as SDL_WINDOWPOS_CENTERED or SDL_WINDOWPOS_UNDEFINED.
	if (centered) {
		winlocation = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE);
	}
	else {
		winlocation = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE);
	}

	//GLContext being addressed into class.
	slvr::glGhostContext = SDL_GL_CreateContext(winlocation);
	glContextLocation = &slvr::glGhostContext;

	//Finished construction.
	SDL_SetWindowBordered(winlocation, SDL_TRUE);
}

//Window destructor, deletes all dangling pointers and memory.
slvr::Window::~Window() {
	//Deleting dangling pointers and window before removing class.
	slvr::glGhostContext = NULL;
	glContextLocation = NULL;
	SDL_DestroyWindow(winlocation);
	winlocation = NULL;
}

///slvr::Window::getWindow()
///Gets the window pointer from private storage to use as a raw variable.
///Parameters: ()
SDL_Window* slvr::Window::getWindow() {
	return winlocation;
}

///slvr::Window::poll()
///Returns the currently pressed key or event enum.
///Parameters: ()
SLVR_KEY slvr::Window::poll() {
	if (SDL_PollEvent(&quitEvent) != 0) {
		switch (quitEvent.type) {
		case SDL_QUIT:
			return QUIT;
			break;
		case SDL_KEYDOWN:
			switch (quitEvent.key.keysym.sym) {
			case SDLK_a:
				return a;
			//TODO: Implement the rest of the keys from A-Z and 0-9, plus symbols.
			default:
				return NOKEY;
			}
			break;
		default:
			return NOKEY;
		}
	}
	else {
		return NOKEY;
	}
}

///slvr::Window::renderTest()
///Renders a basic test card to check the window is working correctly.
///Parameters: ()
void slvr::Window::renderTest() {
	if (slvr::isGlInitialized == true && winlocation != NULL && glContextLocation!=NULL) {
		//Everything's setup already, render test to screen now.
		glClearColor(0.0f, 0.0f, 0.7f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//Rendering.
		SDL_GL_SwapWindow(winlocation);
	}
	else {
		std::cout << "ERROR: Cannot render test card, GL is not initialized, or init() function has not been run.\n";
	}
}