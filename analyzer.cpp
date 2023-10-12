#include <iostream>
#include <vector>
using namespace std;

int linear_search(vector<int> array,int element)
{
    for(int i = 0; i < array.size(); i++){
        if (element == array[i]){
            return i;
        }

    }
    return -1;
}

int binary_search(vector<int> array, int element){
    int low = 0;
    int high = array.size() - 1;
    int mid = (high + low)/2;
    while (low <= high){
        mid = (high + low)/2;
        if (array[mid] == element){
            return mid;
        }
        if (array[mid] < element){
            low = mid + 1;
        }
        if (array[mid] > element){
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> array = { 1, 2,3,4,5,6,7};
    cout<<binary_search(array,7);
}
