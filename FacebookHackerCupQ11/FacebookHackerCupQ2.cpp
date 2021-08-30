#include<iostream>
#include<vector>
#include <algorithm> 

using namespace std;

void main() {
	vector<char> board;
	int n;
	cin >> n;
	char x;
	int row = 0, column = 0;
	vector<int> operationCount;
	int counterX = 0,counterDot=0;


	for (int i = 1; i < (n * n) + 1; i++) {
		cin >> x;
		board.push_back(x);
	}
	for (int i = 1; i < (n * n + 1); i++) {
	    cout << board[i - 1];
	    if (i % n == 0)
	        cout << endl;
	}
	int temp = 0;
	for (int i = 1; i < (n +1); i++)//CONTROL COLUMN
	{
		if (board[i - 1] == '.'||board[i-1]=='X') {
			int x = i;
			while (x <= n*n && x>0)
			{
				if ( board[x-1]=='.') {
					counterDot++;
					temp = x;
				}

				else if (board[x-1] == 'O') {
					counterDot = 0;
					break;
				}
				x = x + n;
			}
			int tempCounter = 0;
			if(counterDot>0)
				operationCount.push_back(counterDot);
			if (counterDot == 1)
			{
				int row = (temp / n) + 1;
				for (int j = 0; j < n; j++) {
					if (board[((n * row) - n) + j] == '.') {
						tempCounter++;
					}
				}
				if (tempCounter == 1) {
					operationCount.pop_back();
				}
			}
			counterDot = 0;
		}
	}
	for (int i = 1; i < (n*n) + 1; i=i+n)//CONTROL HORÝZONTAL
	{
		if (board[i - 1] == '.' || board[i - 1] == 'X') {
			int x = i;
			while (x < n +i && x > 0)
			{
				if (board[x - 1] == '.') {
					counterDot++;
				}
				else if (board[x - 1] == 'O') {
					counterDot = 0;
					break;
				}
				x = x + 1;

			}
			if (counterDot > 0)
				operationCount.push_back(counterDot);
			counterDot = 0;
		}
	}
	int response = 0;
	int min = 0;
	if(operationCount.size()>0)
		min = *min_element(operationCount.begin(), operationCount.end());

	for (int i = 0; i < operationCount.size(); i++)
	{
		if (operationCount[i] == min) {
			response++;
		}
	}
	if (min>0)
	{

	}

	cout << endl << min <<"  " << response << endl;
}