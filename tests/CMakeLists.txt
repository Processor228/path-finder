add_executable(test_graph test-graph.cxx ../src/graph.cxx)

target_link_libraries(test_graph gtest gtest_main pthread)

enable_testing()
add_test(NAME GraphTest COMMAND test_graph)
