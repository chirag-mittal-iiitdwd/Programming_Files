/*
    We have break the string into two parts and keep on breaking until we remain with one character
    We need to make sure sure that no char remains empty after breakdown
    
    And then we can swap non left chars, if after swapping the strings are found identical then we return true

    For doing this we need to use MCM approach, and keep on recrusively break the string until one char is left

    First two conditions can be added in main function
    if(str1.length()!=str2.length()){
        return false;
    }
    if(both empty){
        return true;
    }

    These will be in recursive
    if(str1.compare(str2)==0){
        return true;
    }
    if(str1.length()<=1 || str2.length()<=1){
        return false;
    }

    bool solve(string a,string b){
        if(a.compare(b)==0){
            return true;
        }
        if(a.length()<=1){
            return false;
        }
        int n=a.length();
        bool flag=false;
        for(int i=1;i<=n-1;i++){
            if(solve(a.substr(0,i),b.substr(n-i,i))&&(solve(a.substr(i,n-i),b.substr(0,n-i)))){
                flag=true;
            }
            else if(solve())
        }
    }
*/