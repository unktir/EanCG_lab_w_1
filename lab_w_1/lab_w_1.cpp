#include <GL/freeglut.h>

/*	Функция рендера сцены	*/
static void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glutSwapBuffers();
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
	glutDisplayFunc(RenderScene);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	/*	Запуск механизма обработки событий	*/
	glutMainLoop();

	return 0;
}