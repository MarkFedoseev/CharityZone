#include<vector>
#include<iostream>
#include<math.h>

using namespace std;


int calc_volume(vector<int>::iterator begin, vector<int>::iterator end) {

    if (begin + 1 == end)
        return 0;
    int anti_volume = 0;
    int fixed_anti_volume = 0;
    vector<int>::iterator max_height = begin + 1;

    vector<int>::iterator iter = begin + 1;
    for (; iter != end && *iter <= *begin; iter++) {
        anti_volume += *iter;
        if (*max_height <= *iter) {
            max_height = iter;
            fixed_anti_volume = anti_volume;
        }
    }
    if (iter == end)
        return (max_height - begin - 1)*(*max_height) - fixed_anti_volume + calc_volume(max_height, end);
    else
        return (iter - begin - 1)*(*begin) - fixed_anti_volume + calc_volume(iter, end);
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

    cout << calc_volume(walls.begin(), walls.end());

    return 0;
}