class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int nowFuel = startFuel;
        int nextStop = 0;
        int stop = 0;
        priority_queue <int> fuels;
        
        for(; nextStop < stations.size(); nextStop++) {
            if(nowFuel < stations[nextStop][0])
                break;
            
            fuels.push(stations[nextStop][1]);
        }
        
        while(!fuels.empty() && nowFuel < target) {
            int refuel = fuels.top();
            fuels.pop();
            
            nowFuel += refuel;
            stop++;
            
            for(; nextStop < stations.size(); nextStop++) {
                if(nowFuel < stations[nextStop][0])
                    break;
                
                fuels.push(stations[nextStop][1]);
            }
        }
        
        if(nowFuel >= target)
            return stop;
        return -1;
    }
};