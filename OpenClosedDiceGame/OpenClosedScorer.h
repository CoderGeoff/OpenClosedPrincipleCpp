#pragma once
#include <vector>
#include <map>

class OpenClosedScorer
{
    std::map<int, int> m_Count;
    int GetCountOf(int diceThrow) const;
public:
    explicit OpenClosedScorer(const std::vector<int>& diceThrows);
    int Score() const;
};

