#include<fstream>
#include<iostream>

namespace Delector {//删除器
  template<class T>
    struct DFDel {//默认是new用delete删除
      void operator()(T*& ptr) {
        if ( ptr  ) {
          delete ptr;
          ptr = nullptr;

        }

      }
    };
  template<class T>
    struct Free {//处理maloc的资源
      void operator()(T*& ptr) {
        if ( ptr  ) {
          free (ptr);
          ptr = nullptr;

        }

      }
    };
  struct FClose {
    void operator()(FILE*& pf) {//处理文件流指针和套接字；
      if ( pf  ) {
        fclose (pf);
        pf = nullptr;

      }
    }

  };
}

template<class T , class DE = Delector::DFDel<T>>
class Unique_ptr {
  public:
    Unique_ptr (T* p = nullptr)
      :ptr (p) {

      }
    ~Unique_ptr{
      DE (ptr);

    }
    T& operator*() {
      return *ptr;

    }
    T* operator->() {
      return ptr;

    }
  private:
    Unique_ptr (const Unique_ptr<T>& s) = delete;
    Unique_ptr& operator=(const Unique_ptr<T,DE>&) = delete;
  private:
    T* ptr;

};
