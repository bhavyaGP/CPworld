#include <bits/stdc++.h>
using namespace std;

bool checkrows(int arr[][9])
{
    for (int i = 0; i < 9; i++)
    {
        set<int> st;
        for (int j = 0; j < 9; j++)
        {
            if (st.find(arr[i][j]) == st.end())
            {
                st.insert(arr[i][j]);
            }
            else
            {
                return false;
            }
            if (arr[i][j] == 0)
            {
                continue;
            }
        }
    }
    return true;
}

bool checkcolumn(int arr[][9])
{
    for (int j = 0; j < 9; j++)
    {
        set<int> st;
        for (int i = 0; i < 9; i++)
        {
            if(arr[i][j]==0){
                continue;
            }
            if(st.find(arr[i][j])==st.end()){
                st.insert(arr[i][j]);
            }else{
                return false;
            }
        }
    }
    return true; 
}

bool validbox(int arr[][9],int rowstart,int rowend,int colstart,int colend)
{
    set<int> st;
    for(int i=rowstart; i<=rowend; i++){
        for(int j=colstart; j<=colend; j++){
            if(arr[i][j]==0){
                continue;
            }
            if(st.find(arr[i][j])==st.end()){
                st.insert(arr[i][j]);
            }else{
                return false;
            }
        }
    }
    return true; 
}

bool checkbox(int arr[][9])
{
    for(int rowstart=0;rowstart<9;rowstart+=3){
        int rowend=rowstart+2;
        for(int colstart=0;colstart<9;colstart+=3){
            int colend=colstart+2;
            if(!validbox(arr,rowstart,rowend,colstart,colend)){
                return false; 
            }
        }
    }
    return true; 
}

int main()
{
    int arr[9][9]={
        {1, 4, 7, 0, 0, 0, 0, 0, 3},
        {2, 5, 0, 0, 0, 1, 0, 0, 0},
        {3, 0, 9, 0, 0, 0, 0, 0, 0},
        {0, 8, 0, 0, 2, 0, 0, 0, 4},
        {0, 0, 0, 4, 1, 0, 0, 2, 0},
        {9, 0, 0, 0, 0, 0, 6, 0, 0},
        {0, 0, 3, 0, 0, 0, 0, 0, 9},
        {4, 0, 0, 0, 0, 2, 0, 0, 0},
        {0, 0, 1, 0, 0, 8, 0, 0, 7}
    };
    
    bool rowsValid = checkrows(arr);
    bool columnsValid = checkcolumn(arr);
    bool boxesValid = checkbox(arr);    
    
    if (rowsValid && columnsValid && boxesValid)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    
    return 0;
}