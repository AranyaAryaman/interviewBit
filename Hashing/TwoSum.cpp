/*
2 Sum
Programming
Hashing
easy
44.4% Success

207

19

Bookmark
Asked In:
Problem Description
 
 

Given an array of integers, find two numbers such that they add up to a specific target number.

 

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 < index2. Please note that your returned answers (both index1 and index2 ) are not zero-based. Put both these numbers in order in an array and return the array from your function ( Looking at the function signature will make things clearer ). Note that, if no pair exists, return an empty list.

If multiple solutions exist, output the one where index2 is minimum. If there are multiple solutions with the minimum index2, choose the one with minimum index1 out of them.



Problem Constraints
1 <= |A| <= 105
-108 <= Ai <= 108
-108 <= B <= 108


Input Format
The first argument is an integer array A.
The second argument is an integer B.


Output Format
Return an array of integer, representing the answer


Example Input
A: [2, 7, 11, 15]
B: 9


Example Output
[1, 2]

*/

vector<int> Solution::twoSum(const vector<int> &A, int B) {
    vector<int> ans;
    unordered_map<int,int> myMap;
    int firstIndex=-1;
    int secondIndex = -1;
    myMap.insert(make_pair(A[0],0));
    for(int i=1;i<A.size();i++){
        if(myMap.find(B-A[i])==myMap.end()){
            if(myMap.find(A[i])==myMap.end())
                myMap[A[i]]=i;
        }
        else{
            firstIndex = myMap[B-A[i]];
            secondIndex = i;
            break;
        }
    }
    if(secondIndex!=-1 && firstIndex != -1){
        ans.push_back(firstIndex+1);
        ans.push_back(secondIndex+1);
    }
    return ans;
}
