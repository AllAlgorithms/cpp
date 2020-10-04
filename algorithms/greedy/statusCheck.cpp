// The sum of all factorials of n!
#include<iostream>

using namespace std;

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

void swapc(char* a, char* b){
    char t = *a;
    *a = *b;
    *b = t;
}

void heapify(int start[], int finish[], char status[], int n, int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && finish[l] > finish[largest])
        largest = l;

    if (r < n && finish[r] > finish[largest])
        largest = r;

    if (largest != i){
        swap(&finish[i], &finish[largest]);
        swap(&start[i], &start[largest]);
        swapc(&status[i], &status[largest]);
        heapify(start, finish, status, n, largest);
    }
}

void sort(int start[], int finish[], char status[], int n){
  for (int i = n / 2 - 1; i >= 0; i--)
        heapify(start, finish, status, n, i);

    for (int i=n-1; i>=0; i--){
        swap(&finish[0], &finish[i]);
        swap(&start[0], &start[i]);
        swapc(&status[0], &status[i]);
        heapify(start, finish, status, i, 0);
    }
}

int maxFinishTime(int finish[], int n){
	int max = 0;
	for(int i=0;i<n;i++)
		if(finish[i] > max)
			max = finish[i];
	return max;
}

int status_check(int s[], int f[], char st[], int n) {

  //find the maximum finish time among all process
  int N = maxFinishTime(f, n) + 1;

  //count stores whether status_check() is invoked, if yes count[i] = 1, else count[i] = 0
  int count[N];

  //initialize count to 0 initially
  for(int i=0;i<N;i++)
	  count[i] = 0;

  int i, j;

  //keep track of each process for status_check()
  int pid[n];

  // Initialize all pid to 0
  for(int i=0;i<n;i++)
	  pid[i] = 0;

  i = 0;
  int timeF = 0;;

  // Consider rest of the activities
  for (j = 1; j < n; j++){
    // If this activity has start time greater than or
    // equal to the finish time of previously selected
    // activity, then select it
    if(s[j] == f[i]){

        //last status check
  	  int lastStatusCheck = 0;
  	  for(int k=N-1;k>=0;k--){
  		  if(count[k] == 1){
  			  lastStatusCheck = k;
  			  break;
  		  }
  	  }

      if(pid[i] == 0){
        count[f[i]] = 1;
    		timeF = f[i];
    		pid[i] = 1;
    		pid[j] = 1;
      }

  	  else if(pid[j] == 0 && timeF != lastStatusCheck){
        count[f[j]] = 1;
    		timeF = f[j];
    		pid[j] = 1;
  	  }
    }

    //overlap
    else if(f[i] >= s[j] && s[i] != s[j]){
      //if status is S i.e. 'Sensitive' apply status_check()
      if(timeF < f[i]){
        count[f[i]] = 1;
        timeF = f[j];
        pid[i] = 1;
        pid[j] = 1;
      }
    }

    //no overlap
    else{
      if(timeF < f[i] && s[i] != s[j]){
        count[f[i]] = 1;
        timeF = f[i];
        pid[i] = 1;
        pid[j] = 1;
      }
    }
    i++;
  }
  cout<<endl;
  //count the number of status_check()
  int ch = 0;
  for(int i=0;i<N;i++)
	  ch+=count[i];
  for(int i=0;i<N;i++)
	  cout<< count[i]<< " ";
  cout<<endl;
  return ch;
}

int main(){
  int n;
  cout <<"Enter the number of process"<<endl;
  cin>>n;
  int start[n];
  int finish[n];
  char status[n];
  for(int i=0;i<n;i++){
    cout<<"Enter the start time, finish time, and status of process %d"<<i<<endl;
    cin>>start[i] >> finish[i] >> status[i];
  }

  //sort in non-decreasing order of finish time
  sort(start, finish, status, n);

  //check for conflict
  int check  = status_check(start, finish, status, n);

  cout<<"Number of times status_check() is invoked is %d"<<check;
  return 0;
}
