cmake_minimum_required(VERSION 3.2)

include(sources.cmake)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(DEPLOY_QT_LIBS OFF CACHE BOOL "Set whether windeployqt will be run")
set(QML_FROM_SRC_DIR OFF CACHE BOOL "Sets whether to load QML from the filesystem or QRC")

find_package(Qt5 COMPONENTS Core Quick Qml REQUIRED)
qt5_add_resources(RESOURCES resources.qrc)

if (${QML_FROM_SRC_DIR})
    add_definitions(-DQML_DIR="${CMAKE_SOURCE_DIR}/src/qml")
endif()

if(WIN32)
  set(GUI_TYPE WIN32)
elseif(APPLE)
  set(GUI_TYPE MACOSX_BUNDLE)
endif()

add_executable(${CMAKE_PROJECT_NAME} ${GUI_TYPE} ${SOURCES} ${RESOURCES})

if (${DEPLOY_QT_LIBS})
    add_custom_command(TARGET QmlTest
        POST_BUILD
        COMMAND set PATH="${_qt_bin_dir}"
        COMMAND "${WINDEPLOYQT_EXECUTABLE}" --qmldir "${CMAKE_SOURCE_DIR}/qml" --no-translations "$<TARGET_FILE:QmlTest>"
    )
endif()

target_link_libraries(${CMAKE_PROJECT_NAME} Qt5::Core Qt5::Quick Qt5::Qml)
