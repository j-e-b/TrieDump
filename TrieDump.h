#ifndef _TRIE_DUMP_H
#define _TRIE_DUMP_H

typedef struct TrieNode
{
	int count;
	struct TrieNode *children[26];
} TrieNode;

void writeTrieHelper(TrieNode *root, char *buffer, int t, FILE *out);

void writeTrie(TrieNode *root, char *outname);

void strip(char *str);

TrieNode *createTrie(char *filename);

void insert(TrieNode *temp, char *str);

TrieNode *destroyTrie(TrieNode *root);

#endif
