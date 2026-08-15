#include <iostream>
#include "Serializer.hpp"

int main()
{
    // Test objesi olustur
    Data myData;
    myData.val = 42;

    // Orijinal adresi ve degeri yazdir
    std::cout << "Original Address: " << &myData << std::endl;
    std::cout << "Original Value  : " << myData.val << "\n" << std::endl;

    // Pointer'i sayiya cevir (Serialize)
    uintptr_t raw = Serializer::serialize(&myData);
    std::cout << "Serialized (uintptr_t): " << raw << std::endl;

    // Sayiyi tekrar pointer'a cevir (Deserialize)
    Data* deserializedPtr = Serializer::deserialize(raw);

    // Yeni pointer'in verilerini kontrol et
    std::cout << "\nDeserialized Address: " << deserializedPtr << std::endl;
    std::cout << "Deserialized Value  : " << deserializedPtr->val << std::endl;

    // Adreslerin ayni oldugunu dogrula
    if (&myData == deserializedPtr)
        std::cout << "\nSUCCESS: Addresses match!" << std::endl;
    else
        std::cout << "\nERROR: Addresses do not match!" << std::endl;

    return 0;
}
