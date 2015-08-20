#include "stdafx.h"
#include <memory>

#include <gtest/gtest.h>
#include "Scorer.h"
#include "OpenClosedScorer.h"
#include "ScoringRulesFactory.h"

template <class T>
class ScorerTests : public testing::Test
{
protected:
    T CreateScorer(const std::vector<int>& dice);
};

Scorer ScorerTests<Scorer>::CreateScorer(const std::vector<int>& dice)
{
    return Scorer(dice);
}

OpenClosedScorer ScorerTests<OpenClosedScorer>::CreateScorer(const std::vector<int>& dice)
{
    ScoringRulesFactory rulesFactory;
    return OpenClosedScorer(rulesFactory.CreateRules(), dice);
}

using testing::Types;
typedef Types<Scorer, OpenClosedScorer> ScorerTypes;
TYPED_TEST_CASE(ScorerTests, ScorerTypes);

TYPED_TEST(ScorerTests, GivenOneDie_WhenFiveIsThrown_ScoreShouldBe50)
{
    auto dice = std::vector<int> { 5 };
    TypeParam scorer(this->CreateScorer(dice));
    int score = scorer.Score();
    ASSERT_EQ(50, score);
}

TYPED_TEST(ScorerTests, GivenOneDie_WhenOneIsThrown_ScoreShouldBe100)
{
    auto dice = std::vector<int> { 1 };
    TypeParam scorer(this->CreateScorer(dice));
    int score = scorer.Score();
    ASSERT_EQ(100, score);
}

TYPED_TEST(ScorerTests, GivenThreeDie_WhenAllOnesAreThrown_ScoreShouldBe1000)
{
    auto dice = std::vector<int> { 1, 1, 1 };
    TypeParam scorer(this->CreateScorer(dice));
    int score = scorer.Score();
    ASSERT_EQ(1000, score);
}

TYPED_TEST(ScorerTests, GivenThreeDie_WhenAllTwosAreThrown_ScoreShouldBe200)
{
    auto dice = std::vector<int> { 2, 2, 2 };
    TypeParam scorer(this->CreateScorer(dice));
    int score = scorer.Score();
    ASSERT_EQ(200, score);
}

TYPED_TEST(ScorerTests, GivenThreeDie_WhenAllSixesAreThrown_ScoreShouldBe600)
{
    auto dice = std::vector<int> { 6, 6, 6 };
    TypeParam scorer(this->CreateScorer(dice));
    int score = scorer.Score();
    ASSERT_EQ(600, score);
}

TYPED_TEST(ScorerTests, GivenFourDie_WhenAllSixesAreThrown_ScoreShouldBe1200)
{
    auto dice = std::vector<int> { 6, 6, 6, 6 };
    TypeParam scorer(this->CreateScorer(dice));
    int score = scorer.Score();
    ASSERT_EQ(1200, score);
}

TYPED_TEST(ScorerTests, GivenFiveDie_WhenAllOnesAreThrown_ScoreShouldBe4000)
{
    auto dice = std::vector<int> { 1, 1, 1, 1, 1 };
    TypeParam scorer(this->CreateScorer(dice));
    int score = scorer.Score();
    ASSERT_EQ(4000, score);
}

TYPED_TEST(ScorerTests, GivenSixDie_WhenAllThreesAreThrown_ScoreShouldBe2400)
{
    auto dice = std::vector<int> { 3, 3, 3, 3, 3, 3 };
    TypeParam scorer(this->CreateScorer(dice));
    int score = scorer.Score();
    ASSERT_EQ(2400, score);
}

TYPED_TEST(ScorerTests, GivenTwoDie_WhenTwoFivesAreThrownn_ScoreShouldBe100)
{
    auto dice = std::vector<int> { 5, 5 };
    TypeParam scorer(this->CreateScorer(dice));
    int score = scorer.Score();
    ASSERT_EQ(100, score);
}

TYPED_TEST(ScorerTests, GivenTwoDie_WhenTwoOnesAreThrown_ScoreShouldBe200)
{
    auto dice = std::vector<int> { 1, 1 };
    TypeParam scorer(this->CreateScorer(dice));
    int score = scorer.Score();
    ASSERT_EQ(200, score);
}

TYPED_TEST(ScorerTests, GivenSixDie_FullStraight_ScoreShouldBe1500)
{
    auto dice = std::vector<int> { 1, 2, 3, 4, 5, 6 };
    Scorer scorer(dice);
    int score = scorer.Score();
    ASSERT_EQ(1500, score);
}

