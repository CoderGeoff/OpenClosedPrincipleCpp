#pragma once
#include <memory>
#include <vector>
class IScoringRule;

class ScoringRulesFactory
{
public:
    std::vector<std::shared_ptr<IScoringRule>> CreateRules() const;
};

