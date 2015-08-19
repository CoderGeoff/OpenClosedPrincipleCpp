#include "stdafx.h"
#include <memory>

#include <gtest/gtest.h>
#include "Scorer.h"
#include "TestDie.h"

TEST(DiceGameTests, GivenOneDie_WhenFiveIsThrown_ScoreShouldBe50)
{
    auto dice = std::vector<int> { 5 };
    Scorer scorer;
    int score = scorer.Score(dice);
    ASSERT_EQ(50, score);
}

TEST(DiceGameTests, GivenOneDie_WhenOneIsThrown_ScoreShouldBe100)
{
    auto dice = std::vector<int> { 1 };
    Scorer scorer;
    int score = scorer.Score(dice);
    ASSERT_EQ(100, score);
}

