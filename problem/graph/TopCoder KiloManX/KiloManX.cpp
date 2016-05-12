#include <iostream>
#include <cstring>
#include <queue>
#include <math.h>

using namespace std;

class Node{
public:
    Node(int n)
    : m_bossDead(n , false), m_maxDamage(n, 1), m_cost(0){}

    Node(const char** weaponChart, const vector<bool>& bossDead, const vector<int>& maxDamage, const int bossKill, const int cost)
    : m_bossDead(bossDead.size() , false), m_maxDamage(bossDead.size(), 1), m_cost(cost){
        for(int i=0;i<bossDead.size();++i){
            m_bossDead[i] = bossDead[i];
            if(weaponChart[bossKill][i] - '0' > maxDamage[i])
                m_maxDamage[i] = weaponChart[bossKill][i]  - '0';
            else
                m_maxDamage[i] = maxDamage[i];
        }
        m_bossDead[bossKill] = true;
    }

    bool operator<(const Node& rhs) const{
        return m_cost < rhs.m_cost;
    }

    bool operator>(const Node& rhs) const{
        return m_cost > rhs.m_cost;
    }

    bool isAllDead(){
        for(int i=0;i<m_bossDead.size();++i){
            if(!m_bossDead[i])
                return false;
        }
        return true;
    }

    vector<bool> m_bossDead;
    vector<int> m_maxDamage;
    int m_cost;
};

long convertToInt(const vector<bool>& bossDead){
    long rtn = 0;
    for(int i=0;i<bossDead.size();++i){
        if(bossDead[i])
            rtn += 1L << i;
    }
    return rtn;
}

int solve(const char** weaponChart, const int* bossHP, int n){
    vector<bool> visited(pow(2, n), false);
    priority_queue<Node, vector<Node>, greater<Node> > pq;
    Node start(n);
    pq.push(start);
    while(!pq.empty()){
        Node node = pq.top();
        pq.pop();

        if(node.isAllDead()){
            return node.m_cost;
        }

        if(visited[convertToInt(node.m_bossDead)]){
            continue;
        }

        visited[convertToInt(node.m_bossDead)] = true;
        for(int i=0;i<n;++i){
            if(!node.m_bossDead[i]){
                int shotToKill = bossHP[i] / node.m_maxDamage[i];
                if(bossHP[i] % node.m_maxDamage[i] > 0)
                    ++shotToKill;
                pq.push(Node(weaponChart, node.m_bossDead, node.m_maxDamage, i, node.m_cost + shotToKill));
            }
        }
    }
    return -1;
}

int main(){
//     const char* weaponChart[] = {"198573618294842",
//  "159819849819205",
//  "698849290010992",
//  "000000000000000",
//  "139581938009384",
//  "158919111891911",
//  "182731827381787",
//  "135788359198718",
//  "187587819218927",
//  "185783759199192",
//  "857819038188122",
//  "897387187472737",
//  "159938981818247",
//  "128974182773177",
//  "135885818282838"};
//     const int bossHP[] = {157, 1984, 577, 3001, 2003, 2984, 5988, 190003,
// 9000, 102930, 5938, 1000000, 1000000, 5892, 38};


 //    const char* weaponChart[] = {"02111111", "10711111", "11071111", "11104111",
 // "41110111", "11111031", "11111107", "11111210"};
 //    const int bossHP[] = {28,28,28,28,28,28,28,28};

     const char* weaponChart[] = {"07", "40"};
     const int bossHP[] = {150,10};

    // const char* weaponChart[] = {"07", "40"};
    //  const int bossHP[] = {150,10};



    // const char* weaponChart[] = {"07", "40"};
    // const int bossHP[] = {150,10};

    int n = sizeof(bossHP) / sizeof(int);

    cout << solve(weaponChart, bossHP, n) << endl;
}

