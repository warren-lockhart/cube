cube
====

A simple demonstration of a spinning cube designed with modern OpenGL.

This code is a hybrid of a number of excellent online tutorials, so I must first give credit. 

First to the tutorial at http://duriansoftware.com/joe/An-intro-to-modern-OpenGL.-Table-of-Contents.html, which is a rare tutorial in modern OpenGL - rare for its clarity but also for its focus on OpenGL 2.0, the earliest incarnation of a true programmable OpenGL. This was important to me because my PC only had OpenGL 2.1 support. In particular, the utility functions he provides are gratefully reused here for loading targa files.

The tutorial at http://open.gl/ provided the basis for the code you see here, although there are some important differences in organization. The most important difference in my code in the use of OpenGLUT rather than SFML or GLFW for creating the OpenGL context. The vertices and textures however are the same.

This code is also influenced by the tutorials at http://en.wikibooks.org/wiki/OpenGL_Programming which also teach you how to create a spinning cube. It is worth bookmarking some of these as good, modern OpenGL tutorials are notoriously difficult to find on the web.

Other than these influences, the code is my own. It is the end result of my goal to create a simple OpenGL demonstration using the modern programmable pipeline, and using my own preferences for window creation and code organization. 
