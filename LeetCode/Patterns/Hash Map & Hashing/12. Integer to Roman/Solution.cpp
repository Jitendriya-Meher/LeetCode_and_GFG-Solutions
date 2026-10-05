class Solution {
public:
    string intToRoman(int n) {
        map<char,int> mpp;
        string ans="";
        while(n>=1000)
        {
            ans+="M";
            n-=1000;
        }
        while(n>=900)
        {
            ans+="CM";
            n-=900;
        }
        while(n>=500)
        {
            ans+="D";
            n-=500;
        }
        while(n>=400)
        {
            ans+="CD";
            n-=400;
        }
        while(n>=100)
        {
            ans+="C";
            n-=100;
        }
        while(n>=90)
        {
            ans+="XC";
            n-=90;
        }
        while(n>=50)
        {
            ans+="L";
            n-=50;
        }
        while(n>=40)
        {
            ans+="XL";
            n-=40;
        }
        while(n>=10)
        {
            ans+="X";
            n-=10;
        }   
         while(n>=9)
        {
            ans+="IX";
            n-=9;
        }   
         while(n>=5)
        {
            ans+="V";
            n-=5;
        }  
         while(n>=4)
        {
            ans+="IV";
            n-=4;
        }  
         while(n>=1)
        {
            ans+="I";
            n-=1;
        }  

            return ans;
                    

        
        
    }
};