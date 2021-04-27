CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

project(Zajecia4ShapesDrawing)

include (CTest)


SET(VERSION_MAJOR "1")
SET(VERSION_MINOR "0")
SET(VERSION_PATCH "0")
SET(VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")


set(CMAKE_VERBOSE_MAKEFILE TRUE)
set(VERBOSE TRUE)
set(CMAKE_BUILD_TYPE "Debug") # https://stackoverflow.com/a/8447957/1350091

message("Binary tree path: ${PROJECT_BINARY_DIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(MAIN_PROJECT_DIR ${PROJECT_SOURCE_DIR})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # http://cppcheck.sourceforge.net/manual.html#cmake
# then I run: cppcheck --project=compile_commands.json --force --enable=warning,performance,unusedFunction,style,information --template=gcc --inline-suppr --library=gnu.cfg --library=gtk.cfg --library=std.cfg --library=cppcheck-lib.cfg --library=motif.cfg --library=qt.cfg --library=windows.cfg --library=sdl.cfg --library=gnu.cfg --library=wxwidgets.cfg --library=sfml.cfg --library=posix.cfg --library=embedded_sql.cfg --library=avr.cfg --suppress=missingIncludeSystem > /dev/null

# downloading GTest if not installed:
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(dima)
find_or_download_and_compile_gtest()


include(common)

enable_cpp17()

enable_cxx_compiler_flag_if_supported("-Wall")
enable_cxx_compiler_flag_if_supported("-Wextra")
enable_cxx_compiler_flag_if_supported("-pedantic")

# loading subprojects:
add_subdirectory(src/lab4)
add_subdirectory(src/utils)


#zip_all_work()
