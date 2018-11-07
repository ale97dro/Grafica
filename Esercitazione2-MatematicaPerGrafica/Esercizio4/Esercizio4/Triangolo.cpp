#define GLM_ENABLE_EXPERIMENTAL

#include <iostream>
#include "../glm/glm/glm.hpp"
#include "../glm/glm/gtc/matrix_transform.hpp"
#include "../glm/glm/gtx/string_cast.hpp"

int main()
{
	//Vertici
	glm::vec4 vertici[3];
	vertici[0] = glm::vec4(-15.0f, 0.0f, -50.0f, 1.0f);
	vertici[1] = glm::vec4(15.0f, 0.0f, -50.0f, 1.0f);
	vertici[2] = glm::vec4(0.0f, 15.0f, -50.0f, 1.0f);
	
	//Funzioni
	glm::mat4 t1 = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
	glm::mat4 t2 = glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
	glm::mat4 t3 = glm::translate(glm::mat4(1.0f), glm::vec3(10.0f, 0.0f, 0.0f));

	//Matrice di proiezione per coordinate clip
	glm::mat4 perspective_matrix{ glm::perspective(glm::radians(45.0f), 1.0f, 1.0f, 100.0f) };


	//Clip coordinates
	glm::mat4 pipeline = perspective_matrix * t3 * t2 * t1;

	glm::vec4 pipeline_coordinates[3];

	for (int i = 0; i < 3; i++)
	{
		pipeline_coordinates[i] = pipeline * vertici[i];
		std::cout << glm::to_string(pipeline_coordinates[i]) << std::endl;
	}


	//Normalized device coordinates

	std::cout << "----------------------------------------------" << std::endl << std::endl;
	glm::vec3 ndc[3];

	for (int i = 0; i < 3; i++)
	{
		ndc[i].x = pipeline_coordinates[i].x / pipeline_coordinates[i].w;
		ndc[i].y = pipeline_coordinates[i].y / pipeline_coordinates[i].w;
		ndc[i].z = pipeline_coordinates[i].z / pipeline_coordinates[i].w;

		std::cout << glm::to_string(ndc[i]) << std::endl;
	}

	return 0;
}