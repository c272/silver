//Including basics.
#include "silver_inc.h"
#include "silver_shader.h"

// SECTION 1
// FUNCTIONS

///Shader class constructor, takes the paths (relative or complete) of the vertex and fragment shader that will
///be used in the program.
///Parameters: (char* vertexPath, char* fragmentPath)
slvr::Shader::Shader(char* vertexShaderPath, char* fragmentShaderPath) {
	std::ifstream vertexStream;
	std::ifstream fragmentStream;
	std::string vertexCode;
	std::string fragmentCode;

	//Enabling exceptions on streams.
	vertexStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fragmentStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	//Attempting a stream.
	try {
		vertexStream.open(const_cast<const char*>(vertexShaderPath));
		fragmentStream.open(const_cast<const char*>(fragmentShaderPath));
		//Creating a stringstream to load buffer into.
		std::stringstream vertexSS, fragmentSS;

		vertexSS << vertexStream.rdbuf();
		fragmentSS << fragmentStream.rdbuf();

		//Closing streams, buffers have now been read out.
		vertexStream.close();
		fragmentStream.close();

		//Reading into strings.
		vertexCode = vertexSS.str();
		fragmentCode = fragmentSS.str();
	}
	catch (std::ifstream::failure e) {
		std::cout << "SHADER FAILURE: Could not load vertex/fragment Shader file.\n";
	}

	//Converting vertex/frag to a const char*.
	const char* vertexShaderSource = vertexCode.c_str();
	const char* fragmentShaderSource = fragmentCode.c_str();

	//Attempting to compile shaders.
	GLuint vertex, fragment;
	int noerrors;
	char* log = new char[512];

	//FIRST - Vertex Shader.
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vertexShaderSource, NULL);
	glCompileShader(vertex);
	//Checking for errors.
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &noerrors);

	if (!noerrors) {
		//Failure, dump log.
		glGetShaderInfoLog(vertex, 512, NULL, log);
		std::cout << "SHADER FAILURE: Vertex shader failed to compile.\n" << log;
	}

	//SECOND - Fragment Shader.
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragment);
	//Checking for errors.
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &noerrors);

	if (!noerrors) {
		//Failure, dump log.
		glGetShaderInfoLog(fragment, 512, NULL, log);
		std::cout << "SHADER FAILURE: Fragment shader failed to compile.\n" << log;
	}

	//Attempting to create and link shader program.
	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);
	glGetProgramiv(ID, GL_LINK_STATUS, &noerrors);
	if (!noerrors)
	{
		glGetProgramInfoLog(ID, 512, NULL, log);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << log << std::endl;
	}

	//Deleting shaders after link, no longer required.
	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

///Destructor for the Shader class, deletes the program referenced by private UInt ID.
///Parameters: ()
slvr::Shader::~Shader() {
	glDeleteProgram(ID);
}

///Sets the shader as the current active shader in the engine/OGL.
///Parameters: ()
void slvr::Shader::use() {
	glUseProgram(ID);
}

///Sets a shader uniform property to the value given.
///One example could be "colour".
///Parameters: (std::string name_of_uniform, bool value_of_parameter)
void slvr::Shader::setUniformBool(const std::string &name, bool value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

///Sets a shader uniform property to the value given.
///One example could be "colour".
///Parameters: (std::string name_of_uniform, int value_of_parameter)
void slvr::Shader::setUniformInt(const std::string &name, int value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

///Sets a shader uniform property to the value given.
///One example could be "colour".
///Parameters: (std::string name_of_uniform, float value_of_parameter)
void slvr::Shader::setUniformFloat(const std::string &name, float value) const
{
	glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

///A getter for the raw GL ID of the compiled shader program.
///Parameters: ()
GLuint slvr::Shader::getID() {
	return ID;
}