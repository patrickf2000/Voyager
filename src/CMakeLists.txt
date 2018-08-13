cmake_minimum_required(VERSION 3.0.0)
project(app)

set(BASE_SRC
    main.cxx
    window.cxx
    tabpane.cxx
    path.cxx
    icons.qrc
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

set(BOOKMARK_SRC
    bookmark/bk_manager.cxx
    bookmark/bk_dialog.cxx
    bookmark/bk_action.cxx
)

set(SRC
    ${BASE_SRC}
    ${PAGE_SRC}
    ${MENU_SRC}
    ${HISTORY_SRC}
    ${BOOKMARK_SRC}
)

add_executable(Voyager ${SRC})

target_link_libraries(Voyager
    Qt5::Core
    Qt5::Widgets
    Qt5::WebEngineWidgets
)

if (UNIX)
    install(TARGETS Voyager DESTINATION /usr/local/bin)
endif()
