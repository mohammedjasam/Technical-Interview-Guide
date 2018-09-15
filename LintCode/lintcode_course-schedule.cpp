/*
*
* Tag: Graph
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    /*
     * @param numCourses: a total of n courses
     * @param prerequisites: a list of prerequisite pairs
     * @return: true if can finish all courses or false
     */
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        bool finish = true;
        if(numCourses <= 1)
            return finish;
            
        unordered_map<int, unordered_set<int>> coursesDependencyGraph = buildCoursesDependencyGraph(prerequisites);
        
        vector<int> numDependenciesOfCourses = getListOfNumOfDependedCourses(numCourses, coursesDependencyGraph);
        
        finish = canFinishAllCourses(numCourses, coursesDependencyGraph, numDependenciesOfCourses);
        
        return finish;
    }
    
private:
    unordered_map<int, unordered_set<int>> buildCoursesDependencyGraph( vector<pair<int, int>>& prerequisites ) {
        unordered_map<int, unordered_set<int>> coursesDependencyGraph;
        
        for(int i = 0; i < prerequisites.size(); ++ i){
            int nextCourse = prerequisites[i].first, curCourse = prerequisites[i].second;
            coursesDependencyGraph[curCourse].insert(nextCourse);
        }
         
        return coursesDependencyGraph;
    }
    
    vector<int> getListOfNumOfDependedCourses( int numCourses, unordered_map<int, unordered_set<int>> &coursesDependencyGraph ) {
        vector<int> numDependenciesOfCourses(numCourses, 0);
        
        for(int i = 0; i < numCourses; ++ i){
            int curFinishedCourse = i;
            for(auto it = coursesDependencyGraph[curFinishedCourse].begin(); it != coursesDependencyGraph[curFinishedCourse].end(); ++ it) {
                int nextAttendedCourse = *it;
                ++ numDependenciesOfCourses[nextAttendedCourse];
            }
            
        }
        
        return numDependenciesOfCourses;
    }
    
    bool canFinishAllCourses( int numCourses, unordered_map<int, unordered_set<int>> &coursesDependencyGraph, vector<int> &numDependenciesOfCourses ){
        int numFinishedCourses = 0;
        queue<int> topoSortQueue;
        
        for(int i = 0; i < numCourses; ++ i){
            if(numDependenciesOfCourses[i] == 0)
                topoSortQueue.push(i);
        }
        
        while(!topoSortQueue.empty()) {
            ++ numFinishedCourses;
            int curFinishedCourse = topoSortQueue.front();
            topoSortQueue.pop();

            for(auto it = coursesDependencyGraph[curFinishedCourse].begin(); it != coursesDependencyGraph[curFinishedCourse].end(); ++ it) {
                int nextAttendedCourse = *it;
                -- numDependenciesOfCourses[nextAttendedCourse];
                if(numDependenciesOfCourses[nextAttendedCourse] == 0) {
                    topoSortQueue.push(nextAttendedCourse);
                }
            }
        }
        
        return numFinishedCourses == numCourses;
    }
};
