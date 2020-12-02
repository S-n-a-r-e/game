#version 330 core

in vec2 vOutTexCoords;

uniform sampler2D inpTexture;

out vec4 resultTexture;

void main() {
	resultTexture = vec4(texture(inpTexture, vOutTexCoords));
}
