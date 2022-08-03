class MyCalendar {
private:
    set < pair < int, int > > bookInfo;
public:
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        for(set < pair < int, int > >::iterator iter = this->bookInfo.begin(); iter != this->bookInfo.end(); iter++) {
            if(iter->first < end && start < iter->second)
                return false;
            else if(end <= iter->first)
                break;
        }
        
        this->bookInfo.insert(make_pair(start, end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */