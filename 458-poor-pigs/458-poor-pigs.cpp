class Solution {
private:
    // [time][pigNum]
    long long nCr[11][11];
    long long canCheck[101][11];
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {        
        
        // fill nCr
        for(int n = 0; n < 11; n++) {
            nCr[n][0] = 1;

            for(int r = 1; r <= n; r++) {
                nCr[n][r] = nCr[n-1][r-1] + nCr[n-1][r];
            }
        }
        
        int checkTime = minutesToTest / minutesToDie;
        
        // init time 0, 1
        canCheck[0][0] = 1;
        canCheck[1][0] = 1;
        for(int p = 1; p < 11; p++) {
            canCheck[0][p] = 1;
            canCheck[1][p] = canCheck[1][p-1] * 2;
        }
        
        // calc time 2~
        for(int t = 2; t <= checkTime; t++) {
            canCheck[t][0] = 1;

            for(int p = 1; p < 11; p++) {
                canCheck[t][p] = 0;
                
                for(int r = 0; r <= p; r++)
                    canCheck[t][p] += nCr[p][r] * canCheck[t-1][p-r];
            }
        }
        
        for(int p = 0; p < 11; p++) {
            if(canCheck[checkTime][p] >= buckets)
                return p;
        }
        
        return -1;
    }
};


/*
1회 (확정)
돼지 몇마리가 살아남는 지 신경쓸 필요 없음
구분할 수 있는 영역의 개수
2^pig (각 돼지가 먹는다/안먹는다)


t회
살아남은 돼지로 남은 영역에 대해 (t-1)번 테스트 할 수 있음

1. 2^pig : pC0 * [t-1][p] + pC1 * [t-1][p-1] + ... 의 총합
2. n등분 : (죽는 경우) (p-1) * [p-1][t-1] + (안 죽는 경우) [p][t-1]

*/