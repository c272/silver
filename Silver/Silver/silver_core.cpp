//Including SILVER_CORE header and includes.
#include "silver_inc.h"
#include "silver_core.h"
#include "silver_primitive.h"
#include "silver_renderbus.h"

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
		std::cout << "Initializing.";
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
///Parameters: (std::string [nameofwindow], int [widthofwindow], int [heightofwindow], OPTIONAL int [iscentered=false])
slvr::Window::Window(std::string name, int width, int height, bool centered = false) {
	//Starting SDL and OpenGL.
	slvr::slInitBasic();

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

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
				break;
			case SDLK_b:
				return b;
				break;
			case SDLK_c:
				return c;
				break;
			case SDLK_d:
				return d;
				break;
			case SDLK_e:
				return e;
				break;
			case SDLK_f:
				return f;
				break;
			case SDLK_g:
				return g;
				break;
			case SDLK_h:
				return h;
				break;
			case SDLK_i:
				return i;
				break;
			case SDLK_j:
				return j;
				break;
			case SDLK_k:
				return k;
				break;
			case SDLK_l:
				return l;
				break;
			case SDLK_m:
				return m;
				break;
			case SDLK_n:
				return n;
				break;
			case SDLK_o:
				return o;
				break;
			case SDLK_p:
				return p;
				break;
			case SDLK_q:
				return q;
			case SDLK_r:
				return r;
				break;
			case SDLK_s:
				return s;
				break;
			case SDLK_t:
				return t;
				break;
			case SDLK_u:
				return u;
				break;
			case SDLK_v:
				return v;
				break;
			case SDLK_w:
				return w;
				break;
			case SDLK_x:
				return x;
				break;
			case SDLK_y:
				return y;
				break;
			case SDLK_z:
				return z;
				break;
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
