void insert(stack<int> &st,int var){
	if(st.empty()==true || st.top()<var){
		st.push(var);
	}
	else{
		int temp = st.top();
		st.pop();
		insert(st,var);
		st.push(temp);
	}
}
void sortStack(stack<int> &stack)
{
	if(stack.empty()==true){
		return ;
	}
	int temp = stack.top();
	stack.pop();
	sortStack(stack);
	insert(stack,temp);
}


//time complexity : O(N2)
//space complexity : O(N)