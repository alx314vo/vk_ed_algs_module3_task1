#include "set_graph.h"

SetGraph::SetGraph(int vertices_count) : adjacency_sets_(vertices_count) {}

SetGraph::SetGraph(const IGraph &graph) : adjacency_sets_(graph.VerticesCount())
{
    for (int i = 0; i < adjacency_sets_.size(); ++i)
    {
        for (int j : graph.GetNextVertices(i))
        {
            adjacency_sets_[i].insert(j);
        }
    }
}

void SetGraph::AddEdge(int from, int to)
{
    adjacency_sets_[from].insert(to);
}

int SetGraph::VerticesCount() const
{
    return adjacency_sets_.size();
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const
{
    std::vector<int> next_vertices(adjacency_sets_[vertex].begin(), adjacency_sets_[vertex].end());
    return next_vertices;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const
{
    std::vector<int> prev_vertices;
    for (int i = 0; i < adjacency_sets_.size(); ++i)
    {
        if (adjacency_sets_[i].count(vertex))
        {
            prev_vertices.push_back(i);
        }
    }
    return prev_vertices;
}
