#include <cstdlib>
#include <iostream>

#include <CLI/CLI.hpp>

#include "graph.hxx"


int main(int argc, char** argv)
{
    CLI::App app{"Program that finds shortest path to all nodes from given one"};

    std::string filename = "graph.txt";
    app.add_option("-f,--file", filename, "Path to graph specs");

    CLI11_PARSE(app, argc, argv);

    try {
        auto graph = Graph::fromFilepath(filename);
        auto output = graph.findClosestPaths();

        for (const auto distance : output) {
            std::cout << distance << '\n';
        }
    } catch (...) {
        std::cout << "Couldn't parse the file. Does it exist and comply to the requirements? \n";
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
