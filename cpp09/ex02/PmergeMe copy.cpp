#include "PmergeMe.hpp"
#include <cstddef>
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <sys/time.h>

// --- ANSI RENK TANIMLARI (Görselliği ve takibi kolaylaştırmak için) ---
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define GRAY    "\033[90m"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    _vec = other._vec;
    _deq = other._deq;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        _vec = other._vec;
        _deq = other._deq;
    }
    return (*this);
}

// -----------------------------------------------------------------------------
// Jacobsthal Sayı Dizisi Mantığı:
// J(0)=0, J(1)=1, J(2)=1, J(3)=3, J(4)=5, J(5)=11, J(6)=21 ...
// Karşılaştırma sayısını minimumda tutan ekleme indekslerini üretir.
// -----------------------------------------------------------------------------
int PmergeMe::jacobsthal(int n)
{
    if (n == 0) return (0);
    if (n == 1) return (1);
    return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

std::vector<size_t> PmergeMe::build_jacobsthal_sequence(size_t limit)
{
    std::vector<size_t> order;
    if (limit <= 1)
        return (order);

    std::cout << GRAY << "   ┌── [REHBER: Jacobsthal İndeks Sırası Hesaplanıyor]\n";
    std::cout << "   │   * pend içindeki eleman sayısı (limit): " << limit << "\n";
    std::cout << "   │   * NOT: pend[0] zaten 'bedavadan' ekleneceği için 1 ile " << limit - 1 << " arası sıraya sokulacak." << RESET << "\n";

    size_t last = 1;
    for (int i = 3; ; i++)
    {
        size_t curr = jacobsthal(i);

        if (curr > limit)
        {
            std::cout << GRAY << "   │   └─ [Sınır Aşıldı] curr (" << curr << ") > limit (" << limit << ").\n";
            std::cout << "   │      Kalan indeksler " << limit - 1 << "'den " << last << "'e doğru geriye işleniyor: ";
            for (size_t j = limit - 1; j >= last; j--)
            {
                std::cout << j << " ";
                order.push_back(j);
            }
            std::cout << RESET << "\n";
            break;
        }

        std::cout << GRAY << "   │   └─ İndeks Aralığı [" << curr - 1 << " -> " << last << "]: ";
        for (size_t j = curr - 1; j >= last; j--)
        {
            std::cout << j << " ";
            order.push_back(j);
        }
        std::cout << RESET << "\n";

        last = curr;
        if (last >= limit)
            break;
    }

    std::cout << GRAY << "   └── [REHBER: Jacobsthal Hesabı Bitti]" << RESET << "\n";
    return (order);
}

// Vektör yazdırmak için yardımcı fonksiyon
static void printVec(const std::vector<int>& v)
{
    std::cout << BOLD << BLUE << "[ ";
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << "]" << RESET;
}

// -----------------------------------------------------------------------------
// insertVector: pend elemanlarını mainChain içerisine yerleştiren ana motor
// -----------------------------------------------------------------------------
void PmergeMe::insertVector(std::vector<int>& mainChain, std::vector<int>& pend, std::vector<size_t>& jacobOrder)
{
    if (pend.empty())
        return;

    std::cout << "\n   " << MAGENTA << "➔ [GİRDİ: insertVector Çalışmaya Başladı]" << RESET << "\n";
    
    // IPUCU 1: pend[0] elemanı her zaman en küçük büyük sayının partneridir.
    // Bu yüzden mainChain'in ilk elemanından küçük olduğu Garantidir!
    // Sıfır karşılaştırma (BEDAVA) ile en başa yerleştirilir.
    std::cout << "   • [BELEŞ EKLEME] pend[0] (" << BOLD << pend[0] << RESET 
              << ") hiç karşılaştırma yapılmadan en başa yerleştirildi.\n";
    mainChain.insert(mainChain.begin(), pend[0]);
    
    std::cout << "   • Güncel mainChain: ";
    printVec(mainChain);
    std::cout << "\n";

    std::cout << "   • Ekleme Yapılacak Jacobsthal İndeks Sırası: " << MAGENTA << "[ ";
    for (size_t i = 0; i < jacobOrder.size(); i++)
        std::cout << jacobOrder[i] << " ";
    std::cout << "]" << RESET << "\n";

    // IPUCU 2: Kalan pend elemanları Jacobsthal sırasıyla binary search (std::lower_bound)
    // kullanılarak mainChain içerisine doğru pozisyona yerleştirilir.
    for (size_t i = 0; i < jacobOrder.size(); i++)
    {
        size_t index = jacobOrder[i];
        int num = pend[index];
        
        // std::lower_bound: Log(N) karmaşıklıkla (İkili Arama) eklenmesi gereken ilk iterator'ü bulur.
        std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), num);
        mainChain.insert(it, num);

        std::cout << "   • pend[" << index << "] = " << BOLD << num << RESET 
                  << " ikili aramayla yerleştirildi -> mainChain: ";
        printVec(mainChain);
        std::cout << "\n";
    }
    std::cout << "   " << MAGENTA << "➔ [ÇIKTI: insertVector Tamamlandı]" << RESET << "\n\n";
}

// -----------------------------------------------------------------------------
// sortVector: Ford-Johnson Algoritmasının Özyinelemeli (Recursive) Kalbi
// -----------------------------------------------------------------------------
void PmergeMe::sortVector(std::vector<int>& arr)
{
    static int depth = 0; // Rekürsiyon derinliğini izlemek için (Derinleştikçe çıktılar sağa kayar)
    std::string indent(depth * 3, ' '); // Görsel girinti miktarı

    // Tabana ulaşma şartı (Base Case): Dizi 1 veya 0 elemanlıysa zaten sıralıdır!
    if (arr.size() <= 1)
        return;

    std::cout << "\n" << indent << CYAN << "=======================================================" << RESET << "\n";
    std::cout << indent << GREEN << BOLD << "▶ [GİRDİ: sortVector | Derinlik Seviyesi: " << depth << "]" << RESET << "\n";
    std::cout << indent << "   İşlenecek Dizi: "; printVec(arr); std::cout << " (Eleman Sayısı: " << arr.size() << ")\n";
    std::cout << indent << CYAN << "=======================================================" << RESET << "\n";

    bool hasStraggler = false;
    int straggler = 0;

    // -------------------------------------------------------------------------
    // 1. ADIM: Eleman Sayısı Tek mi Çift mi? (Straggler Kontrolü)
    // -------------------------------------------------------------------------
    if (arr.size() % 2 != 0)
    {
        hasStraggler = true;
        straggler = arr.back();
        arr.pop_back(); // Çiftleştirmeye giremeyecek olan son sayı kenara alındı
        std::cout << indent << YELLOW << "1. ADIM (Tek Sayı Ayırma): " << RED << "Dizi tek elemanlı! " 
                  << RESET << "Son eleman (" << BOLD << RED << straggler << RESET << ") kenara ayrıldı.\n";
        std::cout << indent << "   Kalan Çiftlenebilir Dizi: "; printVec(arr); std::cout << "\n";
    }
    else
    {
        std::cout << indent << YELLOW << "1. ADIM (Tek Sayı Ayırma): " << RESET << "Dizi çift elemanlı, açıkta kalan sayı yok.\n";
    }

    // -------------------------------------------------------------------------
    // 2. ADIM: Sayıları İkili Çiftlere Ayırma ve Kendi İçlerinde Karşılaştırma
    // -------------------------------------------------------------------------
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size(); i += 2)
    {
        if (arr[i] > arr[i+1])
            pairs.push_back(std::make_pair(arr[i], arr[i+1])); // (Büyük, Küçük)
        else
            pairs.push_back(std::make_pair(arr[i+1], arr[i])); // (Büyük, Küçük)
    }

    std::cout << indent << YELLOW << "2. ADIM (Çiftleştirme): " << RESET << "Oluşturulan Çiftler (Büyük, Küçük):\n";
    for (size_t i = 0; i < pairs.size(); i++)
    {
        std::cout << indent << "         Çift " << i + 1 << ": (" 
                  << BOLD << pairs[i].first << RESET << ", " << pairs[i].second << ")\n";
    }

    // -------------------------------------------------------------------------
    // 3. ADIM: Büyük Sayıları Toplayıp Özyinelemeye (Rekürsiyona) Gönderme
    // -------------------------------------------------------------------------
    std::vector<int> largerNums;
    for (size_t i = 0; i < pairs.size(); i++)
        largerNums.push_back(pairs[i].first);

    std::cout << indent << YELLOW << "3. ADIM (Rekürsiyona Hazırlık): " << RESET << "Büyük Sayılar (largerNums) Toplandı: ";
    printVec(largerNums);
    std::cout << "\n" << indent << GREEN << "         ⤷ IPUCU: Şimdi bu büyük sayıları kendi içinde sıralamak için alt seviyeye gidiyoruz..." << RESET << "\n";

    // --- REKÜRSİYON ÇAĞRISI (Aşağı iniliyor) ---
    depth++;
    sortVector(largerNums); // Fonksiyon burada kendisini çağırır ve sıralanana kadar Alt Seviyede bekler
    depth--;
    // --- REKÜRSİYON DÖNDÜ (Yukarı çıkıldı) ---

    std::cout << indent << GREEN << "         ⤶ [REKÜRSİYON DÖNDÜ!] " << RESET << "Sıralanmış Büyük Sayılar: ";
    printVec(largerNums);
    std::cout << "\n";

    // -------------------------------------------------------------------------
    // 4. ADIM: mainChain ve pend Yapılarını Oluşturma (En Kritik Yer!)
    // -------------------------------------------------------------------------
    // Rekürsiyondan sıralı dönen büyükler bizim 'mainChain'imiz olur.
    std::vector<int> mainChain = largerNums; 
    std::vector<int> pend;
    std::vector<bool> used(pairs.size(), false);

    // IPUCU: mainChain'deki büyük sayıların sıralamasına BAKARAK, onların
    // orijinal çiftlerindeki küçük partnerlerini sırasıyla 'pend'e koyuyoruz.
    for (size_t i = 0; i < mainChain.size(); i++)
    {
        for (size_t j = 0; j < pairs.size(); j++)
        {
            if (pairs[j].first == mainChain[i] && !used[j])
            {
                used[j] = true;
                pend.push_back(pairs[j].second);

                // MANTIKLI VE NET DEBUG
                std::cout << indent << "  🔍 [Eşleşme Bulundu] "
                          << "mainChain[" << i << "] = " << mainChain[i] 
                          << " ➔ pairs[" << j << "] (" << pairs[j].first << ", " << pairs[j].second << ")"
                          << " ➔ pend'e eklenen partner: " << pairs[j].second << "\n";
                break;
            }
        }
    }

    std::cout << indent << YELLOW << "4. ADIM (Arama Listeleri Hazırlandı): " << RESET << "\n";
    std::cout << indent << "         • " << BOLD << "mainChain" << RESET << " (Sıralı Büyükler)   : "; printVec(mainChain); std::cout << "\n";
    std::cout << indent << "         • " << BOLD << "pend     " << RESET << " (Eklenecek Küçükler): "; printVec(pend);      std::cout << "\n";

    // -------------------------------------------------------------------------
    // 5. ADIM: Jacobsthal Dizisine Göre pend Elemanlarını mainChain'e Ekleme
    // -------------------------------------------------------------------------
    std::vector<size_t> jacobOrder = build_jacobsthal_sequence(pairs.size());

	std::cout << indent << GREEN << "DEBUG: Jacobsthal Order: " << RESET;
	for (size_t i = 0; i < jacobOrder.size(); i++)
		std::cout << jacobOrder[i] << " ";
	std::cout << std::endl;
	std::cout << indent << GREEN << "DEBUG: mainChain: " << RESET;
	for (size_t i = 0; i < mainChain.size(); i++)
		std::cout << BOLD << mainChain[i] << " " << RESET;
	std::cout << std::endl;
	std::cout << indent << GREEN << "DEBUG: pend: " << RESET;
	for (size_t i = 0; i < pend.size(); i++)
		std::cout << BOLD << pend[i] << " " << RESET;
	std::cout << std::endl;


    std::cout << indent << YELLOW << "5. ADIM (Araya Ekleme Fazı): " << RESET << "insertVector çağrılıyor...\n";
    insertVector(mainChain, pend, jacobOrder);

    // -------------------------------------------------------------------------
    // 6. ADIM: En Başta Ayırdığımız Tek Sayıyı (Straggler) Araya Ekleme
    // -------------------------------------------------------------------------
    if (hasStraggler)
    {
        std::cout << indent << YELLOW << "6. ADIM (Açıkta Kalan Sayı): " << RESET << "Kenardaki sayı (" 
                  << RED << BOLD << straggler << RESET << ") ikili aramayla dizideki yerine sokuluyor...\n";
        
        std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(it, straggler);

        std::cout << indent << "         Güncel Tamamlanmış mainChain: ";
        printVec(mainChain);
        std::cout << "\n";
    }

    // Sıralanmış ve birleştirilmiş son hal ana dizimize aktarılır
    arr = mainChain;
    
    std::cout << indent << GREEN << BOLD << "✔ [ÇIKTI: sortVector Bitti | Derinlik Seviyesi: " << depth << "] " << RESET;
    std::cout << "Bu Seviyenin Tamamlanmış Sonucu: "; printVec(arr);
    std::cout << "\n" << indent << CYAN << "=======================================================" << RESET << "\n";
}

// Zaman hesaplama fonksiyonu (Mikrosaniye cinsinden)
static double getTimeInMicroseconds()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000.0) + tv.tv_usec;
}

// -----------------------------------------------------------------------------
// sort: Dışarıdan çağrılan ana başlatıcı fonksiyon
// -----------------------------------------------------------------------------
void PmergeMe::sort(int ac, char** av)
{
    if (ac < 2)
    {
        std::cerr << RED << "Error: No elements provided." << RESET << std::endl;
        return;
    }

    _vec.clear();
    for (int i = 1; i < ac; i++)
    {
        std::stringstream ss(av[i]);
        long val;
        if (!(ss >> val) || !(ss.eof()) || val <= 0)
        {
            std::cerr << RED << "Error: Invalid positive integer -> " << av[i] << RESET << std::endl;
            return;
        }
        _vec.push_back(static_cast<int>(val));
    }

    std::cout << BOLD << "\n=======================================================" << RESET << std::endl;
    std::cout << BOLD << "🚀 PMERGEME ALGORİTMASI BAŞLATILIYOR (std::vector)" << RESET << std::endl;
    std::cout << BOLD << "=======================================================" << RESET << std::endl;
    
    std::cout << "Girdi Dizisi (Before): ";
    for (size_t i = 0; i < _vec.size(); i++)
        std::cout << _vec[i] << " ";
    std::cout << std::endl;

    double startVec = getTimeInMicroseconds();
    sortVector(_vec); // Ana sıralama fonksiyonunu başlat
    double endVec = getTimeInMicroseconds();

    std::cout << "\n" << BOLD << GREEN << "Sıralanmış Dizi (After): ";
    for (size_t i = 0; i < _vec.size(); i++)
        std::cout << _vec[i] << " ";
    std::cout << RESET << std::endl;

    double timeVec = endVec - startVec;
    std::cout << "Geçen Süre: " << std::fixed << std::setprecision(5) << timeVec << " us (mikrosaniye)" << std::endl;
    std::cout << BOLD << "=======================================================\n" << RESET << std::endl;
}