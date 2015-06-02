message ("building tests for Arduino Mock")

file(GLOB SRCS *.cc)

add_executable(arduinoMockTest ${SRCS})

target_link_libraries(arduinoMockTest
    arduino-mock
    ${GTEST_LIB_DIR}/libgtest.a
    ${GTEST_LIB_DIR}/libgtest_main.a
    ${GMOCK_LIB_DIR}/libgmock.a
    ${CMAKE_THREAD_LIBS_INIT}
)

add_dependencies(arduinoMockTest gtest)
add_test(arduino-mock-test arduinoMockTest)
