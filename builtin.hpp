#pragma once

#include <vector>
#include <string>
#include <list>

template<typename T>
std::list<T> l(T arg)
{
    std::list<T> retValue;
    retValue.push_back(arg);
    return retValue;
}

template<typename T, typename... Args>
std::list<T> l(T value, Args... args)
{
    std::list<T> retValue;
    retValue.push_back(value);
    for (T arg : l(args...))
    {
        retValue.push_back(arg);
    }
    return retValue;
}

template <typename Func,typename Container>
auto reduce(Func f,Container &container)
    ->typename Container::value_type
{
    typedef Container::value_type ReturnType;
    ReturnType result  = ReturnType();
    if(container.begin() != container.end())
    {
        Container::const_iterator it;
        it = container.begin();
        for(result = *(it++);it!=container.end();++it)
        {
            result = f(result,*it);
        }
    }
    return result;
}

template<typename Func, typename Container>
auto map(Func func, Container& container)
    ->std::list<decltype(func(Container::value_type()))>
{
    typedef std::list<decltype(func(Container::value_type()))> ReturnType;
    ReturnType result  = ReturnType();
    for (Container::value_type value : container)
    {
        result.push_back(func(value));
    }
    return result;
}
