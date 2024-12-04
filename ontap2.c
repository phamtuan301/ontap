#include <stdio.h>
int arr[100][100];
int m, n;
int main() {
    int choice;
    int x;
    int found = -1;
    int product;
    int temp;
    while (1) {
        printf("\nMENU\n");
        printf("1. Nhap kich co va gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3. In ra cac phan tu nam tren duong bien va tinh tich\n");
        printf("4. In ra cac phan tu nam tren duong cheo chinh\n");
        printf("5. In ra cac phan tu nam tren duong cheo phu\n");
        printf("6. Sap xep duong cheo chinh theo thu tu tang dan\n");
        printf("7. Tim kiem mot phan tu va in ra vi tri cua phan tu do trong mang\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                // Nhap kich co va gia tri cac phan tu cua mang
                printf("Nhap so dong (n): ");
                scanf("%d", &n);
                printf("Nhap so cot (m): ");
                scanf("%d", &m);
                printf("Nhap gia tri cac phan tu cua mang:\n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        printf("Phan tu: ");
                        scanf("%d", &arr[i][j]);
                    }
                }
                break;
            case 2:
                // In gia tri cac phan tu theo ma tran
                printf("Gia tri cac phan tu trong mang:\n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        printf("%d ", arr[i][j]);
                    }
                    printf("\n");
                }
                break;
            case 3:
                // In ra cac phan tu tren duong bien va tinh tich
                product = 1;
                printf("Cac phan tu tren duong bien:\n");
                for (int i = 0; i < m; i++) {
                    printf("%d ", arr[0][i]);  
                    product *= arr[0][i];
                    if (n > 1) {
                        printf("%d ", arr[n - 1][i]);  
                        product *= arr[n - 1][i];
                    }
                }
                for (int i = 1; i < n - 1; i++) {
                    printf("%d ", arr[i][0]); 
                    product *= arr[i][0];
                    if (m > 1) {
                        printf("%d ", arr[i][m - 1]);  
                        product *= arr[i][m - 1];
                    }
                }
                printf("\nTich cua cac phan tu tren duong bien: %d\n", product);
                break;
            case 4:
                // In ra cac phan tu nam tren duong cheo chinh
                printf("Cac phan tu tren duong cheo chinh:\n");
                for (int i = 0; i < n && i < m; i++) {
                    printf("%d ", arr[i][i]);
                }
                printf("\n");
                break;
            case 5:
                // In ra cac phan tu nam tren duong cheo phu
                printf("Cac phan tu tren duong cheo phu:\n");
                for (int i = 0; i < n && i < m; i++) {
                    printf("%d ", arr[i][m - i - 1]);
                }
                printf("\n");
                break;
            case 6:
                // Sap xep duong cheo chinh theo thu tu tang dan
                for (int i = 0; i < n && i < m; i++) {
                    for (int j = i + 1; j < n && j < m; j++) {
                        if (arr[i][i] > arr[j][j]) {
                            temp = arr[i][i];
                            arr[i][i] = arr[j][j];
                            arr[j][j] = temp;
                        }
                    }
                }
                printf("Cac phan tu tren duong cheo chinh sau khi sap xep:\n");
                for (int i = 0; i < n && i < m; i++) {
                    printf("%d ", arr[i][i]);
                }
                printf("\n");
                break;
            case 7:
                // Tim kiem mot phan tu va in vi tri phan tu do tren mang
                printf("Nhap gia tri phan tu can tim: ");
                scanf("%d", &x);
                found = 0;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        if (arr[i][j] == x) {
                            printf("Phan tu %d tim thay tai vi tri [%d][%d]\n", x, i, j);
                            found++;
                            break;
                        }
                    }
                     break;
                }
                if (found==-1) {
                    printf("Phan tu %d khong tim thay trong mang.\n", x);
                }
                break;
            case 8:
            	printf("Thoat chuong trinh ");
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    }

    return 0;
}
