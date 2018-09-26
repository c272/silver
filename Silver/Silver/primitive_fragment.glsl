#version 330 core
in vec3 colour;
in vec2 texpos;
out vec4 FragColour;

void main() {
	FragColour = vec4(1.0f, 0.5f, 0.2f, 1.0f);
}
