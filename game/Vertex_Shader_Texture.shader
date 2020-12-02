#version 330 core

layout(location = 0) in vec2 coordVec;
layout(location = 1) in vec2 texCoords;

out vec2 vOutTexCoords;

uniform mat4x4 mtx;

void main() {
	gl_Position = mtx * vec4(coordVec, 0.0f, 1.0f);

	vOutTexCoords = texCoords;
}