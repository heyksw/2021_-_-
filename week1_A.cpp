#include <iostream>
#include <string>
using namespace std;

void zigzag(string s, int k)
{
    string answer = "";
    int len = s.length();

    if (len <= k)
    {
        cout << s << '\n';
        return;
    }

    int m = 0;
    
    if (len%k==0){
        m = len/k;
    }
    else{
        m = int(len/k) + 1;
    }
    
    if (len % k != 0)
    {
        for (int i = 0; i < k - int(len % k); i++)
        {
            s += 'X';
        }
    }

    bool down = true;
    char arr[k][m];
    int col = 0;
    int y = 0;

    while (y < len)
    {
        for (int x = 0; x < k; x++)
        {
            if (down)
            {
                arr[x][col] = s[y];
            }
            else
            {
                arr[k - 1 - x][col] = s[y];
            }
            y++;
        }

        down = !down;
        col++;
    }

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] != 'X')
            {
                answer += arr[i][j];
            }
        }
    }

    cout << answer << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T > 0)
    {
        string s;
        int k;
        cin >> s;
        cin >> k;
        zigzag(s, k);

        T--;
    }
}
