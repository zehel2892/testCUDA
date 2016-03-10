// We do not need to include gl.h since glfw3 takes care of it
#define GL_GLEXT_PROTOTYPES
#include<GLFW/glfw3.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glx.h>
#include<GL/glext.h>
#include<iostream>
int main(void)
{

	GLFWwindow* window;
	GLuint VBO;
	struct cudaGraphicsResource * VBO_CUDA;

	// Generate OpenGL buffers
	glGenBuffers(1,&VBO);
	glBindBuffer(GL_ARRAY_BUFFER,VBO);
	 /* Initialize the library */
	if (!glfwInit())
	return -1;

	/* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.05,0.5,0.3,1.0);    
		    
	/* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
