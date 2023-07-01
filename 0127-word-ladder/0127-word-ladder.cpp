class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        queue<pair<string,int>> q;
        q.push({beginWord,1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);

        // modified bfs
        while(!q.empty()){

            string word = q.front().first;
            int len = q.front().second;
            q.pop();

            // target word found
            if(word == endWord) return len;

            for(int i = 0; i<word.size(); i++){

                char c = word[i];

                // changing characters at i position
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    // modified word exists in set
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word,len+1});
                    }
                }

                word[i] = c;
            }
        }

        return 0;
    }
};