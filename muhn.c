#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// User Data Structure
typedef struct {
    char isim[50];
    char pin[10];
    float bakiye;
} Kullanici;

// Function to save transactions to file
void dosyayaKaydet(char *mesaj) {
    FILE *dosya = fopen("atm_kayitlari.txt", "a");
    if (dosya != NULL) {
        fprintf(dosya, "%s\n", mesaj);
        fclose(dosya);
    }
}

int main() {
    Kullanici musteriler[100]; 
    int musterisayisi = 0;
    int secim;
    char logMesaji[255];

    while (1) {
        printf("\n==============================");
        printf("\n   ATM YONETIM SISTEMI");
        printf("\n==============================");
        printf("\n1. Yeni Kullanici Ekle");
        printf("\n2. Para Cek/Yatir");
        printf("\n3. Islem Gecmisini Gor ");
        printf("\n4. Cikis (Exit)");
        printf("\nSeciminiz: ");
        
        if (scanf("%d", &secim) != 1) { 
            while(getchar() != '\n'); 
            continue;
        }

        if (secim == 4) break;

        if (secim == 1) { 
            printf("\nKullanici Adi: ");
            scanf("%s", musteriler[musterisayisi].isim);
            printf("PIN Kodu: ");
            scanf("%s", musteriler[musterisayisi].pin);
            printf("Ilk Bakiye: ");
            scanf("%f", &musteriler[musterisayisi].bakiye);

            sprintf(logMesaji, "YENI KULLANICI: %s | Bakiye: %.2f", musteriler[musterisayisi].isim, musteriler[musterisayisi].bakiye);
            dosyayaKaydet(logMesaji);
            
            musterisayisi++;
            printf("\n--> Kullanici Basariyla Eklendi!");

        } else if (secim == 2) { 
            if (musterisayisi == 0) {
                printf("\n(!) Sistemde kayitli kullanici yok.");
                continue;
            }

            char girilenIsim[50], girilenPin[10];
            printf("\nKullanici Adi: ");
            scanf("%s", girilenIsim);
            printf("PIN: ");
            scanf("%s", girilenPin);

            int bulundu = -1;
            for (int i = 0; i < musterisayisi; i++) {
                if (strcmp(musteriler[i].isim, girilenIsim) == 0 && strcmp(musteriler[i].pin, girilenPin) == 0) {
                    bulundu = i;
                    break;
                }
            }

            if (bulundu != -1) {
                int islemSecim;
                float miktar;
                printf("\nMerhaba %s! Bakiyeniz: %.2f TL", musteriler[bulundu].isim, musteriler[bulundu].bakiye);
                printf("\n1. Para Cek\n2. Para Yatir\nSecim: ");
                scanf("%d", &islemSecim);

                if (islemSecim == 1) {
                    printf("Miktar: ");
                    scanf("%f", &miktar);
                    if (miktar <= musteriler[bulundu].bakiye) {
                        musteriler[bulundu].bakiye -= miktar;
                        sprintf(logMesaji, "ISLEM: %s | %.2f TL Cekti | Yeni Bakiye: %.2f", musteriler[bulundu].isim, miktar, musteriler[bulundu].bakiye);
                        dosyayaKaydet(logMesaji);
                        printf("Islem basarili.");
                    } else {
                        printf("(!) Yetersiz bakiye.");
                    }
                } else if (islemSecim == 2) {
                    printf("Miktar: ");
                    scanf("%f", &miktar);
                    musteriler[bulundu].bakiye += miktar;
                    sprintf(logMesaji, "ISLEM: %s | %.2f TL Yatirdi | Yeni Bakiye: %.2f", musteriler[bulundu].isim, miktar, musteriler[bulundu].bakiye);
                    dosyayaKaydet(logMesaji);
                    printf("Islem basarili.");
                }
            } else {
                printf("\n(!) Hatali isim veya PIN.");
            }

        } else if (secim == 3) { 
            printf("\n--- ISLEM GECMISI (LOG) ---\n");
            FILE *dosyaOku = fopen("atm_kayitlari.txt", "r");
            char satir[255];
            if (dosyaOku) {
                while (fgets(satir, 255, dosyaOku)) {
                    printf("%s", satir);
                }
                fclose(dosyaOku);
            } else {
                printf("Kayit bulunamadi.");
            }
        }
    }

    printf("\nProgram sonlandirildi. Iyi gunler!");
    return 0;
}