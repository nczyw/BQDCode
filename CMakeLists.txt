cmake_minimum_required(VERSION 3.25)
set (PRONAME "BQDCode")
project(${PRONAME} VERSION 1.0.0 LANGUAGES C)
# Set C language
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

option(DllTest "Create dll test exe file" OFF)
option(BQDCODE_SHARED_LIBS "Create BQDCODE shared library" OFF)
set(WITH_TOOLS OFF CACHE BOOL "Force utility tools to be OFF" FORCE) 
# Add libbarcode
add_subdirectory(external/libbarcode)
# Add libqrencode
add_subdirectory(external/libqrencode)
# Add libdmtx
add_subdirectory(external/libdmtx)

# Find all .c files 
file(GLOB_RECURSE SOURCES "src/*.c")

# Find all .h files
file(GLOB_RECURSE HEADERS "inc/*.h")

if (MSVC)
#  set(CMAKE_DEBUG_POSTFIX "_d")
endif(MSVC)

# Create library
if(BQDCODE_SHARED_LIBS)
        add_library(${PRONAME} SHARED
                        ${SOURCES}
                        ${HEADERS}
)
else()
        add_library(${PRONAME} STATIC
                        ${SOURCES}
                        ${HEADERS}
)
endif()

target_link_libraries(${PRONAME} PRIVATE
                        barcode
                        qrencode
                        dmtx_static
)

target_include_directories(${PRONAME} PRIVATE
                                external/libbarcode/inc
                                external/libqrencode
                                external/libdmtx
                                inc                            
)
if(BQDCODE_SHARED_LIBS)
        target_compile_definitions(${PRONAME} PRIVATE
                                        BQDCODE_SHARED_LIBS
                                        BQDCODE_LIBRARY
        )
endif()

if(DllTest)
        #create exception 
        add_executable(Dlltest test/main.c)
        target_include_directories(Dlltest PRIVATE
                                        external/libbarcode/inc
                                        external/libqrencode
                                        external/libdmtx
                                        inc                             
        )
        target_link_libraries(Dlltest PRIVATE 
                                ${PRONAME}
                                #barcode
                                #qrencode
                                #dmtx_static
        )
        
endif()

# Set install path
set(CMAKE_INSTALL_PREFIX install)
# Install
install(TARGETS ${PRONAME}
    EXPORT MyLibraryTargets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)
# Install header files
#[[
file(GLOB_RECURSE HEADERS 
        "inc/*.h"
        "libbarcode/inc/barcode.h"
        "libbarcode/inc/config.h"
        "libqrencode/qrencode.h"
        "libdmtx/dmtx.h"
        "libdmtx/dmtxstatic.h"
)

install(FILES ${HEADERS} DESTINATION include)
]]