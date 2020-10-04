#include<bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &hist) {
   

    stack<int> s;
    int n=hist.size();
    int max_area = 0;
    int tp; 
    int area_with_top;
 
    int i = 0;
    while (i < n)
    {
        if (s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);
 

        else
        {
            tp = s.top(); 
            s.pop();  
 
            area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
 
            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }
 

    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
 
        if (max_area < area_with_top)
            max_area = area_with_top;
    }
 
    return max_area;
}


int maximalRectangle(vector<vector<int> > &A) {
  
  int i,j,k,l,n=A.size(),m=A[0].size(),maxi=0;
  vector<int> vec(m,0);
     
  for(i=0;i<n;i++)
  {
      for(j=0;j<m;j++)
      {
         if(A[i][j]==0)
         vec[j]=0;
         else
         vec[j]+=1;
      }
      maxi=max(maxi,largestRectangleArea(vec));
  }
  return maxi;
}

int main(){
	
	int n,i,j,m,x;
	
	vector<vector<int> > vec;
	vector<int> arr;
	cin>>n>>m;
	
	for(i=0;i<n;i++){
		arr.clear();
		for(j=0;j<m;j++)
		{
			cin>>x;
			arr.push_back(x);
		}
		vec.push_back(arr);
	}
	
	cout<<maximalRectangle(vec);
	
	
	
}

