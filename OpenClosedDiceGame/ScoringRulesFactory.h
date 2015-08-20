#pragma once
#include <memory>
#include <vector>
class IScoringRule;

class ScoringRulesFactory
{
    std::shared_ptr<IScoringRule> MakeShared(IScoringRule * rule) const;
public:
    std::vector<std::shared_ptr<IScoringRule>> CreateRules() const;
};

