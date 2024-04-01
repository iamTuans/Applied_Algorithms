#include <bits/stdc++.h>
#include <string>
#include <unordered_map>

using namespace std;

bool kiemTrasdt(const string& number) {
    for (char c : number) {
        if (!isdigit(c)) {
            return false; 
        }
    }
    return true; 
}

int string_to_second(string s) {
    return s[0] * 36000 + s[1] * 3600 + s[3] * 600 + s[4] * 60 + s[6] * 10 + s[7] - 1933008;
}

struct property {
    int total_call;
    int total_time;
};

int main() {
    bool check = true;
    int _duration = 0;
    int total_call = 0;
    string from_number;
    string to_number;
    string date;
    string from_time;
    string to_time;
    string cmd;
    unordered_map<string, property> properties;

    cin >> cmd;
    while (cmd != "#")
    {
        cin >> from_number;
        if (check)
        {
            check = check && kiemTrasdt(from_number);
        }
        ++total_call;

        ++(properties[from_number].total_call);

        cin >> to_number;
        if (check)
        {
            check = check && kiemTrasdt(to_number);
        }
        
        cin >> date;
        cin >> from_time;
        cin >> to_time;

        properties[from_number].total_time += string_to_second(to_time) - string_to_second(from_time);

        cin >> cmd;
    }

    cin >> cmd;
    while (cmd != "#")
    {
        if (cmd == "?check_phone_number")
        {
            cout << check << endl;
        }
        else if (cmd == "?number_calls_from")
        {
            cin >> cmd;

            cout << properties[cmd].total_call << endl;
        }
        else if (cmd == "?number_total_calls")
        {
            cout << total_call << endl;
        }
        else
        {
            cin >> cmd;

            cout << properties[cmd].total_time << endl;
        }

        cin >> cmd;
    }
    
    return 0;
}