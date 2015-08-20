#include "ScoringRulesFactory.h"
#include "NOfAKindScoresXRule.h"
#include "PatternScoresXRule.h"

std::vector<std::shared_ptr<IScoringRule>> ScoringRulesFactory::CreateRules() const
{
    auto twoToSixPredicate = [](int n){ return n != 1; };
    auto six1sScore8000 = std::make_shared <NOfAKindScoresXRule>(1, 6, 8000);
    auto five1sScore4000 = std::make_shared <NOfAKindScoresXRule>(1, 5, 4000);
    auto four1sScore2000 = std::make_shared <NOfAKindScoresXRule>(1, 4, 2000);
    auto three1sScore1000 = std::make_shared <NOfAKindScoresXRule>(1, 3, 1000);
    auto six2sTo6sScore800TimesDiceValue = std::make_shared <NOfAKindScoresXRule>(twoToSixPredicate, 6, [](int n) { return 800 * n; });
    auto five2sTo6sScore400TimesDiceValue = std::make_shared <NOfAKindScoresXRule>(twoToSixPredicate, 5, [](int n) { return 400 * n; });
    auto four2sTo6sScore200TimesDiceValue = std::make_shared <NOfAKindScoresXRule>(twoToSixPredicate, 4, [](int n) { return 200 * n; });
    auto three2sTo6sScore100TimesDiceValue = std::make_shared <NOfAKindScoresXRule>(twoToSixPredicate, 3, [](int n) { return 100 * n; });
    auto single1Scores100 = std::make_shared <NOfAKindScoresXRule>(1, 1, 100);
    auto single5Scores50 = std::make_shared <NOfAKindScoresXRule>(5, 1, 50);
    auto straightFlushScores1500 = std::shared_ptr<PatternScoresXRule>(new PatternScoresXRule({ 1, 2, 3, 4, 5, 6 }, 1500));

    return std::vector<std::shared_ptr<IScoringRule>> 
    {
        six1sScore8000,
        five1sScore4000,
        four1sScore2000,
        straightFlushScores1500,
        three1sScore1000,
        six2sTo6sScore800TimesDiceValue,
        five2sTo6sScore400TimesDiceValue,
        four2sTo6sScore200TimesDiceValue,
        three2sTo6sScore100TimesDiceValue,
        single1Scores100,
        single5Scores50
    };
}