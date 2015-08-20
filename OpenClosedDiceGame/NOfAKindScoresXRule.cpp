#include "NOfAKindScoresXRule.h"


NOfAKindScoresXRule::NOfAKindScoresXRule(std::function<bool(int)> valuePredicate, int count, std::function<int(int)> scoreEvaluator)
    : m_ValuePredicate(valuePredicate),
      m_Count(count),
      m_ScoreEvaluator(scoreEvaluator)
{
}

ScoringRuleResult NOfAKindScoresXRule::TryMatch(const std::map<int, int>& diceCount) const
{
    std::map<int, int> diceCountAfterApplyingRule(diceCount);
    for (int n = 1; n <= 6; ++n)
    {
        if (m_ValuePredicate(n) && diceCountAfterApplyingRule[n] >= m_Count)
        {
            diceCountAfterApplyingRule[n] -= m_Count;
            return ScoringRuleResult(m_ScoreEvaluator(n), diceCountAfterApplyingRule);
        }
    }
    return ScoringRuleResult();
}

