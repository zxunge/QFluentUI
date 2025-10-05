set(QWINDOWKIT_BUILD_STATIC ON)
set(QWINDOWKIT_BUILD_QUICK OFF)
set(QWINDOWKIT_INSTALL OFF)
add_subdirectory(qwindowkit)
add_library(qwindowkit INTERFACE)
target_link_libraries(qwindowkit INTERFACE
    QWKCore
    QWKWidgets
)

