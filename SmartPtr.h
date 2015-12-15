/* 
 * File:   SmartPtr.h
 * Author: Jay Mata Di
 *
 * Created on December 7, 2015, 11:10 PM
 */

#ifndef SMARTPTR_H
#define	SMARTPTR_H

//#ifdef	__cplusplus
//extern "C" {
//#endif

class SmartPtr {
private:
    int* pData; 
public:
    SmartPtr (int* pInt) : pData (pInt){
    }
    ~SmartPtr(){
        delete pData;
    }
    int& operator * (){
        return *pData;
    }
    int* operator -> (){
        return pData; 
    }
}
    
//#ifdef	__cplusplus
//}
//#endif

#endif	/* SMARTPTR_H */