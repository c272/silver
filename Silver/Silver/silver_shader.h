#ifndef SILVER_SHADER_H
#define SILVER_SHADER_H
//Header guarding.

//Including basics.
#include "silver_inc.h"

//Defning Shader class.
namespace slvr {
	//ALL CLASS DOCUMENTATION IS IN THE CPP FILE.
	class Shader {
	public:
		Shader(char* vertexShaderPath, char* fragmentShaderPath);
		~Shader();
		GLuint getID();
		void use();
		void setUniformBool(const std::string &name, bool value) const;
		void setUniformInt(const std::string &name, int value) const;
		void setUniformFloat(const std::string &name, float value) const;
	private:
		GLuint ID;
	};
}

#endif