int maxXor(int arr[], int n)
	{
		// Your code goes here
		int index = 0;
        
        for(int i=31; i>=0; i--){
            int maxElement = INT_MIN;
            int maxIndex = index;
            for(int j=index; j<n; j++){
                int isSetBit = (arr[j]>>i)&1;
                if(isSetBit && maxElement<arr[j]){
                    maxElement = arr[j];
                    maxIndex = j;
                }
            }
            
            if(maxElement == INT_MIN){
                continue;
            }
            
            swap(arr[index],arr[maxIndex]);
          
            maxIndex = index;
            
            for(int j=0; j<n; j++){
                int isSetBit = (arr[j]>>i)&1;
                if(isSetBit && j!=maxIndex){
                    arr[j] = arr[j]^maxElement;
                }
            }
            
            index += 1;
            
        }
        int res = 0;
        for(int i=0; i<n; i++){
            res = res^arr[i];
        }
        return res;

	}