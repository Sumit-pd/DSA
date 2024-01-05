#include<bits/stdc++.h>
int isCyclicRotation(string &p, string &q) 
{
    if(p.length() != q.length()){
        return 0; 
    }
    string newStr = p+p;
    // size_t found = newStr.find(p);
    if( newStr.find(q) == string::npos){
        return 0;
    }
    else return 1;
}