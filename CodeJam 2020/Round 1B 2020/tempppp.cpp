// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
#include<unordered_map>
#include<algorithm>
vector<pair<int, int> > optimalUtilization(
                            int deviceCapacity,
							vector<pair<int, int> > foregroundAppList,
							vector<pair<int, int> > backgroundAppList)
{
    // WRITE YOUR CODE HERE

    vector< pair<int, int> > result;

    if(foregroundAppList.size() == 0 || backgroundAppList.size()==0) {
        result.push_back({});
        return result;
    }

    unordered_map<int,int> forgrounAppMemoriesMapping;
    vector<int> forgrounAppMemories;
    for(int i = 0; i< (int)foregroundAppList.size();i++) {
        forgrounAppMemories.push_back(foregroundAppList[i].second);
        forgrounAppMemoriesMapping[foregroundAppList[i].second] = foregroundAppList[i].first;
    }

    sort(forgrounAppMemories.begin(), forgrounAppMemories.end());

    int mxUsableMemory = foregroundAppList[0].second + backgroundAppList[0].second;
    for(int i = 0;i<(int) backgroundAppList.size();i++) {
        int memory = backgroundAppList[i].second;
        int upperIndex = upper_bound(forgrounAppMemories.begin(), forgrounAppMemories.end(), deviceCapacity-memory)-forgrounAppMemories.begin();
        upperIndex--;
        if(upperIndex < forgrounAppMemories.size()) {
            mxUsableMemory = max(mxUsableMemory, forgrounAppMemories[upperIndex] + memory);
        }
    }

    for(int i = 0; i< backgroundAppList.size() ;i++) {
        int memory = backgroundAppList[i].second;
        int id = backgroundAppList[i].first;
        if(forgrounAppMemoriesMapping.find(mxUsableMemory-memory)!= forgrounAppMemoriesMapping.end()) {
            result.push_back(make_pair(forgrounAppMemoriesMapping[mxUsableMemory-memory], id));
        }
    }

    return result;
}
// FUNCTION SIGNATURE ENDS
