#include "Serializer.hpp"


Serializer::Serializer(){
    
}
Serializer::~Serializer(){
    
}
Serializer::Serializer(const Serializer& other){
    (void)other;
}
Serializer& Serializer::operator=(const Serializer& other){
    (void)other;
    return *this;
}

uintptr_t Serializer::serialize(Data* ptr){
    /* 
     * NASIL ÇALIŞIYOR?
     * 'ptr' bizim içinde 42 değeri olan Data objemizin RAM'deki adresidir (Örn: 0x16d...).
     * reinterpret_cast<uintptr_t> şunu yapar: 
     * "Gidip RAM'deki 42 değerine DOKUNMA! Sadece bu adresin numarasını al (0x16d...)
     * ve bana onu düz bir tam sayı (Örn: 6128...) olarak geri ver."
     * Yani aslında elimizdeki sayıyı değil, adresin etiketini dönüştürdük.
     */
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw){
    /*
     * NASIL ÇALIŞIYOR?
     * 'raw' bizim elimizdeki devasa tam sayıdır (Örn: 6128...).
     * reinterpret_cast<Data*> şunu yapar:
     * "Bu düz sayıyı al ve bir hafıza adresi (Pointer) gibi kabul et."
     * Biz bu pointer'ı alıp içine baktığımızda (deserializedPtr->val),
     * o adreste başından beri uslu uslu oturan ve hiç değişmeyen 42 sayısını buluruz!
     */
    return reinterpret_cast<Data*>(raw);
}