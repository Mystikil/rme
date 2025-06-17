cmake_minimum_required(VERSION 3.20)
project(rme)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Build type default
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE RelWithDebInfo)
endif()

# vcpkg toolchain setup (only if not already auto-detected)
# set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

# Dependencies
find_package(Boost 1.66.0 REQUIRED COMPONENTS date_time system filesystem iostreams locale json regex container)
find_package(fmt CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(ZLIB REQUIRED)
find_package(wxWidgets COMPONENTS html aui gl adv core net base REQUIRED)
find_package(GLUT REQUIRED)

# Optional: LibArchive support
# find_package(LibArchive REQUIRED)

# Include wxWidgets use file
include(${wxWidgets_USE_FILE})

# Source file inclusion from src/CMakeLists.txt
include(source/CMakeLists.txt)

# Add executable with sources from sub-include
add_executable(${PROJECT_NAME} ${rme_H} ${rme_SRC})

# Includes
target_include_directories(${PROJECT_NAME} PRIVATE
    ${OPENGL_INCLUDE_DIR}
    ${GLUT_INCLUDE_DIRS}
    ${ZLIB_INCLUDE_DIRS}
    ${LibArchive_INCLUDE_DIRS}
)

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
    ${wxWidgets_LIBRARIES}
    ${OPENGL_LIBRARIES}
    ${GLUT_LIBRARIES}
    ${ZLIB_LIBRARIES}
    fmt::fmt
    nlohmann_json::nlohmann_json
    Boost::date_time
    Boost::system
    Boost::filesystem
    Boost::iostreams
    Boost::locale
    Boost::json
    Boost::regex
    Boost::container
    ${LibArchive_LIBRARIES}
)
