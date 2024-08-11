#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>
using namespace std;
//trie using maps...
class trie{
    public:
    char val;
    unordered_map<char,trie*> m;
    bool isTerminal;
    trie(char val){
        this->val = val;
        this->isTerminal = false;
    }
};
void insertW(trie* root,string word){
    //base case
    if(word.length() == 0){
        root->isTerminal = true;
        return;
    }
    char ch = word[0];
    trie* child;
    if(root->m.find(ch) == root->m.end()){
        //present nai hai
        child = new trie(ch);
        root->m[ch] = child;
    }
    else{
        //present hai
        child = root->m[ch];
    }
    word = word.substr(1);
    insertW(child,word);
}
bool findTrie(trie* root,string word){
    if(word.length() == 0)
        return root->isTerminal;
    char ch = word[0];
    trie* child;
    if(root->m.find(ch) == root->m.end()){
        //present nai hai
        return false;
    }
    else{
        //present hai
        child = root->m[ch];
    }
    word = word.substr(1);
    bool recAns = findTrie(child,word);
    return recAns;
}
void deleteTrie(trie* root,string word){
    if(word.length() == 0){
        root->isTerminal = false;
    }
    char ch = word[0];
    trie* child;
    if(root->m.find(ch) == root->m.end()){
        //present nai hai
        return ;
    }
    else{
        //present hai
        child = root->m[ch];
    }
    word = word.substr(1);
    deleteTrie(child,word);
}
void showR(string& ans,trie* root,string prefix,vector<string>& store){
    if(root->isTerminal){
        store.push_back(prefix+ans);
        
    }
    for(auto it: root->m){
        trie* next = it.second;
        if(next!=NULL){
            ans.push_back(it.first);
            showR(ans,next,prefix,store);
            ans.pop_back();
        } 
        else{
            return;
        }
    }
}
void findP(trie* root,string prefix,string ans,vector<string>& store){
    if(ans.length() == 0){
        trie* temp = root;
        showR(ans,root,prefix,store);
    }
    char ch = ans[0];
    trie* child ; 
    if(root->m.find(ch) == root->m.end()){
        return;
    }
    else{
        child = root->m[ch];
    }
    findP(child,prefix,ans.substr(1),store);
}
vector<vector<string> > suggest(trie* root,string input){
    vector<vector<string> > v;
    trie* prev = root;
    string helper = "";
    for(int i=0;i<input.length();i++){
        char ch = input[i];
        if(prev->m.find(ch) != prev->m.end()){
            //present
            trie* curr = prev->m[ch];
            vector<string> nans;
            string dummy = "";
            helper.push_back(ch);
            showR(helper,curr,dummy,nans);
            v.push_back(nans);
            prev = curr;
        }
    }
    return v;
}
int main(){
    trie* root = new trie('-');
    insertW(root,"laksh");
    insertW(root,"lak");
    insertW(root,"lakshya");
    insertW(root,"lakshman");
    insertW(root,"lakhan");
    insertW(root,"piyush");
    insertW(root,"python");
    vector<vector<string> > v = suggest(root,"lakshya");
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
