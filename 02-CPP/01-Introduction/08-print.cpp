// =============================================================================
// std::print / std::println / std::format — Comprehensive Reference & Pitfall Guide
// std::print / std::println  → C++23   (<print>)
// std::format / std::vformat → C++20   (<format>)
// Compile (GCC 14+ / Clang 17+):
//   g++ -std=c++23 -Wall -Wextra -o print std_print_reference.cpp
// =============================================================================

#include <print>       // std::print, std::println  (C++23)
#include <format>      // std::format, std::vformat, std::formatter (C++20)
#include <string>
#include <string_view>
#include <vector>
#include <map>
#include <chrono>
#include <cmath>
#include <iostream>    // still needed for std::cout in mixed-output sections
#include <fstream>
#include <cassert>
#include <stdexcept>

// ── helper ───────────────────────────────────────────────────────────────────
void section(const char* title) {
    std::println("\n====== {} ======", title);
}

// =============================================================================
// 1. std::print vs std::println vs std::format
//    print   → writes to stdout, NO trailing newline
//    println → writes to stdout, WITH trailing newline  (almost always prefer this)
//    format  → returns a std::string, nothing printed
// =============================================================================
void demo_basics() {
    section("Basics: print / println / format");

    // println adds '\n' automatically — use it for almost everything
    std::println("Hello, {}!", "world");

    // print — no newline; useful when building output incrementally
    std::print("Count: ");
    for (int i = 1; i <= 5; ++i)
        std::print("{} ", i);
    std::print("\n");   // manual newline at the end

    // format — produces a std::string (no I/O side effect)
    std::string s = std::format("The answer is {}", 42);
    std::println("format produced: {}", s);

    // All three share the same format-string mini-language
    double pi = std::numbers::pi;   // requires <numbers>
    // std::println("pi = {:.4f}", pi);   // needs <numbers>
    std::println("pi ≈ {:.4f}", 3.14159265);
}

// =============================================================================
// 2. FORMAT STRING SYNTAX  {[arg-id][:[fill][align][sign][#][0][width][.prec][type]}
// =============================================================================
void demo_format_syntax() {
    section("Format String Syntax");

    // ── positional / auto-indexing ────────────────────────────────────────────
    std::println("{} + {} = {}", 1, 2, 3);            // auto-indexed
    std::println("{0} {1} {0}", "echo", "and");        // positional (reuse arg)
    // Cannot MIX auto and manual: "{} {1}" is ill-formed at compile time

    // ── width & alignment ────────────────────────────────────────────────────
    std::println("[{:10}]",  "left");      // left-align (default for strings)
    std::println("[{:<10}]", "left");      // explicit left
    std::println("[{:>10}]", "right");     // right-align
    std::println("[{:^10}]", "center");    // center
    std::println("[{:*^10}]","fill");      // fill char = '*', center

    // ── sign ─────────────────────────────────────────────────────────────────
    std::println("{:+}", 42);     // always show sign: +42
    std::println("{:+}", -42);    // -42
    std::println("{: }", 42);     // space for positive: ' 42'

    // ── integer bases ─────────────────────────────────────────────────────────
    std::println("{:d}",  255);    // decimal:     255
    std::println("{:b}",  255);    // binary:      11111111
    std::println("{:#b}", 255);    // with prefix: 0b11111111
    std::println("{:o}",  255);    // octal:       377
    std::println("{:#o}", 255);    //              0377
    std::println("{:x}",  255);    // hex lower:   ff
    std::println("{:X}",  255);    // hex upper:   FF
    std::println("{:#x}", 255);    //              0xff

    // ── floating point ───────────────────────────────────────────────────────
    double v = 123456.789;
    std::println("{:f}",    v);    // fixed:        123456.789000
    std::println("{:.2f}",  v);    // fixed 2 dp:   123456.79
    std::println("{:e}",    v);    // scientific:   1.234568e+05
    std::println("{:.3e}",  v);    //               1.235e+05
    std::println("{:g}",    v);    // general (shorter of f/e)
    std::println("{:a}",    v);    // hex float

    // ── zero-padding ─────────────────────────────────────────────────────────
    std::println("{:08d}", 42);    // 00000042
    std::println("{:08.2f}", 3.14);// 00003.14

    // ── width from argument ───────────────────────────────────────────────────
    int width = 12;
    std::println("{:{}.{}f}", 3.14159, width, 3);  // width=12, prec=3

    // ── char and bool ─────────────────────────────────────────────────────────
    std::println("{:c}", 65);      // A  (int treated as char)
    std::println("{}", true);      // true
    std::println("{:d}", true);    // 1   (bool as integer)

    // ── escaped string / char (C++23) ────────────────────────────────────────
    std::println("{:?}", "tab\there");   // "tab\there"  (debug/escape view)
    std::println("{:?}", '\n');          // '\n'
}

// =============================================================================
// 3. PRINTING TO A FILE / STREAM  — std::print(file, ...)
// =============================================================================
void demo_file_output() {
    section("Output to File / Stream");

    // print/println accept a FILE* as first argument
    std::println(stdout, "This goes to stdout explicitly");
    std::println(stderr, "This goes to stderr");

    // Writing to an actual file
    std::FILE* f = std::fopen("/tmp/demo_print.txt", "w");
    if (f) {
        std::println(f, "Line 1: value = {}", 42);
        std::println(f, "Line 2: pi ≈ {:.4f}", 3.14159);
        std::fclose(f);
        std::println("Wrote to /tmp/demo_print.txt");
    }

    // Note: print/println do NOT accept std::ostream (e.g. std::ofstream).
    // For std::ostream you still use std::format + <<  or  operator<<:
    //
    //   std::ofstream ofs("out.txt");
    //   ofs << std::format("value = {}\n", 42);
    //
    // OR in C++23 use std::print with the ostream overload if your STL has it.
}

// =============================================================================
// 4. std::format_to / std::format_to_n — write into a buffer or iterator
// =============================================================================
void demo_format_to() {
    section("format_to / format_to_n");

    // format_to — appends formatted text to any output iterator
    std::string buf;
    std::format_to(std::back_inserter(buf), "Hello, {}!\n", "buffer");
    std::format_to(std::back_inserter(buf), "Value: {:.2f}\n", 3.14159);
    std::print("{}", buf);

    // format_to with a raw char array (careful — no bounds check!)
    char arr[64];
    auto end = std::format_to(arr, "raw array: {}", 99);
    *end = '\0';
    std::println("{}", arr);

    // format_to_n — bounded version; safe for fixed-size buffers
    char small[16];
    auto result = std::format_to_n(small, sizeof(small) - 1,
                                   "truncated: {}", 123456789);
    small[result.size] = '\0';   // result.size = chars written
    std::println("format_to_n: '{}'  (out = {})", small, result.out - small);

    // formatted_size — how many chars would format produce? (no allocation)
    std::size_t n = std::formatted_size("pi = {:.10f}", 3.14159265358979);
    std::println("formatted_size: {}", n);
}

// =============================================================================
// 5. CUSTOM FORMATTER — make your own type printable with {}
// =============================================================================
struct Point {
    double x, y;
};

// Specialise std::formatter for Point
template<>
struct std::formatter<Point> {
    // parse() reads the format spec between ':' and '}'
    // ctx.begin() points right after ':'
    char spec = 'f';   // default: fixed float

    constexpr auto parse(std::format_parse_context& ctx) {
        auto it = ctx.begin();
        if (it != ctx.end() && *it != '}') {
            spec = *it++;   // e.g. 'e' for scientific, 'f' for fixed
        }
        return it;   // must return iterator past consumed chars
    }

    // format() writes into ctx.out()
    auto format(const Point& p, std::format_context& ctx) const {
        if (spec == 'e')
            return std::format_to(ctx.out(), "({:e}, {:e})", p.x, p.y);
        return std::format_to(ctx.out(), "({:.3f}, {:.3f})", p.x, p.y);
    }
};

// Struct with nested formatter using another custom type
struct Line {
    Point a, b;
};
template<>
struct std::formatter<Line> : std::formatter<std::string> {
    auto format(const Line& l, std::format_context& ctx) const {
        return std::formatter<std::string>::format(
            std::format("{} → {}", l.a, l.b), ctx);
    }
};

void demo_custom_formatter() {
    section("Custom Formatter");

    Point p{3.14159, 2.71828};
    std::println("default: {}", p);        // (3.142, 2.718)
    std::println("scientific: {:e}", p);   // (3.141590e+00, 2.718280e+00)

    // width/align still work because we forward the outer spec
    // (only if we forward width — advanced; omitted here for clarity)

    Line l{p, {0.0, 1.0}};
    std::println("line: {}", l);
}

// =============================================================================
// 6. RANGES / CONTAINERS (C++23 range formatting)
// =============================================================================
void demo_range_formatting() {
    section("Range / Container Formatting (C++23)");

    // std::vector, std::array, std::list, etc. are formattable in C++23
    std::vector<int>         vi  = {1, 2, 3, 4, 5};
    std::vector<std::string> vs  = {"hello", "world"};
    std::map<int,std::string> m  = {{1,"one"},{2,"two"},{3,"three"}};

    std::println("{}", vi);   // [1, 2, 3, 4, 5]
    std::println("{}", vs);   // ["hello", "world"]
    std::println("{}", m);    // {1: "one", 2: "two", 3: "three"}

    // Per-element format spec: {::<elem-spec>}
    std::println("{::d}",    vi);     // [1, 2, 3, 4, 5]  (explicit decimal)
    std::println("{::#x}",   vi);     // [0x1, 0x2, 0x3, 0x4, 0x5]
    std::println("{::>8}",   vs);     // right-align each string in 8 chars

    // Nested ranges (vector of vectors)
    std::vector<std::vector<int>> vv = {{1,2},{3,4},{5,6}};
    std::println("{}", vv);   // [[1, 2], [3, 4], [5, 6]]

    // Pairs and tuples
    std::pair<int,std::string> pr = {42, "hello"};
    std::println("{}", pr);   // (42, "hello")

    std::tuple<int,double,std::string> t = {1, 3.14, "pi"};
    std::println("{}", t);    // (1, 3.14, "pi")
}

// =============================================================================
// 7. CHRONO FORMATTING — dates and times with {}
// =============================================================================
void demo_chrono() {
    section("Chrono Formatting");

    using namespace std::chrono;

    // Duration formatting
    auto dur = 3h + 25min + 45s;
    std::println("duration: {}", dur);          // 12345s (total seconds)
    std::println("hours part: {}", duration_cast<hours>(dur));

    // Specific duration types
    std::println("{}",  42ns);    // 42ns
    std::println("{}",  3ms);     // 3ms
    std::println("{}",  1.5s);    // 1.5s
    std::println("{}",  2min);    // 2min

    // Formatting with chrono format specs
    auto now = system_clock::now();
    // %Y %m %d %H:%M:%S — strftime-style specifiers inside {}
    std::println("{:%Y-%m-%d}", now);              // e.g. 2024-06-07
    std::println("{:%H:%M:%S}", now);              // e.g. 14:23:05
    std::println("{:%A, %B %d %Y}", now);          // e.g. Friday, June 07 2024

    // std::chrono::year_month_day
    auto ymd = year_month_day{year{2024}, month{6}, day{7}};
    std::println("ymd: {}", ymd);                  // 2024-06-07
    std::println("ymd: {:%d/%m/%Y}", ymd);         // 07/06/2024

    // Weekday
    auto wd = weekday{sys_days{ymd}};
    std::println("weekday: {}", wd);               // Fri
    std::println("weekday: {:%A}", wd);            // Friday
}

// =============================================================================
// 8. RUNTIME FORMAT STRINGS — std::vformat / std::make_format_args
// =============================================================================
void demo_runtime_format() {
    section("Runtime Format Strings (vformat)");

    // std::format requires a compile-time format string literal.
    // For runtime strings, use std::vformat:

    std::string fmt_str = "Value: {:.{}f}";   // built at runtime
    std::string result  = std::vformat(fmt_str, std::make_format_args(3.14159, 3));
    std::println("{}", result);

    // Practical use: format strings from config files, user input, i18n
    auto runtime_print = [](std::string_view fmt, auto... args) {
        std::println("{}", std::vformat(fmt, std::make_format_args(args...)));
    };
    runtime_print("Hello, {}! You are {} years old.", "Alice", 30);

    // WARNING: vformat does NOT check the format string at compile time.
    // A bad runtime format string throws std::format_error at runtime.
    try {
        std::string bad = "{}{}";
        std::vformat(bad, std::make_format_args(1));  // too few args
    } catch (const std::format_error& e) {
        std::println("format_error caught: {}", e.what());
    }
}

// =============================================================================
// 9. std::print vs printf vs std::cout — comparison
// =============================================================================
void demo_comparison() {
    section("print vs printf vs cout");

    int    n = 42;
    double d = 3.14159;
    std::string s = "hello";

    // printf — C-style, type-unsafe, no std::string support
    printf("printf: %d  %.3f  %s\n", n, d, s.c_str());

    // cout — verbose, stateful (manipulators persist!)
    std::cout << "cout:   " << n << "  "
              << std::fixed << std::setprecision(3) << d << "  "    // persists!
              << s << '\n';
    // After this, cout stays in 'fixed' mode with precision 3 until you reset it

    // std::println — clean, type-safe, Unicode-aware, no state leakage
    std::println("println: {}  {:.3f}  {}", n, d, s);
    // Format spec is local to each call — no persistent state

    // Performance: print/println go directly to the FILE* buffer;
    // no sync_with_stdio overhead when mixing with cout.
    // Consider calling std::ios::sync_with_stdio(false) if mixing.
}

// =============================================================================
// 10. UNICODE & ENCODING NOTES
// =============================================================================
void demo_unicode() {
    section("Unicode & Encoding");

    // std::print is Unicode-aware on all platforms (transcodes on Windows)
    std::println("Unicode: \u03C0 \u221E \U0001F600");   // π ∞ 😀

    // Width calculation for formatted strings uses display width (grapheme clusters)
    // Basic ASCII alignment works perfectly
    std::println("[{:>10}]", "hi");      // [        hi]

    // Emoji/wide chars may not align perfectly in all terminals —
    // the format library counts code units, not visual columns
    std::println("[{:>10}]", "😀");      // alignment may look off in terminal

    // {:?} — debug format, escapes non-printable & non-ASCII
    std::println("{:?}", "hello\tworld\n");   // "hello\tworld\n"
    std::println("{:?}", "π");               // "\u03c0" or "π" depending on impl
}

// =============================================================================
// 11. COMMON PITFALLS
// =============================================================================
void demo_pitfalls() {
    section("Pitfalls");

    // ── PITFALL 1: Mixing auto and manual arg indices ─────────────────────────
    // "{} {1}"  → compile error (ill-formed format string)
    // "{0} {1}" → OK (all manual)
    // "{} {}"   → OK (all auto)

    // ── PITFALL 2: Wrong type for format spec ─────────────────────────────────
    // std::println("{:d}", 3.14);   // compile error: 'd' needs integer
    // std::println("{:f}", "hi");   // compile error: 'f' needs float
    // These are caught at COMPILE TIME — huge advantage over printf!

    // ── PITFALL 3: cout manipulators leak state, format specs don't ──────────
    // After: std::cout << std::fixed << std::setprecision(2) << 3.14;
    // ALL subsequent cout floats use fixed + precision 2 until reset.
    // std::println("{:.2f}", 3.14); // self-contained, no state leak.
    std::println("No state leak: {}", 3.14159);   // still prints full precision

    // ── PITFALL 4: print to FILE*, not ostream ────────────────────────────────
    // std::println(std::cout, "bad");  // WON'T COMPILE — not a FILE*
    // std::println(stdout, "good");    // correct
    // For std::ostream: use std::format() and operator<<

    // ── PITFALL 5: vformat is NOT type-safe ───────────────────────────────────
    // Errors from bad runtime format strings throw std::format_error at runtime,
    // not compile time. Always validate externally sourced format strings.

    // ── PITFALL 6: Lifetime in make_format_args ───────────────────────────────
    // make_format_args holds references — the arguments must outlive the call!
    // WRONG:
    //   auto args = std::make_format_args(std::string("temp"));  // dangling!
    //   std::vformat("{}", args);
    // CORRECT: pass the value directly or ensure it lives long enough.

    // ── PITFALL 7: Custom formatter parse() must return correct iterator ──────
    // Returning ctx.begin() without advancing past consumed chars causes
    // the format engine to re-parse, leading to infinite loops or errors.

    // ── PITFALL 8: Range formatting requires C++23 ───────────────────────────
    // std::println("{}", std::vector{1,2,3}) won't compile in C++20.
    // In C++20 you need a manual loop or a custom formatter.

    // ── PITFALL 9: Braces in format strings must be escaped ──────────────────
    std::println("Literal braces: {{}} and {{0}}", 42);   // prints: {} and {0} 42
    // Single '{' or '}' is a syntax error

    // ── PITFALL 10: Not all compilers ship <print> yet ────────────────────────
    // GCC 14+, Clang 17+, MSVC 19.37+ support <print>.
    // <format> (C++20) has wider support (GCC 13, Clang 14, MSVC 19.29).
    // Fallback: use std::format() + std::cout << for C++20 portability.

    std::println("Pitfalls demo complete.");
}

// =============================================================================
// 12. PORTABILITY SHIM — C++20 without <print>
// =============================================================================
// If you're on C++20 only (no <print>), use this pattern:
namespace compat {
    template<typename... Args>
    void println(std::format_string<Args...> fmt, Args&&... args) {
        std::cout << std::format(fmt, std::forward<Args>(args)...) << '\n';
    }
    template<typename... Args>
    void print(std::format_string<Args...> fmt, Args&&... args) {
        std::cout << std::format(fmt, std::forward<Args>(args)...);
    }
}

void demo_compat_shim() {
    section("C++20 Portability Shim");
    compat::println("compat::println: {} + {} = {}", 1, 2, 3);
    compat::print("no newline: {}\n", "done");
}

// =============================================================================
// MAIN
// =============================================================================
int main() {
    demo_basics();
    demo_format_syntax();
    demo_file_output();
    demo_format_to();
    demo_custom_formatter();
    demo_range_formatting();
    demo_chrono();
    demo_runtime_format();
    demo_comparison();
    demo_unicode();
    demo_pitfalls();
    demo_compat_shim();

    std::println("\nDone.");
}