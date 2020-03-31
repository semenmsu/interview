TOOLPATH=$(CGATE_HOME)/bin/
INCLUDEPATH=$(CGATE_HOME)/include/
LIBPATH=$(CGATE_HOME)/lib/
LINKFLAGS=-L$(LIBPATH)
INCLUDEFLAGS=-I$(INCLUDEPATH)

CXX = g++-9
CXXFLAGS = -I$(INCLUDEPATH)
CXXFLAGS += -std=c++17
CXXFLAGS +=-I./cgate/include/
CXXFLAGS += `pkg-config --cflags libmongoc-1.0`
LDFLAGS +=-L$(LIBPATH) `pkg-config --libs libmongoc-1.0`
LIBSFLAGS = -lcgate -lmongoc-1.0 -lbson-1.0 -lzmq -lpthread
#CXXFLAGS += -O3


MKDIR_P=mkdir -p bin/ 

.PHONY: directories

all: directories clean common trades part_pos order_router
 
directories:
	${MKDIR_P}


common:
	$(CXX) -g $(CXXFLAGS) $(CXXFLAGS) $(LDFLAGS) -o bin/common src/common.cpp $(LIBSFLAGS)

trades:
	$(CXX) -g $(CXXFLAGS) $(CXXFLAGS) $(LDFLAGS) -o bin/trades src/trades.cpp $(LIBSFLAGS)

part_pos:
	$(CXX) -g $(CXXFLAGS) $(CXXFLAGS) $(LDFLAGS) -o bin/part-pos src/part_pos.cpp $(LIBSFLAGS)

order_router:
	$(CXX) -g $(CXXFLAGS) $(CXXFLAGS) $(LDFLAGS) -o bin/order-router src/order_router.cpp $(LIBSFLAGS)


clean:
	-rm -rf bin/*