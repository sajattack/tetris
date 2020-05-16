# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall \
		  $(foreach dir,$(LIBDIRS),-L$(dir)) \
		  $(foreach dir,$(INCLUDEDIRS),-I$(dir))

# the build target executable:
TARGET = tetris

# define the C++ source files
SRCS = Point.cpp Tetromino.cpp GridTetromino.cpp Gameboard.cpp Main.cpp TetrisGame.cpp

# define the C object files 
OBJS = $(addprefix $(BUILDDIR)/,$(subst .cpp,.o,$(SRCS))) 

# the libraries we are linking
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# the directories where we have our header files
INCLUDEDIRS = include

# the directories where we have our libraries
LIBDIRS = lib

# the directory where we will build
BUILDDIR = build

# the directory where our source files reside
SOURCEDIR = src

all: $(TARGET)

# create object file from c++ file
$(BUILDDIR)/%.o: $(SOURCEDIR)/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $< 

# link libraries and create final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LDFLAGS) $(LIBS) 

# delete all the build artifacts
clean:
	$(RM) $(BUILDDIR)/*
