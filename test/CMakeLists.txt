message ("building tests for Arduino Mock")

file(GLOB SRCS *.cc)

add_executable(arduino-mock-test ${SRCS})

linkExternalProject(arduino-mock-test "gtest")
linkExternalProject(arduino-mock-test "gmock")

target_link_libraries(arduino-mock-test
    arduino-mock
    ${GTEST_LIB_DIR}/libgtest_main.a
)

add_test(arduino-mock arduino-mock-test)
