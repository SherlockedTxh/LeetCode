// 4.6美团笔试

// 第一题 python3 ac
x = int(input())
h, m = [int(i) for i in input().split(':')]
n = int(input())
num = h*60 + m
while(num < n):
    x -= 1
    if x <= 0:
        x += 7
    n -= 24*60
k = num - n
m1 = k % 60
h1 = k // 60
str1 = ""
if(h1 < 10):
    str1 = '0'
str1 = str1 + str(h1) + ":"
if(m1 < 10):
    str1 = str1 + '0'
str1 = str1 + str(m1)
print(x)
print(str1)

// 第二题 c++ ac
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <set>
#include <ctype.h>
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a,b;
    int tmp;
    unordered_map<int, int> hash;
    vector<int> dp;
    for(int i =0; i< n;i++){
        cin >>tmp;
        hash[tmp] = i;
    }
    int cnt = 0;
    for(int i =0; i< n;i++){
        cin >> tmp;
        dp.push_back(hash[tmp]);
    }
    int m = dp[dp.size()- 1]+1;
    for(int i = dp.size() - 1; i>=0;i--){
        if(dp[i] < m){
            m = dp[i];
        }
        else{
            cnt++;
        }
    }
    cout << cnt<< endl;
    return 0;
}

// 第三题 c++ ac
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <set>
#include <ctype.h>
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int ans = n;
    int sum = n, left = 1, right = ans, mid;
    while(left < right){
        n = sum, ans = left + (right-left)/2;
        mid = ans;
        while(ans){
            n -= ans;
            ans /= k;
        }
        if(n > 0){
            left = mid + 1;
        }
        else{
            right = mid;
        }
    }
    cout<< left <<endl;
    return 0;
}

// 第五题 python3 过了9%
import copy
n,k = [int(i) for i in input().split()]
str1 = []
str2 = []
for _ in range(k):
    tmp = input()
    str1.append(tmp)
str2 = copy.deepcopy(str1)
for _ in range(n):
    line = input()
    if line[0] == '?':
        cnt = 0
        for i in range(len(str1)):
            if str1[i] in line:
                cnt += line.count(str1[i])
        print(cnt)
    elif line[0] == '+':
        a = int(line[1]) - 1
        if str2[a] not in str1:
            str1.append((str2[a]))
    else:
        a = int(line[1]) - 1
        if str2[a] in str1:
            str1.remove(str2[a])