cmake_minimum_required(VERSION 3.0.0)
project(Voyager)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

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

if (UNIX)
	install(FILES share/voyager.desktop DESTINATION /usr/share/applications)
	install(CODE "execute_process(COMMAND update-desktop-database)")
endif()
