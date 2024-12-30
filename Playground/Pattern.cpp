#include <iostream>
using namespace std;

void simpleSquare(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void simplePyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void reversePyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
        // for(int j=i;j<n;j++){
        for (int j = 0; j < n - i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void PyramidNumber(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << j + 1 << " ";
        }
        cout << endl;
    }
}

void HalfDiamond(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void leftHalfPyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j < n - i - 1)
            {
                cout << "  ";
            }
            else
            {
                cout << "* ";
            }
        }

        cout << endl;
    }
}
void rightanglenumber(int n){


    for (int i = 0; i <= n; i++)
    {
        for(int j=0;j<i;j++){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    

}

void printupperpyramid(int n){
    for(int i=0;i<n;i++){
        //print space
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        //print the start
        for(int j=0;j<2*i+1;j++){
            cout<<"*";
        }
        //print space 
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        cout<<endl;
    }
} 
void printinvertedpyramid(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){

        }
    }
}
void printdiamond(int n){
    printupperpyramid(n);
    printinvertedpyramid(n);
}

void SymmetricButterfly(int n){
    int space=2*n-2;

    for(int i=1;i<=2*n-1;i++){
        
    }

}
int main()
{
    int n;
    // cin >> n;
    n = 5;
    // simpleSquare(n);
    cout << endl;
    // simplePyramid(n);
    cout << endl;
    // reversePyramid(n);
    cout << endl;
    // PyramidNumber(n);
    cout << endl;   
    // HalfDiamond(n);
    cout << endl;
    // leftHalfPyramid(n);
    cout<<endl;
    // rightanglenumber(n);
    cout<<endl;
    // printdiamond(n);
    cout<<endl;
    return 0;
}
