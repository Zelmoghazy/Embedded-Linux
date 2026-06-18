// =============================================================================
// std::ranges — Comprehensive Reference & Pitfall Guide
// Requires: C++20 (-std=c++20), C++23 noted where applicable
// Compile:  g++ -std=c++20 -Wall -Wextra -o ranges std_ranges_reference.cpp
// =============================================================================

#include <ranges>
#include <algorithm>
#include <numeric>
#include <vector>
#include <list>
#include <deque>
#include <string>
#include <map>
#include <set>
#include <array>
#include <iostream>
#include <functional>
#include <iterator>
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
// 1. RANGES vs CLASSIC STL ALGORITHMS
//    Classic: std::sort(v.begin(), v.end())
//    Ranges:  std::ranges::sort(v)           ← takes the whole container
// =============================================================================
void demo_ranges_vs_classic() {
    section("Ranges vs Classic Algorithms");

    std::vector<int> v = {5, 3, 8, 1, 9, 2};

    // Classic
    std::sort(v.begin(), v.end());
    print_range(v, "classic sort");

    // Ranges — same container, no .begin()/.end() boilerplate
    std::ranges::sort(v, std::greater{});
    print_range(v, "ranges::sort descending");

    // Ranges also accept iterator pairs for partial ranges:
    std::ranges::sort(v.begin(), v.begin() + 3);
    print_range(v, "ranges::sort first 3 only");
}

// =============================================================================
// 2. PROJECTIONS — sort/find/etc by a field without writing a comparator
// =============================================================================
struct Employee {
    std::string name;
    int salary;
    int dept;
};

void demo_projections() {
    section("Projections");

    std::vector<Employee> team = {
        {"Alice", 90000, 2},
        {"Bob",   75000, 1},
        {"Carol", 85000, 1},
        {"Dave",  95000, 2},
    };

    // Sort by salary (projection instead of custom comparator)
    std::ranges::sort(team, {}, &Employee::salary);
    for (auto& e : team)
        std::cout << e.name << '(' << e.salary << ") ";
    std::cout << '\n';

    // Sort by name length using a lambda projection
    std::ranges::sort(team, {}, [](const Employee& e){ return e.name.size(); });
    for (auto& e : team)
        std::cout << e.name << ' ';
    std::cout << '\n';

    // min_element with projection
    auto lowest = std::ranges::min_element(team, {}, &Employee::salary);
    std::cout << "Lowest salary: " << lowest->name << '\n';

    // find_if with projection
    auto it = std::ranges::find(team, 1, &Employee::dept);
    if (it != team.end())
        std::cout << "First in dept 1: " << it->name << '\n';

    // max with projection
    auto richest = std::ranges::max(team, {}, &Employee::salary);
    std::cout << "Richest: " << richest.name << '\n';
}

// =============================================================================
// 3. NON-MODIFYING ALGORITHMS
// =============================================================================
void demo_non_modifying() {
    section("Non-Modifying Algorithms");

    std::vector<int> v = {1, 2, 3, 4, 5, 2, 3, 2};

    // find / find_if / find_if_not
    auto it = std::ranges::find(v, 3);
    std::cout << "find(3) index: " << std::distance(v.begin(), it) << '\n';

    auto it2 = std::ranges::find_if(v, [](int x){ return x > 4; });
    std::cout << "find_if(>4): " << *it2 << '\n';

    // count / count_if
    std::cout << "count(2): " << std::ranges::count(v, 2) << '\n';
    std::cout << "count_if(>3): " << std::ranges::count_if(v, [](int x){ return x > 3; }) << '\n';

    // all_of / any_of / none_of
    std::cout << "all positive: " << std::ranges::all_of(v, [](int x){ return x > 0; }) << '\n';
    std::cout << "any > 4:      " << std::ranges::any_of(v, [](int x){ return x > 4; }) << '\n';
    std::cout << "none > 9:     " << std::ranges::none_of(v, [](int x){ return x > 9; }) << '\n';

    // for_each — returns {iterator, function}
    int sum = 0;
    auto [end_it, fn] = std::ranges::for_each(v, [&](int x){ sum += x; });
    std::cout << "for_each sum: " << sum << '\n';

    // equal / mismatch
    std::vector<int> w = {1, 2, 3, 4, 5, 2, 3, 2};
    std::cout << "equal: " << std::ranges::equal(v, w) << '\n';

    // search (find subsequence)
    std::vector<int> sub = {2, 3};
    auto pos = std::ranges::search(v, sub);
    std::cout << "search({2,3}) at index: "
              << std::distance(v.begin(), pos.begin()) << '\n';

    // contains (C++23)
    // std::cout << "contains(5): " << std::ranges::contains(v, 5) << '\n';

    // min / max / minmax
    std::cout << "min: " << std::ranges::min(v) << '\n';
    std::cout << "max: " << std::ranges::max(v) << '\n';
    auto [lo, hi] = std::ranges::minmax(v);
    std::cout << "minmax: [" << lo << ", " << hi << "]\n";
}

// =============================================================================
// 4. MODIFYING ALGORITHMS
// =============================================================================
void demo_modifying() {
    section("Modifying Algorithms");

    std::vector<int> v = {1, 2, 3, 4, 5};
    std::vector<int> out(5);

    // copy / copy_if
    std::ranges::copy(v, out.begin());
    print_range(out, "copy");

    std::ranges::copy_if(v, out.begin(), [](int x){ return x % 2 == 0; });
    // (out now has 2 4 followed by stale 3 4 5 — copy_if doesn't resize)

    // transform (writes to output range)
    std::ranges::transform(v, out.begin(), [](int x){ return x * 2; });
    print_range(out, "transform(×2) → out");

    // transform with two input ranges
    std::vector<int> a = {1,2,3}, b = {10,20,30}, c(3);
    std::ranges::transform(a, b, c.begin(), std::plus{});
    print_range(c, "transform(a+b)");

    // fill / fill_n
    std::ranges::fill(out, 0);
    print_range(out, "fill(0)");

    std::ranges::fill_n(out.begin(), 3, 7);
    print_range(out, "fill_n(3, 7)");

    // generate / generate_n
    int n = 0;
    std::ranges::generate(out, [&]{ return n++; });
    print_range(out, "generate(0..4)");

    // replace / replace_if
    std::ranges::replace(v, 3, 99);
    print_range(v, "replace(3→99)");

    std::ranges::replace_if(v, [](int x){ return x > 4; }, -1);
    print_range(v, "replace_if(>4→-1)");

    // remove / remove_if — returns subrange of remaining elements
    std::vector<int> u = {1, 2, 3, 2, 4, 2, 5};
    auto [new_end, _] = std::ranges::remove(u, 2);
    u.erase(new_end, u.end());        // must erase the tail!
    print_range(u, "remove(2) + erase");

    // unique — removes consecutive duplicates
    std::vector<int> dup = {1, 1, 2, 3, 3, 3, 4};
    auto [uend, __] = std::ranges::unique(dup);
    dup.erase(uend, dup.end());
    print_range(dup, "unique");

    // reverse / rotate
    std::vector<int> r = {1, 2, 3, 4, 5};
    std::ranges::reverse(r);
    print_range(r, "reverse");

    std::ranges::rotate(r, r.begin() + 2);   // pivot at index 2
    print_range(r, "rotate(pivot=2)");

    // shuffle
    // std::ranges::shuffle(r, std::mt19937{42});

    // iota (fill with increasing values)
    std::iota(r.begin(), r.end(), 10);   // no ranges::iota in C++20 :(
    print_range(r, "iota(10)");
}

// =============================================================================
// 5. SORTING & PARTITIONING
// =============================================================================
void demo_sorting() {
    section("Sorting & Partitioning");

    std::vector<int> v = {5, 3, 8, 1, 9, 2, 7, 4, 6, 10};

    // sort / stable_sort
    std::ranges::sort(v);
    print_range(v, "sort");

    std::vector<int> w = {5, 3, 8, 1, 9};
    std::ranges::stable_sort(w);
    print_range(w, "stable_sort");

    // partial_sort — only sort first k elements
    std::vector<int> p = {5, 3, 8, 1, 9, 2, 7};
    std::ranges::partial_sort(p, p.begin() + 3);   // 3 smallest in order
    print_range(p, "partial_sort(k=3)");

    // nth_element — O(n) guarantee: element at pos k is what sort would put there
    std::vector<int> q = {5, 3, 8, 1, 9, 2, 7};
    std::ranges::nth_element(q, q.begin() + 3);
    std::cout << "nth_element(3): q[3]=" << q[3] << " (median)\n";

    // is_sorted / is_sorted_until
    std::cout << "is_sorted: " << std::ranges::is_sorted(v) << '\n';

    // partition
    std::vector<int> x = {1,2,3,4,5,6,7,8};
    auto mid = std::ranges::partition(x, [](int n){ return n % 2 == 0; });
    print_range(x, "partition(even|odd)");

    // stable_partition preserves relative order within each group
    std::vector<int> y = {1,2,3,4,5,6};
    std::ranges::stable_partition(y, [](int n){ return n % 2 == 0; });
    print_range(y, "stable_partition");

    // is_partitioned
    std::cout << "is_partitioned: "
              << std::ranges::is_partitioned(y, [](int n){ return n%2==0; })
              << '\n';
}

// =============================================================================
// 6. BINARY SEARCH (on sorted ranges)
// =============================================================================
void demo_binary_search() {
    section("Binary Search (sorted ranges)");

    std::vector<int> v = {1, 2, 4, 4, 5, 7, 9, 10};

    // binary_search — just bool
    std::cout << "binary_search(4): " << std::ranges::binary_search(v, 4) << '\n';
    std::cout << "binary_search(6): " << std::ranges::binary_search(v, 6) << '\n';

    // lower_bound — first element >= value
    auto lb = std::ranges::lower_bound(v, 4);
    std::cout << "lower_bound(4) index: " << lb - v.begin() << '\n';

    // upper_bound — first element > value
    auto ub = std::ranges::upper_bound(v, 4);
    std::cout << "upper_bound(4) index: " << ub - v.begin() << '\n';

    // equal_range — [lower_bound, upper_bound) as subrange
    auto [lo, hi] = std::ranges::equal_range(v, 4);
    std::cout << "equal_range(4): [" << (lo - v.begin()) << ", "
              << (hi - v.begin()) << ")\n";
}

// =============================================================================
// 7. SET ALGORITHMS (on sorted ranges)
// =============================================================================
void demo_set_algos() {
    section("Set Algorithms");

    std::vector<int> a = {1, 2, 3, 4, 5};
    std::vector<int> b = {3, 4, 5, 6, 7};
    std::vector<int> out;

    // merge
    out.resize(a.size() + b.size());
    std::ranges::merge(a, b, out.begin());
    print_range(out, "merge");

    // set_intersection
    out.clear(); out.resize(std::min(a.size(), b.size()));
    auto [oa, ob] = std::ranges::set_intersection(a, b, out.begin());
    out.erase(ob, out.end());
    print_range(out, "set_intersection");

    // set_union
    out.resize(a.size() + b.size());
    auto [ua, ub] = std::ranges::set_union(a, b, out.begin());
    out.erase(ub, out.end());
    print_range(out, "set_union");

    // set_difference (a - b)
    out.resize(a.size());
    auto [da, db] = std::ranges::set_difference(a, b, out.begin());
    out.erase(db, out.end());
    print_range(out, "set_difference(a-b)");

    // includes
    std::cout << "a includes {2,4}: "
              << std::ranges::includes(a, std::vector{2,4}) << '\n';
}

// =============================================================================
// 8. PERMUTATIONS
// =============================================================================
void demo_permutations() {
    section("Permutations");

    std::vector<int> v = {1, 2, 3};

    std::cout << "All permutations of {1,2,3}:\n";
    do {
        print_range(v);
    } while (std::ranges::next_permutation(v).found);

    std::ranges::prev_permutation(v);   // step back one
    print_range(v, "prev_permutation");

    // is_permutation
    std::vector<int> a = {3,1,2}, b = {1,2,3};
    std::cout << "is_permutation: " << std::ranges::is_permutation(a, b) << '\n';
}

// =============================================================================
// 9. NUMERIC / FOLD (C++23 fold_left, fold_right)
// =============================================================================
void demo_fold() {
    section("Fold Algorithms (C++23)");

    std::vector<int> v = {1, 2, 3, 4, 5};

    // fold_left — left-associative reduce
    int sum = std::ranges::fold_left(v, 0, std::plus<>{});
    std::cout << "fold_left sum: " << sum << '\n';

    int product = std::ranges::fold_left(v, 1, std::multiplies<>{});
    std::cout << "fold_left product: " << product << '\n';

    // fold_right — right-associative
    int right_sub = std::ranges::fold_right(v, 0, std::minus<>{});
    std::cout << "fold_right sub: " << right_sub << '\n';

    // fold_left_first — uses first element as init (returns optional)
    auto opt = std::ranges::fold_left_first(v, std::plus<>{});
    if (opt) std::cout << "fold_left_first: " << *opt << '\n';

    // string concatenation with fold
    std::vector<std::string> words = {"hello", " ", "world"};
    auto str = std::ranges::fold_left(words, std::string{}, std::plus<>{});
    std::cout << "fold strings: " << str << '\n';

    // Compare with classic std::accumulate (C++20 still needs it for numeric)
    int acc = std::accumulate(v.begin(), v.end(), 0);
    std::cout << "accumulate (classic): " << acc << '\n';
}

// =============================================================================
// 10. RANGE CONCEPTS — compile-time constraints
// =============================================================================
void demo_concepts() {
    section("Range Concepts");

    // These are checked at compile time — useful in templates
    static_assert(std::ranges::range<std::vector<int>>);
    static_assert(std::ranges::sized_range<std::vector<int>>);
    static_assert(std::ranges::random_access_range<std::vector<int>>);
    static_assert(std::ranges::bidirectional_range<std::list<int>>);
    static_assert(!std::ranges::random_access_range<std::list<int>>);
    static_assert(std::ranges::contiguous_range<std::vector<int>>);
    static_assert(std::ranges::contiguous_range<std::array<int,5>>);

    std::cout << "All concept static_asserts passed.\n";

    // Use in templates to constrain:
    auto sum_any_range = []<std::ranges::input_range R>(R&& r) {
        using T = std::ranges::range_value_t<R>;
        return std::ranges::fold_left(r, T{}, std::plus<>{});
    };

    std::cout << "sum vector: " << sum_any_range(std::vector{1,2,3}) << '\n';
    std::cout << "sum array:  " << sum_any_range(std::array{4,5,6}) << '\n';
}

// =============================================================================
// 11. RETURNED SUBRANGES — C++20 algorithms return rich results
// =============================================================================
void demo_return_types() {
    section("Rich Return Types");

    std::vector<int> v = {1, 2, 3, 4, 5};

    // remove returns in_out_result {in_last, out_last}
    // copy returns in_out_result
    std::vector<int> dst(5);
    auto [in_end, out_end] = std::ranges::copy(v, dst.begin());
    // in_end == v.end(), out_end == dst.end()

    // sort returns the range (begin, end)
    auto sorted_range = std::ranges::sort(v);
    // sorted_range is just v's subrange

    // search returns a subrange
    std::vector<int> needle = {3, 4};
    auto found = std::ranges::search(v, needle);
    if (!found.empty())
        std::cout << "Found {3,4} at index: "
                  << std::distance(v.begin(), found.begin()) << '\n';

    // mismatch returns a pair of iterators
    std::vector<int> w = {1, 2, 99, 4, 5};
    auto [it1, it2] = std::ranges::mismatch(v, w);
    std::cout << "First mismatch: v[" << (it1-v.begin())
              << "]=" << *it1 << " vs w=" << *it2 << '\n';

    // partition_point
    std::vector<int> sorted = {1, 2, 4, 6, 8, 9};
    auto pp = std::ranges::partition_point(sorted, [](int x){ return x < 5; });
    std::cout << "partition_point(<5): *pp=" << *pp << '\n';
}

// =============================================================================
// 12. COMMON PITFALLS
// =============================================================================
void demo_pitfalls() {
    section("Pitfalls");

    // ── PITFALL 1: remove doesn't actually erase! ─────────────────────────────
    std::vector<int> v = {1, 3, 2, 3, 4, 3, 5};
    auto [tail, _] = std::ranges::remove(v, 3);
    // v still has size 7; elements after tail are unspecified
    // MUST erase:
    v.erase(tail, v.end());
    print_range(v, "remove(3)+erase (correct)");

    // ── PITFALL 2: algorithms need the right iterator category ────────────────
    // std::ranges::sort requires random_access_range
    // std::list is only bidirectional — won't compile:
    // std::list<int> lst = {3,1,2};
    // std::ranges::sort(lst);    // compile error — use lst.sort() instead

    // ── PITFALL 3: projections don't modify, they only project for comparison ─
    std::vector<Employee> team = {{"Bob",75000,1},{"Alice",90000,2}};
    std::ranges::sort(team, {}, &Employee::salary);
    // Sorted by salary, but the struct is moved in full — salary itself is NOT
    // extracted/replaced; the whole element moves.
    for (auto& e : team) std::cout << e.name << '(' << e.salary << ") ";
    std::cout << '\n';

    // ── PITFALL 4: binary_search on unsorted range = UB ──────────────────────
    std::vector<int> u = {3, 1, 4, 1, 5};
    // std::ranges::binary_search(u, 4);  // UB — u is not sorted!
    std::ranges::sort(u);
    std::cout << "binary_search(4) after sort: "
              << std::ranges::binary_search(u, 4) << '\n';

    // ── PITFALL 5: stable_sort and stable_partition need extra memory ─────────
    // They fall back to O(n log² n) if no extra heap is available.
    // Not a correctness bug, just a performance note.

    // ── PITFALL 6: equal_range / lower_bound use operator< by default ─────────
    // If you sorted with a custom comparator, pass the SAME comparator here,
    // or results are undefined.
    std::vector<int> desc = {9, 7, 5, 3, 1};
    // WRONG: lower_bound(desc, 5) — assumes ascending!
    // CORRECT:
    auto lb = std::ranges::lower_bound(desc, 5, std::greater{});
    std::cout << "lower_bound(5, greater) index: " << (lb-desc.begin()) << '\n';

    // ── PITFALL 7: mutating while using std::ranges::for_each ────────────────
    // for_each guarantees sequential but modifying the container can invalidate
    // iterators for vector. Use indexed loop or ranges::transform instead.

    // ── PITFALL 8: fold_left_first on empty range returns std::nullopt ────────
    std::vector<int> empty;
    auto result = std::ranges::fold_left_first(empty, std::plus<>{});
    if (!result) std::cout << "fold_left_first on empty = nullopt (safe)\n";
}

// =============================================================================
// 13. VIEWS + RANGES TOGETHER (the full power combo)
// =============================================================================
void demo_combined() {
    section("Views + Ranges Combined");

    std::vector<int> data = {5, 3, 8, 1, 9, 2, 7, 4, 6, 10};

    // Build a lazy pipeline, then run a ranges algorithm on it
    auto pipeline = data
        | std::views::filter([](int x){ return x % 2 == 0; })
        | std::views::transform([](int x){ return x * x; });

    // count_if on a view
    auto count = std::ranges::count_if(pipeline, [](int x){ return x > 25; });
    std::cout << "count >25 in (even²): " << count << '\n';

    // max_element on a view
    auto mx = std::ranges::max_element(pipeline);
    std::cout << "max of (even²): " << *mx << '\n';

    // fold_left on a view
    int sum = std::ranges::fold_left(pipeline, 0, std::plus<>{});
    std::cout << "sum of (even²): " << sum << '\n';

    // Materialize into vector then sort
    std::vector<int> materialized(pipeline.begin(), pipeline.end());
    std::ranges::sort(materialized, std::greater{});
    print_range(materialized, "even² sorted desc");
}

// =============================================================================
// MAIN
// =============================================================================
int main() {
    demo_ranges_vs_classic();
    demo_projections();
    demo_non_modifying();
    demo_modifying();
    demo_sorting();
    demo_binary_search();
    demo_set_algos();
    demo_permutations();
    demo_fold();
    demo_concepts();
    demo_return_types();
    demo_pitfalls();
    demo_combined();

    std::cout << "\nDone.\n";
}