//311318075
//shanibasteker@gmail.com

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP
using namespace std;

#include <string>
#include "Graph.hpp"

using ariel::Graph;
using std::string;

namespace ariel{

    class Algorithms{

    private:
        Algorithms();

        static bool BFS(
                const Graph &graph,
                std::vector<int> &dist,
                size_t src,
                std::vector<int> &prev,
                size_t dest );

        static bool DFS(
                const Graph &graph,
                std::vector<int> &prev );

       static bool DFSVisit(const Graph &graph, size_t vertex,
                          vector<size_t> &color, size_t currTime,
                          vector<size_t> &discTime,
                          vector<size_t> &finishTime,
                          vector<int> &prev);

        static int BF(
                const Graph &graph,
                std::vector<int> &dist,
                std::vector<int> &prev );

        static bool isConnectedHelper( const Matrix& edges );

        static bool isBipartiteHelper(
                const Graph &graph,
                std::vector<size_t> &color,
                size_t src );

        static string reconstructCycle(
                size_t endVertex,
                const std::vector<int>& prev );


    public:
        static bool isConnected( const Graph &graph );

        static bool isContainsCycle( const Graph &graph );


        static string shortestPath(
                const Graph &graph,
                size_t src,
                size_t dest );

        static string isBipartite( const Graph &graph );

        static string negativeCycle( const Graph &graph );


    };
}

#endif