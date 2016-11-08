cmake_minimum_required(VERSION 2.8.3)
project(levmar)


###################################
## Find catkin macros and libraries
###################################
find_package(catkin REQUIRED COMPONENTS
  roscpp
)

find_library(LAPACK_LIB NAMES lapack)
IF(${LAPACK_LIB} STREQUAL "LAPACK_LIB-NOTFOUND")
  message(FATAL_ERROR "lapack library  not found")
ELSE()
  message(STATUS "lapack = ${LAPACK_LIB}")
ENDIF()

find_library(BLAS_LIB NAMES blas)
IF(${BLAS_LIB} STREQUAL "BLAS_LIB-NOTFOUND")
  message(FATAL_ERROR "blas library  not found")
ELSE()
  message(STATUS "blas = ${BLAS_LIB}")
ENDIF()

find_library(M_LIB NAMES m)
IF(${M_LIB} STREQUAL "M_LIB-NOTFOUND")
  message(FATAL_ERROR "m library  not found")
ELSE()
  message(STATUS "m = ${M_LIB}")
ENDIF()


###################################
## catkin specific configuration ##
###################################
catkin_package(
  INCLUDE_DIRS include
  LIBRARIES levmar blas lapack m
  CATKIN_DEPENDS roscpp
)

###########
## Build ##
###########

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_library(levmar SHARED
  src/lm.c src/Axb.c src/misc.c src/lmlec.c src/lmbc.c src/lmblec.c src/lmbleic.c
  src/levmar.h src/misc.h src/compiler.h
)

target_link_libraries(levmar
  ${catkin_LIBRARIES}
)


