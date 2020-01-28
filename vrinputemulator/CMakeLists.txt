SET(TARGET_NAME driver_00vrinputemulator)
FILE(GLOB_RECURSE SRCS
    ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp
    ${CMAKE_CURRENT_LIST_DIR}/../third-party/MinHook.src/src/*.c
    )
ADD_LIBRARY(${TARGET_NAME} SHARED
    ${SRCS}
    )
TARGET_INCLUDE_DIRECTORIES(${TARGET_NAME} PRIVATE
    ${OPENVR_INCLUDE}
    )
TARGET_LINK_LIBRARIES(${TARGET_NAME} PRIVATE
    winmm
    ${CMAKE_CURRENT_LIST_DIR}/../openvr/lib/win64/openvr_api.lib
    debug
    $ENV{VCPKG_DIR}/installed/x64-windows/debug/lib/boost_regex-vc140-mt-gd.lib
    $ENV{VCPKG_DIR}/installed/x64-windows/debug/lib/boost_date_time-vc140-mt-gd.lib
    optimized
    $ENV{VCPKG_DIR}/installed/x64-windows/lib/boost_regex-vc140-mt.lib
    $ENV{VCPKG_DIR}/installed/x64-windows/lib/boost_date_time-vc140-mt.lib
    )

# copy dependencies
FILE(GLOB DLL_DEBUG
    ${CMAKE_CURRENT_LIST_DIR}/../openvr/bin/win64/openvr_api.dll
    $ENV{VCPKG_DIR}/installed/x64-windows/debug/bin/boost_regex-*.dll
    $ENV{VCPKG_DIR}/installed/x64-windows/debug/bin/boost_date_time-*.dll
    $ENV{VCPKG_DIR}/installed/x64-windows/bin/boost_regex-*.dll
    $ENV{VCPKG_DIR}/installed/x64-windows/bin/boost_date_time-*.dll
    )
ADD_CUSTOM_COMMAND(
    TARGET ${TARGET_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${DLL_DEBUG} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG}/
    )
