#pragma once
#include <vector>
#include <map>

class Scorer
{
    std::map<int, int> m_Count;
    int GetCountOf(int diceThrow) const;
public:
    explicit Scorer(const std::vector<int>& diceThrows);
    int Score() const;
};

