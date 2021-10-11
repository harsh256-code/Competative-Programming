#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>a(N),seg(N),lazy(N,0);
void build(int idx,int low,int high){
    if(low==high){
        seg[idx]=a[low];
        return;
    }
    int mid=(low+high)/2;
    build(2*idx+1,low,mid);
    build(2*idx+2,mid+1,high);
    seg[idx]=seg[2*idx+1]+seg[2*idx+2];
}
int query_sum(int idx,int low,int high,int l,int r){
    if(low>=l and high<=r){
        return seg[idx];
    }
    if(high<l or low>r)return 0;
    int mid=(low+high)/2;
    int left=query_sum(2*idx+1,low,mid,l,r);
    int right=query_sum(2*idx+2,mid+1,high,l,r);
    return left+right;

}
void Pointupdate(int idx,int low,int high,int node,int val){
    if(low==high){
        seg[idx]+=val;
        return;
    }
    int mid=(low+high)>>1;
    if(node>=low and node<=mid)Pointupdate(2*idx+1,low,mid,node,val);
    else Pointupdate(2*idx+2,mid+1,high,node,val);
    seg[idx]=seg[2*idx+1]+seg[2*idx+2];
    
}
void Range_Upadate(int idx,int low,int high,int l,int r,int val){
    if(lazy[idx]!=0){
        seg[idx]+=(high-low+1)*lazy[idx];
        if(low!=high){
            lazy[2*idx+1]+=lazy[idx];
            lazy[2*idx+2]+=lazy[idx];
        }
        lazy[idx]=0;
    }
    if(r<low or l>high or low>high)return;
    if(low>=l and high<=r){
        seg[idx]+=(high-low+1)*val;
        if(low!=high){
            lazy[2*idx+1]+=val;
            lazy[2*idx+2]+=val;
        }
        return ;
    }
    int mid=(low+high)>>1;
    Range_Upadate(2*idx+1,low,mid,l,r,val);
    Range_Upadate(2*idx+2,mid+1,high,l,r,val);
    seg[idx]=seg[2*idx+1]+seg[2*idx+2];

}
int query_sum_lazy(int idx,int low,int high,int l ,int r){
    if(lazy[idx]!=0){
        seg[idx]+=(high-low+1)*lazy[idx];
        if(low!=high){
            lazy[2*idx+1]+=lazy[idx];
            lazy[2*idx+2]+=lazy[idx];
        }
        lazy[idx]=0;
    }
    if(r<low or l>high or low>high)return 0;
    if(low>=l and high<=r){
        return seg[idx];
    }
    int mid=(low+high)>>1;
    return query_sum_lazy(2*idx+1,low,mid,l,r)+query_sum_lazy(2*idx+2,mid+1,high,l,r);
}
int main(){
    int n;
    cin>>n;
    int node,val;
    for(int i=0;i<n;i++)cin>>a[i];
    build(0,0,n-1);
    int l,r;
    cin>>l>>r;
    cout<<query_sum_lazy(0,0,n-1,l,r)<<endl;
    cin>>l>>r>>val;
    Range_Upadate(0,0,n-1,l,r,val);
    cin>>l>>r;
    cout<<query_sum(0,0,n-1,l,r)<<endl;
    // int q;
    // cin>>q; //20 16 19
    // while(q--){
    //     int l,r;
    //     cin>>l>>r;
    //     cout<<query(0,0,n-1,l,r)<<endl;

    // }
    return 0;
}