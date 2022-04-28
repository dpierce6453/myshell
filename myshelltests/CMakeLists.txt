cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

set(This myshelltests)

include(../cmake/CPM.cmake)

#FetchContent_Declare(
#  googletest
#  GIT_REPOSITORY https://github.com/google/googletest.git
#  GIT_TAG        703bd9caab50b139428cea1aaff9974ebee5742e # release-1.10.0
  #OPTIONS "INSTALL_GTEST OFF" "gtest_force_shared_crt"
#)

#FetchContent_MakeAvailable(googletest )

CPMAddPackage(
  NAME googletest
  GITHUB_REPOSITORY google/googletest
  GIT_TAG release-1.10.0
  VERSION 1.10.0
  OPTIONS "INSTALL_GTEST OFF" "gtest_force_shared_crt"
)

set(Headers
        ../mystring.h
        ../historybuffer.h
        ../cmdprocessor.h
        ../historyprocessor.h
        )

set(Sources
        ../mystring.cpp
        ../historybuffer.cpp
        ../cmdprocessor.cpp
        ../historyprocessor.cpp
        stringtests.cpp
        buffertests.cpp processortests.cpp)

add_executable(${This} ${Sources} ${Headers} )

target_include_directories(${This} SYSTEM PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}
)

target_compile_features(${This} PRIVATE cxx_std_17)
target_link_libraries(${This}  PUBLIC gmock gtest gtest_main )


add_test(
    NAME ${This}
    COMMAND ${This}
)