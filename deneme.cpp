#include <iostream>
using namespace std;

// --- النماذج الأولية (Prototypes) ---
// يجب وضعها هنا ليعرف المترجم وجود هذه الدوال قبل الـ main
void ReceiveMessage(string msg);
void ShowNotification(string type);

int main() {
    // نقطة انطلاق البرنامج (المدير)
    ReceiveMessage("Hello from Gemini!");
    return 0;
}

// --- تفاصيل الدوال (Implementation) تحت الـ main ---

void ReceiveMessage(string msg) {
    cout << "New Message: " << msg << endl;
    // هذه الدالة تستدعي الدالة الموجودة بالأسفل
    ShowNotification("MessageIcon");
}

void ShowNotification(string type) {
    cout << "Displaying " << type << " on screen." << endl;
    // في الأنظمة المعقدة، قد تحتاج هذه الدالة للرجوع لبيانات الرسائل
}