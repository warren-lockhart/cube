cube
====

A simple demonstration of a spinning cube designed with modern OpenGL.

This code is a hybrid of a number of excellent online tutorials, so I must first give credit. 

First to the tutorial at http://duriansoftware.com/joe/An-intro-to-modern-OpenGL.-Table-of-Contents.html, which is a rare tutorial in modern OpenGL - rare for its clarity but also for its focus on OpenGL 2.0, the earliest incarnation of a true programmable OpenGL. This was important to me because my PC only had OpenGL 2.1 support. In particular, the utility functions he provides are gratefully reused here for loading targa files.

The tutorial at http://open.gl/ provided the basis for the code you see here, although there are some important differences in organization. The most important difference in my code in the use of OpenGLUT rather than SFML or GLFW for creating the OpenGL context. The vertices and textures however are the same.

This code is also influenced by the tutorials at http://en.wikibooks.org/wiki/OpenGL_Programming which also teach you how to create a spinning cube. It is worth bookmarking some of these as good, modern OpenGL tutorials are notoriously difficult to find on the web.

Other than these influences, the code is my own. It is the end result of my goal to create a simple OpenGL demonstration using the modern programmable pipeline, and using my own preferences for window creation and code organization. 

The libraries OpenGLUT and GLEW are required to run the code. The header-only library glm is required for the matrix transformations. These libraries must be installed on your system in order to build and run the program.

Note that Android has a very similar library for matrix operations, so that the glm code can be changed rather trivially to support that platform; see http://developer.android.com/reference/android/opengl/Matrix.html. Setting up the OpenGL ES2.0/3.0 context and responsing to user interaction (to replicate the GLUT code) are a little more involved, but still straightforward; see http://developer.android.com/training/graphics/opengl/index.html. 

The makefile is written for Visual Studio and has been tested with the VS 2010 command prompt. Only small modifications need to made to the makefile to build similar projects. On the VC command prompt the command 'nmake' should suffice, and 'nmake clean' to clean up.
