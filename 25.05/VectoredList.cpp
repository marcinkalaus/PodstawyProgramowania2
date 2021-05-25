#include "VectoredList.h"

#include <utility>
void VectoredList::push_back(string new_element) {
    {
        if(!tail || tail->count==10){
            auto *b=new Bucket();
            size++;
            capacity=10*size;
            if(head==0)
                head=b;
            if(tail)
                tail->next=b;
            if(tail)
                b->previous=tail;
            tail=b;
        }
        tail->append(std::move(new_element));
    }
}

string &VectoredList::operator[](size_t number_of_element) const {
    if(number_of_element > get_size())
        throw std::out_of_range("Size of the array is smaller than the number you gave");
    size_t bucket_number = (number_of_element - number_of_element%10 )/10;
    size_t index_in_last_bucket = number_of_element%10;
    Bucket* current_bucket = head;
    for(int i = 0; i < bucket_number; ++i)
    {
        current_bucket= current_bucket->next;
    }
    return current_bucket->tab[index_in_last_bucket];;
}

VectoredList::VectoredListIterator VectoredList::begin() const {
    VectoredListIterator v(*this);
    return v;
}

VectoredList::VectoredListIterator VectoredList::end() const {
    VectoredListIterator v(*this, this->get_size() -1 );
    return v;
}
size_t VectoredList::VectoredListIterator::return_index(const VectoredList &vector) const {
    VectoredList::VectoredListIterator it(vector);

    bool index_found = false;
    size_t index = 0;
    while(it.int_cursor != this->int_cursor && it.int_cursor != vector.end().int_cursor)
    {
        ++it;
        index++;
    }
    if(it.int_cursor == this->int_cursor)
        index_found = true;
    if(!index_found)
        throw std::invalid_argument("Index not found");
    return index;
}
void VectoredList::erase(VectoredList::VectoredListIterator &iterator) {

    try{
        if (this->is_empty())
            throw std::out_of_range("Your vectored_list is empty");
        size_t index = iterator.return_index(*this);
        string* temp_int = iterator.int_cursor;
        Bucket* temp_bucket = iterator.bucket_cursor;
        VectoredList::VectoredListIterator temp_iterator(*this,index);
        while(iterator != this->end())
        {
            ++temp_iterator;
            *(iterator.int_cursor) = *((temp_iterator).int_cursor);
            ++iterator;
        }
        //std::cout<< "Index: "<< index << " Number: "<< *iterator << std::endl;
        tail->count--;
        if(this->get_size() % 10 == 1)
        {
            //usuwanie kubelka
            tail = tail->previous;
            delete [] tail->next->tab;
            delete tail->next;
            tail->next = nullptr;
            size--;
            capacity-=10;
            iterator.int_cursor = end().int_cursor;
            iterator.bucket_cursor = end().bucket_cursor;
        }
        else
        {
            iterator.int_cursor = temp_int;
            iterator.bucket_cursor = temp_bucket;
        }
    }
    catch(std::exception &error)
    {
        cout << error.what()<<endl;
        return;
    }
}

void VectoredList::erase(VectoredList::VectoredListIterator &start_iterator,VectoredList::VectoredListIterator &end_iterator)
{
    cout<< "tail: "<< tail->tab[0]<<endl;
    try{
        if (this->is_empty())
            throw std::out_of_range("Your vectored_list is empty");
        size_t start_index = start_iterator.return_index(*this);
        size_t end_index = end_iterator.return_index(*this);
        if(start_index > end_index)
            throw std::invalid_argument("First iterator cannot be further than the 2nd one");
        string* temp_string_start = start_iterator.int_cursor;
        string* temp_string_end = end_iterator.int_cursor;
        Bucket* temp_bucket_start = start_iterator.bucket_cursor;
        Bucket* temp_bucket_end = end_iterator.bucket_cursor;

        VectoredList::VectoredListIterator temp_iterator(*this, end_index);
        cout<< "start: "<< *start_iterator<< " end: "<< *end_iterator<<endl;
        cout<< "tail: "<< tail->tab[0]<< " temp: "<< *temp_iterator.int_cursor<<endl;
        size_t current_tail = tail->count;
        if(end_index+1==this->get_size())
        {
            cout<< "usuwamy do konca tail: "<< tail->count<<" usuwamy:"<< end_index-start_index+1<< endl;

            //usuwamy wszystko do końca
            if(tail->count > end_index-start_index+1)
            {
                //dziala
                //cout<< "w tailu jest wiecej niz to ile usuwamy: tail: "<< tail->count<<" usuwamy:"<< end_index-start_index+1<< endl;
                tail->count -= (end_index-start_index+1);
            }
            else
            {
                size_t buckets_to_delete = (end_index-start_index+1 - tail->count)/N + 1;
                cout << "Buckets to delete: "<< buckets_to_delete<<endl;
                for(int i = 0; i < buckets_to_delete; ++i)
                {
                    tail = tail->previous;
                    delete[] tail->next->tab;
                    delete tail->next;
                    tail->next = nullptr;
                    size--;
                    capacity-=10;
                }
                //cout << "AFTER: tail->count "<< tail->count << " "<< tail->tab[0]<<endl;

                size_t left_indexes_to_delete = (end_index-start_index+1 - current_tail) - (buckets_to_delete-1)*N;
                //cout << "Index to delete: "<< left_indexes_to_delete<<endl;

                tail->count -= left_indexes_to_delete;
                end_iterator.int_cursor = start_iterator.int_cursor = end().int_cursor ;
                end_iterator.bucket_cursor = start_iterator.bucket_cursor = end().bucket_cursor ;
            }
        }
        else
        {
            cout<< "zostaje koncowka" << endl;
            cout<< "start_iterator: "<< *start_iterator<< " end_iterator: "<< *end_iterator<< " temp: " << *temp_iterator<< endl;
            while(start_iterator!=end_iterator)
            {

                ++temp_iterator;
                *(start_iterator.int_cursor) = *(temp_iterator.int_cursor);
                //cout<< "!!! start: " << *start_iterator.int_cursor << " temp: "<< *temp_iterator.int_cursor<<endl;
                if(temp_iterator== end())
                    break;
                ++start_iterator;
            }
            cout<< "start_iterator: "<< *start_iterator<< " end_iterator: "<< *end_iterator<< " temp: " << *temp_iterator<< endl;
            if(start_iterator==end_iterator)
            {
                cout<< "elo"<<endl;
                //usuwamy mniej elementow niz zostalo na koncu - trzeba wszystko przesunac
                while(temp_iterator!=end())
                {
                    *(start_iterator.int_cursor) = *(temp_iterator.int_cursor);
                    ++temp_iterator;
                    ++start_iterator;
                }
                //temp_iterator wskazuje na koniec
            }
            cout<< "tail: "<< tail->tab[0]<< " temp: "<< start_iterator.bucket_cursor->tab[0]<<endl;
            cout<< "start: "<< *start_iterator.int_cursor<< " temp: "<< *temp_iterator.int_cursor<<endl;
            cout<< "tail count: "<< tail->count<<endl;
            size_t buckets_to_delete = 0;
            while(tail != start_iterator.bucket_cursor)
                {
                    tail = tail->previous;
                    delete[] tail->next->tab;
                    delete tail->next;
                    tail->next = nullptr;
                    size--;
                    capacity-=10;
                    buckets_to_delete++;
                }
            size_t left_indexes_to_delete = (end_index-start_index+1 - current_tail) - (buckets_to_delete-1)*N;
            tail->count -= left_indexes_to_delete;
        }
    }
    catch(std::exception &error){
        cout << error.what()<<endl;
        return;
    }

}
void VectoredList::clean_vector() {
    // size - ile koszyczkow
    head = nullptr;
    tail = nullptr;
    size = 0;
    capacity = 0;
}
VectoredList &VectoredList::operator=(const VectoredList &vector_to_copy) {
    std::cout<<"const = was called"<< std::endl;
    if(&vector_to_copy!=this)
    {
        //usuwanie tego co obecnie jest w wektorze
        if(!is_empty())
            this->clean_vector();
        //kopiowanie zawartosci vector_to_copy

        for(int i = 0; i < vector_to_copy.get_size(); ++i)
        {
            this->push_back(vector_to_copy[i]);
        }
    }
    return *this;
}

bool VectoredList::is_empty() {
    if(get_size() > 0)
        return false;
    return true;
}

string &VectoredList::pop_back() {
    string& l= tail->tab[tail->count-1];
    tail->count--;
    if(!tail->count){
        Bucket *pom=tail;
        if(tail->previous){
            tail=tail->previous;

        }
        else tail=nullptr;
        delete pom;
        size--;
        capacity-=10;
        if(tail->next)
        {
            delete[] tail->next->tab;
            delete tail->next;
        }
        tail->next=nullptr;
    }
    return l;
}

VectoredList::VectoredList(VectoredList &&v) {
    head = v.head;
    tail = v.tail;
    size = v.size;
    capacity = v.capacity;

    v.clean_vector();
}

VectoredList & VectoredList::operator=(VectoredList &&v) {
    if(this != &v){
        head = v.head;
        tail = v.tail;
        size = v.size;
        capacity = v.capacity;

        v.clean_vector();
    }
    return *this;
}

VectoredList VectoredList::operator+(const VectoredList &rhs) const {
    VectoredList sum;

    for (int i = 0; i < this->get_size(); ++i){
        sum.push_back(this->operator[](i));
    }
    for (int i = 0; i < rhs.get_size(); ++i){
        sum.push_back(rhs[i]);
    }
    return sum;
}

void VectoredList::printVL() {
    for (int i = 0; i < this->get_size(); i++){
        std::cout << this->operator[](i);
    }
    std::cout << std::endl;
}

