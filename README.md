📝 Syslog Management System (C-Language)
Bu proje, C dilinde Çift Yönlü Bağlı Liste (Doubly Linked List) veri yapısını kullanarak geliştirilmiş, hafif ve etkili bir sistem günlüğü (syslog) yönetim simülasyonudur. Sistem, çalışma zamanında log kayıtlarını dinamik olarak oluşturur, zaman damgası ekler ve liste yapısında saklar.

✨ Özellikler
Dinamik Bellek Yönetimi: malloc ve free fonksiyonları ile optimize edilmiş bellek kullanımı.

Otomatik Zaman Damgası: Her log kaydı oluşturulduğu anın tarih ve saat bilgisini otomatik olarak alır.

Veri Yapısı: Çift yönlü bağlı liste sayesinde veriler arasında ileri ve geri hareket imkanı (Geliştirmeye açık yapı).

Log Seviyeleri: INFO, DEBUG, ERROR gibi kategorizasyon desteği.

🛠️ Teknik Mimari
Proje temel olarak bir Node yapısı üzerine kuruludur:
typedef struct Node {
    char timestamp[32];    // Kayıt zamanı (YYYY-MM-DD HH:MM:SS)
    char level[16];        // Log seviyesi (INFO, ERROR, DEBUG)
    char message[256];     // Mesaj içeriği
    struct Node* next;     // Sonraki düğüm adresi
    struct Node* prev;     // Önceki düğüm adresi
} Node;


🚀 Kurulum ve Çalıştırma
Kodun çalışması için sisteminizde bir C derleyicisinin (GCC gibi) yüklü olması yeterlidir.

1-) Dosyayı Derleyin:
gcc syslog_manager.c -o syslog_manager

2-) Programı Çalıştırın:
./syslog_manager

📊 Örnek Çıktı
Program çalıştığında konsolda şu şekilde bir görünüm oluşur:
--- Mevcut Syslog Kayitlari ---
[2026-03-12 18:15:04] INFO   : Sistem baslatildi.

[2026-03-12 18:15:04] DEBUG  : Bagli liste bellek tahsisi yapildi.

[2026-03-12 18:15:04] ERROR  : Disk doluluk orani %90 uzerinde!


[2026-03-12 18:15:04] INFO   : Kullanici 'admin' giris yapti.

-------------------------------


👨‍💻 Geliştirici
İsim: Yusuf


