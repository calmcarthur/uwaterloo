// clang++ -std=c++17 -Wall -Werror -Wextra -Wpedantic -g3 -o q5 q5.cpp

#include<string>
#include<iostream>

using namespace std;

auto IsStringInString (string masterstr, string babystr) -> bool
{
    auto wordpresent = false;
    int size1 = masterstr.size();
    int size2 = babystr.size();
    string masterword;
    for (int i=0; i <= size1-1; ++i ){
        auto currentmastervalue = masterstr[i];
        if (currentmastervalue == (babystr[0])){
            for (int j = 0; j <= (size2-1); ++j){
                masterword += masterstr[j+i];
            }
        if (masterword == babystr){
            wordpresent = true;
            break;
        } else{
            masterword = "";
            continue;
        }
        }
      
    }
    return wordpresent;
}

auto main() -> int
{
    int linesRead {0};
    string currentLine;
    string sourceString;
    string targetString;

    cout << boolalpha;

        while ( getline( cin, currentLine ) )
        {
        linesRead += 1;
        if ( ( linesRead % 2 ) == 1 ) { sourceString = currentLine; }
        else
        {
            targetString = currentLine;
            cout << sourceString << "\t" << targetString << "\t" << IsStringInString( sourceString, targetString ) << endl;
        }
    }
}