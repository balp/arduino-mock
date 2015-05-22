message ("building tests for Arduino Mock")
# include_directories(${GTEST_INCLUDE_DIRS})
file(GLOB SRCS *.cc)

add_executable(arduinoMockTest ${SRCS})

target_link_libraries(arduinoMockTest
    arduino_mock
    ${GTEST_LIBS_DIR}/libgtest.a
    ${GTEST_LIBS_DIR}/libgtest_main.a
    ${GMOCK_LIBS_DIR}/libgmock.a
    ${CMAKE_THREAD_LIBS_INIT}
)

add_dependencies(arduinoMockTest gtest)
add_test(arduino_mock_test arduinoMockTest)
