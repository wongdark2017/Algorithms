#include<bits/stdc++.h>
using namespace std;
const int maxnode =5e5+100;
const int maxn=1010,maxm=1010;


struct  DLX
{
    //data
    int n,m,size;//the number of sets,the number of elements,the number of nodes.
    int U[maxnode],D[maxnode],R[maxnode],L[maxnode],Row[maxnode],Col[maxnode];//create each nodes
    int H[maxn],S[maxm];//
    int ansd,ans[maxn];
    void init(int _n,int _m)
    {
        n=_n,m=_m;
        for(int i=0;i<=m;i++)
        {
            S[i]=0;
            U[i]=D[i]=i;
            L[i]=i-1;
            R[i]=i+1;
        }
        R[m]=0,L[0]=m;
        size=m;
        for(int i=0;i<=n;i++)
        H[i]=-1;
    }

    void Link(int r,int c)
    {
        ++S[Col[++size]=c];
        Row[size]=r;
        D[size]=D[c];
        U[D[c]]=size;
        U[size]=c;
        D[c]=size;
        if(H[r]<0) H[r]=L[size]=R[size]=size;
        else 
        {
            R[size]=R[H[r]];
            L[R[H[r]]]=size;
            L[size]=H[r];
            R[H[r]]=size;
        }
    }
    void remove(int c)
    {
        L[R[c]]=L[c],R[L[c]]=R[c];
        for(int i=D[c];i!=c;i=D[i])
        {
            for(int j=R[i];j!=i;j=R[j])
            {   
                U[D[j]]=U[j];
                D[U[j]]=D[j];
                --S[Col[j]];
            }
        }
    }
    void resume(int c)
    {
        for(int i=U[c];i!=c;i=U[i])
        {
            for(int j=L[i];j!=i;j=L[j])
            {
                ++S[Col[U[D[j]]=D[U[j]]=j]];
            }
        }
        L[R[c]]=R[L[c]]=c;
    }
    bool dance(int d)
    {
        if(R[0]==0)
        {
            ansd=d;
            return true;
        }
        int c=R[0];
        for(int i=R[0];i!=0;i=R[i])
        {
            if(S[i]<S[c]) c=i;
        }
        remove(c);
        for(int i=D[c];i!=c;i=D[i])
        {
            ans[d]=Row[i];
            for(int j=R[i];j!=i;j=R[j])remove(Col[j]);
            if(dance(d+1)) return true;
             for(int j=L[i];j!=i;j=L[j]) resume(Col[j]);
            
        }
        resume(c);
        return false;
    }
}g;


int main()
{


}
