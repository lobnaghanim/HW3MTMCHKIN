cmake_minimum_required(VERSION 3.25)
project(HW3MTMCHKIN)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(HW3MTMCHKIN
        HealthPointsExampleTest.cpp
        QueueExampleTests.cpp
        TestMain.cpp
        TestUtils.h)
