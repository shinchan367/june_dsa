class Solution {
public:

    bool ispalindrome(string basek){
        int i=0;
        int j=basek.length()-1;
        while(i<=j){
            if(basek[i]!=basek[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }



    string convertintobasek(long long pal_new,int k){
         if(pal_new==0){
            return "0";
         }
         string newbase="";
         while(pal_new>0){
            newbase+=to_string(pal_new%k);
            pal_new/=k;
         }
         return newbase;
    }




    long long kMirror(int k, int n) {
        int l=1;
        long long sum=0;
        while(n>0){
        int half_length=(l+1)/2;
        long long min_len=pow(10,half_length-1);
        long long max_len=pow(10,half_length)-1;
        for(int i=min_len;i<=max_len;i++){
            string first_half=to_string(i);
            string second_half=first_half;
            reverse(second_half.begin(),second_half.end());
            string pal="";
            if(l%2==0){
                pal=first_half+second_half;
            }
            else{
                pal=first_half+second_half.substr(1);
            }

            long long pal_new=stoll(pal);
            string basek=convertintobasek(pal_new,k);

            if(ispalindrome(basek)){
                sum+=pal_new;
                n--;
                 if(n==0){
                    break;
                 }
            }
        }
        l++;
    }
    return sum;
    }
};
