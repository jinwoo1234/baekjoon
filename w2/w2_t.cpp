#include<stack>
#include<queue>
#include<iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
//입력줄은 큐에 넣기
    queue<int>number_line;
//사이드는 스택
    stack<int>side_line;
    side_line.push(999999);
    int sad_switch=0;
//입력받아서 큐에 넣기
    for(int i=0 ;i<N ; i++)
    {
        int a;
        cin>> a;
        number_line.push(a);
    }
    for(int i=1;i<=N;i++)
    {
        while(!number_line.empty()&&!side_line.empty())//스택 큐 다비면 종료
        {
//하나 빼서 확인
            int a;
            a=number_line.front();
            number_line.pop();
            if(a==i)// 그 순번에 맞으면 반복문 나가
                break;
            if(side_line.top()==i)//스택에 있으면 나가
            {
                side_line.pop();//스택에서 빼
                break;
            }//아니면 스택에 넣어
            else{
                if(side_line.top()<a)//근데 스택 맨위보다 큰값이 오면 sad
                {
                    sad_switch=1;
                    break;
                }
                side_line.push(a);

            }
        }
        if(sad_switch==1)//sad 면 for문도 나가
            break;

    }
    if(sad_switch==1)
        cout<<"Sad";
    else{
        cout<<"Nice";
    }

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}