#include <cstddef>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <limits>
#include <queue>
#include <stdexcept>
#include <vector>

#include "graph.hxx"

Graph Graph::fromFilepath(std::string_view filepath)
{
    if (!std::filesystem::exists(filepath)) {
        throw std::runtime_error("File does not exist");
    }

    std::ifstream file(filepath.data());

    size_t number_of_nodes;
    size_t number_of_edges;
    size_t source;
    file >> number_of_nodes >> number_of_edges;

    std::vector<std::vector<size_t>> adj_list(number_of_nodes);

    for (size_t i = 0; i < number_of_edges; ++i) {
        size_t from, to;
        file >> from >> to;

        adj_list[from].push_back(to);
        adj_list[to].push_back(from);
    }

    file >> source;

    return Graph{number_of_nodes, source, std::move(adj_list)};
}

/*
 * Complexity: O(V + E)
 * This is simple BFS, actually, we need no Djikstras with min-heaps,
 * since graph is unweighted, non-oriented.
*/
std::vector<size_t> Graph::findClosestDistances()
{
    std::vector<size_t> dist(m_num_of_nodes, std::numeric_limits<size_t>::max());
    dist[m_source] = 0;

    std::queue<size_t> q;
    q.push(m_source);

    while (!q.empty()) {
        size_t node = q.front();
        q.pop();

        for (size_t neighbor : m_adj_list[node]) {
            if (dist[neighbor] == std::numeric_limits<size_t>::max()) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }

    return dist;
}
