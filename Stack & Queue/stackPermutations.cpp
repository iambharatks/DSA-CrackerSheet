#include <bits/stdc++.h>

using namespace std;

bool isStackPermutations(vector<int> inputArray, vector<int> outputArray)
{
    queue<int> inputQ, outputQ;
    for (int i : inputArray)
        inputQ.push(i);
    for (int i : outputArray)
        outputQ.push(i);
    stack<int> tmpS;
    while (!inputQ.empty())
    {
        int ele = inputQ.front();
        inputQ.pop();
        if (ele == outputQ.front())
        {
            outputQ.pop();
            while (!tmpS.empty() && tmpS.top() == outputQ.front())
            {
                tmpS.pop();
                outputQ.pop();
            }
        }
        else
            tmpS.push(ele);
    }
    return tmpS.empty() && inputQ.empty();
}
int main()
{
    int n;
    cin >> n;
    vector<int> inputArray(n), outputArray(n);
    for (int &i : inputArray)
        cin >> i;
    for (int &i : outputArray)
        cin >> i;
    if (isStackPermutations(inputArray, outputArray))
        cout << "Possible\n";
    else
        cout << "Impossible\n";
}