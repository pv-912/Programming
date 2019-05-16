#include <iostream>
#include <cstring>

using namespace std;

void separateStringfromVector(){     // include numeric library
    vector<string> v{"Hello, ", " Cruel ", "World!"};
    string s;
    s = accumulate(begin(v), end(v), s);
    cout << s; // Will print "Hello, Cruel World!"
}

string sortString(string temp){
    vector<int> str;
    for(int i = 0; i < temp.size(); i++){
        str.push_back((int)temp[i]);
    }
    sort(str.begin(), str.end());
    string ans = "";
    for(int i = 0; i < str.size(); i++){
        ans = ans + (char)str[i];
    }
    
    return ans;
}

int splittingBySpace(const string a) {
    if(a.length() == 0){
        return 0;
    }
    string delimiter = " ";
    vector<string> res;
    std::istringstream iss(a);
    for(std::string a; iss >> a; ){
        res.push_back(a);
    }
    int size = res.size();
    if(size == 0)
    {
        return 0;
    }
    return res[size-1].length();
}

int main(){

}