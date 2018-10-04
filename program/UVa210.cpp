#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cstring>
 
using namespace std;
 
const int maxn = 1000;
const int times = 5;
 
deque<int> qr;                      //ģ�����еĶ���
queue<int> qw;                      //ģ�ⱻ����ĳ���
vector<string> program[maxn];       //��¼ÿ������
int var[26], q[maxn],t[times],timelimit;
bool lock = false;
 
void run(int i)
{
    int Q = timelimit, x;       //�趨ʱ������
    string comd;
    while(Q > 0){
        comd = program[i][q[i]];//q����洢��Ӧ���������
        switch(comd[2])
        {
            case '=':   Q -= t[0];
                        x = comd[4] - '0';
                        if (comd.size() == 6) x = x*10 + comd[5]-'0';
                        var[comd[0]-'a'] = x;
                        break;
                        //��ֵ
            case 'i':   Q -= t[1];
                        cout<<i<<": "<<var[comd[6] - 'a']<<endl;
                        break;
                        //print
            case 'c':   Q -= t[2];
                        if(lock) { qw.push(i); return;}
                        lock = true;
                        break;
                        //lock
            case 'l':   Q -= t[3];
                        lock = false;
                        if(!qw.empty())
                        {
                            x = qw.front();  //�õ�����Ԫ��
                            qw.pop();
                            qr.push_front(x);//���ȴ��ĳ���ִ��
                        }
                        break;
                        //unlock
            case 'd' :  return;//end
        }
        ++q[i];     //ִ����Ӧ�������һ������
    }
    qr.push_back(i);//��δִ����ĳ������
}
int main()
{
    int cas;        //������������ĸ���
    cin>>cas;
    while(cas--){
        int n;
        cin>>n;
        for(int i = 0;i < times;i++) cin>>t[i];
        cin>>timelimit;
        string s;
        for(int i = 1;i <= n;i++)
        {
            program[i].clear();
            while(getline(cin,s))
            {
                if ( s == "") continue;
                program[i].push_back(s);
                if ( program[i].back() == "end") break;
            }
            qr.push_back(i);//ģ����ӳ���
        }
        memset(q, 0 ,sizeof(q));
        memset(var, 0, sizeof(var));
        while(!qr.empty()) //�������г���ʱֹͣ
        {
            int t = qr.front();
            qr.pop_front();
            run(t);
        }
        if(cas) cout<<endl;
    }
    return 0;
}

