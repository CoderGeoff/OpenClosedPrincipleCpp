#include <algorithm>
#include "OpenClosedScorer.h"
#include "IScoringRule.h"

OpenClosedScorer::OpenClosedScorer(const std::vector<std::shared_ptr<IScoringRule>>& rules, const std::vector<int>& diceThrows)
    :m_Rules(rules),
    m_DiceThrows(diceThrows)
{
}

int OpenClosedScorer::Score() const
{
    int score = 0;
    std::map<int, int> diceCount = CountDice();
    for (auto ruleIter = m_Rules.begin(); ruleIter != m_Rules.end(); ++ruleIter)
    {
        auto rule = *ruleIter;
        std::map<int, int>  remainingDiceCount;
        while (rule->Matches(diceCount, &remainingDiceCount))
        {
            score += rule->Score();
            diceCount.swap(remainingDiceCount);
        }
    }
    return score;
}

std::map<int, int> OpenClosedScorer::CountDice() const
{
    std::map<int, int> diceCount;
    std::for_each(m_DiceThrows.begin(), m_DiceThrows.end(), [&diceCount](int die) { diceCount[die]++; });
    return diceCount;
}