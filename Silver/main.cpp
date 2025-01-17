#include<bits/stdc++.h>
#define MX 100001
using namespace std;


int N,M;
int qs[MX];
int arr[MX];
int res;
int nums[MX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    for (int i = 0; i < N; i++) cin >> qs[i];
    deque<int> q;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (!qs[i]) q.push_front(arr[i]);
    }

    int M; cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> nums[i];
        q.push_back(nums[i]);
    }

    for (int i = 0; i < M; i++) {
        if (!q.empty()) {
            cout << q.front() << ' ';
            q.pop_front();
        }
    }
    
    return 0;
}