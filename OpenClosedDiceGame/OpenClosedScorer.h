#pragma once
#include <memory>
#include <vector>
#include <map>

class IScoringRule;

class OpenClosedScorer
{
    std::vector<std::shared_ptr<IScoringRule>> m_Rules;
    std::vector<int> m_DiceThrows;

    std::map<int, int> CountDice(const std::vector<int>& diceThrows) const;
public:
    explicit OpenClosedScorer(const std::vector<std::shared_ptr<IScoringRule>>& rules);
    int Score(const std::vector<int>& diceThrows) const;
};

