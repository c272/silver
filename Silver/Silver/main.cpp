//Importing all Silver engine headers.
#include "silver_inc.h"
#include "silver_core.h"
#include "silver_shader.h"
#include "silver_primitive.h"
#include "silver_texture.h"

int main(int argc, char* argv[]) {
	//Creating Silver window.
	slvr::Window win("Window Title", 800, 600, false);
	
	//Initializing GLEW.
	glewInit();

	//Creating vertices for triangle.
	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f,  0.5f, 0.0f
	};

	//Creating Silver shader.
	slvr::Shader shader("vertex.glsl", "fragment.glsl");

	//Creating Silver primitive.
	slvr::Primitive primitive(vertices, sizeof(vertices), &shader);

	//Testing new Texture class.
	slvr::Texture texture("D:\\Files\\Programming\\GitHub\\Silver\\silver\\Silver\\Silver\\bg.jpg");

	bool quit = false;
	while (!quit) {
		//Check for quit.
		SLVR_KEY keypress = win.poll();
		if (keypress==QUIT) {
			quit = true;
		}
		else {
			//Render primitive.
			primitive.render();
			
			//Swap buffers.
			SDL_GL_SwapWindow(win.getWindow());
		}
	}
	
	return 0;
}
