#include<iostream>

template<class T>
struct AVLTreeNode{
  AVLTreeNode(const T& data=T())
    :_pLeft(nullptr)
     ,_pRight(nullptr)
     ,_pParent(nullptr)
     ,_data(data)
     ,_bf(0)
  {}
  AVLTreeNode<T>* _pLeft;
  AVLTreeNode<T>* _pRight;
  AVLTreeNode<T>* _pParent;
  T _data;
  int _bf;//平衡因子
};

template<class T>
class AVLTree{
  typedef AVLTreeNode<T> Node;
  public:
  bool Insert(const T& data){
    if(nullptr==_pRoot){
      _pRoot=new Node(data);
      return true;
    }
    //非空，寻找待插入节点在AVL数里的位置；
    Node* go=_pRoot;
    Node* pParent=nullptr;
    while(go){
      pParent=go;
      if(data<go->_data)
        go=go->_pLeft;
      else if(data>go->_data)
        go=go->_pRight;
      else 
        return false;
    }
    go=new Node(data);//创一个新的，复制给go;
    if(data<pParent->_data)
      pParent->_pLeft=go;
    else 
      pParent->_pRight=go;
    go->_pParent=pParent;//跟新新插入节点的双亲
    //更新双亲平衡因子；
    if(go==pParent->_pLeft)
      pParent->_bf--;
      pParent->_bf++;
    //有可能导致parent平衡因子不符合AVL性质
    while(1){
      if(0==pParent->_bf)//表明树高度未增加；
        return true;
      else if(pParent->_bf==-1||pParent->_bf==1){//向上更新
        go=pParent;
        pParent=go->_pParent;
      }
      else{//双亲平衡因子不满足AVL树位置,平衡因子为2或-2需要旋转处理；
      }
    }
  }
  void RotateLeft(Node* parent){
    Node* pSubR=parent->_pRight;
    Node* pSubRL=pSubR->_pLeft;
    parent->_pRight=pSubRL;
    if(pSubRL)//右单支
      pSubRL->_pParent=parent;
    pSubR->_pLeft=parent;
    Node* pparent=parent->_pParent;//先把parent双亲付给psubR的双亲；
    parent->_pParent=pSubR;
    pSubR->_pParent=pparent;
    //如果parent存在，让它指向pSubR
    if(pparent){
      if(parent==pparent->_pLeft)
        pparent->_pLeft=pSubR;
      else
        pparent->_pRight=pSubR;
    }
    pparent->_bf=pSubR->_bf=0;
  }
  private:
  Node* _pRoot;
};
