//311318075
//shanibasteker@gmail.com

#include <iostream>
#include <stdexcept>
#include <vector>
#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"


using namespace std;

TEST_CASE("Test graph operator + graph")
{
    ariel::Graph g1;
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(matrix);

    ariel::Graph g2;
    vector<vector<int>> matrix1 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(matrix1);

    ariel::Graph expectedGraph;
    vector<vector<int>> expectedMatrix = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    expectedGraph.loadGraph(expectedMatrix);
    ariel::Graph g3 = g1 + g2;
    CHECK(expectedGraph == g3);
}

TEST_CASE("Test graph operator - graph"){
    ariel::Graph g1;
    vector<vector<int>> matrix = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    g1.loadGraph(matrix);

    ariel::Graph g2;
    vector<vector<int>> matrix1 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(matrix1);

    ariel::Graph expectedGraph;
    vector<vector<int>> expectedMatrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    expectedGraph.loadGraph(expectedMatrix);
    ariel::Graph g3 = g1 - g2;
    CHECK(expectedGraph == g3);
}

TEST_CASE("Test graph operator += graph"){
    ariel::Graph g1;
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(matrix);

    ariel::Graph g2;
    vector<vector<int>> matrix1 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(matrix1);

    ariel::Graph expectedGraph;
    vector<vector<int>> expectedMatrix = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    expectedGraph.loadGraph(expectedMatrix);
    g1 += g2;
    CHECK(expectedGraph == g1);

}
TEST_CASE("Test print graph to ostream"){
    ariel::Graph g1;
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(matrix);
    std::cout<<"Test print graph to ostream"<<std::endl;
    CHECK_NOTHROW(std::cout<<g1<<std::endl);
}

TEST_CASE("Test print graph to ostream with operator"){
    ariel::Graph g1;
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(matrix);
    std::cout<<"Test print graph to ostream with operator"<<std::endl;
    CHECK_NOTHROW(std::cout<<++g1<<std::endl); //add 1 to all edges
    CHECK_NOTHROW(std::cout<<g1--<<std::endl); //sub 1 from all edges but wont be seein in the next print
    CHECK_NOTHROW(std::cout<<g1<<std::endl); //now the edges are back to the original
}

TEST_CASE("Test graph operator * ")
{
    ariel::Graph g1;
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(matrix);
    ariel::Graph g2;
    vector<vector<int>> matrix2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(matrix2);
    ariel::Graph g3 = g1 * g2;
    vector<vector<int>> expectedMatrix = {
        {1, 0, 2},
        {1, 3, 1},
        {1, 0, 2}};
    ariel::Graph expected;
    expected.loadGraph(expectedMatrix);
    CHECK(g3 == expected);
}

TEST_CASE("Test graph operator *= ")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    g1 *= g2;
    vector<vector<int>> expectedGraph = {
        {1, 0, 2},
        {1, 3, 1},
        {1, 0, 2}};
    ariel::Graph expected;
    expected.loadGraph(expectedGraph);
    CHECK(g1==expected);
}
TEST_CASE("Test graph operator >"){
    ariel::Graph g1;
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(matrix);
    ariel::Graph g2;
    vector<vector<int>> matrix2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(matrix2);
    CHECK(g2>g1);
}

TEST_CASE("Test graph operator >"){
    ariel::Graph g1;
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(matrix);
    ariel::Graph g2;
    vector<vector<int>> matrix2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(matrix2);
    CHECK(g2>g1);
    
}
TEST_CASE("Test graph operator <="){
    ariel::Graph g1;
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(matrix);
    ariel::Graph g2;
    vector<vector<int>> matrix2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(matrix2);
    CHECK(g1<=g2);
}

TEST_CASE("Test graph operator <"){
    ariel::Graph g1;
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(matrix);
    ariel::Graph g2;
    vector<vector<int>> matrix2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(matrix2);
    CHECK(g1<g2);
}


TEST_CASE("Test graph operator ++ postfix"){
    ariel::Graph g1;
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(matrix);
    ariel::Graph g2;
    vector<vector<int>> matrix2 = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    g2.loadGraph(matrix2);
    CHECK(g1++ != g2);
    CHECK(g1 == g2);

}

TEST_CASE("Test graph operator ++ prefix"){
    ariel::Graph g1;
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(matrix);
    ariel::Graph g2;
    vector<vector<int>> matrix2 = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    g2.loadGraph(matrix2);
    CHECK(g1 != g2);
    CHECK(++g1 == g2);
}

TEST_CASE("Test graph operator --prefix"){
    ariel::Graph g1;
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(matrix);
    ariel::Graph g2;
    vector<vector<int>> matrix2 = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    g2.loadGraph(matrix2);
    CHECK(g1 != g2);
    CHECK(g1 == --g2);
}

TEST_CASE("Test graph operator --postfix"){
    ariel::Graph g1;
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(matrix);
    ariel::Graph g2;
    vector<vector<int>> matrix2 = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    g2.loadGraph(matrix2);
    CHECK(g1 != g2--);
    CHECK(g1 == g2);
}

TEST_CASE("Test graph operator !="){
    ariel::Graph g1;
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(matrix);
    ariel::Graph g2;
    vector<vector<int>> matrix2 = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    g2.loadGraph(matrix2);
    CHECK(g1 != g2);
    CHECK(g1++ != g2);
}

TEST_CASE("Test graph operator =="){
    ariel::Graph g1;
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(matrix);
    ariel::Graph g2;
    vector<vector<int>> matrix2 = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    g2.loadGraph(matrix2);
    ariel::Graph g3;
    vector<vector<int>> matrix3 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g3.loadGraph(matrix3);
    CHECK(g3 == g1);
    CHECK(++g1 == g2);
    ++g1;
    CHECK(--g1 == g2);
}

//207275215
//amitgini0369@gmail.com
#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Graph Initialization")
{
    ariel::Graph g;

    CHECK(g.getNumOfVertices() == 0);
    CHECK(g.getNumOfEdges() == 0);
    CHECK(g.isUndirectedGraph() == false);
    CHECK(g.isWeightedGraph() == false);
}

TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
}

TEST_CASE("Graph With Neg Edges")
{
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, -3},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(g.getNumOfVertices() == 3);
    CHECK(g.getNumOfEdges() == 4);
    CHECK(g.isUndirectedGraph() == false);
    CHECK(g.isWeightedGraph() == true);
}

TEST_CASE("Graph With Pos Edges")
{
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(g.getNumOfVertices() == 3);
    CHECK(g.getNumOfEdges() == 2);
    CHECK(g.isUndirectedGraph() == true);
    CHECK(g.isWeightedGraph() == false);
}

TEST_CASE("Load and Retrieve Graph Properties")
{
    ariel::Graph g;
    ariel::Matrix matrix = {
        {0, 1, 2},
        {1, 0, 0},
        {2, 0, 0}};

    g.loadGraph(matrix);

    CHECK(g.getNumOfVertices() == 3);
    CHECK(g.getNumOfEdges() == 2);
    CHECK(g.isWeightedGraph() == true);
    CHECK(g.isUndirectedGraph() == true);
    CHECK(g.getMatrix() == matrix);
    CHECK(g.getTransposeMatrix() == matrix); // Assuming it processes the transpose correctly
}

TEST_CASE("Check Undirected Graph Detection")
{
    ariel::Graph g;
    ariel::Matrix symmetricMatrix = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};

    g.loadGraph(symmetricMatrix);

    CHECK(g.isWeightedGraph() == false);
    CHECK(g.isUndirectedGraph() == true);
}

TEST_CASE("Check Directed Graph Detection")
{
    ariel::Graph g;
    ariel::Matrix asymmetricMatrix = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 0, 0}};

    g.loadGraph(asymmetricMatrix);

    CHECK(g.isWeightedGraph() == false);
    CHECK(g.isUndirectedGraph() == false);
}


TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);
    
    vector<vector<int>> graph1= {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph1);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
}


TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");
}

TEST_CASE("ShortestPathReturnsCorrectPathForDirectedWeightedGraph")
{
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 3, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 2},
        {4, 0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "0->1->2->3");
}

TEST_CASE("ShortestPathReturnsCorrectPathForDirectGraphWithMixedWeights")
{
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0, 4},
        {0, 0, 2, 0},
        {3, 0, 0, 0},
        {0, 0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");
}

TEST_CASE("ShortestPathReturnsCorrectPathForUndirectedGraphWithUniformWeights")
{
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "0->1->3");
}

TEST_CASE("ShortestPathReturnsCorrectPathForNonDirectGraphWithUniformWeights")
{
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {1, 0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "0->1->2->3");
}

TEST_CASE("ShortestPathReturnsCorrectPathForNonSymmetricGraphWithNegativeWeights")
{
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 2, 0, 0},
        {0, 0, -4, 2},
        {0, 0, 0, 3},
        {1, -1, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "-1");
}

TEST_CASE("ShortestPathReturnsCorrectPathForSymmetricGraphWithNoNegativeWeights")
{
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 3, 2, 0},
        {3, 0, 0, 4},
        {2, 0, 0, 1},
        {0, 4, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "0->2->3");
}

TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}


TEST_CASE("IsConnectedReturnsTrueForLargeConnectedGraph") {
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, 1, 1, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 0, 1, 1},
        {1, 1, 1, 0, 1},
        {1, 1, 1, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g));
}

TEST_CASE("IsConnectedReturnsFalseForLargeNonConnectedGraph") {
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1},
        {0, 1, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 1, 1, 1, 0}};
    g.loadGraph(graph);
    CHECK_FALSE(ariel::Algorithms::isConnected(g));
}

TEST_CASE("IsConnectedReturnsFalseForNonConnectedGraph") {
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 0, 0},
        {0, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}

TEST_CASE("IsConnectedReturnsTrueForConnectedUndirectedGraph_4x4") {
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);
}

TEST_CASE("IsConnectedReturnsTrueForConnectedUndirectedGraph_5x5") {
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}
    };
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);
}

TEST_CASE("IsConnectedReturnsTrueForConnectedUndirectedGraph_6x6") {
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0, 0, 0, 1},
        {1, 0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0, 0},
        {0, 0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 1, 0}
    };
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);
}

TEST_CASE("IsConnectedReturnsTrueForConnectedWeightedUndirectedGraph_4x4") {
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 2, 0, 3},
        {2, 0, 3, 0},
        {0, 3, 0, 4},
        {3, 0, 4, 0}
    };
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);
}

TEST_CASE("IsConnectedReturnsTrueForConnectedWeightedUndirectedGraph_5x5") {
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0, 0, 5},
        {1, 0, 2, 0, 0},
        {0, 2, 0, 3, 0},
        {0, 0, 3, 0, 4},
        {5, 0, 0, 4, 0}
    };
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);
}

TEST_CASE("IsConnectedReturnsTrueForSymmetricConnectedGraphWithNegativeWeights_4x4") {
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, -1, 0, 5},
        {-1, 0, -2, 0},
        {0, -2, 0, -3},
        {5, 0, -3, 0}
    };
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);
}

TEST_CASE("IsConnectedReturnsTrueForConnectedDirectedGraphWithNegativeWeights_4x4") {
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, -2, 0, 3},
        {2, 0, -3, 0},
        {0, 3, 0, -4},
        {-3, 0, 4, 0}
    };
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);
}

TEST_CASE("IsConnectedReturnsTrueForConnectedGraphWithNegativeWeights_6x6") {
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, -2, 0, 3, 0, 0},
        {2, 0, -3, 0, 0, 0},
        {0, 3, 0, -4, 0, 0},
        {-3, 0, 4, 0, 5, 0},
        {0, 0, 0, 5, 0, -6},
        {0, 0, 0, 0, -6, 0}
    };
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);
}

TEST_CASE("IsConnectedReturnsTrueForSymmetricConnectedUndirectedGraphWithNegativeWeights_5x5") {
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, -1, 0, 0, 5},
        {-1, 0, -2, 0, 0},
        {0, -2, 0, -3, 0},
        {0, 0, -3, 0, -4},
        {5, 0, 0, -4, 0}
    };
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);
}


TEST_CASE("IsBipartiteReturnsTrueForBipartiteGraph") {
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");
}
TEST_CASE("Test isBipartite"){
    ariel::Graph g;
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2); // Load the graph to the object.
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    // 5x5 matrix that reprsents a connected weighted graph.
    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3); // Load the graph to the object.
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
}

TEST_CASE("IsBipartiteReturnsTrueForSymmetricGraphWithMixedWeights")
{
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, -1, 2, 0},
        {-1, 0, 0, 3},
        {2, 0, 0, -4},
        {0, 3, -4, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 3}, B={1, 2}");
}

TEST_CASE("IsBipartiteReturnsTrueForSymmetricGraphWithPositiveWeights")
{
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 2, 0, 4},
        {2, 0, 3, 0},
        {0, 3, 0, 1},
        {4, 0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1, 3}");
}

TEST_CASE("IsBipartiteReturnsTrueForSymmetricGraphWithNonWeightedEdges")
{
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1, 3}");
}

TEST_CASE("IsBipartiteReturnsTrueForNonSymmetricGraphWithMixedWeights")
{
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, -2, 0, 0},
        {2, 0, -3, 0},
        {0, 3, 0, 1},
        {0, 0, -1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1, 3}");
}

TEST_CASE("IsBipartiteReturnsTrueForNonSymmetricGraphWithPositiveWeights")
{
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 2, 0, 0},
        {0, 0, 3, 0},
        {0, 0, 0, 1},
        {4, 0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1, 3}");
}

TEST_CASE("IsBipartiteReturnsTrueForNonSymmetricGraphWithNonWeightedEdges")
{
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {1, 0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1, 3}");
}

TEST_CASE("NegativeCycleReturnsCorrectCycleForGraphWithNegativeCycle") {
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, -3},
        {0, 1, 0}};
    g.loadGraph(graph);
    // Assuming the function returns the smallest possible negative cycle.
    CHECK(ariel::Algorithms::negativeCycle(g) == "Cycle: 2->1->2");
}

TEST_CASE("NegativeCycleReturnsFailForGraphWithoutNegativeCycle") {
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 3},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::negativeCycle(g) == "0");
}

TEST_CASE("NegativeCycleReturnsCorrectCycleForSymmetricGraphWithMixedWeights")
{
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 2, -3, 0},
        {2, 0, 0, -4},
        {-3, 0, 0, 1},
        {0, -4, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::negativeCycle(g) == "Cycle: 0->2->3->1->0");
}

TEST_CASE("NegativeCycleReturnsCorrectCycleForSymmetricGraphWithMixedWeights_5x5")
{
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, -2, 0, 0},
        {1, 0, 3, -4, 0},
        {-2, 3, 0, 0, 1},
        {0, -4, 0, 0, 2},
        {0, 0, 1, 2, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::negativeCycle(g) == "Cycle: 0->1->3->0");
}

TEST_CASE("NegativeCycleReturnsCorrectCycleForNonSymmetricGraphWithMixedWeights_6x6")
{
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0, 0, 0, 0},
        {0, 0, -3, 0, 0, 0},
        {0, 2, 0, -1, 0, 0},
        {0, 0, 0, 0, -2, 1},
        {0, 0, 0, 2, 0, -3},
        {-4, 0, 0, 0, 3, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::negativeCycle(g) == "Cycle: 2->1->2");
}