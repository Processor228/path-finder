#include <gtest/gtest.h>
#include "../src/graph.hxx"

TEST(GraphTest, SingleNodeGraph) {
    Graph g(1, 0, {{}});
    std::vector<size_t> expected = {0};  // Distance to itself is 0
    EXPECT_EQ(g.findClosestDistances(), expected);
}

TEST(GraphTest, SimpleGraph) {
    std::vector<std::vector<size_t>> adj_list = {
        {1, 2},  // 0 -> 1, 2
        {0, 3},  // 1 -> 0, 3
        {0, 3},  // 2 -> 0, 3
        {1, 2}   // 3 -> 1, 2
    };
    Graph g(4, 0, std::move(adj_list));

    std::vector<size_t> expected = {0, 1, 1, 2};  // 0 to {1,2} in 1 step, to 3 in 2 steps
    EXPECT_EQ(g.findClosestDistances(), expected);
}

TEST(GraphTest, DisconnectedGraph) {
    std::vector<std::vector<size_t>> adj_list = {
        {1},    // 0 -> 1
        {0},    // 1 -> 0
        {},     // 2 (isolated)
        {4},    // 3 -> 4
        {3}     // 4 -> 3
    };
    Graph g(5, 0, std::move(adj_list));

    std::vector<size_t> expected = {0, 1, std::numeric_limits<size_t>::max(), std::numeric_limits<size_t>::max(), std::numeric_limits<size_t>::max()};
    EXPECT_EQ(g.findClosestDistances(), expected);
}

TEST(GraphTest, LargerGraph) {
    std::vector<std::vector<size_t>> adj_list = {
        {1, 2},  // 0 -> 1, 2
        {0, 3, 4}, // 1 -> 0, 3, 4
        {0, 5},  // 2 -> 0, 5
        {1, 6},  // 3 -> 1, 6
        {1, 7},  // 4 -> 1, 7
        {2, 8},  // 5 -> 2, 8
        {3},    // 6 -> 3
        {4},    // 7 -> 4
        {5}     // 8 -> 5
    };
    Graph g(9, 0, std::move(adj_list));

    std::vector<size_t> expected = {0, 1, 1, 2, 2, 2, 3, 3, 3};
    EXPECT_EQ(g.findClosestDistances(), expected);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}