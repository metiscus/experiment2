lib_LTLIBRARIES=libcore.la librender.la
libcore_la_CXXFLAGS=-ffast-math $(SDL2_CFLAGS)
libcore_la_LDFLAGS =
libcore_la_SOURCES   =	\
	core/math.h			\
	core/ifile.h		\
	core/textfile.h		\
	core/textfile.cpp	\
	core/rectangle.h	\
	core/rectangle.cpp	\
	core/event.h		\
	core/event.cpp		\
	core/eventsystem.h	\
	core/eventsystem.cpp\
	core/events/quit.h	\
	core/events/quit.cpp\
	core/events/keyboard.h\
	core/events/keyboard.cpp\
	core/events/mouse.h\
	core/events/mouse.cpp

librender_la_CXXFLAGS=$(SDL2_CFLAGS) $(OPENGL_CFLAGS)
librender_la_LDFLAGS =$(OPENGL_LIBS) -lcore
librender_la_SOURCES =	\
	render/glad/glad.c	\
	render/glad/glad.h	\
	render/glad/KHR/khrplatform.h\
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
	render/array.cpp	\
	render/uniform.h	\
	render/uniform.cpp	\
	render/program.h	\
	render/program.cpp	\
	render/shader.h		\
	render/shader.cpp	\
	render/vbo.h		\
	render/vbo.cpp		\
	render/sampler.h	\
	render/sampler.cpp	\
	render/state.h		\
	render/state.cpp	\
	render/drawable.h	\
	render/drawable.cpp	\
	render/sprite.h		\
	render/sprite.cpp	\
	render/node.h		\
	render/node.cpp

bin_PROGRAMS=thegame

thegame_CXXFLAGS=$(SDL2_CFLAGS) $(OPENGL_CFLAGS)
thegame_LDFLAGS=$(SDL2_LIBS) $(OPENGL_LIBS) librender.la libcore.la
thegame_SOURCES=\
	game/game.cpp

#TESTS= test_core
#check_PROGRAMS= test_core

#test_core_CXXFLAGS	=-lcore
#test_core_SOURCES	=tests/test_core.cpp
