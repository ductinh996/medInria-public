// /////////////////////////////////////////////////////////////////
// Generated by medPluginGenerator
// /////////////////////////////////////////////////////////////////

#include "%1.h"

#include <dtkCore/dtkAbstract%2Factory.h>

// /////////////////////////////////////////////////////////////////
// %1Private
// /////////////////////////////////////////////////////////////////

class %1Private
{
public:
};

// /////////////////////////////////////////////////////////////////
// %1
// /////////////////////////////////////////////////////////////////

%1::%1(void) : dtkAbstract%2(), d(new %1Private)
{

}

%1::~%1(void)
{

}

bool %1::registered(void)
{
    return dtkAbstract%2Factory::instance()->register%2Type("%1", create%3);
}

QString %1::description(void) const
{
    return "%1";
}

// /////////////////////////////////////////////////////////////////
// Type instantiation
// /////////////////////////////////////////////////////////////////

dtkAbstract%2 *create%3(void)
{
    return new %1;
}
