GPU=0

CPP=g++
CFLAGS= -std=c++11 -I. -Wall
LDFLAGS=

SRCS = SaSL.cpp Client.cpp Signals.cpp Systems.cpp
#OBJS = $(filter %.o,$(SRCS:.cpp=.o))
OBJS = $(SRCS:.cpp=.o)

EXEC= CudaSaSLTest

all: $(EXEC)


$(EXEC): $(OBJS)
	$(CPP) -o $@  $^

%.o:  %.cpp
	$(CPP) $(CFLAGS) -c -g $< -o  $@


.PHONY: clean

clean:
	rm -rf $(OBJS) $(EXEC)



