#include <memory>
template <typename Type>
class RuleOf5 {
    Type* ptr_;

public:
    RuleOf5(Type* resource) : ptr_(resource) {}                     //constructor copy the pointer
    RuleOf5(RuleOf5 const& other) : ptr_(new Type{*other.ptr_}) {}  //copy constructor deep copy to avoid double ptr
    RuleOf5& operator=(RuleOf5 const& other) {                      //assignment operator
        if (&other != this) {                                       //secured self assignment
            ptr_ = new Type(*other.ptr_);
        }
        return *this;
    };
    RuleOf5(RuleOf5&& other) : ptr_(other.ptr_) {                   //move construktor
        other.ptr_ = nullptr;
    }
    RuleOf5& operator=(RuleOf5&& other) {                           //move assignment operator
        if (&other != this) {
            ptr_ = other.ptr_;
            other.ptr_ = nullptr;
        }
        return *this;
    };

    ~RuleOf5() {                                                    //Destructor
        delete ptr_;
    }
};

template <typename Type>
class RuleOf0 {
    std::shared_ptr<Type>ptr_;

public:
    RuleOf0(Type* resource) : ptr_(resource) {}                //constructor copy the pointer
    // RuleOf0(RuleOf0 const& other) = default ;               //copy constructor deep copy to avoid double ptr

    // RuleOf0& operator=(RuleOf0 const& other) = default;     //assignment operator
        
    // RuleOf0(RuleOf0&& other) = default;                     //move construktor
      
    // RuleOf0& operator=(RuleOf0&& other) = default;          //move assignment operator

    // ~RuleOf0() = default;                                    //Destructor
       
};

int main() {
    RuleOf5<int> r{new int{42}};
    auto r2 = r;
    r = r2;
    r = r;
    auto r3 = std::move(r);
    r = std::move(r3);

    RuleOf0<int> ro{new int{42}};
    auto ro2 = ro;
    ro = ro2;
    ro = ro;
    auto ro3 = std::move(ro);
    ro = std::move(ro3);

    return 0;
}