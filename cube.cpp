#include <cstdlib>
#include <GL/glew.h>
#ifdef __APPLE__
#include <GLUT/openglut.h>
#else
#include <GL/openglut.h>
#endif
#include <cstdio>
#include <math.h>
#include "util.h"

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define PI 4 * atan(1.0f)

/* There's a bug in the way some versions of Visual Studio's 
standard C headers interact with glut.h that requires stdlib.h
 to be included before it. */

/* Note: place dlls in windows system folder,
	C:\Windows\SysWoW64, not VC\bin as 
	recommended in some online resources,
	i.e. put them in the same folder as
	opengl32.dll	*/

GLfloat vertices[] = {
        -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
         0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
         0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
         0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
         0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
         0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
         0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,

         0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
         0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
         0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
         0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
         0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
         0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
         0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
         0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
         0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
         0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
         0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
         0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f
};


/* Resource handles. Global variables which
   both the make_resources and render functions
   need to access */
GLuint vao, vbo, ebo;
GLuint textures[2];
GLuint vertexShader, fragmentShader, shaderProgram;
GLint posAttrib, colAttrib, texAttrib;

float angle;

GLint uniMVP, uniModel, uniView, uniProj;

// Shader sources
const GLchar* vertexSource =
    "#version 120\n"
    "attribute vec3 position;"
	"attribute vec3 color;"
	"attribute vec2 texcoord;"
	"varying vec3 Color;"
	"varying vec2 Texcoord;"
	"uniform mat4 mvp;"
    "void main() {"
	"	Color = color;"
	"	Texcoord = texcoord;"
    "   gl_Position = mvp * vec4(position, 1.0);"
    "}";
const GLchar* fragmentSource =
    "#version 120\n"
	"varying vec3 Color;"
	"varying vec2 Texcoord;"
	"uniform sampler2D texKitten;"
	"uniform sampler2D texPuppy;"
    "void main() {"
    "   gl_FragColor = vec4(Color, 1.0) * mix("
    "    texture2D(texKitten, Texcoord),"
    "    texture2D(texPuppy, Texcoord),"
    "    0.5"
	"	);"
    "}";
	
 
	
static int make_resources(void)
{
    // Create Vertex Array Object
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glGenBuffers(1, &vbo); // Generate 1 buffer
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	
	// Create and compile the vertex shader
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);

	// Create and compile the fragment shader
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);
	
	GLint status;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);

	if(!status)
	{
		char buffer[512];
		glGetShaderInfoLog(vertexShader, 512, NULL, buffer);
		fprintf(stderr, "Compilation of the vertex shader was not successful.\n");
		fprintf(stderr, "Compile log:\n\n");
		fprintf(stderr, "%s\n\n", buffer);
		(stderr, "Please check your code.\n");
		return 0;
	}
	else
	{
		printf("The vertex shader compiled successfully.\n");
	}
	
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &status);

	if(!status)
	{
		char buffer[512];
		glGetShaderInfoLog(fragmentShader, 512, NULL, buffer);
		fprintf(stderr, "Compilation of the fragment shader was not successful.\n");
		fprintf(stderr, "Compile log:\n\n");
		fprintf(stderr, "%s\n\n", buffer);
		fprintf(stderr, "Please check your code.\n");
		return 0;
	}
	else
	{
		printf("The fragment shader compiled successfully.\n");
	}

	// Link the vertex and fragment shader into a shader program
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	// Specify the layout of the attribute data
	posAttrib = glGetAttribLocation(shaderProgram, "position");
	colAttrib = glGetAttribLocation(shaderProgram, "color");
	texAttrib = glGetAttribLocation(shaderProgram, "texcoord");

    // Load textures
    glGenTextures(2, textures);

	int width, height;
	void* image;

    glBindTexture(GL_TEXTURE_2D, textures[0]);
    image = read_tga("sample.tga", &width, &height);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	free(image);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
    glBindTexture(GL_TEXTURE_2D, textures[1]);
    image = read_tga("sample2.tga", &width, &height);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	free(image);
	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	uniMVP = glGetUniformLocation(shaderProgram, "mvp");
	
	return 1;
}

/*
 * GLUT callbacks:
 */
 
static void idle_func(void)
{
	const int rate = 90; // degrees per second
	const float rads = PI/180.0f * rate;
	angle = glutGet(GLUT_ELAPSED_TIME) / 1000.0	* rads;
	glutPostRedisplay();
}

static void render(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glUseProgram(shaderProgram);

	// keep glm variables local - global matrices can cause problems
	// e.g. fast, accelerating square, (try it).
	glm::mat4 model;
	model = glm::rotate(model, angle, glm::vec3(0.0f, 0.0f, 1.0f));
	glm::mat4 view;

	view = glm::lookAt(
        glm::vec3(1.5f, 1.5f, 1.5f),
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(0.0f, 0.0f, 1.0f)
    );

	glm::mat4 proj;
	proj = glm::perspective(PI/4.0f, 800.0f / 600.0f, 1.0f, 10.0f);
	glm::mat4 mvp;
	mvp = proj * view * model;

	glUniformMatrix4fv(uniMVP, 1, GL_FALSE, glm::value_ptr(mvp));
	
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glEnableVertexAttribArray(posAttrib);
	glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, 8*sizeof(float), 0);
					   
	glEnableVertexAttribArray(colAttrib);
	glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)(3*sizeof(float)));

	glEnableVertexAttribArray(texAttrib);
    glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(6 * sizeof(GLfloat)));	

	glActiveTexture(GL_TEXTURE0);	
	glBindTexture(GL_TEXTURE_2D, textures[0]);
	glUniform1i(glGetUniformLocation(shaderProgram, "texKitten"), 0);
	
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, textures[1]);
	glUniform1i(glGetUniformLocation(shaderProgram, "texPuppy"), 1);
	
	// Draw cube
    glDrawArrays(GL_TRIANGLES, 0, 36);

    glutSwapBuffers();
}

/*
 * Entry point
 */
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA|GLUT_ALPHA|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("The Cube");
	
	glutIdleFunc(&idle_func);
    glutDisplayFunc(&render);

    glewInit();

    if (!GLEW_VERSION_2_1) {
        fprintf(stderr, "OpenGL 2.1 not available\n");
        return 1;
    }

	else printf("Good, your PC has OpenGL 2.1.\n\n");

    if (!make_resources()) {
        fprintf(stderr, "Failed to load resources\n");
        return 1;
    }

	glEnable(GL_DEPTH_TEST);
    glutMainLoop();
	
    return 0;
}
