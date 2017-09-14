cmake_minimum_required(VERSION 3.0.0)
project(Voyager)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
#set(CMAKE_PREFIX_PATH "/opt/Qt5.6.1/5.6/gcc_64/lib/cmake")
set(CMAKE_PREFIX_PATH "/opt/Qt5.9.0/5.9/gcc_64/lib/cmake")

find_package(Qt5 REQUIRED COMPONENTS
	Core
	Widgets
	WebEngineWidgets
)

if (${Qt5Core_FOUND})
	message(STATUS "Found Qt5 Core")
endif()

if (${Qt5Widgets_FOUND})
	message(STATUS "Found Qt5 Widgets")
endif()

if (${Qt5WebEngineWidgets_FOUND})
	message(STATUS "Found Qt5 Web Engine Widgets")
endif()

add_compile_options(-std=c++11)

add_subdirectory(src)
