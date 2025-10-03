#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<string> st;
    cout << "Please enter your tasks (type BREAK to stop):" << endl;


    for (int i = 0; i < 100; i++)
    {
        cout << "Task " << i + 1 << ": ";
        string inp;
        getline(cin, inp);

        if (inp.empty())
            continue;

        if (inp == "BREAK")
            break;

        st.push(inp);
    }

    // Ask user if they want to delete a task
    cout << "\nDo you want to delete a task? (Type task name or DON'T DELETE): ";
    string toDelete;
    getline(cin, toDelete);

    if (toDelete != "DON'T DELETE")
    {
        stack<string> temp;
        bool found = false;

        while (!st.empty())
        {
            if (st.top() == toDelete && !found)
            {
                found = true;
                st.pop(); // delete the task
                continue;
            }
            temp.push(st.top());
            st.pop();
        }

        // Restore stack
        while (!temp.empty())
        {
            st.push(temp.top());
            temp.pop();
        }

        if (found)
            cout << "\nTask \"" << toDelete << "\" deleted successfully.\n";
        else
            cout << "\n Task \"" << toDelete << "\" not found.\n";
    }
    else
    {
        cout << "\nNo task deleted as per your choice.\n";
    }

    // Final output
    cout << "\nRemaining tasks in reverse order (LIFO):\n";
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}

