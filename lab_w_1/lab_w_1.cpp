#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/vec3.hpp>

GLuint VBO;

/*	Функция рендера сцены	*/
static void RenderSceneCB()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glDisableVertexAttribArray(0);

	glutSwapBuffers();
}

/*	Функция создания буфера вершин	*/
static void CreateVertexBuffer()
{
	glm::vec3 Vertices[3];
	Vertices[0] = glm::vec3(-1.0f, -1.0f, 0.0f);
	Vertices[1] = glm::vec3(1.0f, -1.0f, 0.0f);
	Vertices[2] = glm::vec3(0.0f, 1.0f, 0.0f);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
}

/*	Главная функция	*/
int main(int argc, char** argv)
{
	/*	Инициализация первоначального состояния GLUT	*/
	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(100, 100);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInit(&argc, argv);

	/*	Создаём окно	*/
	glutCreateWindow("Lab work №1");

	/*	Регистрация вызываемой функции	*/
	glutDisplayFunc(RenderSceneCB);

	/*	Инициализация GLEW	*/
	GLenum res = glewInit();

	/*	Проверка GLEW на ошибки	*/
	if (res != GLEW_OK)
	{
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		return 1;
	}

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	/*	Создаём буфер вершин	*/
	CreateVertexBuffer();

	/*	Запуск механизма обработки событий	*/
	glutMainLoop();

	return 0;
}
