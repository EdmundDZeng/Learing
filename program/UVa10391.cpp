
#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
    map<string,bool>hash;
    string str[150000];
    hash.clear();
    string temp;
    string a,b;
    int num=0;
    while(cin>>str[num])
    {
        hash[str[num]]=true;
        num++;
    }
    for(int i=0;i<num;i++)
    {
        temp=str[i];
        for(int j=0;j<temp.size()-1;j++)
        {
            a=temp.substr(0,j+1);
            b=temp.substr(j+1);
            if(hash[a]&&hash[b])
            {
                cout<<temp<<endl;
                break;
            }
        }
    }
    return 0;
}
