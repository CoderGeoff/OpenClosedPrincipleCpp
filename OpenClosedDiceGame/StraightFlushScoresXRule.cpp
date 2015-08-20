#include "StraightFlushScoresXRule.h"
#include <algorithm>
#include <vector>

StraightFlushScoresXRule::StraightFlushScoresXRule(int score)
    : m_Score(score)
{
}

ScoringRuleResult StraightFlushScoresXRule::TryMatch(const std::map<int, int>& diceCount) const
{
    auto flush = std::vector<int>{ 1, 2, 3, 4, 5, 6 };
    auto diceCountForNIs1 = [&diceCount](int n) { auto finder = diceCount.find(n); return finder != diceCount.end() && finder->second == 1; };
    bool matches = std::all_of(flush.begin(), flush.end(), diceCountForNIs1);
    return matches ? ScoringRuleResult(m_Score, std::map<int, int>()) : ScoringRuleResult();
}

