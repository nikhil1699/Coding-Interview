/*

Given a list of n words and a pattern p that we want to search. Check if the pattern p is present the given words or not.

*/

// #include "TrieNode.h"
#include <string>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
	}
};

class Trie {
	TrieNode *root;

	public :
	int count;

	Trie() {
		this->count = 0;
		root = new TrieNode('\0');
	}

	bool insertWord(TrieNode *root, string word) {
		// Base case
		if(word.size() == 0) {
			if (!root->isTerminal) {
				root -> isTerminal = true;
				return true;	
			} else {
				return false;
			}
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			child = new TrieNode(word[0]);
			root -> children[index] = child;
		}

		// Recursive call
		return insertWord(child, word.substr(1));
	}

	// For user
	void insertWord(string word) {
		if (insertWord(root, word)) {
			this->count++;
		}
	}
    
    bool search(TrieNode *root, string pattern)
    {
        if (pattern.size() == 0)
        {
            return true;
        }
        int index = pattern[0] - 'a';
        TrieNode *child = root->children[index];
        if (child != NULL)
            return search(child, pattern.substr(1));
        else
            return false;
    }
	
    
    bool patternMatching(vector<string> vect, string pattern) {
		// Complete this function
		// Return true or false
        for (int i=0; i< vect.size(); i++)
        {
            string str = vect[i];
            while(str.size() != 0)
            {
                insertWord(str);
                str = str.substr(1);
            }
        }
        return search(root, pattern);
        
	}
};


