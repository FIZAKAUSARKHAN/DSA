#include<iostream>
#include<vector>
using namespace std;

//print the vector
void printVector(vector<string> vec)
{
    for(string s: vec)
    {
        cout<<s<<" ";
    }
    cout<<endl;
}

void solveByRecusrion(string str,string output,int index,vector<string> &ans)
{
    if(index >= str.length())
    { 
        //To skip the empty string if want to include it in the answer, remove the if condition
        if(output.length()>0)
        {
           ans.push_back(output);
        }
        return;
    }
    //exclude
    solveByRecusrion(str,output,index+1,ans);
    //include
    char elemenet = str[index];
    output += elemenet;
    solveByRecusrion(str,output,index+1,ans);
}
vector<string> subsequences(string str)
{
    vector<string> ans;
    string output = "";
    int index = 0;
    solveByRecusrion(str,output,index,ans);

    return ans;
}

int main()
{
    string str = "abc";
    vector<string> strVector = subsequences(str);
    printVector(strVector);
}
