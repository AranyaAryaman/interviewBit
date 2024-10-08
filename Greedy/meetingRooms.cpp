/*
Meeting rooms
Programming
Greedy Algorithm
medium
59.7% Success

375

19

Bookmark
Asked In:
Problem Description
 
 

Given an 2D integer array A of size N x 2 denoting time intervals of different meetings.

 

Where:

 

A[i][0] = start time of the ith meeting.
A[i][1] = end time of the ith meeting.
 

Find the minimum number of conference rooms required so that all meetings can be done.

Note :- If a meeting ends at time t, another meeting starting at time t can use the same conference room

 



Problem Constraints
1 <= N <= 105

 

0 <= A[i][0] < A[i][1] <= 2 * 109

 



Input Format
The only argument given is the matrix A.



Output Format
Return the minimum number of conference rooms required so that all meetings can be done.



Example Input
Input 1:

 A = [      [0, 30]
            [5, 10]
            [15, 20]
     ]

Input 2:

 A =  [     [1, 18]
            [18, 23]
            [15, 29]
            [4, 15]
            [2, 11]
            [5, 13]
      ]


Example Output
Output 1:

 2
Output 2:

 4


Example Explanation
Explanation 1:

 Meeting one can be done in conference room 1 form 0 - 30.
 Meeting two can be done in conference room 2 form 5 - 10.
 Meeting three can be done in conference room 2 form 15 - 20 as it is free in this interval.
Explanation 2:

 Meeting one can be done in conference room 1 from 1 - 18.
 Meeting five can be done in conference room 2 from 2 - 11.
 Meeting four can be done in conference room 3 from 4 - 15.
 Meeting six can be done in conference room 4 from 5 - 13.
 Meeting three can be done in conference room 2 from 15 - 29 as it is free in this interval.
 Meeting two can be done in conference room 4 from 18 - 23 as it is free in this interval.
*/

bool comp(int x, int y){
    if(abs(x)<abs(y))
        return true;
    else if(abs(x)>abs(y))
        return false;
    else
        return x<y;
}

int Solution::solve(vector<vector<int> > &A) {
    int ans = 0;
    vector<int> allTimes;
    for(int i=0;i<A.size();i++){
        allTimes.push_back(A[i][0]);
        allTimes.push_back(-1*A[i][1]);
    }
    sort(allTimes.begin(),allTimes.end(),comp);
    int curr = 0;
    for(int i=0;i<allTimes.size();i++){
        //cout<<allTimes[i]<<" ";
        if(allTimes[i]>=0)
            curr++;
        else
            curr--;
        //cout<<curr<<endl;
        ans = max(curr,ans);
    }
    return ans;
}=
