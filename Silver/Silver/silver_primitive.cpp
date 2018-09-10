//Including basic includes.
#include "silver_inc.h"
#include "silver_primitive.h"

// SECTION 0
// FUNCTIONS

//Defining basic class structure.

///Destructor for the primitive class.
///Assumes vertices are assigned to the heap rather than the stack.
///Parameters: ()
slvr::Primitive::~Primitive() {
  //Delete the contents of the pointer, assuming this is assigned to the heap for now.
  delete vertices;
  //Nulling the VBO and VAO in OGL.
  vbo = NULL;
  vao = NULL;
}

///The rendering function for primitives. Any that exist will be rendered sequentially unless otherwise stated.
///Parameters: ()
void slvr::Primitive::render() {
 //Push to render message bus.
  //TODO: Make render message bus.
}

///Sets the vertices for the class that should be rendered in. Positional vertices only, at the moment.
///Parameters: ()
bool slvr::Primitive::setVertices(float* input) {
   if (*input==NULL) {
     printf("ERROR: Vertices pointer contains no data.\n"); 
     return false;
   } else {
     vertices = input;
     return true;
   }
}

#endif
