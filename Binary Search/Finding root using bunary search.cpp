int mySqrt(int x) {
        int low = 1, hi = x;
        int ans;
        while(low <= hi){
            int mid = low + (hi - low) / 2;
            if(mid <= x/mid){
                ans = mid;
                low = mid+1;
            }
            else hi = mid - 1;
        }
        return ans;
}
