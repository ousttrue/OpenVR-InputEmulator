SET(TARGET_NAME lib_vrinputemulator)

ADD_LIBRARY(${TARGET_NAME}
    src/vrinputemulator.cpp
    )
TARGET_INCLUDE_DIRECTORIES(${TARGET_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/include
    ${CMAKE_CURRENT_LIST_DIR}/../openvr/headers
    $ENV{VCPKG_DIR}/installed/x64-windows/include
    )
