/*
*
* Tag: Data Structure
* Time: O(n)
* Space: O(n)
*/

#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <cmath>
#include <ctype.h>
#include <climits>
#include <utility>
#include <assert.h>
using namespace std;

typedef void(*Fun)(void);

class FileSystem {
private:
    unordered_map<string,int> fileMap;
    unordered_map<string,Fun> funMap;
public:
    FileSystem() {
        fileMap[""] = 0;
    }
    
    bool create(string path, int val){
        if(path.size() == 0){
            return false;
        }
        
        string curPath = path;
        while(curPath.size() > 0) {
            int index = curPath.find_last_of('/');
            string dirPath = index <= 0 ? "" : curPath.substr(0, index);
            //cout<<index<<" vs "<<dirPath<<endl;
            if(fileMap.count(dirPath) == 0){
                return false;
            }
            
            curPath = index <= 0 ? "" : curPath.substr(0, index);
        }
        
        fileMap[path] = val;
        return true;
    }
    
    int get(string path){
        if(fileMap.count(path) == 0) {
            return -1;
        }
        
        return fileMap[path];
    }
    
    bool set(string path, int val) {
        if(fileMap.count(path) == 0){
            return false;
        }
        
        fileMap[path] = val;
        
        string curPath = path;
        while(curPath.size() > 0){
            if(funMap.count(curPath) != 0) {
                funMap[curPath]();
            }
            
            int index = curPath.find_last_of('/');
            curPath = curPath.substr(0, index);
        }
        
        return true;
    }
    
    bool watch(string path, Fun fun){
        if(fileMap.count(path) == 0){
            return false;
        }
        
        funMap[path] = fun;
        return true;
    }
};

void test1(){
    cout<<"test1"<<endl;
}

void test2(){
    cout<<"test2"<<endl;
}

int main() {
    FileSystem fs;
    cout<<fs.create("/a",1)<<endl;
    cout<<fs.create("/a/b",2)<<endl;
    cout<<fs.get("/a/b")<<endl;
    cout<<fs.create("/a/c",3)<<endl;
    cout<<fs.create("/a/c/d",4)<<endl;
    cout<<fs.create("/a/c/d/e",4)<<endl;
    cout<<fs.get("/a/b/c/d")<<endl;
    cout<<fs.get("/a/c/d")<<endl;
    cout<<fs.watch("/a",&test1)<<endl;
    cout<<fs.watch("/a/b",&test2)<<endl;
    cout<<fs.set("/a/b",5)<<endl;
    cout<<fs.get("/a/b")<<endl;
    return 0;
}
