#include "ScoringRulesFactory.h"
#include "NOfAKindScoresXRule.h"
#include "PatternScoresXRule.h"

std::vector<std::shared_ptr<IScoringRule>> ScoringRulesFactory::CreateRules() const
{
    auto twoToSixPredicate = [](int n){ return n != 1; };

    auto six1sScore8000 = MakeShared(new PatternScoresXRule({ 1, 1, 1, 1, 1, 1 }, 8000));
    auto five1sScore4000 = MakeShared(new PatternScoresXRule({ 1, 1, 1, 1, 1 }, 4000));
    auto four1sScore2000 = MakeShared(new PatternScoresXRule({ 1, 1, 1, 1 }, 2000));
    auto three1sScore1000 = MakeShared(new PatternScoresXRule({ 1, 1, 1 }, 1000));
    auto six2sTo6sScore800TimesDiceValue = MakeShared(new NOfAKindScoresXRule(6, twoToSixPredicate, [](int n) { return 800 * n; }));
    auto five2sTo6sScore400TimesDiceValue = MakeShared(new NOfAKindScoresXRule(5, twoToSixPredicate, [](int n) { return 400 * n; }));
    auto four2sTo6sScore200TimesDiceValue = MakeShared(new NOfAKindScoresXRule(4, twoToSixPredicate, [](int n) { return 200 * n; }));
    auto three2sTo6sScore100TimesDiceValue = MakeShared(new NOfAKindScoresXRule(3, twoToSixPredicate, [](int n) { return 100 * n; }));
    auto straightFlushScores1500 = MakeShared(new PatternScoresXRule({ 1, 2, 3, 4, 5, 6 }, 1500));
    auto single1Scores100 = MakeShared(new PatternScoresXRule({ 1 }, 100));
    auto single5Scores50 = MakeShared(new PatternScoresXRule({ 5 }, 50));

    return std::vector<std::shared_ptr<IScoringRule>> 
    {
        six1sScore8000,
        five1sScore4000,
        four1sScore2000,
        three1sScore1000,
        six2sTo6sScore800TimesDiceValue,
        five2sTo6sScore400TimesDiceValue,
        four2sTo6sScore200TimesDiceValue,
        three2sTo6sScore100TimesDiceValue,
        straightFlushScores1500,
        single1Scores100,
        single5Scores50
    };
}

std::shared_ptr<IScoringRule> ScoringRulesFactory::MakeShared(IScoringRule* rule) const
{
    return std::shared_ptr<IScoringRule>(rule);
}