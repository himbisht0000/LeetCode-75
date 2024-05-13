class SmallestInfiniteSet {
public:
    int arr[10001];
    int smallest;
    SmallestInfiniteSet() {
        
        memset(arr,0,sizeof(int) * 1001);
        smallest = 1;
    }
    
    int popSmallest() {
        int ans = smallest;
        arr[smallest] = 1;
        while(arr[smallest] == 1)
        {
            smallest++;
        }
        return ans;
    }
    
    void addBack(int num) {
        if(arr[num] == 1)
        {
            if(smallest > num)
            smallest = num;
            arr[num] = 0;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
