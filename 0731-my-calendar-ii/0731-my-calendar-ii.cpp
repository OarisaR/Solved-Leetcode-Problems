/*
- 2 overlaps are allowed


*/
class MyCalendarTwo {
public:
    map<int, int> events;
    MyCalendarTwo() {}

    bool book(int startTime, int endTime) {
        events[startTime] += 1;
        events[endTime] -= 1;
        ; // start,end-1 interval. so here end-1+1 = end
        int cnt = 0;
        for (auto& it : events) {
            cnt += it.second;
            if (cnt > 2) {
                // remove frm calender
                events[startTime] -= 1;
                events[endTime] += 1;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */