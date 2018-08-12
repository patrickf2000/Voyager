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

add_compile_options(-std=c++11)

add_subdirectory(src)

if (UNIX)
    install(FILES share/voyager.desktop DESTINATION /usr/share/applications)
    install(CODE "execute_process(COMMAND update-desktop-database)")
endif()
