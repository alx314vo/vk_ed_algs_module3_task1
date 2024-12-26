#include "list_graph.h"

ListGraph::ListGraph(int vertices_count) : adjacency_lists_(vertices_count) {}

ListGraph::ListGraph(const IGraph &graph) : adjacency_lists_(graph.VerticesCount())
{
    for (int i = 0; i < adjacency_lists_.size(); ++i)
    {
        adjacency_lists_[i] = std::list<int>(graph.GetNextVertices(i).begin(), graph.GetNextVertices(i).end());
    }
}

void ListGraph::AddEdge(int from, int to)
{
    adjacency_lists_[from].push_back(to);
}

int ListGraph::VerticesCount() const
{
    return adjacency_lists_.size();
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const
{
    std::vector<int> next_vertices;
    for (int v : adjacency_lists_[vertex])
    {
        next_vertices.push_back(v);
    }
    return next_vertices;
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const
{
    std::vector<int> prev_vertices;
    for (int i = 0; i < adjacency_lists_.size(); ++i)
    {
        for (int v : adjacency_lists_[i])
        {
            if (v == vertex)
            {
                prev_vertices.push_back(i);
            }
        }
    }
    return prev_vertices;
}
