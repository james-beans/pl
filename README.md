# pl
> Plotting Lists

This library is a simple single-header implementation for C++ declarative data registries, rule definitions and structural lists. It requires the standard C++ library to work.

## License
pl is licensed under the [MPLv2](./LICENSE).

## Example
```cpp
#include <pl.hpp>
#include <iostream>

struct Item {
  int id;
};

int main() {
  // Define a simple declarative list
  auto items = pl(Item, {
    {1},
    {2},
    {3}
  });

  // Iterate through the entries
  for (const auto& item : items.get_entries()) {
    std::cout << item.id << "\n";
  }

  return 0;
}
```

## API
### Instantiation
To create an instance of a rule list or data blueprint, use the `pl` (or `PL`) macro, passing your struct type followed by an initializer list:
```cpp
auto name = pl(type, {
  { /* item 1 */ },
  { /* item 2 */ }
});
```
*(Under the hood, this instantiates an underlying `__pl_list<T>` container wrapping a `std::vector<T>`)*

### Public Methods & Members
- `std::vector<T> entries;`
  - The underlying public vector containing all stored entries initialized via the macro.
- `const std::vector<T>& get_entries() const;`
  - Returns a constant reference to the internal entries vector for safe iteration and inspection.