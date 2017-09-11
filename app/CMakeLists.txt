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
    page/webpage.cxx
)

set(MENU_SRC
    menu/main_menu.cxx
)

set(HISTORY_SRC
    history/history_page.cxx
    history/history.cxx
)

add_executable(Voyager
    ${BASE_SRC}
    ${PAGE_SRC}
    ${MENU_SRC}
    ${HISTORY_SRC}
)

target_link_libraries(Voyager
    Qt5::Core
    Qt5::Widgets
    Qt5::WebEngineWidgets
)
