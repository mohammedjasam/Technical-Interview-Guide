/*
*
* Tag: Sort
* Time: O(n^2)
* Space: O(n)
*/
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <iostream>
using namespace std;
/* Head ends here */
void insertionSort(int ar_size, int *  ar) {
    for(int i = 1; i < ar_size; i ++){
        int val = ar[i];
        int j = i - 1;
        while(j >= 0 && val < ar[j]){
            ar[j + 1] = ar[j];
            j --;
        }
        ar[j + 1] = val;
        for(int j = 0; j < ar_size; j ++)
            cout<<ar[j]<<" ";
        cout<<endl;
    }
}
/* Tail starts here */
int main(void) {
   
    int _ar_size;
    cin >> _ar_size;
    //scanf("%d", &_ar_size);
    int _ar[_ar_size], _ar_i;
    for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
        cin >> _ar[_ar_i];
        //scanf("%d", &_ar[_ar_i]); 
    }

   insertionSort(_ar_size, _ar);
   
   return 0;
}
