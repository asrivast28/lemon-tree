/**
 * @file lemontree_utils_CppRandom.cpp
 * @brief Implements functions for random number generation in C++
 *        that can be used by a JAVA implementation using JNI.
 * @author Ankit Srivastava <asrivast@gatech.edu>
 * @version 1.0
 * @date 2021-01-06
 */
#include "lemontree_utils_CppRandom.h"

#include <random>


static std::mt19937 generator;
static std::uniform_real_distribution<jdouble> distribution(0.0, 1.0);


JNIEXPORT
void
JNICALL Java_lemontree_utils_CppRandom_setSeed(
  JNIEnv*,
  jclass,
  jint seed
)
{
  generator.seed(seed);
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
  std::uniform_int_distribution<jint> dist(lower, upper);
  return dist(generator);
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
