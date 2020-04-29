CXX=clang++
# CXX=g++

# We have -Wno-unused-parameter so that the compiler
# doesn't complain too much about our stubs.

#CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field

# Change to this before final submission:

CXXFLAGS = -std=c++11 -Wall -Wextra -Werror

BINARIES=testMyHashTable

all: ${BINARIES}

leak: testMyHashTable
	- valgrind -q --leak-check=full ./testMyHashTable

testMyHashTable: testMyHashTable.o MyHashTable.o tddFuncs.o
	${CXX} $^ -o $@

clean:
	/bin/rm -f ${BINARIES} *.o
