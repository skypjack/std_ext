#include <type_traits_ext.hpp>
#include <gtest/gtest.h>

using namespace stdext;

struct A { };
struct B { void f() { } };
struct D: B { };

struct S {
    S(A&, B&) { }
    virtual void g() = 0;
};

struct T final: S {
    void g() final override { }
};

enum class E { FOO, BAR };
union U { A a; };

void f() { }
