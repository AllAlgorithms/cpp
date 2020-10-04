#include <bits/stdc++.h> 
using namespace std; 
const int SIZE = 26; 
   
struct MyNode{ 
    struct MyNode *children[SIZE];
    bool isEndOfWord; 
}; 
  
// Returns new trie node
struct MyNode *getNode(void) 
{ 
    struct MyNode *pNode =  new MyNode; 
  
    pNode->isEndOfWord = false; 
  
    for (int i = 0; i < SIZE; i++) 
        pNode->children[i] = NULL; 
  
    return pNode; 
} 
  
/* If not present, inserts key into trie 
 If the key is prefix of trie node, just 
 marks leaf node*/ 
void insert(struct MyNode *root, string key) 
{ 
    struct MyNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            pCrawl->children[index] = getNode(); 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    // mark last node as leaf 
    pCrawl->isEndOfWord = true; 
} 
  
// Returns true if key presents in trie, else false 
bool search(struct MyNode *root, string key) 
{ 
    struct MyNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            return false; 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    return (pCrawl != NULL && pCrawl->isEndOfWord); 
} 
  
// Driver Programme to check above functions
int main() 
{ 
    // For input keys use only lower case 
    string keys[] = {"the", "a", "there", 
                    "answer", "any", "by", 
                     "bye", "their" }; 
    int n = sizeof(keys)/sizeof(keys[0]); 
  
    struct MyNode *root = getNode(); 
  
    // Build trie 
    for (int i = 0; i < n; i++) 
        insert(root, keys[i]); 
  
    // Search for different keys to check is it present in our dictonary or not..?? 
    search(root, "the")? cout << "Yes\n" : cout << "No\n"; 
    search(root, "these")? cout << "Yes\n" : cout << "No\n"; 
    return 0; 
}
