#pragma once

#include "igraph.h"
#include <vector>

class ArcGraph : public IGraph
{
public:
    explicit ArcGraph(int vertices_count);
    ArcGraph(const IGraph &graph);

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::pair<int, int>> edges_;
    int vertices_count_;
};
