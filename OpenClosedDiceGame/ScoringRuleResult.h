#pragma once
#include <map>

class ScoringRuleResult
{
    bool m_Matched;
    int m_Score;
    std::map<int, int> m_RemainingDiceCount;
public:
    ScoringRuleResult();
    ScoringRuleResult(int m_Score, std::map<int, int> remainingDiceCount);
    bool Matched() const;
    int Score() const;
    std::map<int, int>& RemainingDiceCount();
};

