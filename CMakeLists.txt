CMAKE_MINIMUM_REQUIRED(VERSION 3.0.0)
PROJECT(InputEmulator)

SET(OPENVR_INCLUDE 
    ${CMAKE_CURRENT_LIST_DIR}/openvr/headers
    ${CMAKE_CURRENT_LIST_DIR}/lib_vrinputemulator/include
    ${CMAKE_CURRENT_LIST_DIR}/third-party/easylogging++
    ${CMAKE_CURRENT_LIST_DIR}/third-party/MinHook.src/include
    $ENV{VCPKG_DIR}/installed/x64-windows/include
    )
SUBDIRS(driver_vrinputemulator)
