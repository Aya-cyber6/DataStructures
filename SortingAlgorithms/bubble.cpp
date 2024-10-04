#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'countSwaps' function below.
 *
 * The function accepts INTEGER_ARRAY a as parameter.
 */
void countSwaps(vector<int> a) {
    int totalSwap = 0;

    for (int step = 0; step < a.size(); step++)
    {
        int swapped = 0;
        for (int i=0; i < a.size() - 1; i++)
        {        
            if (a[i] > a[i+1])
            {
                int temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;

                swapped += 1; 
                totalSwap += 1;
            }
        }

        if (swapped == 0)
        {
            break; 
        }
    }
     cout << "Array is sorted in " << totalSwap << " swaps\n";
     cout << "First Element: " << a[0] << "\n";
     cout << "Last Element: " << a[a.size() - 1] << "\n";

}   
int main()
{
    string n_temp;
    cout << "Enter the number of integers to be sorted: ";
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string a_temp_temp;
    cout << "Enter the integers to be sorted: ";
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    countSwaps(a);
    return 0;
}



string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), std::not_fn(::isspace)) 
        );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), std::not_fn(::isspace)).base(),  // Replaced ptr_fun and not1 with not_fn
        s.end()

    );
    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;  // Vector to hold the tokens

    string::size_type start = 0;  // Starting index for each token
    string::size_type end = 0;    // Ending index for each token

    // Loop through the string and find each space
    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));  // Add the token (substring) to the vector
        start = end + 1;  // Move the start index to the next character after the space
    }

    tokens.push_back(str.substr(start));  // Add the last token (after the final space)
    return tokens;
}