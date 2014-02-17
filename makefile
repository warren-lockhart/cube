cube.exe: cube.obj util.obj
        link /out:cube.exe /SUBSYSTEM:console cube.obj util.obj opengl32.lib openglut.lib glew32.lib

cube.obj:	cube.cpp
        cl /Focube.obj /c cube.cpp
		
util.obj:	util.cpp
		cl /Foutil.obj /c util.cpp

clean:
        del util.obj
        del cube.obj
        del cube.exe
