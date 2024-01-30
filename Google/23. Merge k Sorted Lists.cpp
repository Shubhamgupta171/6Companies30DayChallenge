class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      int n=lists.size();
        if(n==0)
            return NULL;
        vector<pair<int, ListNode*>> arr; 
        for(int i = 0; i < n; i++) 

        {

            ListNode* curr_list = lists[i];

            

            while(curr_list != NULL) 

            {

                arr.push_back({curr_list -> val, curr_list}); // push into vector

                curr_list = curr_list -> next;

            }

        }
        int k=arr.size();
        if(k==0)
            return NULL;
        sort(arr.begin(),arr.end());
        for(int i=0;i<k-1;i++){
            arr[i].second->next=arr[i+1].second;
        
        }
        arr[k-1].second->next=NULL;
        return arr[0].second;
    }
};
