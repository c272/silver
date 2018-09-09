# Starter Examples

To get started with a simple Silver test setup, you first need to open a main function.

    int main(int argc, char* argv[]) {
		//...
	}

It must have the correct parameters, as outlined above, for maximum compatibility across all operating systems (Simple Directmedia Layer XPlatform). After this, you can create a new ```slvr::Window```. All Silver classes are contained within the shortened ```slvr``` namespace.

    int main(int argc, char* argv[]) {
		slvr::Window win("Window Name", 800, 600, false);
		//...
	}

The first parameter of the Window constructor is a name, followed by width and height, and then whether the window should be centered or not. Now, we'll start a render loop.

    int main(int argc, char* argv[]) { 
	    slvr::Window win("Window Name", 800, 600, false); 
	    
	    bool quit = false;
	    while (!quit) {
			
		} 
	}

Inside, you can simply render a test card, or you can first check for quitting using the "poll" method inside the Window class, and then render a test card.

**With error checking:**
		
	int main(int argc, char* argv[]) { 
		slvr::Window win("Window Name", 800, 600, false); 
	    
	    bool quit = false;
	    while (!quit) {
			SLVR_KEY keypress = win.poll();
			if (SLVR_KEY==QUIT) {
				break;
			}
			win.renderTest();
		} 
	}

**With error checking:**

	int main(int argc, char* argv[]) { 
		slvr::Window win("Window Name", 800, 600, false); 
	    
	    bool quit = false;
	    while (!quit) {
			win.renderTest();
		} 
	}

For more advanced rendering and pipeline descriptions, check further through the "Getting Started" section. If you have problems rendering the basic test card, or anything in the further sections, check through the "Troubleshooting" section, or contact me at @c272 on GitHub, by submitting an issue to the repository (*see top right corner*).