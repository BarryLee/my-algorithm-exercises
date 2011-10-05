#include <cstddef>
#include <vector>

using std::vector;

template<class T>
class Heap {
public:
    Heap() {}
    virtual ~Heap() {}
    Heap(const vector<T> &vec);
    size_t size() { return sz; }
    virtual T& pop();
    virtual const T& top() const;
    virtual void insert(const T&) = 0;
//protected:
    size_t sz;
    vector<T> arr;

    virtual void heapify(size_t) = 0;
    size_t parent(size_t i) { return (i-1)/2; }
    size_t left(size_t i) { return 2*i+1; }
    size_t right(size_t i) { return 2*i+2; }
    void exchange(size_t i, size_t j)
    {
        T temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
};

template<class T>
class Max_heap: public Heap<T> {
public:
    Max_heap() {}
    Max_heap(const vector<T> &vec): Heap<T>(vec) {};
    void insert(const T&);
private:
    void heapify(size_t);
};

