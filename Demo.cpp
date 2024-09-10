//311318075
//shanibasteker@gmail.com
// /*
//  * Demo program for Exercise 2.
//  * Author: Benjamin Saldman.
//  */
//
// #include "Graph.hpp"
// #include "Algorithms.hpp"
// using ariel::Algorithms;
//
// #include <iostream>
// #include <stdexcept>
// #include <vector>
// using namespace std;
//
// int main()
// {
//     ariel::Graph g;
//     // 3x3 matrix that represents a connected graph.
//     vector<vector<int>> graph = {
//         {0, 1, 0},
//         {1, 0, 1},
//         {0, 1, 0}};
//     g.loadGraph(graph); // Load the graph to the object.
//
//     g.printGraph();                                    // Should print: "Graph with 3 vertices and 4 edges."
//     cout << Algorithms::isConnected(g) << endl;        // Should print: "1" (true).
//     cout << Algorithms::shortestPath(g, 0, 2) << endl; // Should print: 0->1->2.
//     cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "0" (false).
//     cout << Algorithms::isBipartite(g) << endl;        // Should print: "The graph is bipartite: A={0, 2}, B={1}."
//
//     // 5x5 matrix that represents a non-connected graph with a cycle.
//     vector<vector<int>> graph2 = {
//         {0, 1, 1, 0, 0},
//         {1, 0, 1, 0, 0},
//         {1, 1, 0, 1, 0},
//         {0, 0, 1, 0, 0},
//         {0, 0, 0, 0, 0}};
//
//     g.loadGraph(graph2); // Load the graph to the object.
//
//     g.printGraph();                                    // Should print: "Graph with 5 vertices and 8 edges."
//     cout << Algorithms::isConnected(g) << endl;        // Should print: "0" (false).
//     cout << Algorithms::shortestPath(g, 0, 4) << endl; // Should print: "-1" (there is no path between 0 and 4).
//     cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "The cycle is: 0->1->2->0".
//     cout << Algorithms::isBipartite(g) << endl;        // Should print: "0" (false).
//
//
//     // 5x4 matrix that reprsents invalid graph.
//     vector<vector<int>> graph4 = {
//         {0, 1, 2, 0},
//         {1, 0, 3, 0},
//         {2, 3, 0, 4},
//         {0, 0, 4, 0},
//         {0, 0, 0, 5}};
//     try
//     {
//         g.loadGraph(graph4); // Load the graph to the object.
//     }
//     catch (const std::invalid_argument &e)
//     {
//         cout << e.what() << endl; // Should print: "Invalid graph: The graph is not a square matrix."
//     }
//
//      ariel::Graph g1;
//     // 3x3 matrix that represents a connected graph.
//     vector<vector<int>> graph6 = {
//         {0, 1, 0},
//         {1, 0, 1},
//         {0, 1, 0}};
//     g1.loadGraph(graph); // Load the graph to the object.
//
//     cout<<g1; // Should print the matrix of the graph: [0, 1, 0], [1, 0, 1], [0, 1, 0]
//
//     // 3x3 matrix that represents a weighted connected graph.
//     vector<vector<int>> weightedGraph = {
//         {0, 1, 1},
//         {1, 0, 2},
//         {1, 2, 0}};
//     ariel::Graph g2;
//     g2.loadGraph(weightedGraph); // Load the graph to the object.
//
//     ariel::Graph g3 = g1 + g2; // Add the two graphs together.
//     cout<<g3;           // Should print the matrix of the graph: [0, 2, 1], [2, 0, 3], [1, 3, 0]
//
//     g1 *= -2;        // Multiply the graph by -2.
//     cout<<g1; // Should print the matrix of the graph: [0, -2, 0], [-2, 0, -2], [0, -2, 0]
//
//     g1 /= -2;
//     ariel::Graph g4 = g1 * g2; // Multiply the two graphs together.
//     cout<<g4;           // Should print the multiplication of the matrices of g1 and g2: [0, 0, 2], [1, 0, 1], [1, 0, 0]
//
//     // 5x5 matrix that represents a connected graph.
//     vector<vector<int>> graph7 = {
//         {0, 1, 0, 0, 1},
//         {1, 0, 1, 0, 0},
//         {0, 1, 0, 1, 0},
//         {0, 0, 1, 0, 1},
//         {1, 0, 0, 1, 0}};
//     ariel::Graph g5;
//     g5.loadGraph(graph2); // Load the graph to the object.
//     try
//     {
//         ariel::Graph g6 = g5 * g1; // Multiply the two graphs together.
//     }
//     catch (const std::invalid_argument &e)
//     {
//         cout << e.what() << endl; // Should print "The number of columns in the first matrix must be equal to the number of rows in the second matrix."
//     }
// }
