#pragma once
#include <vector>
#include <map>

class Scorer
{
    mutable std::map<int, int> m_Subtractions;
    std::map<int, int> m_Count;
    int GetCountOf(int diceThrow) const;
    void SubtractFromCount(int diceThrow, int count = 1) const;
public:
    explicit Scorer(const std::vector<int>& diceThrows);
    int Score() const;
};

