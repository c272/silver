//Including required Silver headers.
#include "silver_inc.h"
#include "silver_primitive.h"
#include "silver_renderbus.h"

// SECTION 0
// FUNCTIONS

///Sorts the GUI pipeline into their respective layers, in preparation for rendering the full set.
///Called automatically by the Window's "render" function, to draw on top of any other 3D models.
///Parameters: ()
void slvr::guiSortPipeline() {
  //todo
}

///Initializes the GUI pipeline into memory, allocating them onto the heap.
///Called automatically by the Window's constructor, so should not need to ever be run manually.
///Parameters: ()
void slvr::guiInitPipeline() {
  std::vector<slvr::Primitive>* renderObjects = new std::vector<slvr::Primitive>;
  std::vector<int>* renderLayers = new std::vector<int>;
}
