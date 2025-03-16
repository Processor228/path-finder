
add_executable(pathfinder main.cxx graph.cxx)

target_link_libraries(pathfinder PRIVATE CLI11::CLI11)
