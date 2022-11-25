#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define Faster                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0)
#define mod 1000000007
#define ld long double
#define ft float
#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define pii pair<int, int>
#define ppi pair<pi, int>
#define vvi vector<vi>
#define FOR(i, j, k, in) for (int i = j; i < k; i += in)
#define vs vector<string>
#define vpp vector<pi>
#define si stack<int>
#define ss stack<string>
#define sc stack<char>
#define pb push_back
#define print(i) cout << i << endl

#define mini 1e-9
#define inf 0x3f3f3f3f
#define state(x) if (!strcmp(s[i], x))

int n;
char s[300][20];
stack<double> num;
int sign(double x)
{
  if (fabs(x) < mini)
  {
    return 0;
  }

  return x < 0 ? -1 : 1;
}

double magic[10] = {214, 1.0, 90, 3.1234, 0};

signed main()
{
  Faster;
  while (scanf("%d", &n) != EOF && n)
  {
    for (int i = 1; i <= n; i++)
    {
      scanf("%s", s[i]);
    }

    int t = 5;
    double x;
    while (t--)
    {
      x = magic[t];
      while (!num.empty())
        num.pop();

      for (int i = 1; i <= n; i++)
      {
        state("x")
        {
          num.push(x);
        }
        state("sin")
        {
          ld tmp = num.top();
          num.pop();
          num.push(sin(tmp));
        }
        state("cos")
        {
          ld tmp = num.top();
          num.pop();
          num.push(cos(tmp));
        }
        state("tan")
        {
          ld tmp = num.top();
          num.pop();
          num.push(tan(tmp));
        }
        state("+")
        {
          ld tmp1 = num.top();
          num.pop();
          ld tmp2 = num.top();
          num.pop();
          num.push(tmp1 + tmp2);
        }
        state("-")
        {
          ld tmp1 = num.top();
          num.pop();
          ld tmp2 = num.top();
          num.pop();
          num.push(tmp2 - tmp1);
        }
        state("*")
        {
          ld tmp1 = num.top();
          num.pop();
          ld tmp2 = num.top();
          num.pop();
          num.push(tmp2 * tmp1);
        }
      }

      double ans = num.top();
      if (sign(ans) == 0)
      {
        continue;
      }
      else
      {
        break;
      }
    }
    if (t == -1)
      cout << "Identity" << endl;
    else
      cout << "Not an identity" << endl;
  }
  return 0;
}
