//User function template for C++
class Solution{
public:	

   void solve(int n,int zero,int ones,vector<string>&vec,string op){
       if(n==0){
           vec.push_back(op);
           return;
       }
       string output=op;
       output.push_back('1');
       solve(n-1,zero,ones+1,vec,output);
       
       if (ones>zero){
           string output1=op;
           output1.push_back('0');
           solve(n-1,zero+1,ones,vec,output1);
       }
   }


	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    vector<string>vec;
	    int zero=0;
	    int ones=0;
	    string op="";
	    solve(n,zero,ones,vec,op);
	    return vec;
	}
};
