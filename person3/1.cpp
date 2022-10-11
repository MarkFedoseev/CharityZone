#include <vector>
#include <set>
#include <iostream>
#include <limits.h>

using namespace std;


struct test {
    int a[(int)(INT_MAX / 2)] = {1};
};

int main() {
    vector<int> vec1;
    set<int> caps1;
    caps1.insert(vec1.capacity());
    for (int i = 0; i < 10000; i++) {
        vec1.push_back(0);
        caps1.insert(vec1.capacity());
    }
    cout << "growth from 0" << endl;
    for (set<int>::iterator iter = caps1.begin(); iter != caps1.end(); iter ++)
        cout << *iter << " ";
    //SUMMARY: starts with 1 then grow x2

    cout << endl;

    vector<int> vec2 = {1, 2, 3};
    set<int> caps2;
    caps2.insert(vec2.capacity());
    for (int i = 0; i < 10000; i++) {
        vec2.push_back(0);
        caps2.insert(vec2.capacity());
    }
    cout << "growth from const" << endl;
    for (set<int>::iterator iter = caps2.begin(); iter != caps2.end(); iter ++)
        cout << *iter << " ";
    //SUMMARY: starts with const then grow x2

    cout << endl;

    vector<int> vec3;
    vec3.reserve(3);
    set<int> caps3;
    caps3.insert(vec3.capacity());
    for (int i = 0; i < 10000; i++) {
        vec3.push_back(0);
        caps3.insert(vec3.capacity());
    }
    cout << "growth from const reserve" << endl;
    for (set<int>::iterator iter = caps3.begin(); iter != caps3.end(); iter ++)
        cout << *iter << " ";
    //SUMMARY: starts with const then grow x2

    return 0;
}