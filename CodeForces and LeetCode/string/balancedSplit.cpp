 int balancedStringSplit(string s) {
        if(s.size() <= 1) return 0;
        int count = 0, res = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'L')
                count += -1;
            else
                count += 1;
            if(count == 0)
                res++;
        }
        return res;
    }