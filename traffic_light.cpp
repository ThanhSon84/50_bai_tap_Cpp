#include <iostream>

// Khai báo lớp cho kiểu liệt kê mô tả màu đèn giao thông.
// Sử dụng 'enum class' là một cách làm hiện đại và an toàn hơn trong C++.
enum class Traffic_light { green, yellow, red };

// Định nghĩa lại hàm toán tử << để có thể in ra tên của màu đèn thay vì giá trị số.
// Điều này giúp kết quả hiển thị trực quan và dễ hiểu hơn.
std::ostream& operator<<(std::ostream& os, const Traffic_light& t) {
    switch (t) {
        case Traffic_light::green:
            os << "green";
            break;
        case Traffic_light::yellow:
            os << "yellow";
            break;
        case Traffic_light::red:
            os << "red";
            break;
    }
    return os;
}

// Định nghĩa lại hàm toán tử ++ (toán tử tiền tố).
// Hàm nhận vào một tham chiếu đến biến Traffic_light và trả về một tham chiếu.
// Điều này cho phép thay đổi trực tiếp giá trị của biến được truyền vào.
Traffic_light& operator++(Traffic_light& t) {
    switch (t) {
        case Traffic_light::green:
            t = Traffic_light::yellow;
            break;
        case Traffic_light::yellow:
            t = Traffic_light::red;
            break;
        case Traffic_light::red:
            t = Traffic_light::green;
            break;
    }
    return t;
}

// Chương trình chính để minh họa hoạt động của toán tử
int main() {
    // Khai báo sử dụng namespace std để không cần gõ std:: trước mỗi lệnh.
    using namespace std;

    // Tạo biến lưu trạng thái màu đèn giao thông, khởi tạo với giá trị green.
    Traffic_light light = Traffic_light::green;

    cout << "Trang thai ban dau: " << light << endl;

    // Thực hiện ba lần phép toán với toán tử ++ và in ra kết quả sau mỗi lần.
    cout << "-------------------------" << endl;

    // Lần 1: green -> yellow
    ++light;
    cout << "Sau khi ++ lan 1: " << light << endl;

    // Lần 2: yellow -> red
    ++light;
    cout << "Sau khi ++ lan 2: " << light << endl;

    // Lần 3: red -> green
    ++light;
    cout << "Sau khi ++ lan 3: " << light << endl;

    return 0;
}
