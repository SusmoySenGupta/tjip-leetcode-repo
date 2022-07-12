/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

// TC: O(N), where N = number of employees
// SC: O(N)
class Solution {
public:
    unordered_map<int, Employee*> emp_map;
    
    int findImportance(int ID) {
        auto emp = emp_map[ID];
        int total_imp = emp->importance;
        for (auto &id : emp->subordinates) {
            total_imp += findImportance(id); 
        }
        return total_imp;
    }
    
    int getImportance(vector<Employee*> employees, int id, int imp = 0) {
       for(auto &emp : employees){
            emp_map[emp->id] = emp;
        }
        return findImportance(id);
    }
};