​
priority_queue<int>maxh;
priority_queue<int,vector<int>,greater<int>>minh;
MedianFinder() {
}
void addNum(int num) {
if(maxh.top()>num || maxh.empty()){
maxh.push(num);
}
else{
minh.push(num);
}
//balancing heaps
if(maxh.size()>minh.size()+1){
minh.push(maxh.top());
maxh.pop();
}
if(minh.size()>maxh.size()+1){
maxh.push(minh.top());
minh.pop();
}
}
double findMedian() {
if(maxh.size()==minh.size()){
return (double)(maxh.top()+minh.top())/2.0;
}
else{
if(maxh.size()>minh.size()){
return maxh.top();
}
else{
return minh.top();
}
}
}