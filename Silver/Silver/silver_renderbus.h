#ifndef SILVER_RENDERBUS_H
#define SILVER_RENDERBUS_H
//Header guarding.

//Including basic Silver headers.
#include "silver_inc.h"

//Wrapping all in SLVR namespace.
namespace slvr {
  //Creating GUI render pipeline on the heap. This is globally accessible.
  extern std::vector<Primitive>* renderObjects;
  extern std::vector<int>* renderLayers;

  //Adding pipeline functions within the namespace.
  void guiSortPipeline();
}
#endif
