#include <math.h>
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
    std::vector<int> diceThrows(m_DiceThrows);
    for (auto ruleIter = m_Rules.begin(); ruleIter != m_Rules.end(); ++ruleIter)
    {
        score += (*ruleIter)->Score(&diceThrows);
    }
    return score;
}
