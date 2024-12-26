#include "matrix_graph.h"

MatrixGraph::MatrixGraph(int vertices_count) : adjacency_matrix_(vertices_count, std::vector<bool>(vertices_count, false)) {}

MatrixGraph::MatrixGraph(const IGraph &graph) : adjacency_matrix_(graph.VerticesCount(), std::vector<bool>(graph.VerticesCount(), false))
{
    for (int i = 0; i < adjacency_matrix_.size(); ++i)
    {
        for (int j : graph.GetNextVertices(i))
        {
            adjacency_matrix_[i][j] = true;
        }
    }
}

void MatrixGraph::AddEdge(int from, int to)
{
    adjacency_matrix_[from][to] = true;
}

int MatrixGraph::VerticesCount() const
{
    return adjacency_matrix_.size();
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const
{
    std::vector<int> next_vertices;
    for (int i = 0; i < adjacency_matrix_.size(); ++i)
    {
        if (adjacency_matrix_[vertex][i])
        {
            next_vertices.push_back(i);
        }
    }
    return next_vertices;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const
{
    std::vector<int> prev_vertices;
    for (int i = 0; i < adjacency_matrix_.size(); ++i)
    {
        if (adjacency_matrix_[i][vertex])
        {
            prev_vertices.push_back(i);
        }
    }
    return prev_vertices;
}
