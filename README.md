# Các thuật toán sắp Xếp Trong C++

Dưới đây là một số thuật toán sắp xếp phổ biến được triển khai bằng C++:

- **Select Sort**: Sắp xếp chọn.
- **Bubble Sort**: Sắp xếp nổi bọt.
- **Insertion Sort**: Sắp xếp chèn.
- **Merge Sort**: Sắp xếp trộn.
- **Quick Sort**: Sắp xếp nhanh.
- **Gnome Sort**: Sắp xếp gnome.

## Hướng Dẫn Sử Dụng

Để sử dụng mã, chỉ cần gọi hàm tương ứng và chuyển mảng cần sắp xếp. Dưới đây là một ví dụ về cách sử dụng hàm `quickSort`:

```cpp
int main() {
    int n = 10;
    int A[10] = {10,2,1,3,2,2,9,6,7,5};
    quickSort(A,0,n - 1);
    pr(A,n);
    return 0;
}
