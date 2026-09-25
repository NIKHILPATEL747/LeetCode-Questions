class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        int sx, sy;
        vector<pair<int,int>> litter;
        
      
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(classroom[i][j]=='S'){ sx=i; sy=j; }
                if(classroom[i][j]=='L') litter.push_back({i,j});
            }
        }
        
        int fullMask = (1<<litter.size()) - 1;
        queue<tuple<int,int,int,int,int>> q; 
        q.push({sx, sy, 0, energy, 0});
        
        vector<vector<vector<int>>> best(m, vector<vector<int>>(n, vector<int>(1<<litter.size(), -1)));
        best[sx][sy][0] = energy;
        
        int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        
        while(!q.empty()){
            auto [x,y,mask,e,steps] = q.front(); q.pop();
            if(mask==fullMask) return steps;
            
            for(auto &d:dirs){
                int nx=x+d[0], ny=y+d[1];
                if(nx<0||ny<0||nx>=m||ny>=n||classroom[nx][ny]=='X') continue;
                int ne=e-1;
                if(ne<0) continue;
                int nmask=mask;
                if(classroom[nx][ny]=='L'){
                    for(int k=0;k<litter.size();k++){
                        if(litter[k].first==nx && litter[k].second==ny) nmask|=(1<<k);
                    }
                }
                if(classroom[nx][ny]=='R') ne=energy;
                if(best[nx][ny][nmask]>=ne) continue;
                best[nx][ny][nmask]=ne;
                q.push({nx,ny,nmask,ne,steps+1});
            }
        }
        return -1;
    }
};
