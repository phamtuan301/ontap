#include <stdio.h>
#define MAX 100
int n;
int arr[MAX];
int isprime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}
int main() {
    int choice;
    int value;
    int index;
    int temp;
    int found;
    while (1) {
        printf("\nMENU\n");
        printf("1. Nhap so phan tu can nhap va gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu dang quan ly\n");
        printf("3. In ra gia tri lon nhat cua mang\n");
        printf("4. In ra cac phan tu la so nguyen to trong mang\n");
        printf("5. Them mot phan tu vao trong mang\n");
        printf("6. Xoa mot phan tu trong mang\n");
        printf("7. Sap xep mang theo thu tu tang dan\n");
        printf("8. Tim kiem phan tu va in ra vi tri index cua phan tu do\n");
        printf("9. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                // Nhap so phan tu va gia tri cac phan tu
                printf("Nhap so phan tu: ");
                scanf("%d", &n);
                printf("Nhap gia tri cac phan tu:\n");
                for (int i = 0; i < n; i++) {
                    printf("Phan tu %d: ", i+1);
                    scanf("%d", &arr[i]);
                }
                break;
            case 2:
                // In ra gia tri cac phan tu
                printf("Gia tri cac phan tu dang quan ly:\n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            case 3:
                // In ra gia tri lon nhat cua mang
                if (n > 0) {
                    int max = arr[0];
                    for (int i = 1; i < n; i++) {
                        if (arr[i] > max) {
                            max = arr[i];
                        }
                    }
                    printf("Gia tri lon nhat cua mang: %d\n", max);
                } else {
                    printf("Mang rong\n");
                }
                break;
            case 4:
                // In ra cac phan tu la so nguyen to trong mang
                printf("Cac phan tu la so nguyen to trong mang:\n");
                for (int i = 0; i < n; i++) {
                    if (isprime(arr[i])) {
                        printf("%d ", arr[i]);
                    }
                }
                printf("\n");
                break;
            case 5:
                // Them phan tu vao mang
                    printf("Nhap gia tri phan tu can them: ");
                    scanf("%d", &value);
                    arr[n] = value;
                    n++;
                    printf("Phan tu %d da duoc them vao mang.\n", value);
                break;
            case 6:
                // Xoa phan tu trong mang
                printf("Nhap gia tri phan tu can xoa: ");
                scanf("%d", &value);
                found = 0;
                for (int i = 0; i < n; i++) {
                    if (arr[i] == value) {
                        for (int j = i; j < n - 1; j++) {
                            arr[j] = arr[j + 1];
                        }
                        n--;
                        found++;
                        printf("Phan tu %d da duoc xoa khoi mang.\n", value);
                        break;
                    }
                }
                if (found==-1) {
                    printf("Phan tu %d khong tim thay trong mang.\n", value);
                }
                break;
            case 7:
                // Sap xep mang theo thu tu tang dan
                for (int i = 0; i < n - 1; i++) {
                    for (int j = i + 1; j < n; j++) {
                        if (arr[i] > arr[j]) {
                            temp = arr[i];
                            arr[i] = arr[j];
                            arr[j] = temp;
                        }
                    }
                }
                printf("Mang sau khi sap xep:\n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            case 8:
                // Tim kiem phan tu nhap vao va in ra vi tri phan tu trong mang
                printf("Nhap gia tri phan tu can tim: ");
                scanf("%d", &value);
                found = 0;
                for (int i = 0; i < n; i++) {
                    if (arr[i] == value) {
                        printf("Phan tu %d tim thay tai vi tri index %d\n", value, i);
                        found++;
                        break;
                    }
                }
                if (found==-1) {
                    printf("Phan tu %d khong tim thay trong mang.\n", value);
                }
                break;
            case 9:
                printf("Thoat chuong trinh");
                return 0;
            default:
                printf("Lua chon khong hop le vui long chon lai.\n");
        }
    }
    return 0;
}
