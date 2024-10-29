cmake_minimum_required(VERSION 3.8)

project(TinyTor)
set(PROJECT_NAME TinyTor)
set(CMAKE_C_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(TinyTor/windows/include)

if(WIN32)
    add_executable(${PROJECT_NAME} src/main.c)
    target_sources(${PROJECT_NAME} PRIVATE 
        TinyTor/windows/src/crypto/aes.c
        TinyTor/windows/src/crypto/capi/base_encode.c
        TinyTor/windows/src/crypto/base16.c
        TinyTor/windows/src/crypto/base64.c
        )

    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /DYNAMICBASE /GS- /MT")
    set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "/NODEFAULTLIB /SUBSYSTEM:CONSOLE /ENTRY:main /stack:0x100000,0x100000")
    target_link_libraries(${PROJECT_NAME} PRIVATE crypt32 msvcrt ucrt bcrypt)

    file(GLOB MSVCRT_DEF_FILES "${CMAKE_CURRENT_SOURCE_DIR}/msvcrt.def")
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/TinyTor/crt/msvcrt.def")
        execute_process(COMMAND lib /def:${CMAKE_CURRENT_SOURCE_DIR}/TinyTor/windows/crt/msvcrt.def /out:${CMAKE_CURRENT_BINARY_DIR}/msvcrt.lib
                        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
    endif()

elseif(UNIX)
    add_executable(${PROJECT_NAME} main.c)
    target_sources(${PROJECT_NAME} PRIVATE TinyTor/linux/src/crypto/base_encode.c)

    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)
    target_link_libraries(${PROJECT_NAME} PRIVATE crypt)

endif()
