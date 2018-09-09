# slvr::Window
**Overview**
This is the main window handling object in Silver, and processes all rendering to the screen. This object should generally be assigned to the stack, however if you're creating an extremely large project, memory could theoretically overflow, so creating a pointer to this on the heap is usually advised.

### Methods
*Window()*

The main window of Silver, must be started to display things on screen. This is a constructor, and is mandatory when creating a new window.

Parameters: (std::string [nameofwindow], int [heightofwindow], int [widthofwindow], OPTIONAL int [iscentered=false])

&nbsp;

*~Window()*

Window destructor, deletes all dangling pointers and memory.

Parameters: ()

&nbsp;

**SDL_Window\*** *Window.getWindow()*

Gets the window pointer from private class storage to use as a raw variable.

Parameters: ()

&nbsp;

**SLVR_KEY** *Window.poll()*

Returns the currently pressed key or event as an SLVR_KEY enum. If no key is pressed, a NO_KEY is returned.

Parameters: ()

&nbsp;

**void** *Window.renderTest()*

Renders a basic test card to check the window is working correctly, showing R0.0f, G0.0f, B0.7f, A1.0f.

Parameters: ()