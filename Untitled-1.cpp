#include <iostream>
#include <cstdlib> 
#include <ctime>   
#include <fstream>
#include <string>    
#include <cmath>
#include <thread>
#include <chrono>
#include <iomanip>
 //(iomanip)bu kütüphane metni düzeltme amacına konulmuş yani yusufcum metni daha düzenli olması için#
//onu şimdili kullanmicaz ama söylüyorum çünkü gelecek güncellemede onunla ilgili bşey yapıcam araştırırsın


using namespace std;  

enum EnMenu{
    ADD_VOLUNTEER =1,
    DISPLAY_ALL=2,
    SEARCH_BY_SKILL=3,
    CHANGE_STATUS = 4,
    Deletevolunteer=5,
    EXIT=0
};
struct Volunteer{
    string Name;
    string City;
    string Number;
    string Skill;
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
// Kullanıcı harf girse bile programın çökmemesi için string kullandım yusufcum
int ShowMenu(){
    string choice;
   while (true)
   {
    cout<<"\n======= ANA MENÜ ======"<<endl;
    cout<<"1. GONULLU EKLE "<<endl;
    cout<<"2. TUM LİSTEYI GÖSTER "<<endl;
    cout<<"3. BECEREYE GORE ARA "<<endl;
    cout<<"4. DURUM DEĞİŞTİR "<<endl;
    cout<<"5.GÖNÜLLÜ SİL"<<endl;

    cout<<"0. CIKIS"<<endl;
    cout<<"Seciminiz: ";
    cin>>choice;
    cin.ignore(); // enter tuşunu temizlemek için
    if(choice=="1")return ADD_VOLUNTEER;
    if (choice=="2")return DISPLAY_ALL;
    if(choice=="3")return SEARCH_BY_SKILL;
    if(choice=="4")return CHANGE_STATUS;
    if(choice=="5")return Deletevolunteer;
    if(choice=="0")return EXIT;
    cout<<"HATA! Lutfen tekrar deneyin.... 1, 2 ,3 ,4 ,5 veya 0 seciniz";
   
    
   }
  
}


void ShoWelcomeMessage(){
cout << "*****************************************" << endl;
cout << "* AGS - AFET GONULLU SISTEMLERI   *" << endl;
cout << "*****************************************" << endl;

    
}
void ReadInformation(Volunteer &v){


cout<<"\nPlease Enter The information of new volunteer...\n"<<endl;
    cout<<"Isminizi giriniz: "<<endl;
    getline(cin,v.Name);
    // telefon kontrolü: 11 hane ve 05 ile başlamalı yusufcum
    do
    {
        cout<<"lütfen numarınızı giriniz (Telefon numarınızı 11 hane ve 05 ile başlamalıdır):"<<endl;
        cin>>v.Number;
        if (v.Number.length() != 11 || v.Number.substr(0, 2) != "05")
        {
            cout<<"Hata! geçersiz numara. lütfen (05xx xxx xx xx) ile başlayan 11 haneli numara giriniz. "<<endl;
        }
        
    } while (v.Number.length() != 11 || v.Number.substr(0, 2) != "05");
     cin.ignore(); // buda belleği temizleyebilmesi için onsuz bu satır okunmayacak
   
   
  cout<<"Lütfen şehirinizi geriniz: "<<endl;
  getline(cin,v.City);
  bool ValidSkill=false;
  while (!ValidSkill)
  {
    
  
  
    cout<<"\n lutfen becerinizi seciniz (numara giriniz): "<<endl;
    cout<<"1. Arama Kurtarma (Search & Rescue) "<<endl;
    cout<<"2. Sağlık Personeli (Doctor/Nurse) "<<endl;
    cout<<"3. Tercüman (Translator) "<<endl;
    cout<<"4. inşaat mühendisliği (Civil Engineer) "<<endl;
    cout<<"5. Piskolog (Psychological Support) "<<endl;
    cout<<"6. Şoför / Operator "<<endl;
    cout<<"7. Aşcılık "<<endl;
    cout<<"8. lojısitk "<<endl;
    cout<<"9. Diğer: "<<endl;
    string SkillChoice;
    cout<<"Seçiminiz: ";
    cin>>SkillChoice;
    cin.ignore();
    if(SkillChoice=="1"){v.Skill="Arama kurtarma",ValidSkill=true;}// seçim doğruysa kilidi aç
    else if(SkillChoice=="2"){v.Skill="Saglık",ValidSkill=true;}
    else if(SkillChoice=="3"){v.Skill="Tercuman",ValidSkill=true;}
    else if(SkillChoice=="4"){v.Skill="Muhendis",ValidSkill=true;}
    else if(SkillChoice=="5"){v.Skill="Piskolog",ValidSkill=true;}
    else if(SkillChoice=="6"){v.Skill="Soför",ValidSkill=true;}
    else if(SkillChoice=="7"){v.Skill="Aşçılık",ValidSkill=true;}
    else if(SkillChoice=="8"){v.Skill="Lojistik",ValidSkill=true;}
    else if(SkillChoice=="9"){
        cout<<"Lutfen becerinizi belirtin: ";// özel giriş olsa bile geçerli say
        getline(cin,v.Skill);
        ValidSkill=true;
    }else{
        // hatalı girişte ValidSkill FALSE kalır ve döngü başa döner
        cout<<"\n[HATA] Gecersiz secim! Lutfen listedeki rakamlardan birini giriniz."<<endl;
    }

  }
   
     v.Isavalible=true;  //burda ilk kaydığındı yaptırtığında otomatiktan müsait oluyor

}
bool Askuser( ){
    string choice;
  while (true)
  {
    cout << "Başka birini eklemek ister misiniz? (evet: 1 / Hayir: 0): ";
    cin>>choice;
    if (choice=="1")
    {
        cin.ignore();
        return true;
    }else if(choice=="0"){
        cin.ignore();
        return false;
    }else{
        cout<<"Hata! lütfen sadece 0 veya 1 giriniz."<<endl;
    }

    
    
  }
  
    

   
        
        

   
   
} 
// CurrentCount ekledim: Eski isimlerin üzerine yazmamak için
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
    return counter; // yeni toplam sayıyı ana sisteme döndürür
}

void PrintInormation(Volunteer v){
    
    cout<<"********************"<<endl;
    cout<<"Name: "<<v.Name<<endl;
    cout<<"City: "<<v.City<<endl;
    cout<<"Phone Number: "<<v.Number<<endl;
    cout<<"Skill: "<<v.Skill<<endl;
   if (v.Isavalible==true)
   {
    cout<<"Durum: Müsait"<<endl;
   }else if(v.Isavalible==false){
    cout<<"Durum: Meşgül"<<endl;
   }
   
    cout<<"********************";
}
void DisplayFullList(Volunteer list[],int count){
    cout << "\n=========================================" << endl;
    cout<< "          ŞU ANDA KAYITLI GÖNÜLLÜLER         "<<endl;
    cout << "\n=========================================" << endl;
if (count==0)
{
cout<<"Henüz kayıtlı gönüllü yok."<<endl;
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
  
    

cout << "\n=========================================" << endl;
}
// Yusufcum, bu fonksiyon beceriye göre arama yapar.
// Hata payını sıfıra indirmek için kullanıcıdan numara (1-9) alıyoruz.
// çok önemli bşey var: Buradaki kelimeler, ReadInformationdaki kelimelerle BİREBİR aynı olmalı.
void SearchBySkill(Volunteer list[],int count){
    if(count==0){
        cout<<"\n[UYARI] Sistemde henüz kayıtlı gönüllü yok!"<<endl;
        return;
    }
cout<<"\n ---Becerye Göre Arama---"<<endl;
cout<<"1. Arama kurtarma\n2. sağlık personeli\n3. Tercüman\n4. Muhendis\n5. Piskolg\n6. Soför\n7.Ascilik\n8. Lojistik\n9.diger"<<endl;
    
    string serachchoice;
    cout<<"Aramak istediğiniz beceri numarasını giriniz:"<<endl;
    cout<<"Seciminiz:";

    cin>>serachchoice;
    cin.ignore();
    string targetskill="";
    if (serachchoice=="1")targetskill="Arama kurtarma";
    else if(serachchoice=="2")targetskill="Saglık";
    else if(serachchoice=="3")targetskill="Tercuman";
    else if(serachchoice=="4")targetskill="Muhendis";
    else if(serachchoice=="5")targetskill="Piskolog";
    else if(serachchoice=="6")targetskill="Soför";
    else if(serachchoice=="7")targetskill="Aşçilik";
    else if(serachchoice=="8")targetskill="Lojistik";
    else if(serachchoice=="9"){
        cout<<"Aramak istediğiniz özel becerinizi yazınız: ";
        getline(cin,targetskill);
    }
    bool found=false;
    cout<<"\n---ARAMA SONUÇLARI---"<<endl;
    for (int i = 0; i < count; i++)
    {// Eğer gönüllünün becerisi, aranan beceriyle tam eşleşirse ekrana yazdırır
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
        cout<<"\n[!] Maalesef bu beceriye sahip bir gönüllü bulunamadı."<<endl;
    }

    cout << "\nMenuye donmek icin Enter'a basiniz...";
    cin.get();
    
    
}
//VERİ KAYDETME FONKSİYONU (RAM'den Sabit Diske)

void SaveToTxtFile(Volunteer list[], int count) {
    ofstream file("Volunteers.txt"); 
    if (file.is_open()) {
        for (int i = 0; i < count; i++) {
            string status = (list[i].Isavalible) ? "Musait" : "Mesgul";
            
            file << list[i].Name << "|" 
                 << list[i].City << "|" 
                 << list[i].Number << "|" 
                 << list[i].Skill << "|" 
                 << status << "|" << endl;
        }
        file.close();
        cout << "\n[OK] Veriler Volunteers.txt dosyasina basariyla kaydedildi!" << endl;
    }
}

//VERİ KAYDETME FONKSİYONU (RAM'den Sabit Diske)

int LoadFromFile(Volunteer list[]) {
    ifstream file("Volunteers.txt");
    int count = 0;
    if (file.is_open()) {
        string line;
        while (count < 100 && getline(file, line)) {
            size_t pos = 0;
            string parts[5];
            int i = 0;
            while ((pos = line.find('|')) != string::npos && i < 5) {
                parts[i++] = line.substr(0, pos);
                line.erase(0, pos + 1);
            }
            list[count].Name = parts[0];
            list[count].City = parts[1];
            list[count].Number = parts[2];
            list[count].Skill = parts[3];
            list[count].Isavalible = (parts[4] == "Musait");
            count++;
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
        cout << "\n[!] Liste boş, silinecek kimse yok!" << endl;
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
// ana mantığı buraya topladık: Main fonksiyonunu temiz tutmak için gelecekte bu kod üzerinde geliştirme yapmak istesek kolay olsun diye
void RunVolunteerSystem(){
    Volunteer Arvolunteer[100];
    int totalcount=LoadFromFile(Arvolunteer);
    int choice;
    do
    {
        choice=ShowMenu(); //burada kullancıdan bir rakam alınamsı istenecek 1,2 veya 0 sonra devam edilecek
        switch (choice)
        {
        case ADD_VOLUNTEER:
            if(totalcount<100){
            totalcount=RegiseterAllVolunteer(Arvolunteer,totalcount);
        }else{
            cout << "\n[HATA] Sistem dolu! Daha fazla gonullu eklenemez." << endl;
        }
            break;
            case DISPLAY_ALL:
            DisplayFullList(Arvolunteer,totalcount);
            break;
        case SEARCH_BY_SKILL:
        // Fonksiyona diziyi (Arvolunteer) ve güncel sayıyı (totalcount) gönderiyoruz
             SearchBySkill(Arvolunteer,totalcount);
             break;
        case CHANGE_STATUS:
              UpdateStatus(Arvolunteer,totalcount);
              break;
        case Deletevolunteer:
             DeleteVolunteer(Arvolunteer,totalcount);
             SaveToTxtFile(Arvolunteer, totalcount);
             break;
              
        case EXIT:
            SaveToTxtFile(Arvolunteer,totalcount);
            //system("start volunteer.html");
            cout<<"Sistemden cıkılıyor... Iyı günler"<<endl;
        return;

        
        default:
            break;
        }

    } while (choice!=EXIT);
    

}



int main(){
    
system("chcp 65001");
    ShoWelcomeMessage();
    RunVolunteerSystem(); // Programı buradan başlatıyoruz

   





}
