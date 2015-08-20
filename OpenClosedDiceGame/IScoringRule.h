#pragma once
#include <map>

class IScoringRule
{
public:
    virtual ~IScoringRule() = 0 {};
    virtual int Score() const = 0;
    virtual bool Matches(const std::map<int, int>& diceCount, std::map<int, int>* remainingDice) const = 0;
};

