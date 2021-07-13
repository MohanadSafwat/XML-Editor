using System;

namespace minifying_XML
{
    class Program
    {
        static void Main(string[] args)
        {
            string x="";
            int y = 0;
           int z = 0;
            Console.WriteLine("enter your paragraph");
            do 
            {
                x += Console.ReadLine();

                if (x.Contains("<!--"))
                {
                    y = x.IndexOf("!")-1;
                    z = y;
                    while (x[z]!='>') 
                    {
                        z++;
                    }
                    x=x.Remove(y, (z - y+1));
                }
              

            } while (x!=null && x.Substring(x.Length - 1) != "q" );
            Console.WriteLine(y + "  " + z);
            int k = 0;
            for(int i=0;i<x.Length;i++)
            {
                if(x[i]=='>'&&x[i+1]==' ')
                {
                    k = i;
                    while (x[k] != '<')
                    {
                        k++;
                    }
                    x = x.Remove(i+1, (k - i-1));
                }
            }
           // Console.WriteLine(x);


        }
    }
}
