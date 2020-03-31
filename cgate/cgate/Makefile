TOOLPATH=$(CGATE_HOME)/bin/
INCLUDEPATH=$(CGATE_HOME)/include/
LIBPATH=$(CGATE_HOME)/lib/
LINKFLAGS=-L$(LIBPATH)
INCLUDEFLAGS=-I$(INCLUDEPATH)

CXX = g++-9
CPPFLAGS = -I$(INCLUDEPATH)
CXXFLAGS += -std=c++17
#CXXFLAGS += -O3
CPPFLAGS += `pkg-config --cflags libmongoc-1.0`
LDFLAGS +=	-L$(LIBPATH)
LDFLAGS +=	-L$(LIBPATH) `pkg-config --libs libmongoc-1.0`
LIBSFLAGS = -lcgate -lmongoc-1.0 -lbson-1.0


			

MKDIR_OBJ=mkdir -p obj/
MKDIR_LIB=mkdir -p lib/
MKDIR_INCLUDE=mkdir -p include/

.PHONY: directories

all: directories lib clean 
 
directories:
	${MKDIR_OBJ}
	${MKDIR_LIB}
	${MKDIR_INCLUDE}

lib: env.o connection.o listener.o
	ar rcs lib/libcgateyard.a obj/env.o obj/connection.o obj/listener.o

env.o:
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) -c src/env.cpp -o obj/env.o $(LIBSFLAGS)

connection.o:
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) -c src/connection.cpp -o obj/connection.o $(LIBSFLAGS)

listener.o:
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) -c src/listener.cpp -o obj/listener.o $(LIBSFLAGS)


clean:
	-rm -rf obj