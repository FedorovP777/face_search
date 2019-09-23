cmake_minimum_required(VERSION 3.13)

project(untitled CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-march=haswell")
set(BUILD_ARCH "-m64")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m64")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -msse4.1")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -msse4.2")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mavx")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)


FIND_PACKAGE(Boost)
IF (Boost_FOUND)
	INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
	ADD_DEFINITIONS( "-DHAS_BOOST" )
ENDIF()

#
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

add_executable(${PROJECT_NAME} main.cpp src/FaceStorage.cpp src/FaceStorage.h src/FaceProvider.cpp src/FaceProvider.h src/RecognizeService.cpp src/RecognizeService.h)
include(./PVS-Studio.cmake)

pvs_studio_add_target(TARGET example1.analyze ALL
		OUTPUT FORMAT errorfile
		ANALYZE ${PROJECT_NAME}
		MODE GA:1,2 OP
		LOG target.err)