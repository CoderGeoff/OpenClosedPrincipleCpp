#pragma once
#include "IDie.h"

class TestDie : public IDie
{
    int m_Thrown;
public:
    TestDie(int thrown);
    virtual int Throw() const override;
};

