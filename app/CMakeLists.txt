cmake_minimum_required(VERSION 3.0.0)
project(app)

set(BASE_SRC
    main.cxx
    window.cxx
    tabpane.cxx
)

set(PAGE_SRC
    page/page.cxx
    page/webview.cxx
    page/addressbar.cxx
    page/searchbar.cxx
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
