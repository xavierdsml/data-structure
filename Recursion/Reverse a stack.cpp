void f(stack<int> &st, queue<int> &qt){
    while(!st.empty()){
        int ele = st.top();
        qt.push(ele);
        st.pop();
    }
}
void reverseStack(stack<int> &stack) {
   queue<int>qt;
   f(stack, qt);
   while(!qt.empty()){
       int ele = qt.front();
       stack.push(ele);
       qt.pop();
   }
}
