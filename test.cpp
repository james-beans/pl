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