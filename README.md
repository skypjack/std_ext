## Synopsis

`stdext::` offers a set of functionalities built upon the ones that can
be found in the **Standard Template Library**.

This library is a work in progress project.<br/>
New functionalities will be added whenever:

* I need them and I find the time to correctly define them
* Someone asks for them with a ticket (I'll try to updated the project as soon
  as possible)
* A PR is sent and it contains code, tests and documentation as well

## Code Example

Examples of the above mentioned functionalities are:

* **are_same**

    ```
    struct S { };
    struct T { };
    static_assert(not are_same<S, T, S>::value, "are not all the same")
    ```

* **is_base_of_all**

    ```
    struct B { };
    struct D: B { };
    struct C: B { };
    static_assert(is_base_of_all<B, D, C>::value, "B is base of D and C")
    ```

* **tail**

    ```
    std::tuple<int, double> tup{};
    auto t = tail(tup);
    assert((std::is_same<decltype(t), std::tuple<double>>::value));
    ```

## Motivation

The **Standard Template Library** contains a lot of facilities, but it also
lacks a lot of other useful tools.<br/>
`stdext::` tries to fill the gap, offering those utilities that are not
part of the **Standard Template Library**.

## Installation

The `stdext::` library is a header only library.<br/>
Because of that, a user is demanded simply to include it and all the
functionalities will be available at once.<br/>
Please, note that all the types are part of the `stdext` namespace.<br/>
See the files in `src` for further details.

## API Reference

The documentation is available by means of `cmake`.<br/>
Be sure to have `doxygen` installed and use the following commands:
```
cd build
cmake ..
make docs
```

It will be created in `build/docs/html`.<br/>
One can simply open the file `index.html` and navigate it.

List of currently available facilities and classes.

### Tuple

* `tail`

    ```
    template<typename H, typename... T>
    constexpr std::tuple<T...> tail(std::tuple<H, T...> &tup);

    template<typename H, typename... T>
    constexpr std::tuple<T...> tail(std::tuple<H, T...> &&tup);
    ```

* `invoke`

    ```
    template<typename F, typename... T>
    constexpr auto invoke(F &&f, std::tuple<T...> &tup);
    ```

### Type Traits

**Primary type categories**

* `are_void`
* `are_null_pointer`
* `are_integral`
* `are_floating_point`
* `are_array`
* `are_enum`
* `are_union`
* `are_class`
* `are_function`
* `are_pointer`
* `are_lvalue_reference`
* `are_rvalue_reference`
* `are_member_object_pointer`
* `are_member_function_pointer`

**Composite type categories**

* `are_fundamental`
* `are_arithmetic`
* `are_scalar`
* `are_object`
* `are_compound`
* `are_reference`
* `are_member_pointer`

**Type properties**

* `are_const`
* `are_volatile`
* `are_trivial`
* `are_trivially_copyable`
* `are_standard_layout`
* `are_pod`
* `are_literal_type`
* `are_empty`
* `are_polymorphic`
* `are_abstract`
* `are_signed`
* `are_unsigned`

**Supported operations**

* `are_constructible`
* `are_trivially_constructible`
* `are_nothrow_constructible`
* `are_default_constructible`
* `are_trivially_default_constructible`
* `are_nothrow_default_constructible`
* `are_copy_constructible`
* `are_trivially_copy_constructible`
* `are_nothrow_copy_constructible`
* `are_move_constructible`
* `are_trivially_move_constructible`
* `are_nothrow_move_constructible`

**Type relationships**

* `is_same_of_any`
* `is_same_of_all`
* `are_all_same_of`
* `is_base_of_any`
* `is_base_of_all`
* `are_all_base_of`
* `is_convertible_to_any`
* `is_convertible_to_all`
* `are_all_convertible_to`

Please, note that all the types above mentioned are provided along with their
*helper variable templates*, similar to the ones available in the
**Standard Template Library** (mostly since C++17).<br/>
As an example, the helper variable template for the `is_same_of_any` type is
defined as:

```
template<class... A>
constexpr bool is_same_of_any_v = is_same_of_any<A...>::value;
```

More in general, all those helpers are defined as:

```
template<class... A>
constexpr bool actual_type_name_v = actual_type_name<A...>::value;
```

### Utility

* `function_proxy`

    ```
    std::is_same<
        typename function_proxy<1, void(int, char, double)>::type,
        std::function<void(int)>
    >::value; // true
    ```

* `inherit_from`

    ```
    std::is_same<
        inherit_from_t<const int ** const &&, char>,
        types<int, const char ** const &&>
    >::value

    std::is_same<
        inherit_from_basic_t<int const **[][3][5], double>,
        int
    >::value

    std::is_same<
        inherit_from_decorated_t<int const **[][3][5], double>,
        double const **[][3][5]
    >::value
    ```

Please, note that all the types above mentioned are provided along with their
*helper type templates*, similar to the ones available in the
**Standard Template Library** (mostly since C++14).<br/>
As an example, the helper variable template for the `function_proxy` type is
defined as:

```
template<std::size_t N, typename F>
using function_proxy_t = typename function_proxy<N, F>::type;
```

More in general, all those helpers are defined as:

```
template<class... A>
using actual_type_name_t = typename actual_type_name<A...>::type;
```

## Tests

Building in-tree is not allowed, so you should compile them in the *build*
directory before to launch them.<br/>
To do that, you can simply execute the following commands:
```
cd build
cmake ..
make
make test
```

## Contributors

Michele Caini ([skypjack](https://github.com/skypjack))

## License

The MIT License (MIT)
=====================

Copyright © `2016` `Michele Caini`

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the “Software”), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
