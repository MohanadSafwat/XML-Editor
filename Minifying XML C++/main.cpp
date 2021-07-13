#include <iostream>
#include <string.h>
using namespace std;

string Minify(string x)
{
int y = 0;
int z = 0;
for(int i=0;i<x.length();i++)
    {
         if(x.find("<!--")!=-1)
        {
        y=x.find("!")-1;
        z=y;
        while(x[z]!='>')
        {
            z++;
        }
        x=x.erase(y,(z-y+1));
        }

    }
int k = 0;
        for(int i=0 ; i< x.length() ; i++)
            {
                if(x[i]=='>'&&x[i+1]==' ')
                {
                    k = i;
                    while (x[k] != '<')
                    {
                        k++;
                    }
                    x = x.erase(i+1, (k - i-1));
                }
            }

            cout<<y<<endl<<z<<endl<<k;
    return x;

}




int main()
{
string x="";
string xx;
int y = 0;
int z = 0;
do
{
    getline(cin,xx) ;
    x+=xx;


}while(xx !="q");
string zezo=Minify(x);

cout<<zezo;
    return 0;
}
