#include<bits/stdc++.h>
using namespace std;
class tree
{
   public:
   int freq;
   string name;
   tree*right;
   tree*left;
   tree()
   {
      right=NULL;
      name="";
      left=NULL;
      freq=0;
   }
   tree(string a,int f)
   {
      name=a;
      freq=f;
      left=NULL;
      right=NULL;
   }

};
class custom
{
  public:
   bool operator()(pair<tree*,int>a,pair<tree*,int>b)
   {
        if(a.second>b.second)
        {
            return true;
        }
        else{
          return false;
        }
   }

};
int main()
{
   fstream newfile;
   newfile.open("pro.txt",ios::in);

   unordered_map<string,int>sto;
   while(newfile)
   {    
         string word;
        newfile>>word;
     
         if(word!="")
         {
          sto[word]=sto[word]+1;
        }
   }
  
   priority_queue<pair<tree*,int>,vector<pair<tree*,int>>,custom>sto1;
   auto i=sto.begin();
   while(i!=sto.end())
   {  
      tree*root=new tree(i->first,i->second);
    
      sto1.push(make_pair(root,i->second));
      
      i++;
   };
   tree*ans;
   while(sto1.size()!=1)
   {
    pair<tree*,int>a=sto1.top();
    sto1.pop();
    pair<tree*,int>b=sto1.top();
    sto1.pop();
    
    tree*root=new tree;
    ans=root;
    if(a.second<b.second)
    {
       root->left=a.first;
       root->right=b.first;

    }
    else{
      
       root->right=a.first;
       root->left=b.first;
      
    }
    
    sto1.push(make_pair(root,a.second+b.second));
    ans=root;

   }
   unordered_map<string,string>sto3;
   stack<pair<tree*,string>>sto2;
   sto2.push(make_pair(ans,""));
   while(!sto2.empty())
   {  
      pair<tree*,string>a=sto2.top();
      sto2.pop();
      
      if(a.first->name.length()!=0)
      {   
         sto3[a.first->name]=a.second;
      }else{
       
         sto2.push(make_pair(a.first->left,a.second+'0'));
         sto2.push(make_pair(a.first->right,a.second+'1'));
      }
   }
fstream com;
 com.open("com.txt",ios::out);
 for(auto i=sto3.begin();i!=sto3.end();i++)
 {  

     com<<i->first;
     com<<" ";
     com<<i->second;
     com<<" ";
 }
newfile.close();
 com<<"decode"<<" ";
newfile.open("pro.txt",ios::in);
 while(newfile)
   {    
         string word;
        newfile>>word;
        com<<sto3[word];
       
   }
 
return 0;
}