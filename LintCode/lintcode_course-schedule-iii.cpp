/*
*
* Tag: Greedy
* Time: O(nlgn)
* Space: O(n)
*/
class Solution {
public:
    /*
     * @param : duration and close day of each course
     * @return: the maximal number of courses that can be taken
     */
    int scheduleCourse(vector<vector<int>> &courses) {
        if(courses.size() < 0)
            return 0;
        int curTime = 0;
        priority_queue<int> courseScheduler;
        
        sort(courses.begin(), courses.end(), [](vector<int> &a, vector<int> &b) {return a[1] < b[1];});
        
        for(int i = 0; i < courses.size(); ++ i) {
            curTime += courses[i][0];
            courseScheduler.push(courses[i][0]);
            if(curTime > courses[i][1]) {
                curTime -= courseScheduler.top();
                courseScheduler.pop();
            }
        }
        
        
        return courseScheduler.size();
    }
};
