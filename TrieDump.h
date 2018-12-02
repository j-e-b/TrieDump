#ifndef _TRIE_DUMP_H
#define _TRIE_DUMP_H

typedef struct TrieNode
{
	int count;
	struct TrieNode *children[26];
} TrieNode;

TrieNode *createTrie(char *filename);

void insert(TrieNode *temp, char *str);

void dumpTrie(char *filename);

#endif
