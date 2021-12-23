 void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         int n1=m-l+1;
     int n2=r-m;
     int start[n1];
     int end[n2];
     
     int i=0;
     int j=0;
     int k=l;
     
     for(int i=0;i<n1;i++){
         start[i]=arr[l+i];
     }
     
     for(int j=0;j<n2;j++){
         end[j]=arr[j+1+m];
     }
     
     while(i<n1 && j<n2){
         if(start[i]<=end[j]){
             arr[k]=start[i];
            i++;
         }
         else{
             arr[k]=end[j];
            j++;            
         }
         k++;
     }
     while(i<n1){
         arr[k]=start[i];
         i++;
         k++;
     }
      while(j<n2){
         arr[k]=end[j];
         j++;
         k++;
     }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
    }