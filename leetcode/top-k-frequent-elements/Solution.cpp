#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node{
    int num;
    int count;
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<Node> ans;
        unordered_map<int,int> pos;

        for(int i=0;i<nums.size();++i){
            unordered_map<int,int>::const_iterator target = pos.find(nums[i]);
            if(target == pos.end()){
                pos[nums[i]] = 1;
                Node node = {nums[i],1};
                ans.push_back(node);
            } else {
                int position = target->second;

                while(position > 0 && ans[position].count > ans[position-1].count){
                    Node tmpNode = ans[position];
                    ans[position] = ans[position-1];
                    ans[position-1] = tmpNode;

                    pos[ans[position].num]= position;
                    pos[ans[position-1].num] = position - 1;

                    --position;
                }
            }
        }

        vector<int> rtn;
        for(int i=0;i<k;++i){
            rtn.push_back(ans[i].num);
        }

        return rtn;
    }
};

int main(){
    
}