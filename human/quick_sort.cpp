#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &vi, int low, int up)
{
    int pivot = vi[up];
    int i= low -1 ;
    for(auto j = low; j< up; j++){

        if(vi[j] <= pivot){
            i++;
            swap(vi[i], vi[j]);
        }

    }
    swap(vi[i+1], vi[up]);
    return i+1;
}
void quickSort(vector<int>&vi, int low, int up)
{
    if(low < up){
        int mid = partition(vi, low, up);

        quickSort(vi, low, mid-1);
        quickSort(vi, mid+1, up);

    }
}
void qSort(vector<int>&vi)
{
    quickSort(vi, 0, vi.size()-1);
}
int main()
{
	int a[] = {3,5,7,9,2,3,1,0,7,5,4};
    vector<int> va(a, a+1);
    qSort(va);

	cout<<"After quicksort:\n";
	for(auto x:va)
		cout<<x<<" ";
	cout<<endl;
    
    return 0;
    
}
