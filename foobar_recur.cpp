#include <iostream>
#include <sstream>

using namespace std;

int foo(int& count, int num, int* list, string ans, bool start, int last)
{

    if (num == 1)
    {
        list[1] = 0;
        cout << ans << "1" << endl;
        count++;
        return 1;
    }
    if (num == 2)
    {
        list[2] = 0;
        
        if (last < 2)
        return 1;
        if (last != 2)
        {
            cout << ans << "2" << endl;
        count++;
        }
        
        return 1;
    }
    int i;
    for (i = num; i > 0; i--)
    {
        if (start && i == num) continue;
        if (i >= last) continue;

        stringstream ss;
        ss << i;
        if (i == num)
        {
            cout << ans+ss.str() << endl;
            count++;
        }
        int temp = foo(count, num-i, list, ans+ss.str()+"+", false, i);

    }
   

    list[num] = count;
    return count;

}

int main()
{
    cout << "Enter a number: ";
    string input;
    cin >> input;
    int number = stoi(input);
    int c[number+1];
    for (int i = 0; i < number+1; i++)
    {
        c[i] = 0;
    }
    string ans = "";
    int count = 0;
    cout << foo(count, number, c, ans, true, number) << endl;
    
   
}