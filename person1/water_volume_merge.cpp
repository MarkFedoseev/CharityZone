#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int left_volume(vector<int>::iterator begin, vector<int>::iterator end) {
    if (begin == end)
        return 0;
    vector<int>::iterator max_elem = max_element(begin, end - 1);
    int anti_volume = 0;
    for (vector<int>::iterator iter = max_elem + 1; iter != end; iter++)
        anti_volume += *iter;
    return (end - max_elem - 1)*(*max_elem) - anti_volume + left_volume(begin, max_elem);
}
int right_volume(vector<int>::iterator begin, vector<int>::iterator end) {
    if (begin == end - 1)
        return 0;
    vector<int>::iterator max_elem = max_element(begin + 1, end);
    int anti_volume = 0;
    for (vector<int>::iterator iter = begin + 1; iter != max_elem; iter++)
        anti_volume += *iter;
    return (max_elem - begin - 1)*(*max_elem) - anti_volume + right_volume(max_elem, end);
}

int main() {

    int n = 0;
    cin >> n;

    vector<int> walls;

    for (int i = 0; i < n; i++) {
        int wall = 0;
        cin >> wall;
        walls.push_back(wall);
    }

    vector<int>::iterator max_elem = max_element(walls.begin(), walls.end());
    cout << left_volume(walls.begin(), max_elem) + right_volume(max_elem, walls.end());

    return 0;
}