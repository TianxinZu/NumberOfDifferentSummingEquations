#include <iostream>
#include <sstream>

using namespace std;

void foo(int& count, int num, string ans, bool start, int last)
{
    //base cases
    if (num == 1)
    {
        cout << ans << "1" << endl;
        count++;
        return;
    }
    if (num == 2)
    {
        if (last < 2)
        return;
        if (last != 2)
        {
            cout << ans << "2" << endl;
            count++;
        }
        
        return;
    }

    for (int i = num; i > 0; i--)
    {
        if (start && i == num) continue; //first number should not equal to the input
        if (i >= last) continue;

        stringstream ss;
        ss << i;
        if (i == num)
        {
            cout << ans+ss.str() << endl;
            count++;
        }
        foo(count, num-i, ans+ss.str()+"+", false, i); 
    }
}

int main()
{
    cout << "Enter a number: ";
    string input;
    cin >> input;
    int number = stoi(input);
    string ans = "";
    int count = 0;
    foo(count, number, ans, true, number); //this will print out all equations
    cout << count << endl;
    return 0;
}