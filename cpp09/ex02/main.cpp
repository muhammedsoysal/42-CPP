/*
  Örnek dizi: arr = {5, 8, 1, 4, 3, 9, 7}
  Hedef (Sorted): 1, 3, 4, 5, 7, 8, 9

  1. ADIM: İkili Eşleştirme ve Kıyaslama (Pairs)
     - (5, 8) -> Büyük: 8, Küçük: 5
     - (1, 4) -> Büyük: 4, Küçük: 1
     - (3, 9) -> Büyük: 9, Küçük: 3
     - (7)    -> Tek kaldı (Straggler / kenarda bekleyen)

  2. ADIM: Gruplar ve Partnerler
     - Kazananlar (Büyükler) : [8, 4, 9]
     - Kaybedenler (Küçükler): [5, 1, 3]
     - Tek kalan sayı        : 7

     Partner eşleşmeleri:
     - 4 kimi yenmişti? -> 1'i
     - 8 kimi yenmişti? -> 5'i
     - 9 kimi yenmişti? -> 3'ü
     - 7 kimi yenmişti? -> (yok, tek kaldı)

  3. ADIM: Kazananları Kendi Arasında Sırala (Ana Zincir - Main Chain)
     Kazananlar [8, 4, 9] sıralanır:
     Ana Zincir = [4, 8, 9]

  4. ADIM: İlk Elemanın Bedava Eklenmesi (Zero Comparison)
     - Zincirin en küçük kazananı: 4
     - 4 kimi yenmişti? -> 1'i
     - 1 zaten 4'ten küçük ve 4 şu an en küçük olduğuna göre, 1 direkt en başa eklenir!
     Ana Zincir = [1, 4, 8, 9]

  5. ADIM: Kalan Küçüklerin Jacobsthal Sırasıyla Eklenmesi (Binary Search)
     Eklenmeyi bekleyenler: 5 (8'in partneri), 3 (9'un partneri) ve 7 (tek kalan).
     Jacobsthal sırası: Önce 3. eleman, sonra 2. eleman...

     a) Önce 3'ü ekle:
        - 3'ün yenildiği sayı: 9 (yani 9'dan önce olmalı).
        - [1, 4, 8] aralığında ikili arama yapılır -> 1 ile 4 arasına girer.
        Zincir = [1, 3, 4, 8, 9]

     b) Şimdi geriye dönüp 5'i ekle:
        - 5'in yenildiği sayı: 8 (yani 8'den önce olmalı).
        - [1, 3, 4] aralığında ikili arama yapılır -> 4 ile 8 arasına girer.
        Zincir = [1, 3, 4, 5, 8, 9]

     c) Kenarda bekleyen tek sayı 7'yi ekle:
        - [1, 3, 4, 5, 8, 9] içinde ikili arama yapılır -> 5 ile 8 arasına girer.
        Zincir = [1, 3, 4, 5, 7, 8, 9]

  SONUÇ: [1, 3, 4, 5, 7, 8, 9] (Tamamen sıralandı!)
*/

#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>

std::string intToStr(int num) {
    std::ostringstream oss;
    oss << num;
    return oss.str();
}

int jacobsthalDebug(int n, int depth = 0, std::string branch = "KOK CAGRI")
{
    std::string indent = "";
    for (int i = 0; i < depth; ++i)
        indent += "│  ";

    std::cout << indent << "┌── [" << branch << "] Hesaplaniyor: J(" << n << ")\n";

    if (n == 0) {
        std::cout << indent << "└── [Taban] J(0) = 0\n";
        return 0;
    }
    if (n == 1) {
        std::cout << indent << "└── [Taban] J(1) = 1\n";
        return 1;
    }

    int left = jacobsthalDebug(n - 1, depth + 1, "Sol Dal: J(" + intToStr(n - 1) + ")");
    int right = jacobsthalDebug(n - 2, depth + 1, "Sag Dal: J(" + intToStr(n - 2) + ")");
    int result = left + 2 * right;

    std::cout << indent << "└── [HESAPLANDI] J(" << n << ") = J(" << n - 1 << ") + 2*J(" << n - 2 << ") "
              << "= " << left << " + 2*(" << right << ") = " << result << "\n";
    return result;
}

void debugJacobsthalSequence(size_t limit)
{
    std::cout << "\n========================================================\n";
    std::cout << "  JACOBSTHAL SAYILARI INDEKSE NASIL DONUSUYOR? (Limit: " << limit << ")\n";
    std::cout << "========================================================\n\n";

    std::vector<size_t> order;
    size_t last = 1;

    // J(0)=0, J(1)=1, J(2)=1, J(3)=3, J(4)=5, J(5)=11, J(6)=21...
    int jacobNumbers[] = {3, 5, 11, 21, 43, 85};
    int k = 3;

    for (size_t idx = 0; idx < sizeof(jacobNumbers)/sizeof(jacobNumbers[0]); ++idx)
    {
        size_t curr = jacobNumbers[idx];
        std::cout << "[Adim " << idx + 1 << "] Jacobsthal Sayisi J(" << k << ") = " << curr << "\n";

        if (curr > limit)
        {
            std::cout << "    -> Sayi limitimiz olan " << limit << "'i asti!\n";
            std::cout << "    -> Kalan indeksler sondan (" << limit - 1 << ") geriye (" << last << ") dogru ekleniyor: ";
            for (size_t i = limit - 1; i >= last; --i)
            {
                std::cout << i << " ";
                order.push_back(i);
            }
            std::cout << "\n\n";
            break;
        }

        std::cout << "    -> Indeksler: " << curr - 1 << "'den " << last << "'e kadar geriye dogru ekleniyor: ";
        for (size_t i = curr - 1; i >= last; --i)
        {
            std::cout << i << " ";
            order.push_back(i);
        }
        std::cout << "\n\n";

        last = curr;
        if (last >= limit)
            break;
        k++;
    }

    std::cout << "--------------------------------------------------------\n";
    std::cout << "🎯 FINAL EKLEME SIRAMIZ (Dongunun kullanacagi indeksler):\n[ ";
    for (size_t i = 0; i < order.size(); ++i)
        std::cout << order[i] << " ";
    std::cout << "]\n";
    std::cout << "--------------------------------------------------------\n";
}

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	try
	{
		// jacobsthalDebug(5);
		// (void)av;
		// (void)ac;
		PmergeMe pm;
		pm.sort(ac, av);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}

    // build_jacobsthal_sequence (9)

    std::vector<size_t> jacobOrder = build_jacobsthal_sequence<std::vector<size_t> >(11);
    for (size_t i = 0; i < jacobOrder.size(); i++)
        std::cout << jacobOrder[i] << " ";
    std::cout << std::endl;

	return (0);
}
