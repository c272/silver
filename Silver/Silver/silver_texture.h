#ifndef SILVER_TEXTURE_H
#define SILVER_TEXTURE_H

//Basic includes.
#include "silver_inc.h"
#include "silver_shader.h"

//The main file for the Silver Texture class.
// ALL FUNCTION DOCUMENTATION CAN BE FOUND IN THE .CPP FILE!

//Wrapping all in SLVR namespace.
namespace slvr {
	class Texture {
	public:
		Texture(std::string path, int wrapmode=0, int filtermode=0);
		//todo:
		//~Texture();
		//void bind();
		//void setTextureCoords(slvr::Shader shader, std::vector<int> coords);
	private:
		int width, height, channelNumber;
		unsigned char* data;
		std::vector<int> texCoords;
		GLuint texture;
	};
}

#endif