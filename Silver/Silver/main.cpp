//Importing all system dependencies.
#include <iostream>
#include <stdio.h>
#include <SDL.h>
#include <glew.h>
#include <string>
#include <vector>

//Importing all Silver engine headers.
int main(int argc, char* argv[]) {
  //Creating nullptr for Window and OGL Renderer.
  SDL_Window* window = NULL;
  SDL_OpenGL_Renderer* window_renderer = NULL;
  
  //Instantiating GLEW environment for OpenGL commands from 3.3 and up.
  glewExperimental = true;
  glewInit();
  
  //Initializing SDL.
  if (SDL_Init(SDL_INIT_EVERYTHING)!=0) {
    std::cout << "FATAL ERROR: Could not initialize SDL. Please restart the program.\n"; 
  }
  
  //Creating window using SDL.
  window = SDL_CreateWindow("NAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_OPENGL);
  if (window==NULL) {
    std::cout << "FATAL ERROR: Could not initialize SDL Window. Please restart the program.\n"; 
  }
  
  //Creating OGL VAO
  GLuint vao;
  glGenVertexArrays(1, &vao);
  //Creating OGL VBO
  GLuint vbo;
  glGenBuffers(1, &vbo);
  
  //Binding current vertex array.
  glBindVertexArray(vao);
  //Binding current vertex buffer object.
  glBindBuffer(vbo);
  
  //Points to feed into the VBO. Vec3 set 1 is Points, Vec3 set 2 is Colours.
  float testDummy[] = {
    //Points (xyz)        //Colours (rgb[a])
    1.0f, 0.5f, 0.0f,     1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.5f,     0.0f, 1.0f, 0.0f,
    0.5f, 0.0f, 1.0f,     0.0f, 0.0f, 1.0f
  }
  
  glBufferData(vbo, 18, testDummy, GL_STATIC_DRAW);
  
  
}
