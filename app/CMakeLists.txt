cmake_minimum_required(VERSION 3.0.0)
project(app)

set(BASE_SRC
    main.cxx
    window.cxx
    tabpane.cxx
)

set(PAGE_SRC
    page/webview.cxx
)

add_executable(Voyager
    ${BASE_SRC}
    ${PAGE_SRC}
)

target_link_libraries(Voyager
    Qt5::Core
    Qt5::Widgets
    Qt5::WebEngineWidgets
)
