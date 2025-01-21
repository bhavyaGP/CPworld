#include <bits/stdc++.h>
using namespace std;
int main()
{
    int month, year;
    cin >> month >> year;
    if(month>12 || month<1){
        cout<<"Invalid month";
        return 0;
    }
    int arr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string months[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        arr[1] = 29;
    }
    cout<<months[month-1]<<" "<<year<<" has "<<arr[month-1]<<" days";
    return 0;

}