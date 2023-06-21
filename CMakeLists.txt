cmake_minimum_required(VERSION 3.5)

if (WIN32)
    project(projectBd VERSION 1.0.0 LANGUAGES CXX)
elseif(UNIX)
    project(projectBd VERSION 1.0.0)
endif()


#======================= INCLUSION OF Qt =======================#

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH $ENV{QTDIR})
find_package(Qt6Core REQUIRED)
find_package(Qt6Widgets REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Sql)


#=================== INCLUSION OF Project Files ====================#
set(FORMS_DIR "${CMAKE_SOURCE_DIR}/forms")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")

include_directories(${FORMS_DIR})
include_directories(${INCLUDE_DIR})
include_directories(${SOURCE_DIR})

file(GLOB_RECURSE SOURCES
    "${FORMS_DIR}/*.ui"
    "${FORMS_DIR}/*.qrc"
    "${SOURCE_DIR}/*.h"
    "${INCLUDE_DIR}/*.h"
    "${SOURCE_DIR}/*.cpp"
)

file(GLOB_RECURSE FORMS
    "${FORMS_DIR}/forms.ui"
    "${FORMS_DIR}/forms.qrc"
)



#=================== SETUP EXECTUABLE ====================#


# Add the forms directory to the AUTOUIC search paths
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_AUTOUIC_SEARCH_PATHS} ${FORMS_DIR})

# Add the executable
if (WIN32)
    add_executable(projectBd WIN32 ${SOURCES})
elseif(UNIX)
    add_executable(projectBd ${SOURCES})
endif()



#=========================SUBDIRECTORIES AND TESTS============
enable_testing()

add_subdirectory(
    "${CMAKE_CURRENT_SOURCE_DIR}/tests"
)


#==========================================================


# Add the target includes for MY_PROJECT
target_include_directories(projectBd PRIVATE ${FORMS_DIR})
target_include_directories(projectBd PRIVATE ${INCLUDE_DIR})
target_include_directories(projectBd PRIVATE ${SOURCE_DIR})

#===================== LINKING LIBRARIES =======================#
target_link_libraries(projectBd Qt6::Widgets)
target_link_libraries(projectBd Qt6::Sql)




