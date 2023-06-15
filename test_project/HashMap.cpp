////#include<iostream>
////#include<cstdlib>
////#include<string>
////#include<cstdio>
////
////using namespace std;
////const int NumItems = 200;
////
////class OpenHash{
////public:
////    int k, v;
////    OpenHash(int k, int v) : k(k), v(v){
////    }
////
////};
////
////class Hash{
////private:
////    OpenHash **t;
////public:
////    Hash(){
////        t = new OpenHash*[NumItems];
////        for(int i = 0; i < NumItems; i++){
////            t[i] = NULL;
////        }
////    }
////    int HashFunc(int k){
////        return k % NumItems;
////    }
////    void InsertItem(int k, int v){
////        int h = HashFunc(k);
////        while(t[h] != NULL && t[h]->k != k){
////            h = HashFunc(h + 1);
////        }
////        if(t[h] != NULL){
////            delete t[h];
////        }
////        t[h] = new OpenHash(k,v);
////    }
////    int RetrieveItem(int k){
////        int h = HashFunc(k);
////        while(t[h] != NULL && t[h] ->k !=k){
////            h = HashFunc(h +1);
////        }
////        if(t[h] == NULL){
////            return -1;
////        } else {
////            return t[h]->v;
////        }
////    }
////    void DeleteItem(int k){
////        int h = HashFunc(k);
////        cout<<t[h]<<endl;
////        while(t[h] != NULL){
////            if(t[h]->k ==k)
////                break;
////            h = HashFunc(h+1);
////        }
////        if(t[h] == NULL){
////            cout<< "No Element found";
////        }else{
////            delete t[h];
////            t[h] = NULL;
//////            cout<<t[h]<<endl;
////        }
////
////    }
////    ~Hash(){
////        for(int i = 0; i<NumItems; i++){
////            if(t[i] != NULL)
////                delete t[i];
////        }
////        delete[] t;
////    }
////};
//////int main(){
//////
//////
//////}
//#include <iostream>
//const int NumItems = 200;
//using namespace std;
//struct OpenHash {
//   int d, k;
//   OpenHash *n;
//   OpenHash *p;
//};
//class Hash {
//public:
//    OpenHash **ht, **top;
//    Hash() {
//        ht = new OpenHash*[NumItems];
//        top = new OpenHash*[NumItems];
//        for (int i = 0; i < NumItems; i++) {
//            ht[i] = NULL;
//            top[i] = NULL;
//        }
//    }
//    int HashFunc(int key) {
//        return key % NumItems;
//    }
//    void InsertItem(int k, int v) {
//        bool flag_ = true;
//        int hash_v= HashFunc(k);
//        OpenHash *en = ht[hash_v];
//        if (en == NULL) {
//            en = new OpenHash;
//            en->d = v;
//            en->k = k;
//            en->n = NULL;
//            en->p = NULL;
//            ht[hash_v] = en;
//            top[hash_v] = en;
//        } else {
//            while (en != NULL)
//            {
//                if(en->k == k){
//                    en->d = v;
//                    flag_ = false;
//                    cout<<"fund"<<endl;
//                    break;
//                }
//                en = en->n;
//
//            }
//            if(flag_){
//                en = new OpenHash;
//                en->d = v;
//                en->k = k;
//                en->n = NULL;
//                en->p = top[hash_v];
//                top[hash_v]->n = en;
//                top[hash_v] = en;
//
//            }
//        }
//    }
//    void DeleteItem(int k) {
//        int hash_v = HashFunc(k);
//        OpenHash *en = ht[hash_v];
//        if (en->k != k || en == NULL) {
//            cout<<"No Element found at key: "<<k<<endl;
//            return;
//        }
//        while (en != NULL) {
//            if (en->n == NULL) {
//                if (en->p == NULL) {
//                    ht[hash_v] = NULL;
//                    top[hash_v] = NULL;
//                    delete en;
//                    break;
//                } else {
//                    top[hash_v] = en->p;
//                    top[hash_v]->n = NULL;
//                    delete en;
//                    en = top[hash_v];
//                }
//            }
//            en = en->n;
//        }
//    }
//    void RetrieveItem(int k) {
//        int hash_v = HashFunc(k);
//        bool flag = false;
//        OpenHash* en = ht[hash_v];
//        if (en != NULL) {
//            while (en != NULL) {
//                if (en->k == k) {
//                    flag = true;
//                }
//                if (flag) {
//                    cout<<"Element found at key "<<k<<": ";
//                    cout<<en->d<<endl;
//                    break;
//                }
//
//                en = en->n;
//            }
//        }
//        if (!flag)
//            cout<<"No Element found at key "<<k<<endl;
//    }
//    ~Hash() {
//        delete [] ht;
//    }
//};

//#include <iostream>
//
//using namespace std;
//struct OpenHash {
//   int d, k;
//   OpenHash *n;
//   OpenHash *p;
//};
//class Hash {
//    int NumItems;
//public:
//    OpenHash **ht, **top;
//    Hash(int NumItems = 100) : NumItems(NumItems) {
//
//        ht = new OpenHash*[NumItems];
//        top = new OpenHash*[NumItems];
//        for (int i = 0; i < NumItems; i++) {
//            ht[i] = NULL;
//            top[i] = NULL;
//        }
//    }
//
//    int HashFunc(int key) {
//        return key % NumItems;
//    }
//
//    bool InsertItem(int k, int v) {
//        int hash_v = HashFunc(k);
//        OpenHash *en = ht[hash_v];
//        if (en == NULL) {
//            en = new OpenHash;
//            en->d = v;
//            en->k = k;
//            en->n = NULL;
//            en->p = NULL;
//            ht[hash_v] = en;
//            top[hash_v] = en;
//        } else {
//            while (en->n != NULL) {
//                if(en->k == k){
//                    en->d = v;
//                    return true;
//                }
//                en = en->n;
//
//            }
//            if(en != NULL && en->k == k){
//                en->d = v;
//                return true;
//            }
//            en->n = new OpenHash;
//            en->n->d = v;
//            en->n->k = k;
//            en->n->n = NULL;
//            en->n->p = en;
//            top[hash_v] = en->n;
//            return true;
//        }
//    }
//
//    bool DeleteItem(int k) {
//        int hash_v = HashFunc(k);
//        OpenHash *en = ht[hash_v];
//        if (en == NULL) {
//            cout << "No Element found at key: " << k << endl;
//            return false;
//        }
//        if (en->k == k) {
//            ht[hash_v] = en->n;
//            if (ht[hash_v] != NULL) {
//                ht[hash_v]->p = NULL;
//            } else {
//                top[hash_v] = NULL;
//            }
//            delete en;
//            cout<<"Delete k";
//            return true;
//        }
//        while (en != NULL && en->k != k) {
//            en = en->n;
//        }
//        if (en == NULL) {
//            cout << "No Element found at key: " << k << endl;
//            return false;
//        }
//        en->p->n = en->n;
//        if (en->n != NULL) {
//            en->n->p = en->p;
//        } else {
//            top[hash_v] = en->p;
//        }
//        delete en;
//        return true;
//    }
//
//    bool RetrieveItem(int k) {
//        int hash_v = HashFunc(k);
//        bool flag = false;
//        OpenHash* en = ht[hash_v];
//        if (en != NULL) {
//            while (en != NULL) {
//                if (en->k == k) {
//                    flag = true;
//                }
//                if (flag) {
//                    cout<<"Element found at key "<<k<<": ";
//                    cout<<en->d<<endl;
//                    return true;
//                    break;
//                }
//
//                en = en->n;
//            }
//        }
//        if (!flag)
//            {
//                cout<<"No Element found at key "<<k<<endl;
//                return false;
//            }
//        return false;
//
//    }
//    ~Hash() {
//        delete [] ht;
//    }
//
//};


#include <iostream>

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
