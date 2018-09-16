# slvr::Shader
**Overview**
A class that handles the loading and unloading of basic OpenGL shaders, using ifstreams and stringstreams. The raw OpenGL ID for the program can also be accessed.

## Methods
*Shader()*

Constructor, takes the relative or complete path to the GLSL vertex shader and the GLSL fragment shader.

Parameters: (char\* vertexShaderPath, char\* fragmentShaderPath)

&nbsp;

*~Shader()*

Destructor, automatically called when the Shader object goes out of scope. Deletes the shader program.

Parameters: ()

&nbsp;

***GLuint** getID()*

This returns the raw ID of the OpenGL graphics program. Should only really be used if doing some obscure feature using shader programs that is not supported by the built in class functions.

Parameters: ()

&nbsp;

***void** use()*

Makes the shader program contained within the class the current active OpenGL shader.

Parameters: ()

&nbsp;

***void** setUniformBool()*

Sets a shader uniform property that is defined in the GLSL source file, of type boolean.

Parameters: (const std::string &name, bool value)

&nbsp;

***void** setUniformInt()*

Sets a shader uniform property that is defined in the GLSL source file, of type integer..

Parameters: (const std::string &name, int value)

&nbsp;

***void** setUniformFloat()*

Sets a shader uniform property that is defined in the GLSL source file, of type float.

Parameters: (const std::string &name, float value)

&nbsp;

> *Author's Note*: Function overloads will be added soon, for uniforms that contain 2 values and above, up to 4.
