#include <iostream> 
#include <vector>
using namespace std; 
const int SIZE = 26; 
   
struct Node {
    Node *children[SIZE];
    bool isEndOfWord; 
 
    Node() {
        isEndOfWord = false;
        for (int i = 0; i < SIZE; i++) 
            children[i] = NULL;
    }

    ~Node() {
        for (int i = 0; i < SIZE; i++) {
            if (children[i])
                delete children[i];
        }
    }
}; 
  
/* 
 If the key is not present, inserts it into the trie.
 If the key is the prefix of a trie node, just marks leaf node.
 */ 
void insert(Node *root, const string& key) 
{ 
    Node *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            pCrawl->children[index] = new Node(); 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    // mark last node as leaf 
    pCrawl->isEndOfWord = true; 
} 
  
// Returns true if the key is present in the trie, else returns false.
bool search(Node *root, const string& key) 
{ 
    Node *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            return false; 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    return (pCrawl != NULL && pCrawl->isEndOfWord); 
} 
  
// Driver Program for Trie.
int main() 
{ 
    // For input keys use only lower case.
    vector<string> keys{"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their" }; 
    Node *root = new Node(); 
  
    // Build trie 
    for (string key: keys) 
        insert(root, key); 
  
    // Search for different keys to check is it present in our dictonary or not..?? 
    search(root, "the") ? cout << "Yes\n" : cout << "No\n"; 
    search(root, "these") ? cout << "Yes\n" : cout << "No\n"; 
    
    delete root;
    return 0; 
}
