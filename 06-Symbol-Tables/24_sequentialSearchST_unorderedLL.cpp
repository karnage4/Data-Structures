#include<iostream>
#include<vector>
#include<stdexcept>
#include<string>
using namespace std;

template<typename Key, typename Value>
class SequentialSearchST{
    struct node{
        Key key;
        Value val;
        node* next;

        node(Key k, Value v, node* n) : key(k), val(v), next(n){}
    };

    node* head;

    public:
    SequentialSearchST(){
        head = NULL;
    }
    ~SequentialSearchST(){
        while ( head!= NULL){
            node* ptr = head;
            head = head->next;
            delete(ptr);
        }
    }

    //get the value associated with the given key
    Value get(const Key& key){
        node* ptr = head;
        while(ptr!=NULL){
            if(key == ptr->key){
                return ptr->val; //search hit
            }
            ptr = ptr->next;
        }
        throw runtime_error("Key-Value pair doesnt exist..."); //search miss
    }

    //put the new key value pair, if the key already exists, update the value
    void put(const Key& key,const Value& val){
        node* ptr = head;
        while(ptr!=NULL){
            if (key == ptr->key){
                ptr->val= val; //search hit 
                return;
            }
            ptr = ptr->next;
        }

        head = new node(key,val,head); //search miss
    }

    //check if symbol table contains the key
    bool contains(const Key& key){
        try{
            get(key);
            return true;
        }
        catch(const runtime_error&){
            return false;
        }
    }

    //delete the key and the value associated with it
    void deleteKey(const Key& key){
        node* prev = NULL;
        node* curr = head;
        while(curr!= NULL){
            if (key == curr->key){
                
                if (prev==NULL){
                    head = curr->next; //remove first node
                }
                else{
                    prev->next = curr->next; //bypass node
                }
                delete(curr);
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        throw runtime_error("Key not in table...");
    }

    bool isempty(){
        return head==NULL;
    }

    int size(){
        node* ptr = head;
        int count =0 ;
        while(ptr!=NULL){
            count++;
            ptr = ptr->next;
        }   
        return count;
    }

    //return a list of all the keys in the table
    vector<Key> keys(){
        node* ptr = head;
        vector<Key> allkeys;
        while(ptr!=NULL){
            allkeys.push_back(ptr->key);
            ptr= ptr->next;
        }

        return allkeys;
    }

    void traverse(){
        // node* ptr = head;
        // while(ptr!=NULL){
        //     cout << ptr->key << " | " << ptr->val<<endl;
        //     ptr=ptr->next;
        // }
        node* ptr = head;
        vector<Key> allkeys;
        vector<Value> allsymbols;
        while(ptr!=NULL){
            allkeys.push_back(ptr->key);
            allsymbols.push_back(ptr->val);
            ptr= ptr->next;
        }
        for(int i=allkeys.size()-1; i<allkeys.size(); i--){
            cout << allkeys[i] << " | " << allsymbols[i]<<endl;
        }
    }
};

int main(){
    SequentialSearchST<string,int> st;
    st.put("a",5);
    st.put("b",3);
    st.put("c",7);
    
    st.put("a",2);
    st.put("d",5);
    st.traverse();
    cout << endl;
    
    cout << "size: "<< st.size() << endl;
    cout << st.get("c") << endl;
    cout <<boolalpha<<st.contains("a")<<endl;
    st.deleteKey("c");
    // st.traverse();
    cout << "c deleted"<<endl;
    cout << endl;
    vector<string> keys = st.keys();
    cout << "Keys: " <<endl;
    for (int i=keys.size()-1; i<keys.size(); i--){
        cout << keys[i] << endl;
    }
}