// FacebookHackerCupQ11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
#include <iterator>
#include <map>

using namespace std;

int main()
{
    //Creating a map that its key is char and its value is integer.
    map<char, int> map;

    string input;
    int vovelCt = 0, consonantCt = 0;
    cin >> input;
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
        if (x.first == 'A'||  x.first == 'E'||  x.first == 'I' || x.first == 'O'|| x.first == 'U') {
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
                if (x.first == 'A'||  x.first == 'E'||  x.first == 'I' || x.first == 'O' || x.first == 'U')
                {
                    result = result + (2 * x.second);
                }
                else {
                    result = result + x.second;
                }
            }
        }
    }
    cout << result;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file