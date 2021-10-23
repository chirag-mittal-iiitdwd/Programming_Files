/*
    Identificication + Format
    We would have given with a string or array

    and after selecting two locations i and j in that string or array
    we would have to select another integer k such than we would break the problem into two problems
    it from ( i to k ) and from ( k+1 to j ) after solving these two individually recursively i will return their answers


    int solve(int arr[],int i,int j){
        This condition may change depending upon the problme
        if(i>j){
            return 0;
        }

        for(int k=i;k<=j;k++){
            calculate temporary answer
            int tempAns=solve(arr,i,k);
            tempAns+=solve(arr,k+1,j);

            Operation will change depending upon problem
            ans=someOpeartion(tempAns);
        }
        return ans;
    }
*/