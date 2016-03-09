#include<stdio.h>
#include<iostream>
#include<GL/glew.h>
#include<GL/glut.h>

void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.5f,0.7f,0.1f,1.0f);
	glutSwapBuffers();
}


int main(int argc , char ** argv)
{
	printf("Hello OpenGL \n");
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(840,480);
	glutCreateWindow("Hello OpenGL");
	glutDisplayFunc(RenderScene);
	glutMainLoop();

return 1;
}


