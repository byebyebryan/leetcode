/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 *
 * https://leetcode.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (23.31%)
 * Total Accepted:    240.3K
 * Total Submissions: 1M
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * the length of shortest transformation sequence from beginWord to endWord,
 * such that:
 * 
 * 
 * Only one letter can be changed at a time.
 * Each transformed word must exist in the word list. Note that beginWord is
 * not a transformed word.
 * 
 * 
 * Note:
 * 
 * 
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * Output: 5
 * 
 * Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" ->
 * "dog" -> "cog",
 * return its length 5.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 
 * Output: 0
 * 
 * Explanation: The endWord "cog" is not in wordList, therefore no possible
 * transformation.
 * 
 * 
 * 
 * 
 * 
 */

#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int source = -1;
        int dest = -1;

        int m = wordList.size();

        for(int i=0; i<m; i++) {
            if(wordList[i] == beginWord) {
                source = i;
            }
            else if(wordList[i] == endWord) {
                dest = i;
            }

            if(source > -1 && dest > -1) break;
        }
        if(dest == -1) return 0;

        if(check(beginWord, endWord)) return 1;
        
        bool connected[m][m];

        for(int i=0; i<m; i++) {
            for(int j=0; j<m; j++) {
                connected[i][j] = false;
            }
        }

        for(int i=0; i<m-1; i++) {
            for(int j=i+1; j<m; j++) {
                if(check(wordList[i], wordList[j])) {
                    connected[i][j] = true;
                    connected[j][i] = true;
                }
            }
        }

        queue<pair<int, int>> next;

        bool checked[m];
        for(int i=0; i<m; i++) {
            checked[i] = false;
        }

        if(source > -1) {
            checked[source] = true;
            for(int i=0; i<m; i++) {
                if(i != source && connected[source][i]) {
                    next.push(make_pair(i, 1));
                }
            }
        }
        else {
            for(int i=0; i<m; i++) {
                if(check(beginWord, wordList[i])) {
                    next.push(make_pair(i, 1));
                }
            }
        }
        

        while (!next.empty()) {
            auto node = next.front();
            next.pop();

            if(node.first == dest) return node.second;
            checked[node.first] = true;

            for(int i=0; i<m; i++) {
                if( node.first != i && !checked[i] && connected[node.first][i]) {
                    next.push(make_pair(i, node.second + 1));
                }
            }
        }

        return 0;
    }

    bool check(string& a, string& b) {
        int distance = 0;

        for(int i=0; i< a.length(); i++) {
            if(a[i] != b[i]) {
                distance ++;
                if(distance > 1) return false;
            }
        }

        return distance == 1;
    }
};
