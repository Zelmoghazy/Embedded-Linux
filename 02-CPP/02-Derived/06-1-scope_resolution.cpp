
// The :: operator tells the compiler *where* to look for a name.
// It resolves ambiguity between identically-named identifiers
// that exist in different scopes/namespaces/classes.
//
// SECTIONS:
//   1. Global vs. Class Scope
//   2. Namespace Scope
//   3. Nested Namespaces
//   4. Defining Class Members Outside the Class
//   5. Static Member Access
//   6. Enum Class (Scoped Enums)
//   7. Inheritance & Calling Base-Class Methods
//   8. Multiple Inheritance Disambiguation
//   9. Anonymous Namespaces
//  10. Using Declarations vs. Using Directives
// ============================================================

#include <iostream>
#include <string>

// ============================================================
// SECTION 1 — Global vs. Class Scope
//
// When a class method and a global function share the same name,
// the unqualified call resolves to the local (class) scope.
// Prepending :: forces the compiler into the global scope.
// ============================================================

void greet() {
    std::cout << "[Global] Hello from the global greet()!\n";
}

class Robot {
public:
    void greet() {
        std::cout << "[Robot] Hello from Robot::greet()!\n";
    }

    void demo() {
        greet();    // Calls Robot::greet()  — local scope wins
        ::greet();  // Calls ::greet()        — forced global scope
    }
};

// ============================================================
// SECTION 2 — Namespace Scope
//
// Namespaces group related names to avoid collisions across
// libraries or modules.  :: separates the namespace from the
// symbol: NamespaceName::symbol
// ============================================================

namespace Physics {
    const double GRAVITY = 9.81;   // m/s²

    void describe() {
        std::cout << "[Physics] Gravity = " << GRAVITY << " m/s²\n";
    }
}

namespace Chemistry {
    const double GRAVITY = 0.0;    // not used in chemistry — just for demo

    void describe() {
        std::cout << "[Chemistry] describe() — a different function entirely\n";
    }
}

// ============================================================
// SECTION 3 — Nested Namespaces
//
// Namespaces can be nested arbitrarily deep.
// Access: Outer::Inner::symbol
// C++17 shorthand: namespace Outer::Inner { ... }
// ============================================================

namespace Engine {
    namespace Renderer {
        void render() {
            std::cout << "[Engine::Renderer] render() called\n";
        }
    }
    namespace Audio {
        void play() {
            std::cout << "[Engine::Audio] play() called\n";
        }
    }
}

// ============================================================
// SECTION 4 — Defining Class Members *Outside* the Class
//
// Declare inside the class body, define outside using
// ClassName::methodName().  This is the most common pattern
// in real-world header / source file pairs.
// ============================================================

class Vector2D {
public:
    double x, y;
    Vector2D(double x, double y);   // declaration
    double length() const;           // declaration
    void print() const;              // declaration
};

// Definitions — each prefixed with Vector2D::
Vector2D::Vector2D(double x, double y) : x(x), y(y) {}

double Vector2D::length() const {
    return std::sqrt(x * x + y * y);   // std:: is also a scope resolution!
}

void Vector2D::print() const {
    std::cout << "[Vector2D] (" << x << ", " << y
              << ")  |length| = " << length() << "\n";
}

// ============================================================
// SECTION 5 — Static Member Access
//
// Static members belong to the class, not to any instance.
// They are accessed (and defined) with ClassName::member.
// ============================================================

class Counter {
public:
    static int count;   // declaration

    Counter()  { ++count; }
    ~Counter() { --count; }

    static int getCount() { return count; }   // static method
};

int Counter::count = 0;   // definition — mandatory for non-inline static

// ============================================================
// SECTION 6 — Scoped Enums (enum class)
//
// Unlike plain enums, enum class enumerators do NOT leak into
// the surrounding scope.  You must use EnumName::value.
// This eliminates a major source of name collisions.
// ============================================================

enum class Direction { North, South, East, West };  // scoped
enum OldDirection   { North, South, East, West };   // unscoped — leaks!

void printDirection(Direction d) {
    // Must qualify with Direction::
    if (d == Direction::North) std::cout << "[Direction] North\n";
    if (d == Direction::South) std::cout << "[Direction] South\n";
}

// ============================================================
// SECTION 7 — Inheritance: Calling Base-Class Methods
//
// When a derived class overrides a base method, :: lets you
// explicitly call the base version: Base::method()
// ============================================================

class Animal {
public:
    virtual void speak() const {
        std::cout << "[Animal] Generic animal sound\n";
    }
};

class Dog : public Animal {
public:
    void speak() const override {
        Animal::speak();    // explicitly call the base version first
        std::cout << "[Dog] Woof!\n";
    }
};

// ============================================================
// SECTION 8 — Multiple Inheritance Disambiguation
//
// When two base classes share a method name, the compiler
// can't choose.  :: picks the correct base explicitly.
// ============================================================

class Flyable {
public:
    void move() { std::cout << "[Flyable] Flying...\n"; }
};

class Swimmable {
public:
    void move() { std::cout << "[Swimmable] Swimming...\n"; }
};

class Duck : public Flyable, public Swimmable {
public:
    void doBoth() {
        Flyable::move();    // unambiguous
        Swimmable::move();  // unambiguous
    }
    // If you wrote just move() here, the compiler would error: ambiguous
};

// ============================================================
// SECTION 9 — Anonymous Namespaces
//
// A namespace with no name gives its contents internal linkage
// (like static at file scope).  Names are visible in this
// translation unit only.  No :: prefix needed to access them.
// ============================================================

namespace {
    int internalHelper() {
        return 42;   // invisible to other .cpp files
    }
}

// ============================================================
// SECTION 10 — using declarations vs. using directives
//
// using Physics::GRAVITY;   → imports ONE name (declaration)
// using namespace Physics;  → imports ALL names (directive)
//
// Prefer declarations to avoid polluting scope — and NEVER put
// "using namespace std;" in a header file.
// ============================================================

// ============================================================
// MAIN — demonstrates all sections
// ============================================================

int main() {
    std::cout << "=== SECTION 1: Global vs. Class Scope ===\n";
    Robot robot;
    robot.demo();

    std::cout << "\n=== SECTION 2: Namespace Scope ===\n";
    Physics::describe();
    Chemistry::describe();
    std::cout << "Physics gravity constant: " << Physics::GRAVITY << "\n";

    std::cout << "\n=== SECTION 3: Nested Namespaces ===\n";
    Engine::Renderer::render();
    Engine::Audio::play();

    std::cout << "\n=== SECTION 4: Defining Members Outside the Class ===\n";
    Vector2D v(3.0, 4.0);
    v.print();

    std::cout << "\n=== SECTION 5: Static Members ===\n";
    {
        Counter a, b, c;
        std::cout << "Counters alive: " << Counter::getCount() << "\n";  // 3
    }
    std::cout << "Counters alive after scope: " << Counter::getCount() << "\n"; // 0

    std::cout << "\n=== SECTION 6: Scoped Enums ===\n";
    printDirection(Direction::North);
    printDirection(Direction::South);
    // OldDirection leaks: North == 0 without any prefix (bad practice)

    std::cout << "\n=== SECTION 7: Calling Base-Class Method ===\n";
    Dog dog;
    dog.speak();

    std::cout << "\n=== SECTION 8: Multiple Inheritance Disambiguation ===\n";
    Duck duck;
    duck.doBoth();

    std::cout << "\n=== SECTION 9: Anonymous Namespace ===\n";
    std::cout << "Internal helper returns: " << internalHelper() << "\n";

    std::cout << "\n=== SECTION 10: using Declaration vs. Directive ===\n";
    {
        using Physics::GRAVITY;         // only GRAVITY is imported
        std::cout << "GRAVITY = " << GRAVITY << "\n";
        // Chemistry::describe() still needs full qualification
    }
    {
        using namespace Chemistry;      // everything from Chemistry imported
        describe();                     // resolves to Chemistry::describe()
    }

    return 0;
}

// ============================================================
// QUICK-REFERENCE SUMMARY
//
//  Syntax                  Meaning
//  ──────────────────────────────────────────────────────────
//  ::name                  Global scope
//  NS::name                Symbol inside namespace NS
//  NS1::NS2::name          Symbol in nested namespace
//  Class::member           Static member or out-of-class def
//  Class::method()         Explicit base-class call (inherited)
//  Base::method()          Override disambiguation
//  EnumClass::value        Scoped enum value (mandatory)
//  std::cout               std library — also just a namespace!
// ============================================================