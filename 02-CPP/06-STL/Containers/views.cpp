// =============================================================================
// std::views — Comprehensive Reference & Pitfall Guide
// Requires: C++20 (-std=c++20), C++23 noted where applicable
// Compile:  g++ -std=c++20 -Wall -Wextra -o views std_views_reference.cpp
// =============================================================================

#include <ranges>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <string_view>
#include <iostream>
#include <algorithm>
#include <optional>
#include <functional>
#include <cassert>

// ── helpers ──────────────────────────────────────────────────────────────────
void section(const char* title) {
    std::cout << "\n====== " << title << " ======\n";
}
void print_range(auto&& r, const char* label = "") {
    if (*label) std::cout << label << ": ";
    for (auto&& v : r) std::cout << v << ' ';
    std::cout << '\n';
}

// =============================================================================
// 1. FACTORY VIEWS  — produce elements from scratch
// =============================================================================
void demo_factory_views() 
{
    section("Factory Views");

    // iota: [start, end)  or infinite starting from start
    auto finite   = std::views::iota(1, 6);          // 1 2 3 4 5
    auto infinite = std::views::iota(0);              // 0 1 2 3 … (lazy!)
    print_range(finite,   "iota(1,6)");
    print_range(infinite | std::views::take(5), "iota(0)|take(5)");

    // repeat (C++23) — single value repeated n times
    // auto rep = std::views::repeat(42, 3);           // 42 42 42
    // print_range(rep, "repeat(42,3)");

    // single — one-element range (useful for uniform interfaces)
    auto one = std::views::single(99);
    print_range(one, "single(99)");

    // empty — zero-element typed range
    auto none = std::views::empty<int>;
    print_range(none, "empty<int>");
}

// =============================================================================
// 2. ADAPTOR VIEWS — transform / filter an existing range
// =============================================================================
void demo_adaptor_views() {
    section("Adaptor Views");

    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // ── filter ───────────────────────────────────────────────────────────────
    auto evens = v | std::views::filter([](int x){ return x % 2 == 0; });
    print_range(evens, "filter(even)");

    // ── transform ────────────────────────────────────────────────────────────
    auto squares = v | std::views::transform([](int x){ return x * x; });
    print_range(squares, "transform(x²)");

    // ── take / drop ──────────────────────────────────────────────────────────
    print_range(v | std::views::take(3),  "take(3)");
    print_range(v | std::views::drop(7),  "drop(7)");

    // ── take_while / drop_while ──────────────────────────────────────────────
    auto lt5 = v | std::views::take_while([](int x){ return x < 5; });
    print_range(lt5, "take_while(<5)");

    auto ge8 = v | std::views::drop_while([](int x){ return x < 8; });
    print_range(ge8, "drop_while(<8)");

    // ── reverse ──────────────────────────────────────────────────────────────
    print_range(v | std::views::reverse, "reverse");

    // ── elements / keys / values (on tuple-like ranges) ──────────────────────
    std::map<std::string, int> m = {{"a", 1}, {"b", 2}, {"c", 3}};
    print_range(m | std::views::keys,   "map|keys");
    print_range(m | std::views::values, "map|values");

    // elements<N> — general tuple projection
    std::vector<std::tuple<int,double,char>> tuples = {{1, 1.1, 'x'}, {2, 2.2, 'y'}};
    print_range(tuples | std::views::elements<0>, "elements<0>");
    print_range(tuples | std::views::elements<2>, "elements<2>");

    // ── enumerate (C++23) ────────────────────────────────────────────────────
    // for (auto [i, val] : v | std::views::enumerate)
    //     std::cout << i << ':' << val << ' ';

    // ── zip (C++23) ──────────────────────────────────────────────────────────
    // std::vector<char> chars = {'a','b','c'};
    // for (auto [n, c] : std::views::zip(v, chars))
    //     std::cout << n << c << ' ';

    // ── join ─────────────────────────────────────────────────────────────────
    std::vector<std::vector<int>> nested = {{1,2},{3,4},{5}};
    auto flat = nested | std::views::join;
    print_range(flat, "join (flatten)");

    // ── split ────────────────────────────────────────────────────────────────
    std::string csv = "one,two,three";
    auto parts = csv | std::views::split(',');
    std::cout << "split(','):";
    for (auto part : parts) {
        std::cout << ' ';
        for (char c : part) std::cout << c;
    }
    std::cout << '\n';

    // ── counted ──────────────────────────────────────────────────────────────
    auto it  = v.begin() + 2;
    auto seg = std::views::counted(it, 4);   // starting at index 2, 4 elements
    print_range(seg, "counted(begin+2, 4)");

    // ── common — makes a view satisfy CommonRange (begin==end type) ───────────
    // Some old STL algos need iterator/sentinel of the same type.
    auto common_iota = std::views::iota(0, 5) | std::views::common;
    std::vector<int> out(common_iota.begin(), common_iota.end());
    print_range(out, "iota|common → vector");

    // ── as_rvalue (C++23) ────────────────────────────────────────────────────
    // auto moved = v | std::views::as_rvalue;   // yields rvalue refs
}

// =============================================================================
// 3. COMPOSING PIPELINES
// =============================================================================
void demo_pipeline() {
    section("Pipeline Composition");

    std::vector<int> data = {5, 3, 8, 1, 9, 2, 7, 4, 6, 10};

    // Read as: take data, keep odds, square them, take first 4
    auto pipeline = data
        | std::views::filter([](int x){ return x % 2 != 0; })
        | std::views::transform([](int x){ return x * x; })
        | std::views::take(4);

    print_range(pipeline, "filter(odd)|transform(²)|take(4)");

    // Chains are lazy — nothing runs until you iterate!
    // Storing a pipeline in a variable is fine:
    auto lazy = std::views::iota(1)
              | std::views::filter([](int x){ return x % 3 == 0; })
              | std::views::transform([](int x){ return x * 2; })
              | std::views::take(5);
    print_range(lazy, "infinite iota|div3|×2|take(5)");
}

// =============================================================================
// 4. RANGE ADAPTORS AS FUNCTIONS (without pipe)
// =============================================================================
void demo_functional_style() {
    section("Functional Style (no pipe)");

    std::vector<int> v = {1,2,3,4,5};

    // Equivalent to v | std::views::transform(f)
    auto t = std::views::transform(v, [](int x){ return x * 10; });
    print_range(t, "transform() as function");

    auto f = std::views::filter(v, [](int x){ return x > 2; });
    print_range(f, "filter() as function");
}

// =============================================================================
// 5. VIEWS ARE LAZY — key mental model
// =============================================================================
void demo_laziness() {
    section("Laziness Demo");

    int call_count = 0;
    auto expensive = [&](int x) {
        ++call_count;
        return x * x;
    };

    auto view = std::views::iota(0, 100)
              | std::views::transform(expensive)
              | std::views::take(3);

    std::cout << "Before iteration: call_count = " << call_count << '\n';
    for (auto x : view) std::cout << x << ' ';
    std::cout << '\n';
    std::cout << "After iterating 3 elements: call_count = " << call_count << '\n';
    // Only 3 calls, not 100!
}

// =============================================================================
// 6. COMMON PITFALLS
// =============================================================================
void demo_pitfalls() {
    section("Pitfalls");

    // ── PITFALL 1: Dangling reference from a temporary ────────────────────────
    // WRONG — 'v' is destroyed, view dangles!
    // auto bad_view = std::vector<int>{1,2,3} | std::views::filter(...);
    // for (auto x : bad_view) { ... }   // UB!

    // CORRECT — keep the owner alive
    std::vector<int> owner = {1, 2, 3};
    auto safe_view = owner | std::views::filter([](int x){ return x > 1; });
    print_range(safe_view, "safe view (owner lives)");

    // ── PITFALL 2: Modifying while iterating ─────────────────────────────────
    std::vector<int> v = {1, 2, 3, 4, 5};
    auto view = v | std::views::filter([](int x){ return x % 2 == 0; });
    // Doing v.push_back(...) or v.erase() here invalidates iterators → UB!
    print_range(view, "filter(even) — don't modify v here");

    // ── PITFALL 3: filter + non-const is tricky ───────────────────────────────
    // filter_view caches begin() for bidirectional/common ranges.
    // Calling begin() on a non-const filter_view mutates it.
    // Passing a filter_view to a function expecting const& can fail to compile
    // if the predicate isn't const-invocable.

    // ── PITFALL 4: views::split gives subranges, NOT strings ─────────────────
    std::string s = "hello world";
    for (auto word : s | std::views::split(' ')) {
        // word is a subrange of char — NOT a std::string
        std::string w(word.begin(), word.end());   // must construct explicitly
        std::cout << "[" << w << "] ";
    }
    std::cout << '\n';

    // ── PITFALL 5: iota on unsigned types can wrap ────────────────────────────
    // std::views::iota(0u, 5)  →  iota<unsigned, int> — type mismatch, may warn
    // Be explicit: std::views::iota(0u, 5u)

    // ── PITFALL 6: Not all views are random-access ────────────────────────────
    // filter_view is at most bidirectional.
    // You CANNOT do: evens[3]  or  evens.size()
    auto evens = v | std::views::filter([](int x){ return x%2==0; });
    // evens[2];    // compile error — no operator[]
    // evens.size(); // compile error — not a sized range
    std::cout << "filter_view has no operator[] or size()\n";

    // ── PITFALL 7: Reusing an input-range view ────────────────────────────────
    // Some views (e.g. owning_view over an istream) are single-pass.
    // Iterating them twice gives empty results on the second pass.

    // ── PITFALL 8: transform returning references ─────────────────────────────
    std::vector<std::string> words = {"hello", "world"};
    // WRONG: lambda returns dangling ref to local
    // auto bad = words | std::views::transform([](const std::string& s) -> const char* {
    //     std::string tmp = s + "!";
    //     return tmp.c_str();   // tmp destroyed → dangling!
    // });

    // CORRECT: return by value
    auto good = words | std::views::transform([](const std::string& s) {
        return s + "!";
    });
    print_range(good, "transform returning by value (safe)");
}

// =============================================================================
// 7. MATERIALIZING VIEWS  — converting back to containers
// =============================================================================
void demo_materialize() {
    section("Materializing a View");

    auto view = std::views::iota(1, 6)
              | std::views::transform([](int x){ return x * x; });

    // C++23: std::ranges::to<std::vector>(view)
    // C++20: manual
    std::vector<int> v(view.begin(), view.end());
    print_range(v, "iota(1,6)|x² → vector");

    // via push_back loop (works for any output)
    std::vector<int> v2;
    for (auto x : view) v2.push_back(x);
    print_range(v2, "same via push_back");
}

// =============================================================================
// 8. YOUR LEETCODE PATTERN — explained
// =============================================================================
int waviness(int n) { return n % 2 == 0 ? n : -n; }   // example waviness fn

void demo_leetcode_pattern(int num1, int count) {
    section("Leetcode Pattern Breakdown");

    // Step 1 — generate a range of indices [num1, num1+count)
    auto iota_view = std::views::iota(num1, num1 + count);
    print_range(iota_view, "iota_view");

    // Step 2 — transform each index through waviness()
    auto transformed_view = iota_view | std::views::transform(waviness);
    print_range(transformed_view, "transformed_view");

    // Step 3 — fold (reduce) to a single value
    int result = std::ranges::fold_left(transformed_view, 0, std::plus<>{});
    std::cout << "fold_left sum = " << result << '\n';

    // All three steps in one expression (pipeline style):
    auto result2 = std::ranges::fold_left(
        std::views::iota(num1, num1 + count)
            | std::views::transform(waviness),
        0, std::plus<>{}
    );
    assert(result == result2);
    std::cout << "pipeline result = " << result2 << '\n';
}

// =============================================================================
// MAIN
// =============================================================================
int main() {
    demo_factory_views();
    demo_adaptor_views();
    demo_pipeline();
    demo_functional_style();
    demo_laziness();
    demo_pitfalls();
    demo_materialize();
    demo_leetcode_pattern(3, 6);   // try num1=3, count=6

    std::cout << "\nDone.\n";
}