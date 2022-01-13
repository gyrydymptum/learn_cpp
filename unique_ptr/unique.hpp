#include <memory>

template <typename T>
class defultDeleter { //based on the course Mateusz
public:
    void operator()(T* ptr) const {
        static_assert(!std::is_void<T>::value,
                      "can't delete pointer to incomplete type");
        static_assert(sizeof(T) > 0,
                      "can't delete pointer to incomplete type");
        delete ptr;
    }
};
template <typename T, typename Deleter = defultDeleter<T>>
class UniquePtr {

public:
//Construktors
    UniquePtr(T* ptr)
        : ptr_(ptr) {}

    UniquePtr(T* ptr, const Deleter& deleter)
        : ptr_(ptr), deleter_(deleter) {}

    UniquePtr(T* ptr, const Deleter&& deleter)
        : ptr_(ptr), deleter_(std::move(deleter)) {}

    UniquePtr(std::nullptr_t)
        : ptr_(nullptr) {}

    UniquePtr()
        : ptr_(nullptr) {}
    
    UniquePtr(const UniquePtr&) = delete; //delete copy constructor

//Destructors
    ~UniquePtr(){
        if (ptr_)
            deleter_(ptr_);
        ptr_ = nullptr;
    }

// Operators
    UniquePtr& operator = (const UniquePtr&) = delete; // delete copy assignment operator
    UniquePtr& operator = (nullptr_t) {
        reset(nullptr);
        return *this;  
    }
    explicit operator bool() const {
        return ptr_;
    }
    T* operator->() {
        return ptr_;
    }
    const T* operator->() const {
        return ptr_;
    }
    T& operator*() {
        return *ptr_;
    }
    const T& operator*() const {
        return *ptr_;
    }

//Move

    UniquePtr(UniquePtr&& other) noexcept {
        ptr_ = other.release();
        deleter_ = std::forward<Deleter>(other.getDeleter());
    }
    UniquePtr& operator = (UniquePtr&& other) noexcept{
        if (this == &other) {
            return *this;
        }
        reset(other.release());
        return *this;
    }
    // UniquePtr(UniquePtr<T>&& other) noexcept
    // : ptr_(other.ptr_) {
    //     other.ptr_= nullptr;
    // }

//metodhs
    T* get() {
        return ptr_;
    }
    const T* get() const {
        return ptr_;
    }
    Deleter& getDeleter() {
        return deleter_;
    }
    const Deleter& getDeleter() const {
        return deleter_;
    }

    void reset(T* ptr) {
        if (ptr_)
            deleter_(ptr_);
        ptr_ = ptr;
    }
    T* release() {
        return std::exchange(ptr_, nullptr);
    }
    void swap(UniquePtr& other) noexcept {
        std::swap(other, *this);
    }

    private:
    T* ptr_ = nullptr;
    Deleter deleter_;
};