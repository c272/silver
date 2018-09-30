#version 330 core
in vec3 colour;
in vec2 texpos;
out vec4 FragColour;

uniform sampler2D itexture;

void main() {
	//Not sure of the syntax to check whether a uniform has been set or not.
	if (texture) {
		FragColour = texture(itexture, texpos) * vec4(1.0f, colour.xyz);
	} else {
		FragColour = vec4(1.0f, colour.xyz);
	}
}
