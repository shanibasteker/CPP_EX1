//311318075
//shanibasteker@gmail.com

#include <iostream>
#include "Graph.hpp"

constexpr int NONE_WEIGHTED_EDGE = 1;
constexpr int NONE_EDGE = 0;


//using namespace ariel;
namespace ariel {
    typedef Matrix Matrix;

    Graph::Graph() : numVertices(0), numEdges(0), isUndirected(false), isWeighted(false) {}

    Graph::~Graph() = default;

    void Graph::updateGraphProperty() {
        // Get the size of the matrix
        this->numVertices = myMatrix.size();
        // Transpose the matrix, initial with row, column size.
        Matrix transpose(this->numVertices, std::vector<int>(this->numVertices));

        bool changeFlagWeight = false;

        // Iterate over the matrix and fill the transpose matrix
        for (std::size_t vertexA = 0; vertexA < this->numVertices; ++vertexA) {
            for (std::size_t vertexB = 0; vertexB < this->numVertices; ++vertexB) {
                transpose[vertexB][vertexA] = myMatrix[vertexA][vertexB];

                if (myMatrix[vertexA][vertexB] != NONE_EDGE) {
                    this->numEdges++;

                    if (myMatrix[vertexA][vertexB] != NONE_WEIGHTED_EDGE && !changeFlagWeight) {
                        this->isWeighted = true;
                        changeFlagWeight = true;
                    }
                }
            }
        }
        this->myTransposeMatrix = transpose;
        this->isUndirected = (myMatrix == transpose);

        //If its true the count of numEdges was not correct.
        if (this->isUndirected) {
            this->numEdges = (this->numEdges % 2 == 0) ? (this->numEdges / 2) : ((this->numEdges / 2) - 1);
        }

    }

// Getter for myMatrix
    Matrix &Graph::getMatrix() { return myMatrix; }

// Getter for myTransposeMatrix
    const Matrix &Graph::getTransposeMatrix() const { return myTransposeMatrix; }

// Getter for myMatrix
    const Matrix &Graph::getMatrix() const { return myMatrix; }

// Getter for directed graph status
    bool Graph::isUndirectedGraph() const { return this->isUndirected; }

// Getter for weighted graph status
    bool Graph::isWeightedGraph() const { return this->isWeighted; }

// Getter for the number of vertices
    size_t Graph::getNumOfVertices() const { return this->numVertices; }

// Getter for the number of edges
    size_t Graph::getNumOfEdges() const { return this->numEdges; }

// Load the graph from the input matrix
    void Graph::loadGraph(const Matrix &inputMatrix) {
        // init / clean last uploaded graph.
        this->numVertices = 0;
        this->isWeighted = false;
        this->isUndirected = false;

        if (inputMatrix.empty()) {
            throw std::invalid_argument("Invalid graph: The graph is empty.");
        }

        if (inputMatrix.size() != inputMatrix[0].size()) {
            throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
        }

        this->myMatrix = inputMatrix;
        updateGraphProperty();
    }

    // Print the graph number of vertices and edges
    void Graph::printGraph() const {
        std::cout << "Graph with " << this->numVertices << " vertices and " << this->numEdges << " edges." << std::endl;
    }
    

// Implementation of operator '=='
    bool ariel::Graph::operator==(const Graph& rhs) const {
        return ((*this).getMatrix()) == (rhs.getMatrix());
    }

// Implementation of operator '!='
    bool ariel::Graph::operator!=(const Graph& rhs) const {
        return !(*this == rhs);
    }

// Implementation of operator '<'
    bool ariel::Graph::operator<(const Graph& rhs) const {
        if (numVertices != rhs.numVertices) {
            return numVertices < rhs.numVertices;
        }
        if (numEdges != rhs.numEdges) {
            return numEdges < rhs.numEdges;
        }
        return myMatrix < rhs.myMatrix; // Lexicographical comparison of matrices
    }

// Implementation of operator '<='
    bool ariel::Graph::operator<=(const Graph& rhs) const {
        return *this < rhs || *this == rhs;
    }

// Implementation of operator '>'
    bool ariel::Graph::operator>(const Graph& rhs) const {
        return !(*this < rhs);
    }

// Implementation of operator '>='
    bool ariel::Graph::operator>=(const Graph& rhs) const {
        return *this > rhs || *this == rhs;
    }

// Implementation of operator '*'
    ariel::Graph operator*(const ariel::Graph& lhs, const ariel::Graph& rhs){
        // Check if the graphs have the same number of vertices
        if (lhs.getNumOfVertices() != rhs.getNumOfVertices()) {
            throw std::invalid_argument("Cannot multiply graphs of different sizes.");
        }

        // Create a new graph object to store the result
        ariel::Graph result;

        // Get matrices from both graphs
        const Matrix& lhsMatrix = lhs.getMatrix();
        const Matrix& rhsMatrix = rhs.getMatrix();
        Matrix sumMatrix(lhs.getNumOfVertices(), std::vector<int>(lhs.getNumOfVertices(), 0));

        // Perform element-wise addition
        for (size_t row = 0; row < lhs.getNumOfVertices(); ++row) {
            for (size_t column = 0; column < lhs.getNumOfVertices(); ++column) {
                for(size_t multi = 0; multi < lhs.getNumOfVertices(); ++multi){
                    sumMatrix[row][column] += lhsMatrix[row][multi] * rhsMatrix[multi][column];
                }
            }
        }
        // Load the summed matrix into the result graph
        result.loadGraph(sumMatrix);

        return result;

    }

// Implementation of operator '*='
    const ariel::Graph& operator*=(ariel::Graph& lhs, const ariel::Graph& rhs) {
        Graph sumGraph;
        sumGraph.loadGraph(rhs.getMatrix());
        lhs =  lhs * sumGraph;
        return lhs;
    }

    Graph& Graph::operator*=(int rhs) {
    for (auto& row : myMatrix) {
        for (auto& value : row) {
            value *= rhs;  // Scale each element by the integer
        }
    }
    return *this;
}
Graph& Graph::operator/=(int rhs) {
    if (rhs == 0) {
        throw std::invalid_argument("Division by zero is not allowed.");
    }
    
    for (auto& row : myMatrix) {
        for (auto& value : row) {
            value /= rhs;  // Divide each element by the integer
        }
    }
    return *this;
}

// Implementation of operator '+'
    ariel::Graph operator+(const ariel::Graph& lhs, const ariel::Graph& rhs) {
        // Check if the graphs have the same number of vertices
        if (lhs.getNumOfVertices() != rhs.getNumOfVertices()) {
            throw std::invalid_argument("Cannot add graphs of different sizes.");
        }

        // Create a new graph object to store the result
        ariel::Graph result;

        // Get matrices from both graphs
        const Matrix& lhsMatrix = lhs.getMatrix();
        const Matrix& rhsMatrix = rhs.getMatrix();
        Matrix sumMatrix(lhs.getNumOfVertices(), std::vector<int>(lhs.getNumOfVertices(), 0));

        // Perform element-wise addition
        for (size_t row = 0; row < lhs.getNumOfVertices(); ++row) {
            for (size_t column = 0; column < lhs.getNumOfVertices(); ++column) {
                sumMatrix[row][column] = lhsMatrix[row][column] + rhsMatrix[row][column];
            }
        }
        // Load the summed matrix into the result graph
        result.loadGraph(sumMatrix);

        return result;
    }

// Implementation of operator '+='
    const ariel::Graph& operator+=(ariel::Graph& lhs, const ariel::Graph& rhs) {
        Graph sumGraph;
        sumGraph.loadGraph(rhs.getMatrix());
        lhs =  lhs + sumGraph;
        return lhs;
    }

    // Implementation of operator '++Prefix'
    ariel::Graph& ariel::Graph::operator++() {
        // Increment the weight of all edges by 1
        for (auto& row : myMatrix) {
            for (auto& val : row) {
                if (val != NONE_EDGE) { // Assuming NONE_EDGE represents no edge
                    val += 1;  // Increment edge weight by 1
                }
            }
        }
        // Optionally update other properties if your graph behavior depends on edge weights
        updateGraphProperty();

        return *this;  // Return the updated graph
    }

//Implementation of operator 'Postfix++'
    ariel::Graph Graph::operator++(int) {
        Graph cpy(*this);  // Make a copy of the current state
        ++(*this);  // Apply the prefix increment
        return cpy;  // Return the old state
    }

// Implementation of operator '-'
    ariel::Graph operator-(const ariel::Graph& lhs, const ariel::Graph& rhs) {
        // Check if the graphs have the same number of vertices
        if (lhs.getNumOfVertices() != rhs.getNumOfVertices()) {
            throw std::invalid_argument("Cannot add graphs of different sizes.");
        }

        // Create a new graph object to store the result
        ariel::Graph result;

        // Get matrices from both graphs
        const Matrix& lhsMatrix = lhs.getMatrix();
        const Matrix& rhsMatrix = rhs.getMatrix();
        Matrix sumMatrix(lhs.getNumOfVertices(), std::vector<int>(lhs.getNumOfVertices(), 0));

        // Perform element-wise addition
        for (size_t row = 0; row < lhs.getNumOfVertices(); ++row) {
            for (size_t column = 0; column < lhs.getNumOfVertices(); ++column) {
                sumMatrix[row][column] = lhsMatrix[row][column] - rhsMatrix[row][column];
            }
        }
        // Load the summed matrix into the result graph
        result.loadGraph(sumMatrix);

        return result;
    }

// Implementation of operator '-='
    const ariel::Graph& operator-=(ariel::Graph& lhs, const ariel::Graph& rhs) {
        Graph sumGraph;
        sumGraph.loadGraph(rhs.getMatrix());
        lhs =  lhs - sumGraph;
        return lhs;
    }

// Implementation of operator '--Prefix'
    ariel::Graph& ariel::Graph::operator--() {
        // Increment the weight of all edges by 1
        for (auto& row : myMatrix) {
            for (auto& val : row) {
                if (val != NONE_EDGE) { // Assuming NONE_EDGE represents no edge
                    val -= 1;  // Increment edge weight by 1
                }
            }
        }
        // Optionally update other properties if your graph behavior depends on edge weights
        updateGraphProperty();

        return *this;  // Return the updated graph 9 8 7 5 lo 2 3 4 6 1
    }

// Implementation of operator 'Postfix--'
    ariel::Graph Graph::operator--(int) {
        Graph cpy(*this);  // Make a copy of the current state
        --(*this);  // Apply the prefix increment
        return cpy;  // Return the old state
    }

// Implementation of operator printing the graph (using cout<<graph)
    std::ostream& operator<<(std::ostream &stream, ariel::Graph const &graph) {
            const ariel::Matrix &matrix = graph.getMatrix();
            for (const auto &row: matrix) {
                stream << "[";
                for (const auto &val: row) {
                    stream << val;
                    if (&val != &row.back()) {
                        stream << ", ";
                    }
                }
                stream << "]" << std::endl;
            }
        return stream;
    }
}