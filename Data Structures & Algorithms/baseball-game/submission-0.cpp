class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(const string& s: operations){
            if(s == "+" || s == "D" || s == "C"){
                if(s == "+"){
                    int num1 = st.top(); st.pop();
                    int num2 = st.top();

                    st.push(num1);
                    st.push(num1 + num2);
                }else if(s == "D"){
                    int num1 = st.top();

                    st.push(2 * num1);
                }else{
                    st.pop();
                }
            }else{
                st.push(stoi(s));
            }
        }
    
        int sum = 0;
        while(!st.empty()){
            sum += st.top();
            st.pop();
        }
    
        return sum;
    }
};