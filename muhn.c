#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

// 4. Ürün kategorisi için Struct yapısı güncellendi
struct Urun {
    int id;
    char isim[50];
    char kategori[20]; // Elektronik, Gida, Giyim
    float fiyat;
    int stokAdedi;
};

// Sepet için ayrı bir yapı
struct SepetUrunu {
    char isim[50];
    float fiyat;
    int alinanAdet;
};

// Global Değişkenler
struct Urun stoklar[100];
int stokSayisi = 0;

struct SepetUrunu sepet[100];
int sepetSayisi = 0;

// 6. Dosyadan verileri okuma (Program açıldığında)
void DosyadanYukle() {
    FILE *dosya = fopen("stok.txt", "r");
    if (dosya != NULL) {
        stokSayisi = 0;
        // Dosyadaki verileri okuyup struct dizisine aktarma
        while (fscanf(dosya, "%d %s %s %f %d", &stoklar[stokSayisi].id, stoklar[stokSayisi].isim, 
                      stoklar[stokSayisi].kategori, &stoklar[stokSayisi].fiyat, &stoklar[stokSayisi].stokAdedi) != EOF) {
            stokSayisi++;
        }
        fclose(dosya);
    }
}

// 6. Dosyaya verileri kaydetme (Program kapandığında)
void DosyayaKaydet() {
    FILE *dosya = fopen("stok.txt", "w");
    if (dosya != NULL) {
        for (int i = 0; i < stokSayisi; i++) {
            fprintf(dosya, "%d %s %s %.2f %d\n", stoklar[i].id, stoklar[i].isim, 
                    stoklar[i].kategori, stoklar[i].fiyat, stoklar[i].stokAdedi);
        }
        fclose(dosya);
    }
}

// 1. Sisteme Kullanıcı Adı ve Şifre ile Giriş
void GirisEkrani() {
    char kullaniciAdi[20];
    char sifre[20];
    int girisBasarili = 0;

    printf("=== SİSTEME GİRİŞ ===\n");
    while (!girisBasarili) {
        printf("Kullanici Adi: ");
        scanf("%s", kullaniciAdi);
        printf("Sifre: ");
        scanf("%s", sifre);

        // Varsayılan giriş bilgileri: admin / 1234
        if (strcmp(kullaniciAdi, "admin") == 0 && strcmp(sifre, "1234") == 0) {
            printf("\n[BASARILI] Sisteme giris yapildi!\n\n");
            girisBasarili = 1;
        } else {
            printf("[HATA] Hatali kullanici adi veya sifre. Lutfen tekrar deneyin.\n\n");
        }
    }
}

void MenuyuGoster() {
    printf("\n======= MARKET YONETIM SISTEMI =======\n");
    printf("1. Yeni Urun Ekle (Stok)\n");
    printf("2. Urun Sil (Stoktan)\n");
    printf("3. Urun Guncelle (Stokta)\n");
    printf("4. Stoklari Listele\n");
    printf("5. Sepete Urun Ekle (Musteri Isbemi)\n");
    printf("6. Sepeti Listele\n");
    printf("0. Fatura Yazdir ve Cikis\n");
    printf("Seciminiz: ");
}

int main() {
    SetConsoleOutputCP(65001); 

    // Program başlarken kayıtlı stokları yükle
    DosyadanYukle();

    // Sisteme giriş yap
    GirisEkrani();

    int secim;

    while (1) {
        MenuyuGoster(); 
        scanf("%d", &secim);

        if (secim == 1) {
            // YENİ ÜRÜN EKLEME (STOK)
            if (stokSayisi < 100) {
                stoklar[stokSayisi].id = stokSayisi + 1;
                printf("Urun Adi: ");
                scanf("%s", stoklar[stokSayisi].isim);
                
                // Kategori Seçimi
                int katSecim;
                printf("Kategori Secin (1-Elektronik, 2-Gida, 3-Giyim): ");
                scanf("%d", &katSecim);
                if(katSecim == 1) strcpy(stoklar[stokSayisi].kategori, "Elektronik");
                else if(katSecim == 2) strcpy(stoklar[stokSayisi].kategori, "Gida");
                else strcpy(stoklar[stokSayisi].kategori, "Giyim");

                printf("Fiyat: ");
                scanf("%f", &stoklar[stokSayisi].fiyat);
                printf("Stok Adedi: ");
                scanf("%d", &stoklar[stokSayisi].stokAdedi);
                
                stokSayisi++;
                printf("[TAMAM] Urun stoga eklendi.\n");
            } else {
                printf("[HATA] Stok kapasitesi dolu!\n");
            }
        } 
        else if (secim == 2) {
            // 2. ÜRÜN SİLME
            int silinecekID, bulundu = 0;
            printf("Silmek istediginiz urunun ID'sini girin: ");
            scanf("%d", &silinecekID);

            for (int i = 0; i < stokSayisi; i++) {
                if (stoklar[i].id == silinecekID) {
                    bulundu = 1;
                    // Diziyi kaydırarak silme işlemi
                    for (int j = i; j < stokSayisi - 1; j++) {
                        stoklar[j] = stoklar[j + 1];
                    }
                    stokSayisi--;
                    printf("[TAMAM] Urun basariyla silindi.\n");
                    break;
                }
            }
            if (!bulundu) printf("[HATA] Urun bulunamadi!\n");
        }
        else if (secim == 3) {
            // 2. ÜRÜN GÜNCELLEME
            int guncellenecekID, bulundu = 0;
            printf("Guncellemek istediginiz urunun ID'sini girin: ");
            scanf("%d", &guncellenecekID);

            for (int i = 0; i < stokSayisi; i++) {
                if (stoklar[i].id == guncellenecekID) {
                    bulundu = 1;
                    printf("Yeni Fiyat: ");
                    scanf("%f", &stoklar[i].fiyat);
                    printf("Yeni Stok Adedi: ");
                    scanf("%d", &stoklar[i].stokAdedi);
                    printf("[TAMAM] Urun basariyla guncellendi.\n");
                    break;
                }
            }
            if (!bulundu) printf("[HATA] Urun bulunamadi!\n");
        }
        else if (secim == 4) {
            // STOKLARI LİSTELE
            printf("\n--- MEVCUT STOKLAR ---\n");
            for (int i = 0; i < stokSayisi; i++) {
                printf("ID: %d | %s | Kat: %s | Fiyat: %.2f TL | Stok: %d\n", 
                       stoklar[i].id, stoklar[i].isim, stoklar[i].kategori, stoklar[i].fiyat, stoklar[i].stokAdedi);
            }
        }
        else if (secim == 5) {
            // 5. DOSYALAMA MANTIĞI İLE STOK TAKİBİ (Sepete Ekleme ve Stok Düşme)
            int secilenID, alinacakAdet, bulundu = 0;
            printf("Sepete eklemek istediginiz urunun ID'sini girin: ");
            scanf("%d", &secilenID);

            for (int i = 0; i < stokSayisi; i++) {
                if (stoklar[i].id == secilenID) {
                    bulundu = 1;
                    printf("Kac adet almak istiyorsunuz? (Mevcut Stok: %d): ", stoklar[i].stokAdedi);
                    scanf("%d", &alinacakAdet);

                    if (alinacakAdet <= stoklar[i].stokAdedi && alinacakAdet > 0) {
                        // Sepete Ekle
                        strcpy(sepet[sepetSayisi].isim, stoklar[i].isim);
                        sepet[sepetSayisi].fiyat = stoklar[i].fiyat;
                        sepet[sepetSayisi].alinanAdet = alinacakAdet;
                        sepetSayisi++;

                        // Stoktan Düş
                        stoklar[i].stokAdedi -= alinacakAdet;
                        printf("[TAMAM] Urun sepete eklendi ve stok guncellendi.\n");
                    } else {
                        printf("[HATA] Yetersiz stok veya gecersiz adet!\n");
                    }
                    break;
                }
            }
            if (!bulundu) printf("[HATA] Urun bulunamadi!\n");
        }
        else if (secim == 6 || secim == 0) {
            // 3. TOPLAM FİYAT VE KDV HESAPLAMA & 7. FATURA YAZDIRMA
            float toplamAra = 0;
            float kdvOrani = 0.20; // %20 KDV varsayımı
            
            if (secim == 0) printf("\n======= MÜŞTERİ FATURASI =======\n");
            else printf("\n--- SEPET DETAYI ---\n");
            
            if (sepetSayisi == 0) {
                printf("Sepetiniz su an bos.\n");
            } else {
                for (int i = 0; i < sepetSayisi; i++) {
                    float urunToplam = sepet[i].fiyat * sepet[i].alinanAdet;
                    printf("%d. %s | Birim Fiyat: %.2f TL | Adet: %d | Ara Toplam: %.2f TL\n", 
                            i + 1, sepet[i].isim, sepet[i].fiyat, sepet[i].alinanAdet, urunToplam);
                    toplamAra += urunToplam;
                }
                
                float kdvTutari = toplamAra * kdvOrani;
                float genelToplam = toplamAra + kdvTutari;

                printf("------------------------------\n");
                printf("Ara Toplam         : %.2f TL\n", toplamAra);
                printf("KDV Tutari (%%20)   : %.2f TL\n", kdvTutari);
                printf("KDV'li GENEL TOPLAM: %.2f TL\n", genelToplam);
            }

            if (secim == 0) {
                printf("================================\n");
                printf("Bizi tercih ettiginiz icin tesekkurler!\n");
                DosyayaKaydet(); // Çıkarken stok son durumunu dosyaya kaydet
                break;
            }
        }
        else {
            printf("Lutfen gecerli bir secim yapin!\n");
        }
    }

    return 0;
}