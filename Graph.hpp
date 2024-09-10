//311318075
//shanibasteker@gmail.com

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <ostream>



namespace ariel {
    typedef std::vector<std::vector<int>> Matrix;

    class Graph {
    private:
        Matrix myMatrix;
        Matrix myTransposeMatrix;
        std::size_t numEdges; //Changed from EX1
        std::size_t numVertices;
        bool isUndirected;
        bool isWeighted;

        void updateGraphProperty();


    public:
        Graph();

        ~Graph();

        void loadGraph(const Matrix &matrix);

        void printGraph() const;

        // Getter methods
        Matrix& getMatrix();

        const Matrix &getMatrix() const;

        const Matrix &getTransposeMatrix() const;

        bool isUndirectedGraph() const;

        bool isWeightedGraph() const;

        std::size_t getNumOfVertices() const;

        std::size_t getNumOfEdges() const;

        bool operator==(const Graph& rhs) const;

        bool operator!=(const Graph& rhs) const;

        bool operator<(const Graph& rhs) const;

        bool operator<=(const Graph& rhs) const;

        bool operator>(const Graph& rhs) const;

        bool operator>=(const Graph& rhs) const;

        friend Graph operator*(const Graph& lhs, const Graph& rhs);

        friend const Graph& operator*=(Graph& lhs, const Graph& rhs);
        Graph& operator*=(int rhs);
        Graph& operator/=(int rhs);


        Graph& operator++();
        
        Graph operator++(int);   
        
        friend Graph operator+(const Graph& lhs, const Graph& rhs);
        
        friend const Graph& operator+=(Graph&, const Graph&);
        
        Graph& operator--();
        
        Graph operator--(int); 
        
        friend Graph operator-(const Graph& lhs, const Graph& rhs);
        
        friend const Graph& operator-=(Graph& lhs, const Graph& rhs);

        friend std::ostream &operator<<(std::ostream &stream, Graph const &graph);
    };
}



#endif