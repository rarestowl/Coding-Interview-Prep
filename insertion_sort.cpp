//to print the vector
void print_vector(vector<int> a){
	for(int i=0; i<a.size(); i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

//in increasing order
vector<int> min_to_max_insertion_sort(vector<int> a){
	for(int i=1; i<a.size(); i++){
		int key=a[i];
		int j=i-1;
		while(j>=0 && a[j]>key){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
	return a;
}

//in decreasing order
vector<int> max_to_min_insertion_sort(vector<int> a){
	for(int i=1; i<a.size(); i++){
		int key=a[i];
		int j=i-1;
		while(j>=0 && a[j]<key){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
	return a;
}


