#include <cstddef>
#include <string_view>
#include <vector>

class Graph {
public:

    static Graph fromFilepath(std::string_view filepath);

    Graph(size_t n_nodes, size_t source, std::vector<std::vector<size_t>>&& adj_list) noexcept
        : m_num_of_nodes(n_nodes),
          m_adj_list(std::move(adj_list)),
          m_source(source)
    {}

    std::vector<size_t> findClosestDistances();

private:
    size_t m_num_of_nodes;
    std::vector<std::vector<size_t>> m_adj_list;
    size_t m_source;
};
