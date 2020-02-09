cmake_minimum_required(VERSION 3.10)

project(monte_carlo)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-stdlib=libc++")

include_directories(common benchmarks)
add_subdirectory(benchmarks)
add_executable(monte_carlo common/main.cpp)
target_link_libraries(monte_carlo PUBLIC RNGBenchmark)

# add a target to generate API documentation with Doxygen
 
FIND_PACKAGE(Doxygen)
OPTION(BUILD_DOCUMENTATION "Create and install the HTML based API documentation (requires Doxygen)" ${DOXYGEN_FOUND})
 
IF(BUILD_DOCUMENTATION)
    IF(NOT DOXYGEN_FOUND)
        MESSAGE(FATAL_ERROR "Doxygen is needed to build the documentation.")
    ENDIF()
 
    SET(doxyfile_in ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
    SET(doxyfile ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
 
    CONFIGURE_FILE(${doxyfile_in} ${doxyfile} @ONLY)
 
    ADD_CUSTOM_TARGET(doc
        COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM)
 
    INSTALL(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/html DESTINATION share/doc)
ENDIF()