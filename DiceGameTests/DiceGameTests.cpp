#include "stdafx.h"
#include <memory>

#include <gtest/gtest.h>
#include "Scorer.h"
#include "TestDie.h"

TEST(DiceGameTests, GivenOneDie_WhenFiveIsThrown_ScoreShouldBe50)
{
    auto dice = std::vector<int> { 5 };
    Scorer scorer(dice);
    int score = scorer.Score();
    ASSERT_EQ(50, score);
}

TEST(DiceGameTests, GivenOneDie_WhenOneIsThrown_ScoreShouldBe100)
{
    auto dice = std::vector<int> { 1 };
    Scorer scorer(dice);
    int score = scorer.Score();
    ASSERT_EQ(100, score);
}

TEST(DiceGameTests, GivenThreeDie_WhenAllOnesAreThrown_ScoreShouldBe1000)
{
    auto dice = std::vector<int> { 1, 1, 1 };
    Scorer scorer(dice);
    int score = scorer.Score();
    ASSERT_EQ(1000, score);
}

TEST(DiceGameTests, GivenThreeDie_WhenAllTwosAreThrown_ScoreShouldBe200)
{
    auto dice = std::vector<int> { 2, 2, 2 };
    Scorer scorer(dice);
    int score = scorer.Score();
    ASSERT_EQ(200, score);
}

TEST(DiceGameTests, GivenThreeDie_WhenAllSixesAreThrown_ScoreShouldBe600)
{
    auto dice = std::vector<int> { 6, 6, 6 };
    Scorer scorer(dice);
    int score = scorer.Score();
    ASSERT_EQ(600, score);
}

TEST(DiceGameTests, GivenFourDie_WhenAllSixesAreThrown_ScoreShouldBe1200)
{
    auto dice = std::vector<int> { 6, 6, 6, 6 };
    Scorer scorer(dice);
    int score = scorer.Score();
    ASSERT_EQ(1200, score);
}

TEST(DiceGameTests, GivenFiveDie_WhenAllOnesAreThrown_ScoreShouldBe4000)
{
    auto dice = std::vector<int> { 1, 1, 1, 1, 1 };
    Scorer scorer(dice);
    int score = scorer.Score();
    ASSERT_EQ(4000, score);
}

TEST(DiceGameTests, GivenSixDie_WhenAllThreesAreThrown_ScoreShouldBe2400)
{
    auto dice = std::vector<int> { 3, 3, 3, 3, 3, 3 };
    Scorer scorer(dice);
    int score = scorer.Score();
    ASSERT_EQ(2400, score);
}

TEST(DiceGameTests, GivenTwoDie_WhenTwoFivesAreThrownn_ScoreShouldBe100)
{
    auto dice = std::vector<int> { 5, 5 };
    Scorer scorer(dice);
    int score = scorer.Score();
    ASSERT_EQ(100, score);
}

TEST(DiceGameTests, GivenTwoDie_WhenTwoOnesAreThrown_ScoreShouldBe200)
{
    auto dice = std::vector<int> { 1, 1 };
    Scorer scorer(dice);
    int score = scorer.Score();
    ASSERT_EQ(200, score);
}
TEST(DiceGameTests, GivenSixDie_FullStraight_ScoreShouldBe1500)
{
    auto dice = std::vector<int> { 1, 2, 3, 4, 5, 6 };
    Scorer scorer(dice);
    int score = scorer.Score();
    ASSERT_EQ(1500, score);
}

