// 1. Basic Macro: Simple println! style macro
// This macro takes a variable number of arguments
macro_rules! say_hello {
    // Match a single name
    ($name:expr) => {
        println!("Hello, {}!", $name);
    };
    // Match multiple names separated by commas
    ($($name:expr),*) => {
        $(
            println!("Hello, {}!", $name);
        )*
    };
}

// 2. Intermediate: Vector creation macro
macro_rules! create_vec {
    // Empty vector
    () => {
        Vec::new()
    };
    // Single element
    ($element:expr) => {{
        let mut v = Vec::new();
        v.push($element);
        v
    }};
    // Multiple elements
    ($($element:expr),+ $(,)?) => {{
        let mut v = Vec::new();
        $(
            v.push($element);
        )+
        v
    }};
}

// 3. Advanced: Struct builder macro
macro_rules! build_struct {
    (
        $(#[$meta:meta])*
        struct $name:ident {
            $(
                $(#[$field_meta:meta])*
                $field:ident: $type:ty
            ),* $(,)?
        }
    ) => {
        $(#[$meta])*
        struct $name {
            $(
                $(#[$field_meta])*
                $field: $type
            ),*
        }

        impl $name {
            pub fn builder() -> $name {
                $name {
                    $(
                        $field: Default::default()
                    ),*
                }
            }

            $(
                pub fn $field(mut self, value: $type) -> Self {
                    self.$field = value;
                    self
                }
            )*
        }
    };
}

// 4. Expert: SQL-like query builder
macro_rules! query {
    // SELECT * FROM table
    (SELECT * FROM $table:ident) => {{
        format!("SELECT * FROM {}", stringify!($table))
    }};
    
    // SELECT field1, field2 FROM table
    (SELECT $($field:ident),+ FROM $table:ident) => {{
        let fields = vec![$(stringify!($field)),+].join(", ");
        format!("SELECT {} FROM {}", fields, stringify!($table))
    }};
    
    // SELECT fields FROM table WHERE condition
    (SELECT $($field:ident),+ FROM $table:ident WHERE $condition:expr) => {{
        let fields = vec![$(stringify!($field)),+].join(", ");
        format!("SELECT {} FROM {} WHERE {}", 
            fields, 
            stringify!($table),
            $condition
        )
    }};
}

// 5. Expert: Trait implementation generator
macro_rules! impl_trait_for {
    ($trait_name:ident, $($type:ty),+) => {
        $(
            impl $trait_name for $type {
                fn describe(&self) -> String {
                    format!("This is a {}", stringify!($type))
                }
            }
        )+
    };
}

// Example usage of all macros
fn main() {
    // 1. Basic macro usage
    say_hello!("Alice");
    say_hello!("Bob", "Charlie", "Dave");

    // 2. Vector creation
    let v1 = create_vec![];
    let v2 = create_vec![1];
    let v3 = create_vec![1, 2, 3, 4];
    println!("Vectors: {:?}, {:?}, {:?}", v1, v2, v3);

    // 3. Struct builder usage
    build_struct! {
        #[derive(Debug, Default)]
        struct Person {
            name: String,
            age: u32,
            email: String,
        }
    }

    let person = Person::builder()
        .name("John Doe".to_string())
        .age(30)
        .email("john@example.com".to_string());
    
    // 4. SQL query builder usage
    let query1 = query!(SELECT * FROM users);
    let query2 = query!(SELECT name, age FROM users);
    let query3 = query!(SELECT id, name FROM users WHERE "age > 18");
    
    println!("Queries:\n{}\n{}\n{}", query1, query2, query3);

    // 5. Trait implementation usage
    trait Describable {
        fn describe(&self) -> String;
    }

    impl_trait_for!(Describable, i32, f64, String);
    
    let num = 42;
    let float = 3.14;
    let string = String::from("Hello");
    
    println!("{}", num.describe());
    println!("{}", float.describe());
    println!("{}", string.describe());
}