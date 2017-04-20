cmake_minimum_required (VERSION 2.8 FATAL_ERROR)

project (process-keeper)

if (CMAKE_VERSION VERSION_LESS "3.1")
	if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
		set (CMAKE_CXX_FLAGS "--std=gnu++11 ${CMAKE_CXX_FLAGS}")
	endif ()
else ()
	set (CMAKE_CXX_STANDARD 11)
endif ()

add_executable (process-keeper
	./application.cpp
	./application.hpp
	./main.cpp
	)

target_link_libraries (process-keeper
	boost_program_options
	)
