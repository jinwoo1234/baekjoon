#include<stack>
#include<queue>
#include<iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
//�Է����� ť�� �ֱ�
    queue<int>number_line;
//���̵�� ����
    stack<int>side_line;
    side_line.push(999999);
    int sad_switch=0;
//�Է¹޾Ƽ� ť�� �ֱ�
    for(int i=0 ;i<N ; i++)
    {
        int a;
        cin>> a;
        number_line.push(a);
    }
    for(int i=1;i<=N;i++)
    {
        while(!number_line.empty()&&!side_line.empty())//���� ť �ٺ�� ����
        {
//�ϳ� ���� Ȯ��
            int a;
            a=number_line.front();
            number_line.pop();
            if(a==i)// �� ������ ������ �ݺ��� ����
                break;
            if(side_line.top()==i)//���ÿ� ������ ����
            {
                side_line.pop();//���ÿ��� ��
                break;
            }//�ƴϸ� ���ÿ� �־�
            else{
                if(side_line.top()<a)//�ٵ� ���� �������� ū���� ���� sad
                {
                    sad_switch=1;
                    break;
                }
                side_line.push(a);

            }
        }
        if(sad_switch==1)//sad �� for���� ����
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