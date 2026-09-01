class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);

        for(int i=0;i<prerequisites.size();i++){
            int course = prerequisites[i][0];
            int prerequisite = prerequisites[i][1];
            adj[prerequisite].push_back(course);
            indegree[course]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        int count =0;

        while(!q.empty()){
            int course = q.front();
            q.pop();
            count++;

            for(int i=0;i<adj[course].size();i++){
                int neighbour = adj[course][i];
                indegree[neighbour ]--;
                if(indegree[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }
        if(count == numCourses){
            return true;
        }
        return false;
    }
};