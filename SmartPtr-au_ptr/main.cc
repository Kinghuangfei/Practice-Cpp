template<class T>
class AutoPtr {
  public:
    AutoPtr (T* ptr = NULL)
      : _ptr (ptr) {

      }
    ~AutoPtr () {
      if ( _ptr  )
        delete _ptr;

    }
   // 一旦发生拷贝，就将ap中资源转移到当前对象中，然后另ap与其所管理资源断开联系，
      // 这样就解决了一块空间被多个对象使用而造成程序奔溃问题
      AutoPtr (AutoPtr<T>& ap)
      : _ptr (ap._ptr) {
        ap._ptr = NULL;
      }
    AutoPtr<T>& operator=(AutoPtr<T>& ap) {
      // 检测是否为自己给自己赋值
      if ( this != &ap  ) {
        // 释放当前对象中资源
        if ( _ptr  )
          delete _ptr;
        // 转移ap中资源到当前对象中
        _ptr = ap._ptr;
        ap._ptr = NULL;
      }
      return *this;
    }
    T& operator*() { return *_ptr;  }
    T* operator->() { return _ptr;  }
  private: T* _ptr;
};
int main () {
  AutoPtr<int> ap (new int);
  // 现在再从实现原理层来分析会发现，这里拷贝后把ap对象的指针赋空了，导致ap对象悬空
  // 通过ap对象访问资源时就会出现问题。
  AutoPtr<int> copy (ap);
  *ap= 2018;
  return 0;
}
