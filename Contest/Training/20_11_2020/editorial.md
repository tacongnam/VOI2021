# HAMMING DISTANCE 

Gọi dp[i][j][k] là số lượng số sao cho 8 bit đầu lập thành số i và khoảng cách hamming giữa 8 bit sau của số đó và j là k.

# XOR THE GRAPH

Sử dụng ý tưởng tô màu đồ thị. Chú ý verdict MLE on test 42.

# INVITED SPEAKERS

Duyệt hoán vị rồi nối hai điểm tương ứng bằng 1 đoạn thẳng.
Xét hai cặp điểm (a1, b1), (a2, b2) cắt nhau. Chúng ta có thể nối lại bằng cách (a1, b2), (a2, b1). Do (a1, b2) + (a2, b1) < (a1, b1) + (a2, b2).
Do đó, hoán vị có tổng khoảng cách giữa hai điểm xanh và đỏ là nhỏ nhất là đáp án.

# SEREJA AND LCM

dp[i][l]: tạo được i số, lcm của a1 -> ai = l
lcm = x chia hết cho D <=> gcd(x, D) = D.
gcd(D, lcm(x, l))

# SWAP AND FLIP

dp bitmask

# ABSTRACT PAINTING

Quan sát theo hướng: từ mép bên phải ta vẽ một hình tròn. Ta chỉ cần quan tâm 10 ô gần nhất xem có thể được điền các mép bên trái vào được không.
dp[i][mask]: Xét điểm mép phải là i, 10 ô gần nhất có trạng thái là mask
<!--stackedit_data:
eyJoaXN0b3J5IjpbOTc4MDY4MTUyLDkyNTI4OTE3OSwtMTQzOD
E1NjY1NCw3NDA5ODEwOTksMjIzMjYyMDM2LC0xMTE4NTY2Mzk4
LDIzNjEwNzM4NF19
-->