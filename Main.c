#include <stdio.h>
#include "TrieDump.h"

/***************************************************************
______  ____   ____    ___      ___    __ __  ___ ___  ____
|      ||    \ |    |  /  _]    |   \  |  |  ||   |   ||    \
|      ||  D  ) |  |  /  [_     |    \ |  |  || _   _ ||  o  )
|_|  |_||    /  |  | |    _]    |  D  ||  |  ||  \_/  ||   _/
 |  |  |    \  |  | |   [_     |     ||  :  ||   |   ||  |
 |  |  |  .  \ |  | |     |    |     ||     ||   |   ||  |
 |__|  |__|\_||____||_____|    |_____| \__,_||___|___||__|

****************************************************************/

int main(int argc, char **argv)
{
	// Unsuccesful.
	if (argc != 3)
	{
		return -1;
	}

	TrieNode *root = createTrie(argv[1]);
	writeTrie(root, argv[2]);
	destroyTrie(root);

	return 0;
}
