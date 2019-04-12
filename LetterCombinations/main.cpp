#include<iostream>
#include<vector>
#include<cstring>
#include<string>
using namespace std;

string map[10] ={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
class Solution {
	public:
	void _letterCombinations(const string& digits,size_t i,const string&combinstr,vector<string>&back){
		if(i==digits.size()){
			back.push_back(combinstr);
			return;
		}
		string strs = map[digits[i]-'0'];
		for(size_t j = 0;j<strs.size();++j){
			_letterCombinations(digits,i+1,combinstr+strs[j],back);
		}
	}
	vector<string> letterCombinations(string digits) {
		if(digits.empty())
			return vector<string>();
		size_t i = 0;
		vector<string> back;
		string combinstrstr;
		_letterCombinations(digits,i,combinstrstr,back);
		return back;
	}
};

int main(){
	Solution test;
	string a("327");
	vector<string> b = test.letterCombinations(a);
	for(size_t i= 0;i<b.size();i++){
			cout<<b[i].c_str()<<endl;
}
	return 0;
}
