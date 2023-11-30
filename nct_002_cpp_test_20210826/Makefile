# store compiler into variable CC
CC := g++

# collects all source files into variable
SRCS := $(wildcard *.cpp)

# collect all binary files into variable
# remove .cpp suffix!
BINS := $(SRCS:%.cpp=%)

# all: target = binaries
all: ${BINS}

# %     - target (binary without suffix)
# %.cpp - prerequisite (source files)
# $< source files
# $@ targets (binary files)
%: %.cpp
	@echo "Building ..."
	${CC} $< -o $@ -lncurses

clean:
	   @echo "Cleaning up..."
	   rm -rvf ${BINS}
