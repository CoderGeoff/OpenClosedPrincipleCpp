#include "stdafx.h"
#include "TestDie.h"

TestDie::TestDie(int thrown)
    : m_Thrown(thrown)
{
}

int TestDie::Throw() const
{
    return m_Thrown;
}
