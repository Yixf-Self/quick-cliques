#ifndef LIGHTWEIGHT_MCQ_H
#define LIGHTWEIGHT_MCQ_H

#include "Algorithm.h"
#include "CliqueColoringStrategy.h"

#include <vector>
#include <list>

class LightWeightMCQ : public Algorithm
{
public:
    LightWeightMCQ(std::vector<std::vector<char>> const &vAdjacencyMatrix);
    virtual ~LightWeightMCQ();

    virtual long Run(std::list<std::list<int>> &cliques);

    virtual void Color(std::vector<int> const &vVertexOrder, std::vector<int> &vVerticesToReorder, std::vector<int> &vColors);

    virtual void InitializeOrder(std::vector<int> &P, std::vector<int> &vVertexOrder, std::vector<int> &vColors);
    virtual void GetNewOrder(std::vector<int> &vNewVertexOrder, std::vector<int> &vVertexOrder, std::vector<int> const &P, int const chosenVertex);
    virtual void PostProcessOrder(std::vector<int> &vVertexOrder, int const chosenVertex) {}

    virtual void RunRecursive(std::vector<int> &P, std::vector<int> &vVertexOrder, std::list<std::list<int>> &cliques, std::vector<int> &vColors);

////    void SetInvert(bool const invert);

protected:
    std::vector<std::vector<char>> const &m_AdjacencyMatrix;
    CliqueColoringStrategy coloringStrategy;
    size_t m_uMaximumCliqueSize;
    std::vector<int> R;
    std::vector<std::vector<int>> stackP;
    std::vector<std::vector<int>> stackColors;
    std::vector<std::vector<int>> stackOrder;
    int nodeCount;
////    bool m_bInvert;
};
#endif
