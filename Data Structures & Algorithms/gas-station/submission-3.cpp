class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        set<int> possibleIndices;
        for(int i = 0; i < gas.size(); ++i){
            if(gas[i] >= cost[i]){
                possibleIndices.insert(i);
            }
        }
    
        if(possibleIndices.empty()) return -1;

        int failIdx = -1;
        for(const int startIdx: possibleIndices){
            int jumps = gas.size() - 1;
            int j = startIdx;
            int availableGas = gas[j] - cost[j];
            while(jumps--){
                j = (j + 1) % gas.size();
                availableGas += gas[j];

                if(cost[j] > availableGas){
                    failIdx = j;
                    break;
                }
                availableGas -= cost[j];
            }
            if(jumps == -1) return startIdx;
        }
    
        return -1;
    }
};
