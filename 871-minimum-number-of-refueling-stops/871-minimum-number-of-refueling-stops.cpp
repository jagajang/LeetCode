class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int nowFuel = startFuel;
        int nextStop = 0;
        int stop = 0;
        priority_queue <int> fuels;

        if(startFuel >= target)
            return 0;
        
        for(; nextStop < stations.size(); nextStop++) {
            if(nowFuel < stations[nextStop][0])
                break;
            
            fuels.push(stations[nextStop][1]);
        }
        
        while(!fuels.empty()) {
            int refuel = fuels.top();
            fuels.pop();
            
            nowFuel += refuel;
            stop++;
            
            if(nowFuel >= target) {
                return stop;
            }
            
            for(; nextStop < stations.size(); nextStop++) {
                if(nowFuel < stations[nextStop][0])
                    break;
                
                fuels.push(stations[nextStop][1]);
            }
        }
        
        return -1;
    }
};