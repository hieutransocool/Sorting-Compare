//  HiuTranPro01
//  from -- Chuyen Nguyen Du Dak Lak -- UITer K18 
//  Nothing to say =)))
//

 
#include <chrono>
#include<bits/stdc++.h>
//#pragma GCC optimize("Ofast")
#define ll long long
#define N 100000
#define fi first
#define se second
#define BUG cout << "\n------------\n"
#define MODHASH 1001399111
#define pb(u) push_back(u)
#define TASK "test4"
#define ld long double
#define FAST cin.tie(0); cout.tie(0);  ios_base::sync_with_stdio(0);
using namespace std;
using namespace std::chrono;

ll dx[]={0,0,-1,1,-1,1,1,-1};
ll dy[]={-1,1,0,0,-1,1,-1,1};
typedef pair<ll,ll> ii;

const ll INF=(ll)1e15;
const ll mod=1000000007;

int n,m,numtest,k;
int arr[N + 10],b[N + 10];
int L[N + 10], M[N + 10];
int temp[N + 10];

void myswap(int a[], int b[])
{
  for (int i = 1; i <= N; i ++) b[i] = a[i];
}


void merge(int p, int q, int r) {
  
  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;


  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int l, int r) {
  if (l < r) {
    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(l, m);
    mergeSort(m + 1, r);

    // Merge the sorted subarrays
    merge(l, m, r);
  }
}

/////////////////////////////////

int partition(int start, int end)
{
 
     int index = 0, pivotElement = arr[(end - start + 1) / 2 + start], pivotIndex;
    for (int i = start; i <= end; i++) // pushing all the elements in temp which are smaller than pivotElement
    {
        if(arr[i] < pivotElement)
        {
            temp[index] = arr[i];
            index++;
        }
    }
 
    temp[index] = pivotElement; // pushing pivotElement in temp
    index++;
 
    for (int i = start; i < end; i++) // pushing all the elements in temp which are greater than pivotElement
    {
        if(arr[i] > pivotElement)
        {
            temp[index] = arr[i];
            index++;
        }
    }
  // all the elements now in temp array are order : 
  // leftmost elements are lesser than pivotElement and rightmost elements are greater than pivotElement
               
     
     
    index = 0;
    for (int i = start; i <= end; i++) // copying all the elements to original array i.e arr
    {   
        if(arr[i] == pivotElement)
        {
              // for getting pivot index in the original array.
              // we need the pivotIndex value in the original and not in the temp array
            pivotIndex = i;
        }
        arr[i] = temp[index];
        index++;
    }
    return pivotIndex; // returning pivotIndex
}

int cnt = 0;
 
void quickSort(int start, int end)
{
    // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition(start, end);
 
    // Sorting the left part
    quickSort(start, p - 1);
 
    // Sorting the right part
    quickSort(p + 1, end);
}



////////////////////


void heapify(int NN, int i)
{
 
    // Initialize largest as root
    int largest = i;
 
    // left = 2*i + 1
    int l = 2 * i + 1;
 
    // right = 2*i + 2
    int r = 2 * i + 2;
 
    // If left child is larger than root
    if (l < NN && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest
    // so far
    if (r < NN && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected
        // sub-tree
        heapify(NN, largest);
    }
} 
// Main function to do heap sort
void heapSort(int NN)
{
 
    // Build heap (rearrange array)
    for (int i = N / 2 - 1; i >= 1; i--)
        heapify(N, i);
 
    // One by one extract an element
    // from heap
    for (int i = N - 1; i > 1; i--) {
 
        // Move current root to end
        swap(arr[1], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(i, 0);
    }
}

void solve()
{
  cout << TASK << endl;
  myswap(arr,b);

   {
	      auto start = high_resolution_clock::now();
        quickSort(1,N);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Quicksort: "<< duration.count() << " microseconds" << endl;
    }

    myswap(b,arr);

    {
        auto start = high_resolution_clock::now();
        mergeSort(1,N);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Mergesort" << ": " << duration.count() << " microseconds" << endl;
    }

    
    myswap(b,arr);

    {
        auto start = high_resolution_clock::now();
        sort(arr + 1,arr + 1 + N);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "C++ sort" << ":  " << duration.count() << " microseconds" << endl;    
    }

    
    myswap(b,arr);

    {    
        auto start = high_resolution_clock::now();
        heapSort(N + 1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Heapsort" << ":  " << duration.count() << " microseconds" << endl;    
    }

}

int main()
{
	    FAST

        
        freopen(TASK".inp","r",stdin);
        freopen(TASK".out","w",stdout);
        //srand(time(NULL));
        //for (int i = 1; i <= N; i++)  cout << rand() % mod << " ";
        for (int i = 1; i <= N; i++)    cin >> arr[i];
        //sort(arr + 1, arr + 1 + n);
        //cout << arr[1];
        solve();

        
        
        


        




return 0;

//----WA
//-try special case:0,1,<0,n...
//-limit of n,a[i],....
//-wrong approach,try st new
//-check the kind of ouput answer

//----TLE
//-same name of variable
//-limit of n,a[i]....
//-wrong approach,try st new
//-repeat inf in special case

//--AC --> ^_Congratulation_^
	


}
