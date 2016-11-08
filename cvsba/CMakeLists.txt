cmake_minimum_required(VERSION 2.8.3)
project(cvsba)

###################################
## Find catkin macros and libraries
###################################

find_package(catkin REQUIRED COMPONENTS
  roscpp
)

find_package(OpenCV REQUIRED)

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


########################
## Code optimizations ##
########################

if(${CMAKE_SYSTEM_PROCESSOR} MATCHES arm*) # We can use only -O2 because the -O3 causes gcc crash
	set(USE_O2 ON CACHE BOOL "Enable -O2 for GCC")
	set(USE_FAST_MATH ON CACHE BOOL "Enable -ffast-math for GCC")
endif()
if(${CMAKE_SYSTEM_PROCESSOR} MATCHES powerpc*)
	set(USE_O3 ON CACHE BOOL "Enable -O3 for GCC")
	set(USE_POWERPC ON CACHE BOOL "Enable PowerPC for GCC")
endif ()
if(${CMAKE_SYSTEM_PROCESSOR} MATCHES amd64* OR ${CMAKE_SYSTEM_PROCESSOR} MATCHES x86_64*)
	set(USE_O3 ON CACHE BOOL "Enable -O3 for GCC")
	set(USE_FAST_MATH ON CACHE BOOL "Enable -ffast-math for GCC")
	set(USE_MMX ON CACHE BOOL "Enable MMX for GCC")
	set(USE_SSE ON CACHE BOOL "Enable SSE for GCC")
	set(USE_SSE2 ON CACHE BOOL "Enable SSE2 for GCC")
	set(USE_SSE3 ON CACHE BOOL "Enable SSE3 for GCC")
endif()
if(${CMAKE_SYSTEM_PROCESSOR} MATCHES i686* OR ${CMAKE_SYSTEM_PROCESSOR} MATCHES x86)
	set(USE_O3 ON CACHE BOOL "Enable -O3 for GCC")
	set(USE_FAST_MATH ON CACHE BOOL "Enable -ffast-math for GCC")
	set(USE_MMX ON CACHE BOOL "Enable MMX for GCC")
	set(USE_SSE OFF CACHE BOOL "Enable SSE for GCC")
	set(USE_SSE2 OFF CACHE BOOL "Enable SSE2 for GCC")
	set(USE_SSE3 OFF CACHE BOOL "Enable SSE3 for GCC")
endif ()

# Release compilation
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DNDEBUG")

# The -Wno-long-long is required in 64bit systems when including sytem headers.
if(${CMAKE_SYSTEM_PROCESSOR} MATCHES x86_64* OR ${CMAKE_SYSTEM_PROCESSOR} MATCHES amd64*)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-long-long")
endif()

# Add optimizations
if(USE_O2)
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
endif()
if(USE_O3)
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
endif()
if(USE_FAST_MATH)
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ffast-math")
endif()
if(USE_POWERPC)
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mcpu=G3 -mtune=G5")
endif()
if(USE_MMX)
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mmmx")
endif()
if(USE_SSE)
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -msse")
endif()
if(USE_SSE2)
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -msse2")
endif()
if(USE_SSE3) 
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -msse3")
endif()
message(STATUS "Optimizations = ${CMAKE_CXX_FLAGS}")



###################################
## catkin specific configuration ##
###################################

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES cvsba lapack blas m
  CATKIN_DEPENDS roscpp
  DEPENDS OpenCV
)

###########
## Build ##
###########

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)

## Declare a C++ library
add_library(cvsba SHARED 
  src/cvsba.cpp  src/cvsba.h src/compiler.h
  src/sba.h src/sba_chkjac.c src/sba_chkjac.h
  src/sba_crsm.c src/sba_lapack.c src/sba_levmar.c
  src/sba_levmar_wrap.c
)

target_link_libraries(cvsba
  ${catkin_LIBRARIES}
  ${OpenCV_LIBRARIES}
)

