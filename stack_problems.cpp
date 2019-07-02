/************************ maximum rectangle area **********************/
void maximum_rectangle_area(){
    int n;
    cin>>n;
    int hist[n];
    int maxArea = 0;
    int i=0;
    for(i=0; i<n; i++)
        cin>>hist[i];
    stack<int> st;
    i=0;
    while(i<n){
        if(st.empty() || hist[i]>=hist[st.top()]){
            st.push(i);
            i++;
        }
        else{
            int now = hist[st.top()];
            st.pop();
            int area_with_now = st.empty()? now*i : now*(i-st.top()-1);
            maxArea = max(maxArea, area_with_now);
        }
    }
    while(!st.empty()){
        int now = hist[st.top()];
        st.pop();
        int area_with_now = st.empty()? now*i : now*(i-st.top()-1);
        maxArea = max(maxArea, area_with_now);
    }
    cout<<maxArea<<endl;
}
/****************************************************************************/
