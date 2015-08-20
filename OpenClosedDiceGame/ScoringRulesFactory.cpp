#include "ScoringRulesFactory.h"
#include "Single5Scores50Rule.h"

std::vector<std::shared_ptr<IScoringRule>> ScoringRulesFactory::CreateRules() const
{
    return std::vector<std::shared_ptr<IScoringRule>> { std::make_shared<Single5Scores50Rule>() };
}