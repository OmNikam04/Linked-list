#include<bits/stdc++.h>
using namespace std;

bool binary(int *a, int lo, int hi, int key){
    if(lo>hi){
        return false;
    }
    else{
        int mid = (hi+lo)/2;
        if(a[mid]== key){
            return true;
        }
        else if(a[mid] > key){
            // hi = mid -1;
            binary(a,  lo, mid-1, key);
        }
        else{
            binary(a, mid+1, hi, key);
        }
    }
    return false;
}

int main()
{
    int arr[5] = {15, 25, 35, 45, 55};
    bool res = binary(arr,  0, 4, 3);
    if(res) cout<<"found"<<endl;
    else cout<<"not found"<<endl;
    return 0;
}