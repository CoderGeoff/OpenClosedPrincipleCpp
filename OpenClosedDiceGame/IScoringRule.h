#pragma once
#include <vector>

class IScoringRule
{
public:
    virtual ~IScoringRule() = 0 {};
    virtual int Score(std::vector<int>* diceThrow) const = 0;
};

