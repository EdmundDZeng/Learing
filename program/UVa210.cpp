#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cstring>
 
using namespace std;
 
const int maxn = 1000;
const int times = 5;
 
deque<int> qr;                      //模拟运行的队列
queue<int> qw;                      //模拟被挂起的程序
vector<string> program[maxn];       //记录每个程序
int var[26], q[maxn],t[times],timelimit;
bool lock = false;
 
void run(int i)
{
    int Q = timelimit, x;       //设定时间限制
    string comd;
    while(Q > 0){
        comd = program[i][q[i]];//q数组存储相应程序的行数
        switch(comd[2])
        {
            case '=':   Q -= t[0];
                        x = comd[4] - '0';
                        if (comd.size() == 6) x = x*10 + comd[5]-'0';
                        var[comd[0]-'a'] = x;
                        break;
                        //赋值
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
                            x = qw.front();  //得到队首元素
                            qw.pop();
                            qr.push_front(x);//将等待的程序执行
                        }
                        break;
                        //unlock
            case 'd' :  return;//end
        }
        ++q[i];     //执行相应程序的下一条代码
    }
    qr.push_back(i);//将未执行完的程序挂起
}
int main()
{
    int cas;        //读入测试样例的个数
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
            qr.push_back(i);//模拟添加程序
        }
        memset(q, 0 ,sizeof(q));
        memset(var, 0, sizeof(var));
        while(!qr.empty()) //当无运行程序时停止
        {
            int t = qr.front();
            qr.pop_front();
            run(t);
        }
        if(cas) cout<<endl;
    }
    return 0;
}

