//Including basic libraries.
#include "silver_inc.h"
#include "silver_primitive.h"

//Defining functions.

///Constructor for the "Primitive" class.
///Takes a set of points, along with a shader to render them with, and draws them on screen using glDrawArrays.
///Parameters: (float* points, int array_size_in_bytes, slvr::Shader shader)
slvr::Primitive::Primitive(float* points, int arraySizeBytes, slvr::Shader* shader) {
	//Copying pointer into class.
	shaderptr = shader;
	//Enabling current shader.
	shaderptr->use();

	//Creating VAO.
	glGenVertexArrays(1, &vao);
	//Binding as current.
	glBindVertexArray(vao);

	//Creating VBO.
	glGenBuffers(1, &vbo);
	//Setting current VBO.
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	//Adding vertices into buffer data, which will automatically put it in current VAO at index 0.
	glBufferData(GL_ARRAY_BUFFER, arraySizeBytes, points, GL_STATIC_DRAW);

	//Setting the attribute vertex data to the right spot in the VBO.
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	std::cout << "Constructed primitive, with VAO and VBO.\n";
}

///Renders the primitive object on screen.
///Parameters: ()
void slvr::Primitive::render() {
	//Enabling VBO, VAO, shader.
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	shaderptr->use();

	//Drawing using glDrawArrays.
	glDrawArrays(GL_TRIANGLES, 0, 3);
	std::cout << "Attempted to render triangles.\n";
}