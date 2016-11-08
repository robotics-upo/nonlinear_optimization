cmake_minimum_required(VERSION 2.8.3)
project(cvsba_demo)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  cvsba
  roscpp
)


###################################
## catkin specific configuration ##
###################################

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES cvsba_demo
#  CATKIN_DEPENDS cvsba roscpp
#  DEPENDS system_lib
)


###########
## Build ##
###########

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(cvsba_demo_node src/cvsba_demo_node.cpp)

target_link_libraries(cvsba_demo_node
  ${catkin_LIBRARIES}
)

