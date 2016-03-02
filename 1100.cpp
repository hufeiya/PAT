#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <sstream>

using namespace std;

bool isNum(string str)
{
    stringstream sin(str);
    int d;
    char c;
    if(!(sin >> d))
        return false;
    if (sin >> c)
        return false;
    return true;
}

int main() {
    int n;
    vector<string> bit1 = {"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    vector<string> bit2 = {"null","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

    while(cin>>n) {
        string nothing;
        getline(cin,nothing);
        for(int i = 0;i < n;i++) {
            string s;
            getline(cin,s);
            if(isNum(s)) {
                string result1,result2;
                stringstream sin(s);
                int d;
                sin >> d;
                result1 = bit2.at(d/13);
                result2 = bit1.at(d % 13);
                if(d < 13){
                    cout<<result2<<endl;
                }
                else {
                    if(d % 13 == 0){
                        cout<<result1<<endl;
                    }else{
                        cout<<result1<<" "<<result2<<endl;
                    }

                }
            }
            else
            {
                string s1,s2;
                int spaceIndex = -1;
                int theSecondStringStartIndex = -1;
                for(int i = 0; i < s.length();i++){
                    if(s[i] == ' '){
                        spaceIndex = i;
                    }
                    if(spaceIndex != -1 && s[i] != ' '){
                        theSecondStringStartIndex = i;
                        break;
                    }
                }
                if(spaceIndex == -1){
                    int result = -1;
                    for(int i = 0; i < bit1.size();i++){
                        if(s.compare(bit1[i]) == 0){
                            result = i;
                            break;
                        }
                    }
                    if(result != -1){
                        cout<<result<<endl;
                    }else{
                        for(int i = 0; i < bit2.size();i++){
                            if(s.compare(bit2[i]) == 0){
                                result = i;
                                break;
                            }
                        }
                        cout<<result * 13<<endl;
                    }
                }else{
                    s1 = s.substr(0,spaceIndex);
                    s2 = s.substr(theSecondStringStartIndex,s.length() - spaceIndex);
                    int result1,result2;
                    for(int i = 0; i < bit2.size();i++){
                        if(s1.compare(bit2[i]) == 0){
                            result1 = i;
                            break;
                        }
                    }
                    for(int i = 0; i < bit1.size();i++){
                        if(s2.compare(bit1[i]) == 0){
                            result2 = i;
                            break;
                        }
                    }
                    cout<<result1*13 + result2<<endl;
                }
            }
        }
    }
    return 0;
}

