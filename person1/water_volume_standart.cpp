#include<stack>
#include<iostream>
#include<math.h>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    stack<int> inds;
    for (int i = n - 1; i >= 0; i--)
        inds.push(arr[i]);

    int top_ind = -1;
    int volume = 0;

    for (int i = 0; i < n; i++) {
        while(inds.size() != 0 && arr[i] > arr[inds.top()]) {
            top_ind = inds.top();
            inds.pop();
            int dist = abs(i - inds.top());
            int min_height = abs(min(arr[i], arr[inds.top()]) - arr[top_ind]);
            volume += dist*min_height;
        }
    }

    cout << volume;
    return 0;
}