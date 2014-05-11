# this Makefile is intended to make any of the examples in this directory
#all:  proto-texture proto-ui proto-ui2 proto-counting proto-windows proto-sound proto-chat proto-multiplayer

# the following lines pertain to using sound
# if you download FMOD onto your own machine, change the line below
FMOD_DIR = /usr/local/dept/apps/fmod
FMOD_INCLUDE = -I$(FMOD_DIR)/api/inc -I$(FMOD_DIR)/examples/common
FMOD_LIB = $(FMOD_DIR)/api/lib/libfmodex64.so

# the following lines pertain to setting up compiler options and libraries
OPTS = -Wall -g -std=c++11
LIBS = -lGL -lglut -lm
ARCH := $(shell uname)
ifeq ($(ARCH), Linux)
else
 MACOSX_DEFINE = -DMACOSX -I/sw/include
 LIBS = -I/usr/common/include -I/usr/include/GL -L/System/Library/Frameworks/OpenGL.framework/Libraries -framework GLUT -framework OpenGL -lGL -lm -lobjc -lstdc++

endif

# here are the usual make rules

JumpyJumpyShootShoot: JumpyJumpyShootShoot.o texture.o character.o sound.o player.o squater.o platform.o pewpew.o bullet.o
	g++ $(OPTS) -o JumpyJumpyShootShoot JumpyJumpyShootShoot.o sound.o texture.o character.o player.o squater.o platform.o pewpew.o bullet.o $(LIBS) $(FMOD_LIB) -pthread

JumpyJumpyShootShoot.o: JumpyJumpyShootShoot.cpp
	g++ $(OPTS)  $(FMOD_INCLUDE) $(MACOSX_DEFINE) -c JumpyJumpyShootShoot.cpp


testCharacter: testCharacter.o texture.o character.o 
	g++ $(OPTS) -o testCharacter testCharacter.o texture.o character.o $(LIBS)

testCharacter.o: testCharacter.cpp
	g++ $(OPTS) $(MACOSX_DEFINE) -c testCharacter.cpp

character.o: character.cpp character.h
	g++ $(OPTS) $(MACOSX_DEFINE) -c character.cpp

player.o: player.cpp  player.h
	g++ $(OPTS) $(MACOSX_DEFINE) -c player.cpp

squater.o: squater.cpp squater.h
	g++ $(OPTS) $(MACOSX_DEFINE) -c squater.cpp 

pewpew.o: pewpew.cpp pewpew.h
	g++ $(OPTS) $(MACOSX_DEFINE) -c pewpew.cpp 

platform.o: platform.cpp platform.h
	g++ $(OPTS) $(MACOSX_DEFINE) -c platform.cpp 

bullet.o: bullet.cpp bullet.h
	g++ $(OPTS) $(MACOSX_DEFINE) -c bullet.cpp
proto-texture: proto-texture.o texture.o
	g++ $(OPTS) -o proto-texture proto-texture.o texture.o $(LIBS)

proto-texture.o: proto-texture.cpp
	g++ $(OPTS) $(MACOSX_DEFINE) -c proto-texture.cpp

project-texture: project-texture.o texture.o
	g++ $(OPTS) -o project-texture project-texture.o texture.o $(LIBS)

project-texture.o: project-texture.cpp
	g++ $(OPTS) $(MACOSX_DEFINE) -c project-texture.cpp

proto-ui: proto-ui.o
	g++ $(OPTS) -o proto-ui proto-ui.o $(LIBS)

proto-ui.o: proto-ui.cpp
	g++ $(OPTS) $(MACOSX_DEFINE) -c proto-ui.cpp

proto-ui2: proto-ui2.o texture.o
	g++ $(OPTS) -o proto-ui2 proto-ui2.o texture.o $(LIBS)

proto-ui2.o: proto-ui2.cpp
	g++ $(OPTS) $(MACOSX_DEFINE) -c proto-ui2.cpp

proto-counting: proto-counting.o
	g++ $(OPTS) -o proto-counting proto-counting.o $(LIBS)

proto-counting.o: proto-counting.cpp
	g++ $(OPTS) $(MACOSX_DEFINE) -c proto-counting.cpp

proto-windows: proto-windows.o texture.o
	g++ $(OPTS) -o proto-windows proto-windows.o texture.o $(LIBS)

proto-windows.o: proto-windows.cpp
	g++ $(OPTS) $(MACOSX_DEFINE) -c proto-windows.cpp

proto-sound: proto-sound.o sound.o
	g++ $(OPTS) -o proto-sound proto-sound.o sound.o $(LIBS) $(FMOD_LIB) -pthread

proto-sound.o: proto-sound.cpp
	g++ $(OPTS) $(FMOD_INCLUDE) $(MACOSX_DEFINE) -c proto-sound.cpp

proto-chat: proto-chat.o network.o
	g++ $(OPTS) -o proto-chat proto-chat.o network.o $(LIBS)

proto-chat.o: proto-chat.cpp
	g++ $(OPTS) $(MACOSX_DEFINE) -c proto-chat.cpp

proto-multiplayer: proto-multiplayer.o network.o
	g++ $(OPTS) -o proto-multiplayer proto-multiplayer.o network.o $(LIBS)

proto-multiplayer.o: proto-multiplayer.cpp
	g++ $(OPTS) $(MACOSX_DEFINE) -c proto-multiplayer.cpp

# proto-image1: proto-image1.o
# 	g++ $(OPTS) -o proto-image1 proto-image1.o $(LIBS)
# 
# proto-image1.o: proto-image1.cpp
# 	g++ $(OPTS) -c proto-image1.cpp
# 

texture.o: texture.cpp texture.h
	g++ $(OPTS) $(MACOSX_DEFINE) -c texture.cpp

sound.o: sound.cpp sound.h
	g++ $(OPTS) $(FMOD_INCLUDE) -c sound.cpp

network.o: network.cpp network.h
	g++ $(OPTS) -c network.cpp
