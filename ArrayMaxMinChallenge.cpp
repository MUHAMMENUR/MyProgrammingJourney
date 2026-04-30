#include <iostream>
#include <cstdlib> 
#include <ctime>   
#include <fstream>
#include <string>    
#include <cmath>
#include <thread>
#include <chrono>
#include <iomanip>
#include <windows.h> 

using namespace std;  

// Yonetici menusu icin enum
enum EnAdminMenu{
    ADMIN_ADD = 1,
    ADMIN_DISPLAY = 2,
    ADMIN_SEARCH = 3,
    ADMIN_CHANGE_STATUS = 4,
    ADMIN_DELETE = 5,
    ADMIN_STATISTICS = 6, // YENI EKLENDI
    ADMIN_EXIT = 0
};

struct Volunteer{
    string Name;
    string City;
    string Number;
    string Skill;
    string Password; 
    bool Isavalible;
};

void PrintVolunteerRow(Volunteer v,int id){
    string status = (v.Isavalible) ? "Musait" : "Mesgul";
    cout << left << setw(5) << id 
         << setw(20) << v.Name 
         << setw(15) << v.Number
         << setw(15) << v.City 
         << setw(20) << v.Skill 
         << setw(15) << status << endl;
}

// 5. OZELLIK: ILK ACILISTA KULLANICI ROLUNU SECTIREN MENU
int ShowRoleMenu() {
    string choice;
    while(true) {
        cout << "\n=========================================" << endl;
        cout << "   AFET GONULLU YONETIM SISTEMI (MIS)    " << endl;
        cout << "=========================================" << endl;
        cout << "1. Yonetici (Admin) Girisi" << endl;
        cout << "2. Gonullu Girisi (Profil & Durum)" << endl;
        cout << "0. Sistemden Cikis" << endl;
        cout << "Seciminiz: ";
        cin >> choice;
        
        if(choice == "1") return 1;
        if(choice == "2") return 2;
        if(choice == "0") return 0;
        cout << "\n[HATA] Lutfen gecerli bir islem seciniz (1, 2 veya 0).\n";
    }
}

// YONETICI MENUSU
int ShowAdminMenu(){
    string choice;
    while (true)
    {
        cout<<"\n======= YONETICI PANELİ ======"<<endl;
        cout<<"1. GONULLU EKLE "<<endl;
        cout<<"2. TUM LISTEYI GOSTER "<<endl;
        cout<<"3. BECERIYE GORE ARA "<<endl;
        cout<<"4. DURUM DEGISTIR (Listeden)"<<endl;
        cout<<"5. GONULLU SIL"<<endl;
        cout<<"6. SISTEM ISTATISTIKLERI (Dashboard)"<<endl; // YENI EKLENDI
        cout<<"0. ANA EKRANA DON (Oturumu Kapat)"<<endl;
        cout<<"Seciminiz: ";
        cin>>choice;
        cin.ignore(); 
        
        if(choice=="1") return ADMIN_ADD;
        if(choice=="2") return ADMIN_DISPLAY;
        if(choice=="3") return ADMIN_SEARCH;
        if(choice=="4") return ADMIN_CHANGE_STATUS;
        if(choice=="5") return ADMIN_DELETE;
        if(choice=="6") return ADMIN_STATISTICS; 
        if(choice=="0") return ADMIN_EXIT;
        
        cout<<"HATA! Lutfen tekrar deneyin.... 1, 2, 3, 4, 5, 6 veya 0 seciniz\n";
    }
}

// YONETICI GIRIS KONTROLU
bool AdminLogin() {
    string pass;
    cout << "\n--- YONETICI GIRISI ---" << endl;
    cout << "Sifre (Varsayilan: admin123): ";
    cin >> pass;
    
    if (pass == "admin123") {
        cout << "\n[OK] Yonetici girisi basarili!\n";
        return true;
    }
    cout << "\n[HATA] Hatali sifre! Erisim reddedildi.\n";
    return false;
}

void ShoWelcomeMessage(){
    cout << "*****************************************" << endl;
    cout << "* AGS - AFET GONULLU YONETIM SISTEMI    *" << endl;
    cout << "*****************************************" << endl;
}

void ReadInformation(Volunteer &v){
    cout<<"\nLutfen yeni gonullunun bilgilerini giriniz...\n"<<endl;
    cout<<"Isminizi giriniz: ";
    getline(cin,v.Name);
    
    do
    {
        cout<<"Lutfen numaranizi giriniz (Telefon numaraniz 11 hane ve 05 ile baslamalidir): ";
        cin>>v.Number;
        if (v.Number.length() != 11 || v.Number.substr(0, 2) != "05")
        {
            cout<<"Hata! Gecersiz numara. lutfen (05xx xxx xx xx) formatinda 11 haneli numara giriniz.\n";
        }
    } while (v.Number.length() != 11 || v.Number.substr(0, 2) != "05");
    cin.ignore(); 
   
    cout<<"Lutfen sehirinizi giriniz: ";
    getline(cin,v.City);
    
    bool ValidSkill=false;
    while (!ValidSkill)
    {
        cout<<"\nLutfen becerinizi seciniz (numara giriniz): "<<endl;
        cout<<"1. Arama Kurtarma (Search & Rescue) "<<endl;
        cout<<"2. Saglik Personeli (Doctor/Nurse) "<<endl;
        cout<<"3. Tercuman (Translator) "<<endl;
        cout<<"4. Insaat Muhendisligi (Civil Engineer) "<<endl;
        cout<<"5. Piskolog (Psychological Support) "<<endl;
        cout<<"6. Sofor / Operator "<<endl;
        cout<<"7. Ascilik "<<endl;
        cout<<"8. Lojistik "<<endl;
        cout<<"9. Diger "<<endl;
        
        string SkillChoice;
        cout<<"Seciminiz: ";
        cin>>SkillChoice;
        cin.ignore();
        
        if(SkillChoice=="1"){v.Skill="Arama kurtarma"; ValidSkill=true;}
        else if(SkillChoice=="2"){v.Skill="Saglik"; ValidSkill=true;}
        else if(SkillChoice=="3"){v.Skill="Tercuman"; ValidSkill=true;}
        else if(SkillChoice=="4"){v.Skill="Muhendis"; ValidSkill=true;}
        else if(SkillChoice=="5"){v.Skill="Piskolog"; ValidSkill=true;}
        else if(SkillChoice=="6"){v.Skill="Sofor"; ValidSkill=true;}
        else if(SkillChoice=="7"){v.Skill="Ascilik"; ValidSkill=true;}
        else if(SkillChoice=="8"){v.Skill="Lojistik"; ValidSkill=true;}
        else if(SkillChoice=="9"){
            cout<<"Lutfen becerinizi belirtin: ";
            getline(cin,v.Skill);
            ValidSkill=true;
        }else{
            cout<<"\n[HATA] Gecersiz secim! Lutfen listedeki rakamlardan birini giriniz."<<endl;
        }
    }
   
    cout << "Giris icin bir sifre olusturunuz: ";
    getline(cin, v.Password);

    v.Isavalible=true; 
}

bool Askuser(){
    string choice;
    while (true)
    {
        cout << "Baska birini eklemek ister misiniz? (Evet: 1 / Hayir: 0): ";
        cin>>choice;
        if (choice=="1")
        {
            cin.ignore();
            return true;
        }else if(choice=="0"){
            cin.ignore();
            return false;
        }else{
            cout<<"Hata! lutfen sadece 0 veya 1 giriniz."<<endl;
        }
    }
} 

int RegiseterAllVolunteer(Volunteer list[],int CurrentCount){
    int counter=CurrentCount;
    bool Keepgoing=true;
    while (Keepgoing&&counter<100)
    {
        ReadInformation(list[counter]);
        counter++;
        if (counter<100)
        {
            Keepgoing=Askuser();
        }
    }
    return counter; 
}

void DisplayFullList(Volunteer list[],int count){
    cout << "\n==========================================================================================" << endl;
    cout << "                                SU ANDA KAYITLI GONULLULER                                "<<endl;
    cout << "==========================================================================================" << endl;
    if (count==0)
    {
        cout<<"Henuz kayitli gonullu yok."<<endl;
        return;
    }
    cout << "\n" << left << setw(5) << "ID" 
         << setw(20) << "ISIM" 
         << setw(15) << "TEL"      
         << setw(15) << "SEHIR"    
         << setw(20) << "BECERI" 
         << setw(15) << "DURUM" << endl;
    cout << string(90, '-') << endl;
    for (int i = 0; i < count; i++) {
        PrintVolunteerRow(list[i], i + 1);
    }
    cout << "\n==========================================================================================" << endl;
}

void SearchBySkill(Volunteer list[],int count){
    if(count==0){
        cout<<"\n[UYARI] Sistemde henuz kayitli gonullu yok!"<<endl;
        return;
    }
    cout<<"\n--- Beceriye Gore Arama ---"<<endl;
    cout<<"1. Arama kurtarma\n2. Saglik personeli\n3. Tercuman\n4. Muhendis\n5. Piskolog\n6. Sofor\n7. Ascilik\n8. Lojistik\n9. Diger"<<endl;
    
    string serachchoice;
    cout<<"Aramak istediginiz beceri numarasini giriniz: ";
    cin>>serachchoice;
    cin.ignore();
    
    string targetskill="";
    if (serachchoice=="1")targetskill="Arama kurtarma";
    else if(serachchoice=="2")targetskill="Saglik";
    else if(serachchoice=="3")targetskill="Tercuman";
    else if(serachchoice=="4")targetskill="Muhendis";
    else if(serachchoice=="5")targetskill="Piskolog";
    else if(serachchoice=="6")targetskill="Sofor";
    else if(serachchoice=="7")targetskill="Ascilik";
    else if(serachchoice=="8")targetskill="Lojistik";
    else if(serachchoice=="9"){
        cout<<"Aramak istediginiz ozel becerinizi yaziniz: ";
        getline(cin,targetskill);
    }
    
    bool found=false;
    cout<<"\n--- ARAMA SONUCLARI ---"<<endl;
    for (int i = 0; i < count; i++)
    {
        if (list[i].Skill == targetskill) {
            if (!found) { 
                cout << left << setw(5) << "ID" 
                << setw(20) << "ISIM" 
                << setw(15) << "TEL" 
                << setw(15) << "SEHIR" 
                << setw(20) << "BECERI" << endl;
                cout << string(90, '-') << endl;
            }
            PrintVolunteerRow(list[i], i + 1);
            found = true;
        }
    }
    if(!found){
        cout<<"\n[!] Maalesef bu beceriye sahip bir gonullu bulunamadi."<<endl;
    }

    cout << "\nMenuye donmek icin Enter'a basiniz...";
    cin.get();
}

// 2. OZELLIK: SISTEM ISTATISTIKLERINI (DASHBOARD) HESAPLAMA VE GOSTERME
void ShowStatistics(Volunteer list[], int count) {
    if (count == 0) {
        cout << "\n[!] Sistemde kayitli gonullu bulunmadigi icin istatistik gosterilemiyor." << endl;
        return;
    }
    
    int available = 0;
    int busy = 0;
    
    // En cok ihtiyac duyulan/kayitli beceriyi bulmak icin degiskenler
    string skills[100];
    int skillCounts[100] = {0};
    int uniqueSkills = 0;

    for (int i = 0; i < count; i++) {
        // Durum sayaci
        if (list[i].Isavalible) available++;
        else busy++;

        // Beceri sayaci (Frekans hesaplama)
        bool found = false;
        for(int j = 0; j < uniqueSkills; j++) {
            if (skills[j] == list[i].Skill) {
                skillCounts[j]++;
                found = true;
                break;
            }
        }
        // Eger beceri dizide yoksa yeni ekle
        if (!found) {
            skills[uniqueSkills] = list[i].Skill;
            skillCounts[uniqueSkills] = 1;
            uniqueSkills++;
        }
    }

    // En yuksek frekansa sahip beceriyi bulma
    int maxIndex = 0;
    for(int i = 1; i < uniqueSkills; i++) {
        if(skillCounts[i] > skillCounts[maxIndex]) {
            maxIndex = i;
        }
    }

    cout << "\n=================================================" << endl;
    cout << "          SISTEM ISTATISTIKLERI (DASHBOARD)      " << endl;
    cout << "=================================================" << endl;
    cout << "-> Toplam Kayitli Gonullu : " << count << " kisi" << endl;
    cout << "-> Su An Musait Olanlar   : " << available << " kisi" << endl;
    cout << "-> Sahada / Mesgul Olanlar: " << busy << " kisi" << endl;
    cout << "-> En Cok Kayitli Beceri  : " << skills[maxIndex] << " (" << skillCounts[maxIndex] << " kisi)" << endl;
    cout << "=================================================\n" << endl;
}

void SaveToTxtFile(Volunteer list[], int count) {
    ofstream file("Volunteers.txt"); 
    if (file.is_open()) {
        for (int i = 0; i < count; i++) {
            string status = (list[i].Isavalible) ? "Musait" : "Mesgul";
            
            file << list[i].Name << "|" 
                 << list[i].City << "|" 
                 << list[i].Number << "|" 
                 << list[i].Skill << "|" 
                 << list[i].Password << "|" 
                 << status << "|" << endl;
        }
        file.close();
        // cout << "\n[OK] Veriler Volunteers.txt dosyasina basariyla kaydedildi!" << endl; // Gereksiz kalabalik yapmamasi icin gizledik
    }
}

int LoadFromFile(Volunteer list[]) {
    ifstream file("Volunteers.txt");
    int count = 0;
    if (file.is_open()) {
        string line;
        while (count < 100 && getline(file, line)) {
            size_t pos = 0;
            string parts[6]; 
            int i = 0;
            while ((pos = line.find('|')) != string::npos && i < 6) {
                parts[i++] = line.substr(0, pos);
                line.erase(0, pos + 1);
            }
            if (i == 6) {
                list[count].Name = parts[0];
                list[count].City = parts[1];
                list[count].Number = parts[2];
                list[count].Skill = parts[3];
                list[count].Password = parts[4]; 
                list[count].Isavalible = (parts[5] == "Musait");
                count++;
            }
        
            else if (i == 5) {
                list[count].Name = parts[0];
                list[count].City = parts[1];
                list[count].Number = parts[2];
                list[count].Skill = parts[3];
                list[count].Password = parts[2]; 
                list[count].Isavalible = (parts[4] == "Musait");
                count++;
            }
        }
        file.close();
    }
    return count;
}

void UpdateStatus(Volunteer list[], int count) {
    int id;
    cout << "\nDurumunu degistirmek istediginiz kisinin ID'sini giriniz: ";
    cin >> id;

    if (id < 1 || id > count) {
        cout << "[HATA] Gecersiz ID!" << endl;
        return;
    }

    list[id - 1].Isavalible = !list[id - 1].Isavalible;
    
    string newStatus = (list[id-1].Isavalible) ? "Musait" : "Mesgul";
    cout << "\n[OK] " << list[id-1].Name << " isimli kisinin yeni durumu: " << newStatus << endl;
}

void DeleteVolunteer(Volunteer list[], int &count) {
    if (count == 0) {
        cout << "\n[!] Liste bos, silinecek kimse yok!" << endl;
        return;
    }

    int id;
    cout << "\nSilmek istediginiz kisinin ID numarasini giriniz: ";
    cin >> id;

    if (id < 1 || id > count) {
        cout << "[HATA] Gecersiz ID! Lutfen 1 ile " << count << " arasinda bir rakam giriniz." << endl;
        return;
    }

    char confirm;
    cout << list[id-1].Name << " isimli kaydi silmek istediginize emin misiniz? (y/n): ";
    cin >> confirm;

    if (confirm == 'y' || confirm == 'Y') {
        for (int i = id - 1; i < count - 1; i++) {
            list[i] = list[i + 1]; 
        }
        count--; 
        SaveToTxtFile(list, count);
        cout << "\n[OK] Kayit basariyla silindi " << endl;
    } else {
        cout << "\n[!] Islem iptal edildi." << endl;
    }
}

void VolunteerLogin(Volunteer list[], int count){
    if(count == 0) {
        cout << "\n[HATA] Sistemde kayitli gonullu bulunmamaktadir." << endl;
        return;
    }

    string phone, password;
    cout << "\n--- GONULLU GIRISI ---" << endl;
    cout << "Telefon: ";
    cin >> phone;
    cout << "Sifre: ";
    cin >> password;

    int loggedInIndex = -1; 

    for(int i = 0; i < count; i++){
        if(list[i].Number == phone && list[i].Password == password){
            loggedInIndex = i;
            break;
        }
    }

    if(loggedInIndex != -1){
        cout << "\n[OK] Giris basarili!" << endl;
        cout << "Hosgeldiniz, " << list[loggedInIndex].Name << "!" << endl;
        
        string currentStatus = (list[loggedInIndex].Isavalible) ? "Musait" : "Mesgul";
        cout << "\n--- PROFIL BILGILERINIZ ---" << endl;
        cout << "Mevcut Durumunuz: " << currentStatus << endl;
        cout << "\nDurumunuzu degistirmek ister misiniz? (Evet: 1 / Hayir: 0): ";
        
        string choice;
        cin >> choice;
        
        if(choice == "1") {
            list[loggedInIndex].Isavalible = !list[loggedInIndex].Isavalible;
            string newStatus = (list[loggedInIndex].Isavalible) ? "Musait" : "Mesgul";
            cout << "\n[OK] Durumunuz basariyla guncellendi! Yeni durum: " << newStatus << endl;
        } else {
            cout << "\n[!] Herhangi bir degisiklik yapilmadan ana menuye donuluyor." << endl;
        }
        
    } else {
        cout << "\n[HATA] Telefon veya sifre yanlis!" << endl;
    }
}

void RunVolunteerSystem(){
    Volunteer Arvolunteer[100];
    int totalcount = LoadFromFile(Arvolunteer);
    int roleChoice;
    
    // ANA AKIS DONGUSU
    do {
        roleChoice = ShowRoleMenu();
        
        // YONETICI SECILDIYSE
        if (roleChoice == 1) {
            if (AdminLogin()) {
                int adminChoice;
                do {
                    adminChoice = ShowAdminMenu(); 
                    switch (adminChoice) {
                        case ADMIN_ADD:
                            if(totalcount < 100){
                                totalcount = RegiseterAllVolunteer(Arvolunteer, totalcount);
                            } else {
                                cout << "\n[HATA] Sistem dolu! Daha fazla gonullu eklenemez." << endl;
                            }
                            break;
                        case ADMIN_DISPLAY:
                            DisplayFullList(Arvolunteer, totalcount);
                            break;
                        case ADMIN_SEARCH:
                             SearchBySkill(Arvolunteer, totalcount);
                             break;
                        case ADMIN_CHANGE_STATUS:
                             UpdateStatus(Arvolunteer, totalcount);
                             SaveToTxtFile(Arvolunteer, totalcount);
                             break;
                        case ADMIN_DELETE:
                             DeleteVolunteer(Arvolunteer, totalcount);
                             break;
                        case ADMIN_STATISTICS:
                             ShowStatistics(Arvolunteer, totalcount); // YENI EKLENEN DASHBOARD ÇAĞRISI
                             break;
                        case ADMIN_EXIT:
                             cout << "\nYonetici oturumu kapatiliyor. Ana ekrana donuluyor..." << endl;
                             break;
                    }
                } while (adminChoice != ADMIN_EXIT);
                SaveToTxtFile(Arvolunteer, totalcount); // Yonetici cikarken her ihtimale karsi kaydet
            }
        } 
        // GONULLU SECILDIYSE
        else if (roleChoice == 2) {
            VolunteerLogin(Arvolunteer, totalcount);
            SaveToTxtFile(Arvolunteer, totalcount); // Gonullu durumunu degistirmisse aninda kaydet
        }
        
    } while (roleChoice != 0); // 0 SECILENE KADAR SISTEM ACIK KALIR
    
    SaveToTxtFile(Arvolunteer, totalcount);
    cout << "\nSistemden cikiliyor... Iyi gunler dileriz." << endl;
}

int main(){
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    
    ShoWelcomeMessage();
    RunVolunteerSystem(); 
    
    return 0;
}