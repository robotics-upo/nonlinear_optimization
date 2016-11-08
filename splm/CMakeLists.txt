cmake_minimum_required(VERSION 2.8.3)
project(splm)

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

find_library(CXSPARSE_LIB NAMES cxsparse)
IF(${CXSPARSE_LIB} STREQUAL "CXSPARSE_LIB-NOTFOUND")
  message(FATAL_ERROR "cxsparse library  not found")
ELSE()
  message(STATUS "cxsparse = ${CXSPARSE_LIB}")
ENDIF()

find_library(METIS_LIB NAMES metis)
IF(${METIS_LIB} STREQUAL "METIS_LIB-NOTFOUND")
  message(FATAL_ERROR "metis library  not found")
ELSE()
  message(STATUS "metis = ${METIS_LIB}")
ENDIF()

find_library(LDL_LIB NAMES ldl)
IF(${LDL_LIB} STREQUAL "LDL_LIB-NOTFOUND")
  message(FATAL_ERROR "ldl library  not found")
ELSE()
  message(STATUS "ldl = ${LDL_LIB}")
ENDIF()

find_library(CHOLMOD_LIB NAMES cholmod)
IF(${CHOLMOD_LIB} STREQUAL "CHOLMOD_LIB-NOTFOUND")
  message(FATAL_ERROR "cholmod library  not found")
ELSE()
  message(STATUS "cholmod = ${CHOLMOD_LIB}")
ENDIF()

find_library(SUPERLU_LIB NAMES superlu)
IF(${SUPERLU_LIB} STREQUAL "SUPERLU_LIB-NOTFOUND")
  message(FATAL_ERROR "superlu library  not found")
ELSE()
  message(STATUS "superlu = ${SUPERLU_LIB}")
ENDIF()

find_library(UMFPACK_LIB NAMES umfpack)
IF(${UMFPACK_LIB} STREQUAL "UMFPACK_LIB-NOTFOUND")
  message(FATAL_ERROR "umfpack library  not found")
ELSE()
  message(STATUS "umfpack = ${UMFPACK_LIB}")
ENDIF()

find_library(CCOLAMD_LIB NAMES ccolamd)
IF(${CCOLAMD_LIB} STREQUAL "CCOLAMD_LIB-NOTFOUND")
  message(FATAL_ERROR "ccolamd library  not found")
ELSE()
  message(STATUS "ccolamd = ${CCOLAMD_LIB}")
ENDIF()

find_library(COLAMD_LIB NAMES colamd)
IF(${COLAMD_LIB} STREQUAL "COLAMD_LIB-NOTFOUND")
  message(FATAL_ERROR "colamd library  not found")
ELSE()
  message(STATUS "colamd = ${COLAMD_LIB}")
ENDIF()

find_library(CAMD_LIB NAMES camd)
IF(${CAMD_LIB} STREQUAL "CAMD_LIB-NOTFOUND")
  message(FATAL_ERROR "camd library  not found")
ELSE()
  message(STATUS "camd = ${CAMD_LIB}")
ENDIF()

find_library(AMD_LIB NAMES amd)
IF(${AMD_LIB} STREQUAL "AMD_LIB-NOTFOUND")
  message(FATAL_ERROR "amd library  not found")
ELSE()
  message(STATUS "amd = ${AMD_LIB}")
ENDIF()


###################################
## catkin specific configuration ##
###################################
catkin_package(
  INCLUDE_DIRS include
  LIBRARIES splm lapack blas m cxsparse metis ldl cholmod superlu umfpack ccolamd colamd camd amd
  CATKIN_DEPENDS roscpp
)

###########
## Build ##
###########

include_directories(
  ${catkin_INCLUDE_DIRS}
  /usr/include/suitesparse
  /usr/include/superlu
)

add_definitions(-DHAVE_CSPARSE -DHAVE_LDL -DHAVE_CHOLMOD -DHAVE_SuperLU -DHAVE_UMFPACK)

add_library(splm SHARED
  src/compiler.h src/splm.h src/splm_priv.h
  src/splm.c src/splm_crsm.c src/splm_ccsm.c src/splm_hessian.c src/splm_time.c src/splm_stm.c src/splm_misc.c
  src/splm_csparse.c src/splm_ldlp.c src/splm_cholmod.c src/splm_superlu.c src/splm_umfpack.c 
)

target_link_libraries(splm
  ${catkin_LIBRARIES}
)
