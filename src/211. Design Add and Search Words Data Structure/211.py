'''
File: 211.py
File Created: 2021-01-12 14:30:02 -08:00
Author: Taowyoo (caoyxsh@outlook.com)
Brief: https://leetcode.com/problems/design-add-and-search-words-data-structure/
-----
Last Modified: 2021-01-12 14:30:05 -08:00
Modified By: Taowyoo (caoyxsh@outlook.com>)
-----
Copyright 2020 - 2021
'''

class WordDictionary:
    """Trie Tree
    """
    def __init__(self):
        self.d = defaultdict(set)


    def addWord(self, word: str) -> None:
        self.d[len(word)].add(word)


    def search(self, word: str) -> bool:
        m = len(word)
        for dict_word in self.d[m]:
            i = 0
            while i < m and (dict_word[i] == word[i] or word[i] == '.'):
                i += 1
            if i == m:
                return True
        return False

class WordDictionary:
    """My solution, recrusive Trie Tree
    """
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.wordTree = {}
        
    def addWord(self, word: str) -> None:
        """
        Adds a word into the data structure.
        """
        if word:
            if word[0] in self.wordTree:
                self.wordTree[word[0]].addWord(word[1:])
            else:
                self.wordTree[word[0]] = WordDictionary()
                self.wordTree[word[0]].addWord(word[1:])
        else:
            if word not in self.wordTree:
                self.wordTree[word] = None
    def search(self, word: str) -> bool:
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        """
        if not word:
            return word in self.wordTree;
        if word[0] == '.':
            for val in self.wordTree.values(): 
                if val and val.search(word[1:]):
                    return True
        else:
            if word[0] in self.wordTree:
                return self.wordTree[word[0]].search(word[1:])
                pass
        return False