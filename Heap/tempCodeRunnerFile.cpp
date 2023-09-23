priority_queue<int>maxh;
    for(int i=0;i<6;i++)
    {
        maxh.push(arr[i]);
        if(maxh.size()>k)
            maxh.pop(); 

        //cout<<maxh.top()<<" ";       
    }
    //cout<<endl;
    return maxh.top();