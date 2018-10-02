GPU=1
DEBUG=0

ARCH= -gencode arch=compute_30,code=sm_30 \
      -gencode arch=compute_35,code=sm_35 \
      -gencode arch=compute_50,code=[sm_50,compute_50] \
      -gencode arch=compute_52,code=[sm_52,compute_52]

EXEC=cudaSaSLTest
OBJDIR=./

CC=gcc
CPP=g++
NVCC=/usr/local/cuda/bin/nvcc 
AR=ar
OPTS=-Ofast
LDFLAGS= -lm -pthread 
COMMON= -I./
CFLAGS=-Wall -Wno-unused-result -Wno-unknown-pragmas -Wfatal-errors -fPIC


ifeq ($(DEBUG), 1) 
OPTS=-O0 -g
endif

CFLAGS+=$(OPTS)

ifeq ($(GPU), 1) 
COMMON+= -DGPU -I/usr/local/cuda/include/
CFLAGS+= -DGPU
LDFLAGS+= -L/usr/local/cuda/lib64 
endif


OBJ= cudaSaSL.o cudaSignals.o cudaSystems.o cudaClient.o

ifeq ($(GPU), 1) 
LDFLAGS+= -lstdc++ -lcudart
OBJ+= cudaSignals_kernels.o
endif

OBJS = $(addprefix $(OBJDIR), $(OBJ))
DEPS = $(wildcard *.h) Makefile

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(COMMON) $(CFLAGS) $^ -o $@ $(LDFLAGS)

%.o: %.cpp $(DEPS)
	$(CPP) -std=c++11 $(COMMON) $(CFLAGS) -c $< -o $@

%.o: %.c $(DEPS)
	$(CC) $(COMMON) $(CFLAGS) -c $< -o $@

%.o: %.cu $(DEPS)
	$(NVCC) $(ARCH) $(COMMON) --compiler-options "$(CFLAGS)" -c $< -o $@

.PHONY: clean

clean:
	rm *.o $(EXEC)
