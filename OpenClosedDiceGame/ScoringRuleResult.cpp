#include "ScoringRuleResult.h"


ScoringRuleResult::ScoringRuleResult()
    : m_Matched(false),
     m_Score(0)
{
}

ScoringRuleResult::ScoringRuleResult(int m_Score, std::map<int, int> remainingDiceCount)
    : m_Matched(true),
    m_Score(m_Score),
    m_RemainingDiceCount(std::move(remainingDiceCount))
{
}

bool ScoringRuleResult::Matched() const
{
    return m_Matched;
}

int ScoringRuleResult::Score() const
{
    return m_Score;
}

std::map<int, int>& ScoringRuleResult::RemainingDiceCount()
{
    return m_RemainingDiceCount;
}
