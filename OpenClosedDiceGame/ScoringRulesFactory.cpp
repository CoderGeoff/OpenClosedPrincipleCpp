#include "ScoringRulesFactory.h"
#include "NOfAKindScoresXRule.h"

std::vector<std::shared_ptr<IScoringRule>> ScoringRulesFactory::CreateRules() const
{
    auto single5Scores50 = std::make_shared <NOfAKindScoresXRule>(5, 1, 50);
    return std::vector<std::shared_ptr<IScoringRule>> { single5Scores50 };
}