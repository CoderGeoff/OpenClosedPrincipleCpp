#include "PatternScoresXRule.h"
#include <algorithm>

PatternScoresXRule::PatternScoresXRule(std::initializer_list<int> pattern, int score)
    : m_Pattern(pattern),
    m_Score(score)
{
}

ScoringRuleResult PatternScoresXRule::TryMatch(const std::map<int, int>& diceCount) const
{
    std::map<int, int> diceCountAfterMatch(diceCount);
    auto decrementCount = [&diceCountAfterMatch](int n) { diceCountAfterMatch[n]--; };

    std::for_each(m_Pattern.begin(), m_Pattern.end(), decrementCount);
    bool matches = all_of(diceCountAfterMatch.begin(), diceCountAfterMatch.end(), [](std::pair<const int, int>& entry){ return entry.second >= 0; });
    
    return matches ? ScoringRuleResult(m_Score, diceCountAfterMatch) : ScoringRuleResult();
}