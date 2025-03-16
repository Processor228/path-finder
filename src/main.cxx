#include <iostream>

#include <CLI/CLI.hpp>

int main(int argc, char** argv)
{
    CLI::App app{"Program that finds shortest path to all nodes from given one"};

    std::string filename = "graph.txt";
    app.add_option("-f,--file", filename, "Path to graph specs");

    CLI11_PARSE(app, argc, argv);

    std::cout << "Hello " << filename << "\n";
}
