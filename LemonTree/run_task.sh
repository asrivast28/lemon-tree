# Script for running lemon-tree tasks with C++ random number generation
BASEDIR=$(dirname "$0")
java -Djava.library.path=${BASEDIR}/src/lemontree/utils -jar ${BASEDIR}/lemontree_v3.1.1.jar $@
