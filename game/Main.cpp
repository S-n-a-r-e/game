#include <glew.h>
#include <glfw3.h>

#include <mat4x4.hpp>
#include <gtc\matrix_transform.hpp>

#include "ShaderParser.h"
#define STB_IMAGE_IMPLEMENTATION
#include "Texture.h"

#include <thread>
#include <chrono>

#include <iostream>

#include "Character.h"

int main() {
	glfwInit();

	int width = 800, height = width * 0.75;
	GLFWwindow* wind = glfwCreateWindow(width, height, "thefck", 0, 0);
	glfwMakeContextCurrent(wind);

	glewInit();

	Shader shader("Vertex_Shader_Texture.shader", "Fragment_Shader_Texture.shader");

	float coords[8] = {
		0.5f, 0.5f,
		-0.5f, 0.5f,
		-0.5f, -0.5f,
		0.5f, -0.5f
	};

	float colors[12] = {
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f
	};

	float texCoords[8] = {
		1.0f, 1.0f,
		0.0f, 1.0f,
		0.0f, 0.0f,
		1.0f, 0.0f
	};

	glm::mat4x4 mtx = glm::ortho(0.0f, (float)width, 0.0f, (float)height);

	Character player = Character(10.0f, height / 2.0f, 100.0f, 100.0f, mtx, 0.0f, "Textures\\Texture1.png", shader.getProgram(), width);
	Character enemy = Character(width - 10.0f, height / 2.0f, 100.0f, 100.0f, mtx, 3.14f, "Textures\\Texture1.png", shader.getProgram(), width);

	int keyWasPressed[GLFW_KEY_LAST] = { 0 };

	while (!glfwWindowShouldClose(wind)) {
		glClear(GL_COLOR_BUFFER_BIT);

		player.drawIt();
		enemy.drawIt();

		if (glfwGetKey(wind, GLFW_KEY_UP) == true) {
			player.moveIt(3.0f);
		}
		if (glfwGetKey(wind, GLFW_KEY_DOWN) == true) {
			player.moveIt(-3.0f);
		}

		if ((glfwGetKey(wind, GLFW_KEY_SPACE) == true) && (keyWasPressed[GLFW_KEY_SPACE] == false)) {
			player.shoot();
		}



		for (int i = 0; i < GLFW_KEY_LAST; ++i) {
			keyWasPressed[i] = glfwGetKey(wind, i);
		}
		
		glfwPollEvents();
		glfwSwapBuffers(wind);
		std::this_thread::sleep_for(std::chrono::milliseconds(1000/60));
	}



	return 0;
}
