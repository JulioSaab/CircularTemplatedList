cmake_minimum_required(VERSION 4.0)
project(CircularTemplatedList)

set(CMAKE_CXX_STANDARD 20)

add_executable(CircularTemplatedList main.cpp
        Media.h
        Song.h
        Podcast.h
        LinkedList.h)
