##
# @file Makefile
# @brief Build file for the library which enables using
#        C++ random number generator in JAVA using JNI
# @author Ankit Srivastava <asrivast@gatech.edu>
# @version 1.0
# @date 2021-01-06
#

all: header source

header: CppRandom.java
	javac -h . CppRandom.java

source: lemontree_utils_CppRandom.h lemontree_utils_CppRandom.cpp
	g++ -c -fPIC -I${JAVA_HOME}/include -I ${JAVA_HOME}/include/linux lemontree_utils_CppRandom.cpp -o lemontree_utils_CppRandom.o
	g++ -shared -fPIC -o libCppRandom.so lemontree_utils_CppRandom.o -lc

.PHONY: clean
clean:
	rm -f CppRandom.class lemontree_utils_CppRandom.h
	rm -f lemontree_utils_CppRandom.o libCppRandom.so
