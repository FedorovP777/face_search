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

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

set(boost_dir "${PROJECT_SOURCE_DIR}/third_party/boost/boost")

include_directories(
		${boost_dir}
		${boost_dir}/libs
)

FIND_PACKAGE(Boost)
IF (Boost_FOUND)
	INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
	ADD_DEFINITIONS("-DHAS_BOOST")
ENDIF ()

#
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

add_executable(${PROJECT_NAME} main.cpp src/FaceStorage.cpp src/FaceStorage.h src/FaceProvider.cpp src/FaceProvider.h src/RecognizeService.cpp src/RecognizeService.h)

################################
# PVS-Studio
################################

include(./PVS-Studio.cmake)

pvs_studio_add_target(TARGET example1.analyze ALL
		OUTPUT FORMAT errorfile
		ANALYZE ${PROJECT_NAME}
		MODE GA:1,2 OP
		LOG target.err)


################################
# GTest
################################

enable_testing()

if (INSTALL_GTEST)
	set(cmake_package_name GTest)
endif ()

set(googletest_source_dir "${PROJECT_SOURCE_DIR}/third_party/googletest/googletest")


include_directories(
		${googletest_source_dir}
		${googletest_source_dir}/include

)
set(project_files
		${PROJECT_SOURCE_DIR}/src//FaceStorage.cpp
		${PROJECT_SOURCE_DIR}/src/FaceStorage.h
		${PROJECT_SOURCE_DIR}/src/FaceProvider.cpp
		${PROJECT_SOURCE_DIR}/src/FaceProvider.h
		${PROJECT_SOURCE_DIR}/src/RecognizeService.cpp
		${PROJECT_SOURCE_DIR}/src/RecognizeService.h

		)

set(common_test_files
		${PROJECT_SOURCE_DIR}/src/FaceStorageUnittest.cpp

		)

add_executable(tests ${common_test_files} ${project_files})
target_link_libraries(tests gtest gtest_main)