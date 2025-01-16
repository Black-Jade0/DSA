#include <iostream>
#include <map>

int main()
{
    std::map<int, std::string> mp;

    // Insertion
    mp[2] = "Two";
    mp.insert({3, "Three"});
    mp[1] = "One";

    // Deletion
    mp.erase(2); // Erase by key

    // Iteration
    for (const auto &entry : mp)
    {
        std::cout << entry.first << ": " << entry.second << '\n';
    }

    return 0;
}
