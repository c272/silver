#version 330 core
layout (location=0) in vec3 position;
layout (location=1) in vec3 icolour;
layout (location=2) in vec2 itexpos;
out vec2 texpos;
out vec3 colour;

void main() {
	//Outputting generic texture coordinate.
	texpos = itexpos;
	//Passing colour to next shader.
	colour = icolour;
	//Updating position.
	gl_Position = vec4(position.xyz, 1.0);
}
