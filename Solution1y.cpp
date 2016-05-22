#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Node{
    int num;
    int count;
    Node(){
        num = 0;
        count = 0;
    }

    Node(const Node& other){
        num = other.num;
        count = other.count;
    }

    Node(int n, int c){
        num = n;
        count = c;
    }

    bool operator<(const Node& other) const{
        return count < other.count;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<Node> v;
        v.push_back(Node(1,4));
        v.push_back(Node(2,3));
        v.push_back(Node(3,2));
        v.push_back(Node(4,1));
        pop_heap(v.begin(), v.end());
        v.pop_back();

        for(int i=0;i<v.size();++i){
            cout << v[i].num << " " << v[i].count << endl;
        }
        cout << endl;
    }
};
