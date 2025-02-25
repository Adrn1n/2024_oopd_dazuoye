# cmake_minimum_required(VERSION 3.5)

# project(super VERSION 0.1 LANGUAGES CXX)

# set(CMAKE_AUTOUIC ON)
# set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTORCC ON)

# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
# find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# set(PROJECT_SOURCES
#         main.cpp
#         mainwindow.cpp
#         mainwindow.h
#         mainwindow.ui
# )

# if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
#     qt_add_executable(super
#         MANUAL_FINALIZATION
#         ${PROJECT_SOURCES}
#         form.h form.cpp form.ui
#     )
# # Define target properties for Android with Qt 6 as:
# #    set_property(TARGET super APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
# #                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# # For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
# else()
#     if(ANDROID)
#         add_library(super SHARED
#             ${PROJECT_SOURCES}
#         )
# # Define properties for Android with Qt 5 after find_package() calls as:
# #    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#     else()
#         add_executable(super
#             ${PROJECT_SOURCES}
#         )
#     endif()
# endif()

# target_link_libraries(super PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# # Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# # If you are developing for iOS or macOS you should consider setting an
# # explicit, fixed bundle identifier manually though.
# if(${QT_VERSION} VERSION_LESS 6.1.0)
#   set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.super)
# endif()
# set_target_properties(super PROPERTIES
#     ${BUNDLE_ID_OPTION}
#     MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
#     MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
#     MACOSX_BUNDLE TRUE
#     WIN32_EXECUTABLE TRUE
# )

# include(GNUInstallDirs)
# install(TARGETS super
#     BUNDLE DESTINATION .
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
# )

# if(QT_VERSION_MAJOR EQUAL 6)
#     qt_finalize_executable(super)
# endif()

cmake_minimum_required(VERSION 3.5)
project(Supermarket_Manage_System)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "D:/Qt/5.15.2/mingw81_64") # Qt Kit Dir
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Qt5 COMPONENTS Widgets Sql REQUIRED) # Qt COMPONENTS
aux_source_directory(./src srcs)
include_directories(include)
add_library(sqlite3)
add_executable(${PROJECT_NAME}
${srcs} ./include/mainwindow.h ./include/form.h ./include/Sell_Dialog.h ./include/Sell_Add_Dialog.h ./assets/mainwindow.ui ./assets/form.ui ./assets/Sell_Dialog.ui ./assets/Sell_Add_Dialog.ui ./assets/assets.qrc)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets Qt5::Sql sqlite3)
