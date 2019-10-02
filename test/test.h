#pragma once

#include "test_macros.h"

class Test
{
protected:
    virtual void beforeTest() = 0;
    virtual void test() = 0;
    virtual void afterTest() = 0;

public:
    void startTesting() { beforeTest(); test(); afterTest(); }
};