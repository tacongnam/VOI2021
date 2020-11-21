# DATA2
TH1: Nếu đồ thị là 1 cây -> Tập A chính là các lá.

TH2: Đồ thị tổng quát:

> Nhận xét: Đồ thị vô hướng luôn bao gồm các thành phần song liên thông, được nối với nhau bằng cầu. Nếu coi mỗi tpslt là 1 đỉnh thì ta được 1 cây.

Trên cây song liên thông (mỗi đỉnh là 1 tpslt), mỗi thành phần bậc 1 -> 1 đỉnh. Giả sử có p lá, số đỉnh trong mỗi lá lần lượt là a1, a2, ..., ap.

=> Đáp số: p a1.a2...ap.

### Mục tiêu:
+) Duyệt, gán xem mỗi đỉnh thuộc tpslt nào
+) Tạo cạnh giữa các tpslt dựa theo các cạnh
+) Đếm số tpslt có bậc 1.

# MOU

Bài toán quy về: Cho dãy $a_1 = h_2 - h_1$, ..., $a_{n-1} = h_n - h_{n-1}$. Đếm các dãy khác nhau của dãy {$a_1$, $a_2$, ..., $a_{n-1}$}.

Chiến lược: 

Đặt $f[i]$ = số lượng cách khác nhau kết thúc tại $i$. Đặt $prev[i] = k$ là vị trị $k < i$ gần nhất sao cho $a_k = a_i$. Đặt $f[0] = 1$.

TH1: $prev[i] = 0$ => $f[i] = 1 + f[1] + f[2] + ... + f[i - 1]$. (Kết thúc tại 1 điểm trước nó, sau đó thêm $a[i]$ vào cuối dãy).

TH2: $prev[i] > 0$ => $f[i] = 1 + (f[1] + ... + f[i - 1]) - (f[1] + ... + f[k - 1])$.

Đáp số là $f[n - 1]$.


<!--stackedit_data:
eyJoaXN0b3J5IjpbMTgyNTg3NzM5OCwxNDU1ODI2NTU0LC0xOT
YwODYwODk2XX0=
-->