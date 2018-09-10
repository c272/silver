#ifndef SILVER_PRIMITIVES_H
#define SILVER_PRIMITIVES_H
//Header guarding.

//Including core includes.
#include "silver_inc.h"

//All functions are wrapped in the SLVR namespace.
//All documentation for class functions is contained within CPP files, and not in the header.

// SECTION 0
// Enumerations

namespace slvr {

	// SECTION I
	// Classes

	//"Primitive" class, for drawing primitives.
  class Primitive {
  public:
    ~Primitive();
    void render();
    bool setVertices(float* input);
  private:
    float* vertices = nullptr;
    GLuint vbo;
    GLuint vao;
  }

#endif
