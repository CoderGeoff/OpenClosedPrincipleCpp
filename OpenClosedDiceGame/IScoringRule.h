#pragma once
#include <map>
#include "ScoringRuleResult.h"

class IScoringRule
{
public:
    virtual ~IScoringRule() = 0 {};
    virtual ScoringRuleResult TryMatch(const std::map<int, int>& diceCount) const = 0;
};

