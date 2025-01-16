#include <iostream>
#include <vector>

using namespace std;

class TrieNode
{
public:
    TrieNode *child[26];
    bool isLeaf;
    TrieNode()
    {
        isLeaf = false;
        for (size_t i = 0; i < 26; i++)
        {
            child[i] = nullptr;
        }
    }
};

class WordDictionary
{
    TrieNode *root;

public:
    WordDictionary()
    {
        root = new TrieNode();
    }
    void addWord(string word)
    {
        TrieNode *p = root;
        for (auto i : word)
        {
            int a = i - 'a';
            if (!p->child[a])
            {
                p->child[a] = new TrieNode();
            }
            p = p->child[a];
        }
        p->isLeaf = true;
    }
    bool searchHelper(string word, int i, TrieNode *p)
    {
        if (i == word.size())
        {
            return p->isLeaf;
        }
        if (word[i] == '.')
        {
            for (int j = 0; j < 26; j++)
            {
                if (p->child[j] && searchHelper(word, i + 1, p->child[j]))
                {
                    return true;
                }
            }
        }
        else
        {
            if (p->child[word[i] - 'a'])
            {
                return searchHelper(word, i + 1, p->child[word[i] - 'a']);
            }
        }
        return false;
    }
    bool search(string word)
    {
        return searchHelper(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main()
{
    // Your code goes here

    return 0;
}