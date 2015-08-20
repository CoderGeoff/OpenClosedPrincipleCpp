#pragma once
#include <memory>
#include <vector>
#include <map>

class IScoringRule;

class OpenClosedScorer
{
    std::vector<std::shared_ptr<IScoringRule>> m_Rules;
    std::vector<int> m_DiceThrows;

    std::map<int, int> m_Count;
    int GetCountOf(int diceThrow) const;
public:
    explicit OpenClosedScorer(const std::vector<std::shared_ptr<IScoringRule>>& rules, const std::vector<int>& diceThrows);
    int Score() const;
};

