#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    priority_queue<int,vector<int>,greater<int>> hello; 
    //처음에는 무지성으로 다 넣고 n-1번 푸쉬해서 n 큰 수를 찾았는데 메모리초과라는 기적의 계산결과 등장
    //최소힙-> 가장 작은 값이 맨 앞에 오고 가장 먼저 빠짐 -> N번째 큰수가 구성원들 중 가장 작은 우선순위큐를 만들자
    int n;
    cin>>n;
    int tmp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>tmp;
            hello.push(tmp);
            if(hello.size()>n){
                hello.pop();
            }
        }
    }
    cout<<hello.top();
    return 0;
}
