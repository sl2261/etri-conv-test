CC = g++
CFLAGS = -g -Wall -std=c++11
SRCS = $(shell find . -name "*.cpp")
PROG = ${SRCS:.cpp=.bin}

OPENCV = `pkg-config opencv4 --cflags --libs`
LIBS = $(OPENCV)

binaties: $(PROG)

$(PROG):$(SRCS)
	@$(CC) $(CFLAGS) -o $@ $< $(LIBS)
