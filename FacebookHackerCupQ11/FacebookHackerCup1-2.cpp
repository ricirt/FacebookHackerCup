// FacebookHackerCupQ11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iterator>
#include <map>
#include<vector>

using namespace std;
int calculateOperationCount(map<char, int> , string ,vector<string> );

int main()
{
    //Creating a map that its key is char and its value is integer.
    map<char, int> Umap;
    map<char, int> mapRules;
    string input;
    cin >> input;
    vector<string> constraints;


    for (auto i : mapRules) {
        cout << i.first + "  " << i.second << endl;
    }
    while (true)//while stirng not consistent
    {
        for (int i = 0; i < mapRules.size();i++) {

        }
    }

    cout<<calculateOperationCount(Umap, input,constraints);

}
int calculateOperationCount(map<char,int> map,string input,vector<string> constraints) {
    int vovelCt = 0, consonantCt = 0;
    map.insert(pair<char, int>(input[0], 1));
    for (int i = 1; i < input.size(); i++)
    {
        if (map.find(input[i]) == map.end() && (input[i] == 'A' || input[i] == 'E' || input[i] == 'I' || input[i] == 'O' || input[i] == 'U')) {
            map.insert(pair<char, int>(input[i], 1));
            vovelCt++;
        }
        else
            map[input[i]]++;
    }
    consonantCt = map.size() - vovelCt;

    char foundV = '\0', foundC = '\0';
    int maxV = 0, maxC = 0;
    for (auto x : map) {
        if (x.first == 'A' || x.first == 'E' || x.first == 'I' || x.first == 'O' || x.first == 'U') {
            if (x.second >= maxV) {
                maxV = x.second;
                foundV = x.first;
            }
        }
        else {
            if (x.second >= maxC) {
                maxC = x.second;
                foundC = x.first;
            }
        }
    }
    int result = 0;
    for (auto x : map)
    {
        if (vovelCt > consonantCt) {
            if (x.first != foundC) {
                //if (count(constraints.begin(), constraints.end(), x.first)) {
                //    string firstStr = constraints[0];
                //    //firstStr[0];
                //}
                //else 
                if (x.first == 'A' || x.first == 'E' || x.first == 'I' || x.first == 'O' || x.first == 'U')
                {
                    result = result + x.second;
                }
                else {
                    result = result + (2 * x.second);
                }
            }
        }
        else {
            if (x.first != foundV) {
                if (x.first == 'A' || x.first == 'E' || x.first == 'I' || x.first == 'O' || x.first == 'U')
                {
                    result = result + (2 * x.second);
                }
                else {
                    result = result + x.second;
                }
            }
        }
    }
    return result;
}
