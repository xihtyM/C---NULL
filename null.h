#pragma once

#ifdef null_t
#undef null_t
#endif

#ifdef null
#undef null
#endif

#ifdef __cplusplus

#if __cplusplus >= 201103L

//
// C++11 introduces nullptr
// use this as null because
// it is the best to use.
//

typedef decltype(nullptr) null_t;
#define null nullptr

#else

//
// Before C++11 you can still
// define your own class for
// nullptr to be emulated.
//

// for std::ostream
#include <ostream>

// NOTE: the address of null
// is not garunteed to be 0
// with this implementation
const class null_t
{
public:
    template<class T>
    operator T() const
    {
        return (T) 0;
    }

    friend std::ostream& operator<<(std::ostream& os, const null_t& n) {
        os << "null";
        return os;
    }
private:
    void operator&() const; // illegal
    void operator*() const; // illegal
} null = {};

// end #if __cplusplus >= 201103L
#endif

// end #ifdef __cplusplus
// #ifndef __cplusplus
#else

#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202000L

//
// c23 declares support for keywords:
// - nullptr
// - typeof
//

#define null nullptr
typedef typeof(null) null_t;

#else

//
// if before c23, fall back to using void*
// for null_t and if possible, define null
// as __null otherwise just use ((null_t)0).
//


#ifdef __GNUG__
typedef long long null_t;
#define null __null
#else
typedef void *null_t;
#define null ((null_t)0)
#endif

#endif
#endif
