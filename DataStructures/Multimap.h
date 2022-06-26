

#ifndef PROIECT_MARE_MULTIMAP_H
#define PROIECT_MARE_MULTIMAP_H
#include <iostream>
#include <vector>
using namespace std;
template <class Key, class Value>
class Multimap {
private:
    template <class K, class V>
    class MapNode {
    public:
        K key;
        V value;
        MapNode<K,V>* next;
        MapNode(K key, V value) : key(key), value(value){ this->next= nullptr;}
    };
    template<class V>
    class ListNode {
    public:
        V info;
        ListNode<V> *next;
        ListNode(V info, ListNode<V> *next) : info(info), next(next) {}
        ListNode(V info) : info(info) { next = nullptr; }
    };
    int size;
    MapNode<Key,ListNode<Value>*>* first;

    MapNode<Key, ListNode<Value>*>* searchAdress(Key k){
        if(this->size == 0) return nullptr;
        MapNode<Key, ListNode<Value>*>* p = first;
        while(p->next != nullptr){
            if(p->key == k) return p;
            p = p->next;
        }
        return p;
    }
    /**
     * Search by Adress
     * @param k key
     * @return Returns a adress to the first element in key, if it doesnt have will return a nullptr
     */
    MapNode<Key, ListNode<Value>*>* searchAdress_v2(Key k){
        if(this->size == 0) return nullptr;
        MapNode<Key, ListNode<Value>*>* p = first;
        while(p!= nullptr){
            if(p->key == k) return p;
            p = p->next;
        }
        return nullptr;
    }

public:
    Multimap(){
        this->first = nullptr;
        this->size = 0;
    }/**
 * Pune valoarea la cheia key
 * @param key key
 * @param value value
 */
    void put(Key key, Value value){
        MapNode<Key, ListNode<Value>*>* poz = searchAdress(key);

        if(poz == nullptr){

            this->first = new MapNode<Key, ListNode<Value>*>(key, new ListNode<Value>(value));
            this->size++;
        }else{
            if(poz->key == key){
                ListNode<Value>* node = new ListNode<Value>(value, poz->value);
                poz->value = node;
            }else{
                poz->next = new MapNode<Key, ListNode<Value>*>(key, new ListNode<Value>(value));
                this->size++;
            }
        }
    }
/**
 * Removes all elements at key
 * @param key key
 * @return a vector with all values in key
 */
    vector<Value> remove(Key key){
        MapNode<Key, ListNode<Value>*>* poz = searchAdress(key);
        vector<Value> result;

        if(poz != nullptr && poz->key == key){
            MapNode<Key, ListNode<Value>*>* p = first;
            if(poz == first) this->first = poz->next;
            else {
                while(p->next != poz) p = p->next;
                p->next = poz->next;
            };
            while(poz->value != nullptr){
                ListNode<Value>* node = poz->value;
                result.push_back(node->info);
                poz->value = node->next;
                delete node;
            }
            this->size--;
            delete poz;
        }
        return result;
    }
    /**
     * Get intems by key
     * @param key key
     * @return result - a vector with all values
     */
    vector<Value> get_items_by_key(Key key){
        vector<Value> result;
        MapNode<Key, ListNode<Value>*>* poz = searchAdress_v2(key);
        if(poz == nullptr)
            return result;
        ListNode<Value>* temp = poz->value;
        while (poz->value!= nullptr){
            ListNode<Value>* node = poz->value;
            result.push_back(node->info);
            poz->value = node->next;
        }
        poz->value = temp;
        return result;
    }
    /**
     * Updateas the values
     * @param key key
     * @param old_value old value
     * @param new_value new value
     */
    void update(Key key,Value old_value,Value new_value){
        MapNode<Key, ListNode<Value>*>* poz = searchAdress(key);
        vector<Value> result;

        if(poz != nullptr && poz->key == key){
            MapNode<Key, ListNode<Value>*>* p = first;
            if(poz == first) this->first = poz->next;
            else {
                while(p->next != poz) p = p->next;
                p->next = poz->next;
            };
            while(poz->value != nullptr){
                ListNode<Value>* node = poz->value;
                result.push_back(node->info);
                if(node->info==old_value)
                    node->info = new_value;
                poz->value = node->next;
            }
        }
    }

};


#endif //PROIECT_MARE_MULTIMAP_H
