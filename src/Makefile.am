lib_LTLIBRARIES=libcore.la librender.la
libcore_la_CXXFLAGS=-ffast-math
libcore_la_SOURCES   =	\
	core/vector2.h		\
	core/vector3.h		\
	core/vector4.h		\
	core/ifile.h		\
	core/textfile.h		\
	core/vector2.cpp	\
	core/vector3.cpp	\
	core/vector4.cpp	\
	core/textfile.cpp	

librender_la_CXXFLAGS=$(SDL2_CFLAGS) $(OPENGL_CFLAGS)
librender_la_LDFLAGS =$(SDL2_LIBS) $(OPENGL_LIBS) -lcore
librender_la_SOURCES =	\
	render/window.cpp	\
	render/window.h		\
	render/render.cpp	\
	render/render.h		\
	render/image.cpp	\
	render/image.h		\
	render/image.inl	\
	render/texture.h	\
	render/texture.cpp	\
	render/array.h		\
	render/array.cpp	

TESTS= test_core
check_PROGRAMS= test_core

test_core_CXXFLAGS	=-lcore
test_core_SOURCES	=tests/test_core.cpp
