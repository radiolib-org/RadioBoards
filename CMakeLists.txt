cmake_minimum_required(VERSION 3.13)

if(ESP_PLATFORM)
  # Build RadioBoards as an ESP-IDF component
  # required because ESP-IDF runs cmake in script mode
  # and needs idf_component_register()
  file(GLOB_RECURSE RADIOBOARDS_ESP_SOURCES
    "src/*.*"
  )

  idf_component_register(
    SRCS ${RADIOBOARDS_ESP_SOURCES} 
    INCLUDE_DIRS . src 
  )

  return()
endif()

if(CMAKE_SCRIPT_MODE_FILE)
  message(FATAL_ERROR "Attempted to build RadioBoards in script mode")
endif()

project(radioboards)

file(GLOB_RECURSE RADIOBOARDS_SOURCES
  "src/*.cpp"
)

add_library(RadioBoards ${RADIOBOARDS_SOURCES})

target_include_directories(RadioBoards
    PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

# use c++20 standard
set_property(TARGET RadioBoards PROPERTY CXX_STANDARD 20)

# enable most warnings
target_compile_options(RadioBoards PRIVATE -Wall -Wextra)

include(GNUInstallDirs)

install(TARGETS RadioBoards
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/RadioBoards
  FILES_MATCHING PATTERN "*.h"
)
