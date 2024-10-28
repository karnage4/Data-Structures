#include<iostream>
#include<stdexcept>
#include<vector>
#include<string>
using namespace std;

template<typename Key, typename Value>
class binarySearchST{
    Key* keys;
    Value* vals;
    int n;
    int capacity;

    void resize(int newcap){
        Key* tempk = new Key[newcap];
        Value* tempv = new Value[newcap];
        for ( int i=0; i<n; i++){
            tempk[i] = keys[i];
            tempv[i] = vals[i];
        }
        delete[] keys;
        delete[] vals;
        keys = tempk;
        vals = tempv;
        capacity = newcap;
    }

    public:
    binarySearchST(int c): capacity(c), n(0){
        keys = new Key[capacity];
        vals = new Value[capacity];
    }
    ~binarySearchST(){
        delete[] keys;
        delete[] vals;
    }

    bool isempty() const{
        return n==0;
    }
    bool isfull() const{
        return n==capacity;
    }
    bool contains(const Key& key) const{
        int i = rank(key);
        return (i<n && key==keys[i]);
    }

    int rank(const Key& key) const {
        int lo = 0;
        int hi = n-1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;

            if (key < keys[mid]) hi = mid-1;
            else if (key > keys[mid]) lo =mid +1;
            else return mid; //key found
        }
        return lo;  //key not found , return insertion point
    }

    Value get(const Key& key) const{ //return value associated with key
        if (isempty()) throw runtime_error("symbol table empty...");
        
        int i = rank(key);
        if(i<n && key == keys[i]) return vals[i];

        throw runtime_error("value not found...");
    }

    void put(const Key& key, const Value& val){
        int i = rank(key);

        if (i<n && key==keys[i]) {
            vals[i] = val; //update existing value
            return;
        }

        if ( n==capacity) resize(2*capacity); //resize if full

        for ( int j = n; j>i; --j){ //make space and shift elements to the right, to insert the new key
            keys[j] = keys[j-1];
            vals[j] = vals[j-1];
        }

        keys[i] = key;  //now insert
        vals[i] = val;
        n++;    
    }

    void deleteKey(const Key& key){
        if  (isempty()) throw runtime_error("symbol table is empty...");

        int i = rank(key);
        if ( i==n || key!=keys[i]) throw runtime_error("key not found...");

        for (int j=i; j<n-1; ++j){
            keys[j] = keys[j+1];
            vals[j] =vals[j+1];
        }

        n--;
    }

    Key min() const{ //returns minimum key
        if (isempty()) throw out_of_range("symbol table empty...");
        return keys[0];
    }

    Key max() const{ //return max key
        if(isempty()) throw out_of_range("symbol table empty...");
        return keys[n-1];
    }

    void deletemin(){
        if(isempty()) throw out_of_range("symbol table empty...");
        deleteKey(min());
    }

    void deletemax(){
        if(isempty()) throw out_of_range("symbol table empty...");
        deleteKey(max());
    }

    Key select(int k) const{ //returns key at index k
        if(isempty()) throw out_of_range("symbol table empty...");
        if (k<0 || k>= n) throw invalid_argument("k out of bound...");
        return keys[k];
    }

    Key floor(const Key& key) const{ //return largest key less than or equal to key
        if(isempty()) throw out_of_range("symbol table empty...");
        int i = rank(key);
        if(i<n && key==keys[i]) return keys[i];
        if (i==0) throw runtime_error("rank out of bound..."); //sabse pehle element se neeche nahi hosakta koi aur
        return keys[i-1]; 
    }

    Key ceiling(const Key& key) const{
        if(isempty()) throw out_of_range("symbol table empty...");
        int i = rank(key);
        if (i==n) throw runtime_error("rank out of bound..."); //sabse uper wale element se uper aur koi nahi hosakta
        return keys[i];
    }

    vector<Key> getkeys() const{
        return getkeys(min(),max());
    }

    vector<Key> getkeys(const Key& lo, const Key& hi) const{

        vector<Key> result;
        if (lo>hi) return result; //return empty vector if lo>hi
        int start = rank(lo); //get the range of indices for keys in [lo,hi]
        int end = rank(hi); 

        for(int i=start; i<=end && i<n; i++){ //add keys in the range [lo,hi)
            result.push_back(keys[i]);
        }

        // if (contains(hi)) result.push_back(keys[end]);

        return result;
        // std::vector<Key> queue;
        // if (lo > hi) return queue;
        // for (int i = rank(lo); i < rank(hi); i++)
        //     queue.push_back(keys[i]);
        // if (contains(hi)) queue.push_back(keys[rank(hi)]);
        // return queue;
    }

    void traverse() {
        for (int i = 0; i < n; i++) {
            cout << keys[i] << " | " << vals[i] << endl;
    }
    }
};

int main(){
    binarySearchST<string,int> st(5);
    st.put("Alice",10);
    st.put("Karam",11);
    st.put("Ali",5);
    st.put("Darius",6);
    st.put("Charlie",8);
    st.put("Umar", 4);
    st.traverse();
    cout << endl;

    // cout<<st.rank("Ali")<<endl;
    // cout<<st.rank("Alice")<<endl;

    cout << "min: "<< st.min()<<endl;
    cout << "max: "<< st.max()<<endl;
    cout <<"select(1): "<< st.select(1)<<endl;
    cout << endl;

    cout << "ceiling of karam: "<<st.ceiling("Karam")<<endl;
    cout << "floor of charlie: "<<st.floor("Charlie")<<endl;
    cout << endl;

    vector<string> v =  st.getkeys("Ali","Umar");
    for (auto& i:v){
        cout << i<<endl;
    }

};
