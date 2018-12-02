#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TrieDump.h"

void writeTrieHelper(TrieNode *root, char *buffer, int t, FILE *out)
{
	int i;

	// Just in (base) case.
	if (root == NULL)
	{
		return;
	}

	// This node represents the end of a stored word. Let's print buffer.
	if (root->count > 0)
	{
		fprintf(out, "%s (%d)\n", buffer, root->count);
	}

	// Ensure this string is properly terminated before potentially printing it.
	buffer[t + 1] = '\0';

	// Follow each non-null route, filling buffer accordingly.
	for (i = 0; i < 26; i++)
	{
		buffer[t] = i + 'a';

		if (root->children[i] != NULL)
		{
			writeTrieHelper(root->children[i], buffer, t + 1, out);
		}
	}

	// Place the NULL terminator at the end of buffer for this recursive call.
	buffer[t] = '\0';
}

// Print all the strings represented in the trie rooted at this node.
void writeTrie(TrieNode *root, char *outname)
{
	char buffer[1024];
	buffer[0] = '\0';

	FILE *out;

	out = fopen(outname, "w");

	writeTrieHelper(root, buffer, 0, out);
}

// This function strips any non-alpha characters from a given string and
// converts any uppercase characters to lowercase.
void strip(char *str)
{
	int i, j = 0, len = strlen(str);
	char newStr[len + 1];

	// In using strtok(), the last word in a given string will contain a '\n'
	// character which we need to get rid of and decrement the string's length.
	if (str[len - 1] == '\n')
	{
		str[len - 1] = '\0';
		len--;
	}

	for (i = 0; i < len; i++)
	{
		if (!isalpha(str[i]))
		{
			continue;
		}

		newStr[j++] = tolower(str[i]);
	}

	newStr[j] = '\0';

	strcpy(str, newStr);
}

void insert(TrieNode *temp, char *str)
{
	int index;

	// Base Case: We have reached the end of this particular insertion process.
	if (str[0] == '\0')
	{
		temp->count++;
		return;
	}

	index = tolower(str[0]) - 'a';

	// Allocate space if the appropriate child does not yet exist.
	if (temp->children[index] == NULL)
	{
		temp->children[index] = calloc(1, sizeof(TrieNode));
	}

	insert(temp->children[index], str + 1);
}

TrieNode *createTrie(char *filename)
{
	TrieNode *root = calloc(1, sizeof(TrieNode));
	char buffer[1024];
	FILE *ifp;

	if ((ifp = fopen(filename, "r")) == NULL)
	{
		free(root);
		return NULL;
	}

	// Absorb the glory.
	while (fscanf(ifp, "%s", buffer) != EOF)
	{
		strip(buffer);
		insert(root, buffer);
	}

	fclose(ifp);
	return root;
}

int main(void)
{
	TrieNode *root = createTrie("corpus01.txt");
	writeTrie(root, "test.txt");

	// Stretch goal: Write a function that recursively destroys your trie.

	return 0;
}
