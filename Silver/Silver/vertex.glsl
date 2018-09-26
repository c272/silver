#version 330 core
layout (location=0) in vec3 position;
//Adding uniform for texture mapping.
uniform vec3 tmap;
out vec3 textureLocs;

void main() {
	textureLocs = tmap;
	gl_Position = vec4(position.xyz, 1.0);
}
