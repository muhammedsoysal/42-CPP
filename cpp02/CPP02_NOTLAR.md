# C++ Module 02 – Fixed-Point Numbers & Notlar

Bu dosya cpp02 modülünü, egzersizleri, integer/float/fixed-point kavramlarını ve Jeff Bezanson'ın "Understanding and Using Floating Point Numbers" makalesinin özetini içerir.

---

## İçindekiler

1. [Subject ↔ Jeff Bezanson Eşlemesi](#1-subject--jeff-bezanson-eşlemesi) ← **Önce bunu oku**
2. [cpp02 Egzersizleri (ex00, ex01, ex02)](#2-cpp02-egzersizleri)
3. [ex00 Subject Gereksinimleri](#3-ex00-subject-gereksinimleri)
4. [Integer vs Float vs Fixed-Point](#4-integer-vs-float-vs-fixed-point)
5. [Jeff Bezanson – Floating Point Makalesi Özeti](#5-jeff-bezanson--floating-point-makalesi-özeti)
6. [IEEE-754 Kısa Özet](#6-ieee-754-kısa-özet)
7. [Pratik Programlama (Eşitlik, Taşma, Hassasiyet Kaybı)](#7-pratik-programlama)

---

## 1. Subject ↔ Jeff Bezanson Eşlemesi

**en.subject.pdf** ile **Jeff Bezanson – "Understanding and Using Floating Point Numbers"** makalesi arasındaki bağlantı aşağıda. Subject’teki hangi cümle Jeff’in neresine denk geliyor, tek bakışta görebilirsin.

| Subject’te yazılan | Jeff makalesinde karşılığı |
|--------------------|----------------------------|
| *"You think you know integers and floating-point numbers. How cute. Please read this 3 pages article... to discover that you don't."* | Makalenin girişi: Float’lar `==` ile güvenilir değil, formüller bazen yanlış/rastgele sonuç veriyor – **“What is going on?”** sorusunun cevabı makalenin tamamı. |
| *"Every number you used was basically either an integer or a floating-point number."* | Aynı fikir: Sayılar ya integer ya float (veya türevleri); makale bu ikisinin **nasıl çalıştığını** anlatıyor. |
| *"Integers and floating-point numbers have **opposite characteristics**."* | **Bölüm I – Accuracy vs. Precision:** Integer = tam doğruluk (accuracy), kesir yok (precision zayıf). Float = kesir var (precision iyi), tam doğruluk yok (accuracy zayıf). Yani **tam zıt**. |
| *"Fixed-point numbers offer a valuable **balance** between performance, accuracy, range and precision."* | **“Don’t forget about integers”** kısmı: Kesiri **integer** (pay/payda veya sabit ölçek) ile tutarsan float hatalarından kaçınırsın. Fixed-point tam da bu: integer saklıyorsun, anlamı “sayı = raw / 2^8” → hem **accuracy** (integer) hem **sabit kesir** (precision) = denge. |
| *"As C++ lacks fixed-point numbers, you're going to **add** them."* | Jeff: Bazen kesiri integer ile tutmak daha iyi. Subject: O yüzden C++’a **Fixed** sınıfı ekliyorsun (ham int + 8 fractional bit). |
| (Subject’te “Berkeley article” fixed-point için ayrı kaynak) | Jeff makalesi **float**’ı anlatıyor (neden garip, neden “opposite”). Berkeley kaynağı **fixed-point** temsilini (bit layout, hesaplama) anlatır; ikisi birbirini tamamlıyor. |

**Kısa özet:**  
Subject diyor ki: “Makaleyi oku, integer ve float’ın **zıt** olduğunu gör, sonra **fixed-point** ile ikisinin ortasını yap.” Jeff makalesi tam olarak “integer ve float neden zıt?” (accuracy vs precision, IEEE-754, ==, yuvarlama) kısmını anlatıyor. Fixed-point ise Jeff’in “kesiri integer ile tut” önerisinin cpp02’deki somut hali: `fixPointValue` (int) + `fractionalBits = 8`.

---

## 2. cpp02 Egzersizleri

### ex00 – Orthodox Canonical Class

**Amaç:** Orthodox Canonical Form'da bir sınıf yazmak (fixed-point sayıyı temsil eden).

**Fixed sınıfı:**
- **Private:** `int fixPointValue`, `static const int fractionalBits = 8`
- **Public:** Default constructor, copy constructor, copy assignment (`operator=`), destructor, `getRawBits()`, `setRawBits(int)`

Bu egzersizde int/float dönüşümü veya operatör yok; sadece canonical form ve ham değer erişimi var.

---

### ex01 – Float ve Int Dönüşümleri

**Yeni constructor'lar:**
- `Fixed(int value)` → `fixPointValue = value << fractionalBits`
- `Fixed(float value)` → `fixPointValue = roundf(value * (1 << fractionalBits))`

**Yeni metodlar:**
- `toInt()` → `fixPointValue >> fractionalBits`
- `toFloat()` → `fixPointValue / (1 << fractionalBits)`
- `operator<<(ostream&, const Fixed&)` → `cout << fixed` ile yazdırma

---

### ex02 – Aritmetik ve Karşılaştırma Operatörleri

**Karşılaştırma:** `<`, `>`, `<=`, `>=`, `==`, `!=`  
**Aritmetik:** `+`, `-`, `*`, `/`  
**Artırma/azaltma:** prefix/postfix `++`, `--`  
**Static:** `Fixed::min(a, b)`, `Fixed::max(a, b)` (const ve non-const versiyonları)

---

## 3. ex00 Subject Gereksinimleri

| İstenen | Açıklama |
|--------|----------|
| **Fixed.{h, hpp}** | Header dosyası (.h veya .hpp) |
| **Private: int** | Fixed-point değerini tutan tamsayı |
| **Private: static const int = 8** | Kesirli bit sayısı (literal 8) |
| **Default constructor** | Değer 0 ile başlatılır |
| **Copy constructor** | Başka bir Fixed'tan kopyalama |
| **Copy assignment** | `operator=` |
| **Destructor** | `~Fixed()` |
| **getRawBits() const** | Ham değeri döndürür |
| **setRawBits(int const raw)** | Ham değeri ayarlar |

---

## 4. Integer vs Float vs Fixed-Point

### Integer
- **Accuracy (doğruluk):** Mükemmel – 2 tam 2'dir, taşma yoksa işlemler bit-bit doğru.
- **Precision (hassasiyet):** Zayıf – Kesir yok; 5/2 ve 4/2 ikisi de 2 olur.
- **Benzetme:** Tuğlalarla inşa; küp tam olur, küre zor.

### Float (IEEE-754)
- **Accuracy:** Zayıf – Çoğu reel sayı tam temsil edilemez; her zaman en az biraz hata.
- **Precision:** İyi – Bilgi kasıtlı atılmaz; yeterli bit ile hesaplar takip edilebilir.
- **Benzetme:** Oyun hamuru; kıvrımlar iyi, mükemmel köşe zor.
- **Özel:** Epsilon, NaN, ±∞, +0/-0.

### Fixed-Point (cpp02)
- **Accuracy:** Integer gibi – Ham değer tamsayı, işlemler (taşma dikkat edilirse) deterministik.
- **Precision:** Sabit kesir – Örn. 8 bit → 1/256 adımla; float gibi “her yerde biraz hata” yok.
- **Kullanım:** Oyun grafikleri, ses, gömülü sistemler, belirli hassasiyet gereken hesaplar.

**Subject'in dediği:** *"Integers and floating-point numbers have opposite characteristics."*  
Fixed-point ikisinin ortası: integer'ın doğruluğu + sabit kesir hassasiyeti.

---

## 5. Jeff Bezanson – Floating Point Makalesi Özeti

**Kaynak:** "Understanding and Using Floating Point Numbers" – Jeff Bezanson  
(42 subject'te "read this 3 pages article" denilen metin büyük ihtimalle bu.)

### I. Accuracy vs. Precision
- **Integer:** Tam doğruluk; kesir yok (precision zayıf).
- **Float:** Kesir var; tam doğruluk yok (accuracy zayıf).
- **1/3 örneği:** Sonlu ondalık (0.333…) veya ikili temsil hiçbir zaman tam 1/3 olamaz; aynı mantık float için de geçerli.

### II. Float Temsili (IEEE-754)
- **Üç bileşen:** sign (işaret), exponent (üssü), mantissa (rakamlar).
- **1.m formatı:** Virgülün solunda her zaman gizli 1; sadece sağdaki kısım saklanır. Sıfır özel durum.
- **Exponent:** "shift-127" ile kodlanır; böylece 1.0 ve sıfır temsil edilebilir.
- **Özel değerler:** +∞, −∞, NaN.
- **Epsilon:** 1 + epsilon > 1 olan en küçük sayı; en sağdaki anlamlı bitin değeri.
- **4 byte float, 4 byte int'ten daha az farklı değer tutar** çünkü bitler sign + exponent + mantissa için bölünür.

### III. Eşitlik (==)
- Float'ta `==` bit-bit eşitliktir; yuvarlama yüzünden "aynı olması gereken" sayılar eşit çıkmayabilir.
- Çözüm: "Yeterince yakın" – örn. `fabs(a - b) < EPSILON`.
- Dikkat: EPSILON büyüklükten bağımsız düşünülmeli; "kaç anlamlı basamak?" sorusu önemli. 1.25e-20 ile 2.25e-20 farkı küçük ama eşit sayılmamalı.

### IV. Taşma (Overflow)
- **Int:** Taşınca wraparound; bakarak anlaşılmaz.
- **Float:** Taşınca ±∞; kontrol etmek kolay.
- **Ara değer taşması:** Sonuç temsil edilebilir olsa bile ara adım taşabilir. Örnek: `sqrt(re*re + im*im)` re=im=1e200 iken re*re = 1e400 → ∞. Çözüm: Formülü büyük olanı dışarı alacak şekilde yeniden yazmak (örn. `re*sqrt(1 + (im/re)^2)`).

### V. Loss of Significance (Hassasiyet Kaybı)
- Birbirine çok yakın iki float'ı çıkarınca başlıklar birbirini götürür; kalan birkaç bit kalır → hassasiyet çok düşer.
- Toplamada: Çok büyük + çok küçük = küçük yutulur (1.0 + 1e-8 float'ta hâlâ 1.0).
- Çözüm: İşlemi cebirsel olarak yeniden düzenlemek; gerekirse terimleri küçükten büyüğe sıralayıp toplamak.

### VI. "Don't forget about integers"
- Kesir rasyonel ve biliniyorsa (ölçek faktörü vb.) **pay/payda (integer)** tutarak float hatalarından kaçınılabilir.
- Unit fraction (1/n) için sadece payda tutup gerektiğinde `1.0/denom` ile float üretmek yeterli.  
**Bu fikir cpp02 fixed-point ile aynı:** Kesri integer + sabit ölçek (2^8) ile tutuyorsun.

---

## 6. IEEE-754 Kısa Özet

| Özellik | float (32 bit) | double (64 bit) |
|--------|----------------|------------------|
| En büyük sayı | ~3.4e+38 | ~1.8e+308 |
| Mantissa bit | 23 | 52 |
| Exponent bit | 8 | 11 |
| Epsilon | ~1.19e-7 | ~2.22e-16 |

**Formül:** `sayı = (sign ? -1 : 1) * 2^exponent * 1.(mantissa)`

**Örnek hex (float):**
- 0 → 0x00000000  
- 1.0 → 0x3f800000  
- 0.5 → 0x3f000000  
- +∞ → 0x7f800000  
- NaN → 0x7fc00000 vb.

---

## 7. Pratik Programlama

- **Float eşitliği:** `==` yerine tolerans: `fabs(a - b) < EPSILON`; EPSILON'u anlamlı basamak sayısına göre seç.
- **Taşma:** Ara sonuçları küçültmek için formülü yeniden yaz (büyük çarpanı dışarı al vb.).
- **Hassasiyet kaybı:** Yakın sayıları çıkarmaktan kaçın; mümkünse cebirsel düzenleme.
- **Feedback:** Önceki çıktıyı girişe bağlayan algoritmalar birikimli hata yapar; mümkünse değeri sabit ifadelerle yeniden hesapla (x = n*inc gibi).

---

## Özet Tablo – cpp02 Egzersizleri

| Egzersiz | Odak |
|----------|------|
| **ex00** | Orthodox Canonical Form, getRawBits/setRawBits |
| **ex01** | Int/float constructor, toInt(), toFloat(), operator<< |
| **ex02** | Karşılaştırma ve aritmetik operatörleri, ++/--, min/max |

Bu notlar cpp02 modülü ve floating-point/fixed-point kavramları için referans amaçlıdır.
