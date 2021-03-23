/**
 * @file lemontree_utils_CppRandom.cpp
 * @brief Implements functions for random number generation in C++
 *        that can be used by a JAVA implementation using JNI.
 * @author Ankit Srivastava <asrivast@gatech.edu>
 * @version 1.0
 * @date 2021-01-06
 */
#include "lemontree_utils_CppRandom.h"

#include <trng/mrg3s.hpp>
#include <trng/uniform01_dist.hpp>
#include <trng/uniform_int_dist.hpp>

#include <iostream>


static trng::mrg3s generator;
static trng::uniform01_dist<jdouble> distribution;


JNIEXPORT
void
JNICALL Java_lemontree_utils_CppRandom_setSeed(
  JNIEnv*,
  jclass,
  jint seed
)
{
  generator.seed(static_cast<uint64_t>(seed));
}

JNIEXPORT
jint
JNICALL Java_lemontree_utils_CppRandom_nextInteger(
  JNIEnv*,
  jclass,
  jint lower,
  jint upper
)
{
  trng::uniform_int_dist dist(lower, upper);
  return static_cast<jint>(dist(generator));
}

JNIEXPORT
jdouble
JNICALL Java_lemontree_utils_CppRandom_nextDouble(
  JNIEnv*,
  jclass
)
{
  return distribution(generator);
}

JNIEXPORT
void
JNICALL Java_lemontree_utils_CppRandom_advanceState(
  JNIEnv *,
  jclass,
  jint count
)
{
  generator.jump(count);
}

JNIEXPORT
void
JNICALL Java_lemontree_utils_CppRandom_printState(
  JNIEnv *,
  jclass
)
{
  std::cout << generator << std::endl;
}
