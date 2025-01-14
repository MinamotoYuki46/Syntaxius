for(int i=0; i<n; i++){
        if((i == 0 && k[i] < k[i+1]) || 
        (k[i] <= k[i-1] && k[i] < k[i+1] && i != n-1)){
            temp = k[i];
        }
        
        if(((k[i] > k[i-1] && k[i] <= k[i+1]) || 
        (k[i] > k[i-1] && k[i] > k[i+1]) || 
        (k[i] > k[i-1] && i == n-1)) && (i != 0)){
            temp2 = k[i];
        }

        if((k[i] > k[i-1] && k[i] >= k[i+1] && i != 0 && i != n-1) || 
        (k[i] > k[i-1] && i == n-1)){
            hasil += temp2 - temp;
        }
    }