cmake_minimum_required(VERSION 3.23.2) # uncomment if you're Ali
#cmake_minimum_required(VERSION 3.25) # uncomment if you're Lobna

project(HW3MTMCHKIN)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

#add_executable(HW3MTMCHKIN
#        HealthPoints.cpp HealthPoints.h Queue.h main.cpp)
#
add_executable(HW3MTMCHKIN
        HealthPointsExampleTest.cpp
        QueueExampleTests.cpp
        TestMain.cpp
        TestUtils.h HealthPoints.cpp HealthPoints.h Queue.h)
