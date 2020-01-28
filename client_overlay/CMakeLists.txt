SET(TARGET_NAME client_overlay)
SET(CMAKE_AUTOMOC ON)
SET(Qt5_DIR $ENV{VCPKG_DIR}/installed/x64-windows/share/cmake)
list(APPEND CMAKE_PREFIX_PATH ${Qt5_DIR})
FIND_PACKAGE(Qt5Core REQUIRED)
FIND_PACKAGE(Qt5Widgets REQUIRED)
FIND_PACKAGE(Qt5Qml REQUIRED)
FIND_PACKAGE(Qt5Quick REQUIRED)
FIND_PACKAGE(Qt5Multimedia REQUIRED)

ADD_EXECUTABLE(${TARGET_NAME}
    src/main.cpp
    src/overlaycontroller.h
    src/overlaycontroller.cpp
    src/logging.h
    src/tabcontrollers/AnalogInputRemappingController.cpp
    src/tabcontrollers/DeviceManipulationTabController.cpp
    src/tabcontrollers/DigitalInputRemappingController.cpp
    )
TARGET_INCLUDE_DIRECTORIES(${TARGET_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/../openvr/headers
    ${CMAKE_CURRENT_LIST_DIR}/../lib_vrinputemulator/include
    ${CMAKE_CURRENT_LIST_DIR}/../third-party/easylogging++
    $ENV{VCPKG_DIR}/installed/x64-windows/include
    $ENV{VCPKG_DIR}/installed/x64-windows/include/QtCore
    $ENV{VCPKG_DIR}/installed/x64-windows/include/QtGui
    $ENV{VCPKG_DIR}/installed/x64-windows/include/QtWidgets
    $ENV{VCPKG_DIR}/installed/x64-windows/include/QtQml
    $ENV{VCPKG_DIR}/installed/x64-windows/include/QtQuick
    $ENV{VCPKG_DIR}/installed/x64-windows/include/QtMultimedia
    )
TARGET_LINK_LIBRARIES(${TARGET_NAME} PRIVATE
    lib_vrinputemulator
    ${CMAKE_CURRENT_LIST_DIR}/../openvr/lib/win64/openvr_api.lib
    Qt5::Core 
    Qt5::Widgets
    Qt5::Qml
    Qt5::Quick
    Qt5::Multimedia
    debug
    $ENV{VCPKG_DIR}/installed/x64-windows/debug/lib/boost_regex-vc140-mt-gd.lib
    $ENV{VCPKG_DIR}/installed/x64-windows/debug/lib/boost_date_time-vc140-mt-gd.lib
    optimized
    $ENV{VCPKG_DIR}/installed/x64-windows/lib/boost_regex-vc140-mt.lib
    $ENV{VCPKG_DIR}/installed/x64-windows/lib/boost_date_time-vc140-mt.lib
    )
