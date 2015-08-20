#pragma once
#include "IScoringRule.h"
class Single5Scores50Rule : public IScoringRule
{
public:
    virtual int Score(std::vector<int>* diceThrow) const;
};

