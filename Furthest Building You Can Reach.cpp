// nice problem on greedy and heap
class Solution {
public:
    // approach: to get optimal sol--- we want to use ladders where it has large diff and bricks fro small diff, so that we can optimally go to the furthest building
    int furthestBuilding(vector<int>& h, int bricks, int ladders)
    {
        int n = h.size();
        priority_queue<int>pq;
        int i = 0;
        for(i = 0; i < n - 1; i++)
        {
            if(h[i + 1] <= h[i])
            {
                continue;
            }
            int diff = h[i + 1] - h[i];
            if(diff <= bricks)
            {
                bricks -= diff;
                pq.push(diff);
            }
            else if(ladders > 0)
            {
                if(!pq.empty())
                {
                     int max_bricks_used = pq.top();
                    if(max_bricks_used > diff)
                    {
                        pq.pop();
                        bricks += max_bricks_used;
                        ladders--;
                        bricks -= diff;
                        pq.push(diff);
                    }
                    else 
                    {
                        ladders--;
                    }   
                }
                else
                {
                    ladders--;
                }
            }
            else 
            {
                break;
            }
        }
        return i;
    }
};

// sc o(n)
// tc o(n)
