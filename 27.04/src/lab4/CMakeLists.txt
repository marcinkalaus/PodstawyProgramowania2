project(lab)

include (CTest)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILER_FLAGS}")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${COMPILER_RELEASE_FLAGS}")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${COMPILER_DEBUG_FLAGS}")

set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE ${PROJECT_NAME}_headers *.h *.hpp)
file(GLOB_RECURSE ${PROJECT_NAME}_sources *.cpp *.cc *.c)


include_directories("${MAIN_PROJECT_DIR}/src")

#find_program(CMAKE_CXX_CPPCHECK NAMES cppcheck)


add_executable (${PROJECT_NAME} ${${PROJECT_NAME}_headers} ${${PROJECT_NAME}_sources})

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    target_link_libraries(${PROJECT_NAME} Utils gtest)
else()
    target_link_libraries(${PROJECT_NAME} Utils gtest pthread)
endif()

GTEST_ADD_TESTS(ShapesTests "" ShapesTests.cpp)

add_test(${PROJECT_NAME}_test ${PROJECT_NAME})

message("Binary saved to: ${CMAKE_CURRENT_BINARY_DIR}")

add_custom_target(run
    COMMAND ${PROJECT_NAME}
    DEPENDS ${PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

# source of code: https://stackoverflow.com/questions/40325957/how-do-i-add-valgrind-tests-to-my-cmake-test-target
add_custom_target(test_memcheck
    COMMAND ${CMAKE_CTEST_COMMAND}
        --force-new-ctest-process --test-action memcheck
    COMMAND cat "${CMAKE_BINARY_DIR}/Testing/Temporary/MemoryChecker.*.log"
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}")

# komenda sprawdzajaca problemy z pamiecia:
#valgrind --child-silent-after-fork=yes --leak-check=full  --error-exitcode=1 bin/lab 2>&1 | grep -v '    by' | grep -v '   at ' | sed 's/^[ \t]*//;s/[ \t]*$//' | grep -vE '^==[[:digit:]]+==$'


file(GLOB_RECURSE studentSources *.c *.cpp)
generate_pdf_if_possible(${studentSources})
