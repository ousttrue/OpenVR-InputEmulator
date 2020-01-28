SET(TARGET_NAME client_commandline)

ADD_EXECUTABLE(${TARGET_NAME}
    src/main.cpp
    src/client_commandline.h
    src/client_commandline.cpp
    )
TARGET_INCLUDE_DIRECTORIES(${TARGET_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/../openvr/headers
    ${CMAKE_CURRENT_LIST_DIR}/../lib_vrinputemulator/include
    $ENV{VCPKG_DIR}/installed/x64-windows/include
    )
TARGET_LINK_LIBRARIES(${TARGET_NAME} PRIVATE
    lib_vrinputemulator
    ${CMAKE_CURRENT_LIST_DIR}/../openvr/lib/win64/openvr_api.lib
    debug
    $ENV{VCPKG_DIR}/installed/x64-windows/debug/lib/boost_regex-vc140-mt-gd.lib
    $ENV{VCPKG_DIR}/installed/x64-windows/debug/lib/boost_date_time-vc140-mt-gd.lib
    optimized
    $ENV{VCPKG_DIR}/installed/x64-windows/lib/boost_regex-vc140-mt.lib
    $ENV{VCPKG_DIR}/installed/x64-windows/lib/boost_date_time-vc140-mt.lib
     )
