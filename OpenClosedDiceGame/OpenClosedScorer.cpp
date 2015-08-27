#include <algorithm>
#include "OpenClosedScorer.h"
#include "IScoringRule.h"

OpenClosedScorer::OpenClosedScorer(const std::vector<std::shared_ptr<IScoringRule>>& rules)
    :m_Rules(rules)
{
}

int OpenClosedScorer::Score(const std::vector<int>& diceThrows) const
{
    int score = 0;
    std::map<int, int> diceCount = CountDice(diceThrows);
    for (auto ruleIter = m_Rules.begin(); ruleIter != m_Rules.end(); ++ruleIter)
    {
        auto rule = *ruleIter;
        std::map<int, int>  remainingDiceCount;
        for (ScoringRuleResult ruleResult = rule->TryMatch(diceCount); ruleResult.Matched(); ruleResult = rule->TryMatch(diceCount))
        {
            score += ruleResult.Score();
            diceCount.swap(ruleResult.RemainingDiceCount());
        }
    }
    return score;
}

std::map<int, int> OpenClosedScorer::CountDice(const std::vector<int>& diceThrows) const
{
    std::map<int, int> diceCount;
    std::for_each(diceThrows.begin(), diceThrows.end(), [&diceCount](int die) { diceCount[die]++; });
    return diceCount;
}