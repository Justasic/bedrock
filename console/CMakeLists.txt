
include_directories(../include)

if(NOT WIN32 AND CURSES_FOUND)
  file(GLOB CONSOLE_SOURCE_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.c")
  add_executable(console ${CONSOLE_SOURCE_FILES})
  target_link_libraries(console ${CURSES_LIBRARIES} ${EVENT_LIBRARY})
  add_dependencies(console util)
endif(NOT WIN32 AND CURSES_FOUND)

