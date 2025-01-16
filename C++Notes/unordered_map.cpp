#include <iostream>
#include <unordered_map>

int main()
{
    std::unordered_map<int, std::string> ump;

    // Insertion
    ump[1] = "One";
    ump[2] = "Two";
    ump.insert({3, "Three"});

    // Deletion
    ump.erase(2); // Erase by key

    // Iteration
    for (const auto &entry : ump)
    {
        std::cout << entry.first << ": " << entry.second << '\n';
    }

    return 0;
}
