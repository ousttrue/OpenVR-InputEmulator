CMAKE_MINIMUM_REQUIRED(VERSION 3.0.0)
PROJECT(InputEmulator)

SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/lib)
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/lib)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/../vrinputemulator/bin/win64)
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/lib)
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/lib)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/../vrinputemulator/bin/win64)

SET(OPENVR_INCLUDE 
    ${CMAKE_CURRENT_LIST_DIR}/openvr/headers
    ${CMAKE_CURRENT_LIST_DIR}/lib_vrinputemulator/include
    ${CMAKE_CURRENT_LIST_DIR}/third-party/easylogging++
    ${CMAKE_CURRENT_LIST_DIR}/third-party/MinHook.src/include
    $ENV{VCPKG_DIR}/installed/x64-windows/include
    )
SUBDIRS(
    lib_vrinputemulator 
    vrinputemulator 
    client_commandline
    client_overlay
    )
