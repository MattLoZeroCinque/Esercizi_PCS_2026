cmake_minimum_required(VERSION 3.20)
project(esercitazione5)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

add_executable(measure_sorts Execution_Time.cpp timecounter.cpp)

add_executable(test_bubblesort Testing_BubbleSort.cpp)
add_executable(test_insertionsort Testing_InsertionSort.cpp)
add_executable(test_selectionsort Testing_SelectionSort.cpp)
add_executable(test_mergesort Testing_MergeSort.cpp)
add_executable(test_quicksort Testing_QuickSort.cpp)
add_executable(test_newquicksort Testing_NewQuickSort.cpp)
