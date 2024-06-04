#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Trie düðüm yapýsý
struct TrieNode {
    struct TrieNode* children[26];
    bool isEndOfWord;
};

// Yeni Trie düðümü oluþturma fonksiyonu
struct TrieNode* getNode(void) {
    struct TrieNode* pNode = NULL;

    pNode = (struct TrieNode*)malloc(sizeof(struct TrieNode));

    if (pNode) {
        pNode->isEndOfWord = false;

        for (int i = 0; i < 26; i++)
            pNode->children[i] = NULL;
    }

    return pNode;
}

// Trie'ye kelime ekleme fonksiyonu
void insert(struct TrieNode* root, const char* key) {
    int level;
    int length = strlen(key);
    int index;

    struct TrieNode* pCrawl = root;

    for (level = 0; level < length; level++) {
        index = key[level] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }

    pCrawl->isEndOfWord = true;
}

// Trie'de kelime arama fonksiyonu
bool search(struct TrieNode* root, const char* key) {
    int level;
    int length = strlen(key);
    int index;
    struct TrieNode* pCrawl = root;

    for (level = 0; level < length; level++) {
        index = key[level] - 'a';

        if (!pCrawl->children[index])
            return false;

        pCrawl = pCrawl->children[index];
    }

    return (pCrawl != NULL && pCrawl->isEndOfWord);
}

// Ana fonksiyon
int main() {
    // Trie kök düðümü oluþturma
    char keys[][8] = { "the", "a", "there", "answer", "any", "by", "bye", "their" };

    struct TrieNode* root = getNode();

    // Kelimeleri Trie'ye ekleme
    for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++)
        insert(root, keys[i]);

    // Kelime arama
    search(root, "the") ? printf("the --- Bulundu\n") : printf("the --- Bulunamadý\n");
    search(root, "these") ? printf("these --- Bulundu\n") : printf("these --- Bulunamadý\n");
    search(root, "their") ? printf("their --- Bulundu\n") : printf("their --- Bulunamadý\n");
    search(root, "thaw") ? printf("thaw --- Bulundu\n") : printf("thaw --- Bulunamadý\n");

    return 0;
}