#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

// aaram se code kro, nhi to bhoot glti hoga
// hm to khenge ki, step by step bdho or dhyan se kro

// agr ek logic kam nhi kr rha ya implement krna muskil hai to duskra try kro

class Trie{
	private:
	int ALPAHBET_SIZE;
	struct TrieNode{
		vector<TrieNode*> nodes;
		bool isEndOfWord;
	};
	TrieNode* root;

	TrieNode* GetNode(){
		TrieNode* newNode = new TrieNode();
		newNode->nodes.assign(ALPAHBET_SIZE,NULL);
		newNode->isEndOfWord = false;
		return newNode;
	}

	bool IsEmpty(TrieNode* node){
		for(int i = 0; i < ALPAHBET_SIZE; i++){
			if(node->nodes[i] != NULL)
				return false;
		}

		return node->isEndOfWord;
	}

	void Insert(TrieNode* root, string value){
		for(char c : value){
			int index = c - 'a';
			if(root->nodes[index] == NULL){
				root->nodes[index] = GetNode();
			}

			root = root->nodes[index];
		}

		root->isEndOfWord = true;
	}

	TrieNode* Remove(TrieNode* root, const string &value, int depth = 0){
		if(root == NULL)
			return root;
		
		if(depth == (int)value.length()){
			if(!root->isEndOfWord)
				return NULL;
			
			root->isEndOfWord = false;
			if(IsEmpty(root)){
				delete(root);
				return NULL;
			}
			return root;
		}

		int index = value[depth] - 'a';
		root->nodes[index] = Remove(root->nodes[index], value, depth + 1);

		if(IsEmpty(root)){
			delete(root);
			return NULL;
		}

		return root;
	}

	bool Search(TrieNode* root, string value){
		for(char c : value){
			int index = c - 'a';
			if(root->nodes[index] == NULL)
				return false;
			
			root = root->nodes[index];
		}

		return root->isEndOfWord;
	}

	public:
	Trie(int alphabetSize, vector<string> dict = vector<string>{}){
		ALPAHBET_SIZE = alphabetSize;
		root = GetNode();
		for(string s : dict)
			insert(s);
	}

	void insert(string value){
		Insert(root, value);
	}

	TrieNode* remove(string value){
		return Remove(root, value, 0);
	}

	bool search(string value){
		return Search(root, value);
	}
};

inline void solve()
{
	vector<string> dict{"shiv", "name", "shankar", "puja", "akanksha", "badmas"};
	class Trie st(26, dict);

	st.insert("something");
	for(string s : dict){
		cout<<s<<" is present "<<st.search(s)<<"\n";
	}

	cout<<"blandah is present "<<st.search("blandah")<<"\n";
	// st.remove("something");
	cout<<"something is present "<<st.search("something")<<"\n";
}

int32_t main()
{
    clock_t startTime;
    startTime = clock();
    int t = 1;
    while(t--){
        solve();
    }
    #ifdef LOCAL
        auto execution_time = [startTime]()->double{return (double)(clock() - startTime) / CLOCKS_PER_SEC;};
        printf("Execution time : %.3f ms", execution_time() * 1000);
    #endif
    return 0;
}
