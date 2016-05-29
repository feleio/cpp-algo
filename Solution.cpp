#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

struct Node{
    int num;
    int count;

    bool operator<(const Node& other) const{
        return count < other.count;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<Node> ans;
        unordered_map<int,int> pos;

        for(int i=0;i<nums.size();++i){
            unordered_map<int,int>::const_iterator target = pos.find(nums[i]);
            if(target == pos.end()){
                pos[nums[i]] = ans.size();
                Node node = {nums[i],1};
                ans.push_back(node);
            } else {
                int position = target->second;
                ++ans[position].count;
                while(position > 0 && ans[position].count > ans[(position-1)/2].count){
                    Node tmpNode = ans[position];
                    ans[position] = ans[(position-1)/2];
                    ans[(position-1)/2] = tmpNode;

                    pos[ans[position].num]= position;
                    pos[ans[(position-1)/2].num] = (position-1)/2;

                    position = (position-1)/2;
                }
            }
        }

        vector<int> rtn;
        for(int i=0;i<k&&!ans.empty();++i){
            rtn.push_back(ans.front().num);
            pop_heap(ans.begin(), ans.end());
            ans.pop_back();
        }

        return rtn;
    }
};
