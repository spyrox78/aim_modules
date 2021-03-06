#######################################################################################################################
# ___________________________________________________________________________________________________________________ #
# ___________________________________________/\/\______/\/\/\/\__/\/\______/\/\______________________________________ #
# _________________________________________/\/\/\/\______/\/\____/\/\/\__/\/\/\______________________________________ #
# _______________________________________/\/\____/\/\____/\/\____/\/\/\/\/\/\/\______________________________________ #
# _______________________________________/\/\/\/\/\/\____/\/\____/\/\__/\__/\/\______________________________________ #
# _______________________________________/\/\____/\/\__/\/\/\/\__/\/\______/\/\______________________________________ #
# ___________________________________________________________________________________________________________________ #
#                                                                                                                     #
#######################################################################################################################

# Your own changes to the CMake build system such as for example FindEigen to support matrix manipulations

##########################################################################################
# Section to include your own FindX cmake files and options
##########################################################################################

## Commented example for the EIGEN library. Replace this with what your module needs, 
## for example Boost libraries, OpenCV, inference libraries, etc.
#
# OPTION(BUILD_EIGEN OFF "Build module with Eigen support")
# CONFIGURE_FILE(${CMAKE_SOURCE_DIR}/config.h.in ${CMAKE_SOURCE_DIR}/inc/config.h)
# IF (BUILD_EIGEN) 
# 	MESSAGE(STATUS "Eigen support, this will enable all (sparse) matrix related code")
# 	FIND_PACKAGE(Eigen3 REQUIRED)
# 	INCLUDE_DIRECTORIES(${EIGEN3_INCLUDE_DIR})
# ENDIF()

##########################################################################################

