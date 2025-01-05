//Question Link: https://leetcode.com/problems/russian-doll-envelopes/ 
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public: 
    int maxNestedEnvelopes(vector<vector<int>>& envelopes){
        int ans = 1;
        int maxI = envelopes[envelopes.size()-1][0];
        int maxJ = envelopes[envelopes.size()-1][1];

        for (int i = envelopes.size()-2; i > -1; i--)
        {
            cout<<"Max: "<<maxI<<" "<<maxJ<<endl;
            int curI = envelopes[i][0];
            int curJ = envelopes[i][1];
            cout<<"Current: "<<curI<<" "<<curJ<<endl;

            if (maxI == curI){
                cout<<"Not considering: "<<curI<<" "<<curJ<<endl;
                continue;
            }
            if(maxJ<curJ){
                cout<<"Not considering: "<<curI<<" "<<curJ<<endl;
                continue;
            }
            maxI = curI;
            maxJ = curJ;
            ans++;
        }
        
        return ans;
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end());
        for (int i = 0; i < envelopes.size(); i++)
        {
            cout<<"At "<<i<<": ";
            for (int j = 0; j < envelopes.at(i).size(); j++)
            {
                cout<<envelopes.at(i).at(j)<<" ";
            }
            cout<<endl;
        }
        int ans = maxNestedEnvelopes(envelopes);
        return ans;
    }
};

int main(){
    Solution S = Solution();
    vector<vector<int>> envelopes = vector<vector<int>>();
    envelopes.push_back({46, 89});
    envelopes.push_back({50, 53});
    envelopes.push_back({52, 68});
    envelopes.push_back({72, 45});
    envelopes.push_back({77, 81});
    cout<<"Maximum Nested Envelopes: "<<S.maxEnvelopes(envelopes);
}