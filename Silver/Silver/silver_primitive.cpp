//Including basic includes.
#include "silver_inc.h"
#include "silver_primitive.h"

// SECTION 0
// FUNCTIONS

//Defining basic class structure.
slvr::Primitive::~Primitive() {
  //Delete the contents of the pointer, assuming this is assigned to the heap for now.
  delete vertices;
}
