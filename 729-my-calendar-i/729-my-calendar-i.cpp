class MyCalendar {
private:
    set < pair < int, int > > bookInfo;
public:
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        for(set < pair < int, int > >::iterator iter = bookInfo.begin(); iter != bookInfo.end(); iter++) {
            if(iter->first < end && start < iter->second)
                return false;
        }
        
        bookInfo.insert(make_pair(start, end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */