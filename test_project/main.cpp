//#include "BS.cpp"
//#include "HashMap.cpp"
#include <iostream>
#include "Recursion.cpp"

using namespace std;
struct OpenHash {
   int d, k;
   OpenHash *n;
   OpenHash *p;
};
class Hash {
    int NumItems;
public:
    OpenHash **ht, **top;
    Hash(int NumItems = 100) : NumItems(NumItems) {

        ht = new OpenHash*[NumItems];
        top = new OpenHash*[NumItems];
        for (int i = 0; i < NumItems; i++) {
            ht[i] = NULL;
            top[i] = NULL;
        }
    }

    int HashFunc(int key) {
        return key % NumItems;
    }

    bool InsertItem(int k) {
        int v = k;
        int hash_v = HashFunc(k);
        OpenHash *en = ht[hash_v];
        if (en == NULL) {
            en = new OpenHash;
            en->d = v;
            en->k = k;
            en->n = NULL;
            en->p = NULL;
            ht[hash_v] = en;
            top[hash_v] = en;
        } else {
            while (en->n != NULL) {
                if(en->k == k){
                    en->d = v;
                    return true;
                }
                en = en->n;

            }
            if(en != NULL && en->k == k){
                en->d = v;
                return true;
            }
            en->n = new OpenHash;
            en->n->d = v;
            en->n->k = k;
            en->n->n = NULL;
            en->n->p = en;
            top[hash_v] = en->n;
            return true;
        }
        return true;
    }

    bool DeleteItem(int k) {
        int hash_v = HashFunc(k);
        OpenHash *en = ht[hash_v];
        if (en == NULL) {
            cout << "No Element found at key: " << k << endl;
            return false;
        }
        if (en->k == k) {
            ht[hash_v] = en->n;
            if (ht[hash_v] != NULL) {
                ht[hash_v]->p = NULL;
            } else {
                top[hash_v] = NULL;
            }
            delete en;
            cout<<"Delete k";
            return true;
        }
        while (en != NULL && en->k != k) {
            en = en->n;
        }
        if (en == NULL) {
            cout << "No Element found at key: " << k << endl;
            return false;
        }
        en->p->n = en->n;
        if (en->n != NULL) {
            en->n->p = en->p;
        } else {
            top[hash_v] = en->p;
        }
        delete en;
        return true;
    }

    bool RetrieveItem(int k) {
        int hash_v = HashFunc(k);
        bool flag = false;
        OpenHash* en = ht[hash_v];
        if (en != NULL) {
            while (en != NULL) {
                if (en->k == k) {
                    flag = true;
                }
                if (flag) {
                    cout<<"Element found at key "<<k<<endl;
//                    cout<<en->d<<endl;
                    return true;
                    break;
                }

                en = en->n;
            }
        }
        if (!flag)
            {
                cout<<"No Element found at key "<<k<<endl;
                return false;
            }
        return false;

    }
    ~Hash() {
        delete [] ht;
    }

};

// int main(){
//     Hash hash;


//     cout<<hash.InsertItem(20);
//     cout<<hash.InsertItem(20);
//     cout<<hash.InsertItem(30)<<endl;
//     cout<<hash.RetrieveItem(30)<<endl;
//     cout<<hash.RetrieveItem(300)<<endl;
//     cout<<hash.RetrieveItem(320)<<endl;
//     cout<<hash.InsertItem(320)<<endl;
//     cout<<hash.RetrieveItem(320)<<endl<<endl;
//     cout<<hash.DeleteItem(320)<<endl;
//     cout<<hash.DeleteItem(320)<<endl;
// }

