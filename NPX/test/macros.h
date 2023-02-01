#ifndef TEST_MACROS_H
#define TEST_MACROS_H

#include <iostream>
#include <cassert>

#define EXIT_SUCCESS 0

#ifdef NDEBUG
#define LOG(var)
#else
#define LOG(var) do{std::cout << #var << '=' << var;} while(false)
#endif

#ifdef NDEBUG
#define INFO(msg)
#else
#define INFO(msg) do{std::cout << msg;} while(false)
#endif

#define ASSERT(test, msg) assert(((void) msg, test))

#endif