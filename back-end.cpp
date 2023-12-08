#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>

using namespace std;

void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printArray (int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
void randomize (int arr[], int n)
{
    srand (time(NULL));
 
    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        swap(&arr[i], &arr[j]);
    }
}
int main(){
    abdulrehman:
    int slot=12, comb=13, completed=0;
    int arr[slot*comb];
    int A1[slot][comb];
    int indexmax[slot];
    int indexmin[slot];
    int gpick,gplace, temp, count=0, j=0, x=0, npick=0, q=1;
    for (int i=0; i<slot; i++)
    {
        indexmax[i]=comb-1;
    }
    for (int i=0; i<slot; i++)
    {
        indexmin[i]=comb-1;
    }
    for (int i = 0; i<(comb*slot); i++)
    {
        j=i%comb;
        // x=i/13;
        arr[i]=j+1;
        //cout<<i<<" "<<j<<endl;
        // cout<<"Our value"<<arr[i]<<endl;
        
    }
    int n = sizeof(arr) / sizeof(arr[0]);
    randomize (arr, n);
    // printArray(arr, n);
    
    for (int i=0; i<comb*slot; i++)
    {
        j=i%comb;
        x=i/comb;
        // cout<<x<<" "<<j<<endl;
        A1[x][j]=arr[i];
    }
    // for (int i=0; i<4;i++)
    // {
    //     for (int j=0; j<13; j++)
    //     {
    //         cout<<A1[i][j]<<endl;
    //     }
    // }
    do {
        for (int i=1; i<=slot; i++)
        {
            if (indexmin[i-1]<0)
            {
                continue;
            }
            // q=index[i-1];
            cout<<"Current Card at Top of group "<<i<<" is "; //<<A1[i-1][q]<<endl;
            
            for (int j=indexmin[i-1]; j<=indexmax[i-1]; j++)
            {
                cout<<A1[i-1][j]<<" ";
            }
            cout<<endl;
        }
        // cout<<"Current Card at Top of second group "<<A1[1][index[1]]<<endl;
        // cout<<"Current Card at Top of third group "<<A1[2][index[2]]<<endl;
        // cout<<"Current Card at Top of fourth group "<<A1[3][index[3]]<<endl;
    
        cout<<"Enter group from which to pick: ";
        cin>>gpick;
        cout<<"How many cards to pick: ";
        cin>>npick;
        cout<<"Enter group at which to place: ";
        cin>>gplace;
        // if (A1[gpick-1][index[gpick-1]]%13 == 1){
        //     goto usman;
        // }
        
    if (A1[gpick-1][indexmax[gpick-1]-(npick-1)]-1==A1[gplace-1][indexmax[gplace-1]] && indexmax[gpick-1]-indexmin[gpick-1]+1 <= npick && indexmin[gpick-1]>0 && indexmin[gplace-1]>0){
        cout<<"It's valid movement. Let me do it."<<endl;
        // count=count+1;
        for (int j=indexmax[gpick-1]-(npick-1) ; j<=indexmax[gpick-1] ; j++)
        {
            indexmax[gplace-1]+=1;
            A1[gplace-1][indexmax[gplace-1]]=A1[gpick-1][j];
        }
        indexmax[gpick-1]-=npick;
        // indexmax[gplace-1]+=1;
        // A1[gplace-1][indexmax[gplace-1]]=A1[gpick-1][indexmax[gpick-1]];
        // indexmax[gpick-1]-=1;
        if (indexmax[gpick-1] < indexmin[gpick-1])
        {
            indexmin[gpick-1] = indexmax[gpick-1];
        }
        cout<<endl;
        // cout<<index[gpick-1]+1<<" "<<index[gplace-1]+1<<endl;
        if (A1[gplace-1][indexmax[gplace-1]]==7 && A1[gplace-1][indexmin[gplace-1]]==1)
        {
            cout<<"One slot completed at slot group number:"<<gplace<<endl;
            indexmin[gplace-1]=indexmin[gplace-1]-1;
            indexmax[gplace-1]=indexmin[gplace-1];
            completed += 1;
        }
        
    }
    else{
        usman:
        cout<<"It's Invalid. Enter 1 to retry or 2 to Exit and 3 to Restart."<<endl;
        cin>>q;
        if (q==1)
        {continue;
            
        }
        if (q==2){
            return 0;
        }
        
        cout<<endl;
        goto abdulrehman;
    }
    }while(completed<slot);
    cout<<endl<<"Game has been completed. You won.";
    
    /*if (gpick==1){
        temp=A1[a1];
    }*/
    return 0;
}