Approach is simple. We need a number which is minimum, thus we need to remove the most significant digits first. For eg. if we have a number having digits 1-4 then 1234 would be the minimum and not 2314 or anything else. So in case of 2314, we remove 3 first, and then we go for 2 (Because they are more significant than 4). Observing this simple idea, we need to remove any digit which is greater than its following digit. Thats why we deleted 3 as it was greater than 1 and similiarly 2 as it was also greater than 1.
​
In order to accomplish this, we use stack Data Structure where we pop the top if it is greater than current digit.
​
The conditions mentioned in while loop are important to avoid any Runtime Error. For eg. ["10001" 2] the answer is "0" but if we don't mention the condition !s.empty(), then the while loop will run on empty stack and try to pop the top which doesn't exist thus throwing RE.
​
stack <char> s;
for(int i = 0; i<str.length(); i++){
while(k>0 && !s.empty() && str[i]<s.top()){
k--;
s.pop();
}
s.push(str[i]);
// We pop any preceeding zeroes
if(s.size() == 1 && str[i] == '0')
s.pop();
}
// For cases like "12345" where every str[i] > s.top()
while(k && !s.empty()){
k--;
s.pop();
}
string res;
while(!s.empty()){
res.push_back(s.top());
s.pop();
}
reverse(res.begin(), res.end());
if(res.size() == 0)
return "0";
else
return res;