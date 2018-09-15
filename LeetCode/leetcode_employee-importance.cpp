/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
*/
/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
private:
    int totalImportance;
    unordered_map<int, Employee*> employeeInfo;
public:
    int getImportance(vector<Employee*> employees, int id) {
        totalImportance = 0;
        if(employees.size() == 0){
            return totalImportance;
        }
        
        employeeInfo.clear();       
        for(Employee *employee : employees){
            employeeInfo[employee->id] = employee;
        }
        
        dfs(id);
        
        return totalImportance;
    }
    
private:
    void dfs(int employeeId){
        totalImportance += employeeInfo[employeeId]->importance;
        
        for(int subordinate : employeeInfo[employeeId]->subordinates){
            dfs(subordinate);
        }
    }
};
